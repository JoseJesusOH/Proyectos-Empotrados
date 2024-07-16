/*
* blinkNoDelay.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* parpadee. Los periodos de estar encendido y apagado del led
* son iguales
*
* No usa la funcion delay(). Esto permite que otro codigo ejecute
* al mismo tiempo que se encuentra en el periodo de espera.
*/
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Periodo en ms que dura encendido o apagado el LED
const long PERIODO = 500;
// Inicialmente el LED está apagado
int estadoLed = LOW;
// Almacena la hora en la que se prendio/apago el LED
unsigned long lapsoAnterior = 0;
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
}
void loop() {
// Obtiene la hora actual
unsigned long lapsoActual = millis();
// Verifica si es tiempo de prender/apagar el LED
if (lapsoActual - lapsoAnterior >= PERIODO) {
// Almacena la hora en la que se prendio/apago el LED
lapsoAnterior = lapsoActual;
// Prender/apagar el LED
if (estadoLed == LOW) {
estadoLed = HIGH;
} else {
estadoLed = LOW;
}
digitalWrite(PIN_LED, estadoLed);
}
}