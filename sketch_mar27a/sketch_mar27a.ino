/*
* pirLedInt.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* se encienda si el sensor PIR (sensor infrarrojo pasivo)
* detecta movimiento.
*
* Entre checadas del estado del PIR, suponemos que el
* microcontrolador ESP32 realiza una tarea que le lleva
* TIEMPO_TAREA ms. Durante ese tiempo si el PIR detecta un
* movimiento, no es detectado por el microcontrolador ESP32.
* Para evitar eso, haremos que el PIR genere una interrupcion
* al ocurrir un cambio en su pin de salida
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NoDelay.h>
// Pin a la que esta conectado el PIR, GPIO4
const unsigned int PIN_PIR = 4;
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Duracion en ms de la tarea que ejecuta el Microcontrolador ESP32
const long TIEMPO_TAREA = 4000;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
// Define los posibles estados del LED
typedef enum {
LED_APAGADO,
LED_ENCENDIDO
} estadoLed;
// Variable que guarda el estado del LED
volatile estadoLed edoLed;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido TIEMPO_TAREA ms
noDelay pausa(TIEMPO_TAREA);
void IRAM_ATTR pirISr();
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED,OUTPUT);
// Establece el pin PIN_PIR (GPIO4) como de entrada.
pinMode(PIN_PIR, INPUT);
// Establece la velocidad de transmisión del puerto serie al
// valor BAUD_RATE
Serial.begin(BAUD_RATE);
// Instala la rutina de atención llamada pirISr al evento
// de un cambio en el pin PIN_PIR (GPIO4)
attachInterrupt(PIN_PIR, pirISr, CHANGE);
// Establece el estado inicial del LED
edoLed = LED_APAGADO;
// Apaga el LED
digitalWrite(PIN_LED, LOW);
// Inicializa la tarea simulada
Serial.println("Inicia tarea");
}
void loop() {
// Verifica si ss termino de ejecutar la tarea
if (pausa.update()) {
Serial.println("Termina tarea");
Serial.println("Inicia tarea");
}
}
/*
* Esta funcion es la rutina de atencion a la interrupcion
* generada cuando el pin conectado al boton cambia de estado
*/
void IRAM_ATTR pirISr() {
// Si se el PIR detecto/dejo de detectar movimiento,
// Prender/apagar el LED
switch(edoLed) {
case LED_APAGADO:
// Enciende el LED
digitalWrite(PIN_LED, HIGH);
// Actualiza la variable que guarda el estado del LED
edoLed = LED_ENCENDIDO;
break;
case LED_ENCENDIDO:
// Apaga el LED
digitalWrite(PIN_LED, LOW);
// Actualiza la variable que guarda el estado del LED
edoLed = LED_APAGADO;
}
}