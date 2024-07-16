/*
* blink
*
* Este programa hace que el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* parpadee. Los periodos de estar encendido y apagado del led
* son iguales.
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
void apagaLED();
void enciendeLED();
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
// Establece el estado inicial del LED
apagaLED();
}
void loop() {
// Pausa por medio segundo
delay(PAUSA);
// Prender/apagar el LED
switch(edoLed) {
case LED_APAGADO:
enciendeLED();
break;
case LED_ENCENDIDO:
apagaLED();
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
