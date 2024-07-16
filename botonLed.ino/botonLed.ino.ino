/*
* botonLed.ino
*
* Este programa hace que el led de del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* encienda cuando el interruptor de boton se presiona y
* se apague al liberarlo.
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
// Crea una instancia de la clase Bounce
Bounce debouncer = Bounce();
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
// Establece el pin PIN_BOTON (GPIO4) como de entrada.
pinMode(PIN_BOTON, INPUT);
// Establece el interruptor de boton al que se le
// eliminara el ruido
debouncer.attach(PIN_BOTON);
// Establece el intervalo (en ms) de espera para eliminar
// el ruido
debouncer.interval(5);
}
void loop() {
// Actualiza el valor de la instancia del objeto Bounce.
// Debe hacerse frecuentemente. Una vez en cada iteracion de
// la funcion loop()
debouncer.update();
// Obten el estado del interruptor (HIGH o LOW)
int valor = debouncer.read();
// Enciende/apaga el led de acuerdo el valor del interruptor
digitalWrite(PIN_LED, valor);
}
