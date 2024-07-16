/*
* botonLedIntRebote.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* cambie de estado (de apagado a prendido o viceversa) cada
* vez que se presiona el interruptor de botón.
*
* Uno de los polos del interruptor de botón está conectado
* al pin 4 y el otro al pin 3.3V. Hay una resistencia de
* 10 KOhm entre tierra y el pin 4.
*
* Entre checadas del estado del boton, suponemos que el
* microcontrolador ESP32 realiza una tarea que le lleva
* TIEMPO_TAREA ms.
*
* Si se presiona el boton se genera una interrupcion
*
* Debido al rebote del boton, se puede generar varias veces la
* interrupcion del boton y el estado del LED no quedar en el
* valor deseado.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NoDelay.h>
// Pin a la que esta conectado el interruptor, GPIO4
const unsigned int PIN_BOTON = 4;
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Duracion en ms de la tarea que ejecuta el Microcontrolador ESP32
const long TIEMPO_TAREA = 1000;
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
void IRAM_ATTR botonIsr();
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED,OUTPUT);
// Establece el pin PIN_BOTON (GPIO4) como de entrada.
pinMode(PIN_BOTON, INPUT);
// Establece la velocidad de transmisión del puerto serie al
// valor BAUD_RATE
Serial.begin(BAUD_RATE);
// Instala la rutina de atención llamada botonIsr al evento
// de un cambio de HIGH a LOW en el pin PIN_BOTON (GPIO4)
attachInterrupt(PIN_BOTON, botonIsr, FALLING);
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
* de HIGH a LOW.
*/
void IRAM_ATTR botonIsr() {
// Si se presiono el boton conectado al pin PIN_BOTON (GPIO4),
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