/*
* blinkNoDelay.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* parpadee. Los periodos de estar encendido y
* apagado del led son iguales
*
* No usa la funcion delay(). Esto permite que otro codigo ejecute
* al mismo tiempo que se encuentra en el periodo de espera.
*/
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Periodo en ms que dura encendido o apagado el LED
const unsigned int PAUSA = 500;
// Define los posibles estados del LED
typedef enum {
LED_APAGADO,
LED_ENCENDIDO
} estadoLed;
// Variable que guarda el estado del LED
estadoLed edoLed;
// Almacena la hora en la que se prendio/apago el LED
unsigned long lapsoAnterior = 0;
void apagaLED();
void enciendeLED();
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
// Establece el estado inicial del LED
apagaLED();
}
void loop() {
// Obtiene la hora actual
unsigned long lapsoActual = millis();
// Verifica si es tiempo de prender/apagar el LED
if (lapsoActual - lapsoAnterior >= PAUSA) {
// Almacena la hora en la que se prendio/apago el LED
lapsoAnterior = lapsoActual;
// Prender/apagar el LED
switch(edoLed) {
case LED_APAGADO:
enciendeLED();
break;
case LED_ENCENDIDO:
apagaLED();
}
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