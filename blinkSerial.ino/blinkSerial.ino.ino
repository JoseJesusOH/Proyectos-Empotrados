/*
* blinkSerial.ino
*
* Este programa hace que el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* parpadee. Los periodos de estar encendido y apagado del led
* son iguales.
*
* Ademas en el monitor serial del IDE 2.0 de Arduino se despliega
* si el led esta prendido o apagado.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NoDelay.h>
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Periodo en ms que dura encendido o apagado el LED
const long PERIODO = 500;
// Inicialmente el LED está apagado
int estadoLed = LOW;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PERIODO ms
noDelay pausa(PERIODO);
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
// Establece la velocidad de transmisión del puerto
// serie al valor BAUD_RATE
Serial.begin(BAUD_RATE);
}
void loop() {
// Verifica si es tiempo de prender/apagar el LED
if (pausa.update()) {
// Prender/apagar el LED
if (estadoLed == LOW) {
estadoLed = HIGH;
// Escribe mensaje al puerto serie
Serial.println("LED encendido");
} else {
estadoLed = LOW;
// Escribe mensaje al puerto serie
Serial.println("LED apagado");
}
digitalWrite(PIN_LED, estadoLed);
}
}