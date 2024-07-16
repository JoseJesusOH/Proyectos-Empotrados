/*
* potLED.ino
*
* Este programa hace que el led conectado al pin 16 del
* microcontrolador ESP32 DEVKIT DOIT de 30 pines, parpadee.
* Los periodos de estar encendido y apagado del led son
* controlados por un potenciometro
*
* Cuando la perilla del potenciómetro esté en su posición
* media, los periodos de encendido y apagado serán iguales
* y su valor será de 2 s.
*
* Al girar la perilla en la dirección antihoraria, el tiempo
* de encendido disminuirá hasta que al girar completamente
* la perilla en la dirección antihoraria, el led permanecerá
* apagado.
*
* Al girar la perilla en la dirección horaria, el tiempo de
* apagado disminuirá hasta que, al girar completamente la
* perilla en la dirección horaria, el led permanecerá encendido.
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
// Pin a la que esta conectado el LED, GPIO16
const unsigned int PIN_LED = 16;
// Pin a la que esta conectado el potenciometro, GPIO34
const unsigned int PIN_POT = 34;
// Numero de valores de salida del ADC. 2**12 = 4096
const unsigned ADC_VALORES = 4096;
// Valor maximo del periodo encendido o apagado
const long PERIODO = 1000;
// Periodo en ms que dura encendido el LED
long periodoOn = PERIODO;
// Periodo en ms que dura apagado el LED
long periodoOff = PERIODO;
// Inicialmente el LED está apagado
int estadoLed = LOW;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PERIODO ms
noDelay pausa(periodoOff);
int obtenPeriodoOn(int muestra);
int obtenPeriodoOff(int muestra);
void setup() {
// Establece el pin PIN_LED (GPIO16) como de salida.
pinMode(PIN_LED, OUTPUT);
}
void loop() {
// Verifica si es tiempo de prender/apagar el LED
if (pausa.update()) {
// Lee y digitaliza el valor del voltaje en el potenciometro
int muestra = analogRead(PIN_POT);
// Convierte a valores para los tiempos de encendido
// y apagado
periodoOn = obtenPeriodoOn(muestra);
periodoOff = obtenPeriodoOff(muestra);
// Si el LED esta apagado
if (estadoLed == LOW) {
// Prende el LED
estadoLed = HIGH;
// Cambia el valor de la pausa a PERIODO_ON
pausa.setdelay(periodoOn);
// Si el led esta encendido
} else {
// Apaga el LED
estadoLed = LOW;
// Cambia el valor de la pausa a PERIODO_OFF
pausa.setdelay(periodoOff);
}
digitalWrite(PIN_LED, estadoLed);
}
}
/**
* Esta función determina el tiempo en el que estara encendido
* el LED en funcion del valor de la resistencia del potenciometro
*/
int obtenPeriodoOn(int muestra) {
return muestra < ADC_VALORES/2 ?
map(muestra, 0, ADC_VALORES/2, 0, PERIODO): PERIODO;
}
/**
* Esta función determina el tiempo en el que estara apagado
* el LED en funcion del valor de la resistencia del potenciometro
*/
int obtenPeriodoOff(int muestra) {
return muestra > ADC_VALORES/2?
map(muestra, ADC_VALORES/2, ADC_VALORES, PERIODO, 0): PERIODO;
}
