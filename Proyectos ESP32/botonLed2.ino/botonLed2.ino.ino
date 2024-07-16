/*
* botonLed2.ino
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
* Este programa utiliza la biblioteca Bounce2 para eliminar
* el ruido en la conmutación de los interruptores
*
* La liga para descargar esta biblioteca es:
*
* https://github.com/thomasfredericks/Bounce2
*/
#include <Bounce2.h>
// Pin a la que esta conectado el interruptor, GPIO4
const unsigned int PIN_BOTON = 4;
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Estado actual del pin del LED
int estadoLed = LOW;
// Crea una instancia de la clase Bounce
Bounce debouncer = Bounce();
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
digitalWrite(PIN_LED, estadoLed);
}
void loop() {
// Actualiza el estadoBoton de la instancia del objeto Bounce.
// Debe hacerse frecuentemente. Una vez en cada iteracion de
// la funcion loop()
debouncer.update();
// Cambia el estado del led solo si el estado del boton cambio
// de HIGH a LOW
if (debouncer.fell()) {
estadoLed = !estadoLed;
digitalWrite(PIN_LED, estadoLed);
}
}