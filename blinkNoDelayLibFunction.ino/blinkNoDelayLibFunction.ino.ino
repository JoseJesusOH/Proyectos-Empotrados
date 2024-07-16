/*
* blinkNoDelayLibFunction.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* parpadee. Los periodos de estar encendido y apagado del led
* son iguales
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*
* La liga para descargar esta biblioteca es:
*
* https://github.com/M-tech-Creations/NoDelay
*/
#include <NoDelay.h>
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Periodo en ms que dura encendido o apagado el LED
const long PERIODO = 500;
// Inicialmente el LED está apagado
int estadoLed = LOW;
// Declaración de la función que sera llamada por la
// funcion update() cuando han transcurrido PERIODO ms
// La funcion debe ser de tipo void y sin argumentos
void ledToggle();
// Crea una instancia de la clase noDelay
// que llama a la funcion ledToggle() cada PERIODO ms
noDelay pausa(PERIODO, ledToggle);
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
}
void loop() {
// Verifica si es tiempo de invocar a la funcion ledToggle()
pausa.update();
}
/*
* Esta funcion enciende el LED si esta apagado o lo apaga si esta
* encendido. Esta funcion es llamada por la funcion update() una
* vez que ha transcurrido el periodo de tiempo dado
*/
void ledToggle() {
// Prender/apagar el LED
if (estadoLed == LOW) {
estadoLed = HIGH;
} else {
estadoLed = LOW;
}
digitalWrite(PIN_LED, estadoLed);
}