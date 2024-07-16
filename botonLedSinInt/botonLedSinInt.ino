/*
* botonLedSinInt.ino
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
* TIEMPO_TAREA ms. Durante ese tiempo si el usuario presiona
* el boton, no es detectado por el microcontrolador ESP32.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*
* Este programa utiliza la biblioteca Bounce2 para eliminar
* el ruido en la conmutación de los interruptores
*/
#include <NoDelay.h>
#include <Bounce2.h>
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
estadoLed edoLed;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido TIEMPO_TAREA ms
noDelay pausa(TIEMPO_TAREA);
// Crea una instancia de la clase Bounce
Bounce debouncer = Bounce();
void apagaLED();
void enciendeLED();
void setup() {

  // Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED,OUTPUT);
// Establece el pin PIN_BOTON (GPIO4) como de entrada.
pinMode(PIN_BOTON, INPUT);
// Establece el interruptor de boton al que se le
// eliminara el ruido
debouncer.attach(PIN_BOTON);
// Establece el intervalo (en ms) de espera para eliminar
// el ruido
debouncer.interval(25);
// Establece la velocidad de transmisión del puerto serie al
// valor BAUD_RATE
Serial.begin(BAUD_RATE);
// Establece el estado inicial del LED
apagaLED();
// Inicializa la tarea simulada
Serial.println("Inicia tarea");
}
void loop() {
// Verifica si ss termino de ejecutar la tarea
if (pausa.update()) {
Serial.println("Termina tarea");
// Actualiza el estadoBoton de la instancia del objeto
// Bounce.
debouncer.update();
// Cambia el estado del led solo si el estado del botón
// cambio de HIGH a LOW
if (debouncer.fell()) {
// Prender/apagar el LED
switch(edoLed) {
case LED_APAGADO:
enciendeLED();
break;
case LED_ENCENDIDO:
apagaLED();
}
}
Serial.println("Inicia tarea");
}
}
/**
* Esta funcion apaga el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2
* También actualiza la variable edoLed al valor LED_APAGADO
*/
void apagaLED() {
// Apaga el LED
digitalWrite(PIN_LED, LOW);
// Actualiza la variable que guarda el estado del LED
edoLed = LED_APAGADO;
}
/**
* Esta funcion enciende el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2
* También actualiza la variable edoLed al valor ENCENDIDO
*/
void enciendeLED() {
// Enciende el LED
digitalWrite(PIN_LED, HIGH);
// Actualiza la variable que guarda el estado del LED
edoLed = LED_ENCENDIDO;
}