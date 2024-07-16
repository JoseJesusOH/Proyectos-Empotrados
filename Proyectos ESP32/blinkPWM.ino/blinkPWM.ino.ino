/*
* blinkPWM.ino
*
* Este programa hace que el led conectado al pin 16 del
* microcontrolador ESP32 DEVKIT DOIT de 30 pines, encienda
* con una intensidad controlada por un canal PWM.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el PAUSA de espera.
*
* La liga para descargar esta biblioteca es:
*
* https://github.com/M-tech-Creations/NoDelay
*/
#include <NoDelay.h>
// Pin a la que esta conectado el LED, GPIO16
const unsigned int PIN_LED = 16;
// PAUSA en ms que dura encendido el LED en una
// determinada intensidad
const long PAUSA = 20;
// Parametros de la señal PWM
const int FRECUENCIA = 5000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;
// Valor minimo del ciclo de trabajo
const unsigned int MIN_CICLO_TRABAJO = 0;
// Valor maximo del ciclo de trabajo. 2**RESOLUCION - 1
const unsigned int MAX_CICLO_TRABAJO = 255;
// Valor inicial del Ciclo de trabajo de la forma de onda PWM
unsigned int cicloTrabajo = MIN_CICLO_TRABAJO;
// Incremento/decremento en el ciclo de trabajo
unsigned int paso = -1;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
void setup() {
// Configura los parametros de la señal PWM
ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
// Establece el canal PWM al pin PIN_LED (GPIO16).
ledcAttachPin(PIN_LED, CANAL_PWM);
}
void loop() {
// Verifica si ha transcuurido el tiempo dado por PAUSA
if (pausa.update()) {
// Cambia la brillantes del LED, cambiando el ciclo
// de trabajo del canal PWM
ledcWrite(CANAL_PWM, cicloTrabajo);
// Si el ciclo de trabajo se hace cero o excede el valor maximo
if(cicloTrabajo <= MIN_CICLO_TRABAJO ||
cicloTrabajo >= MAX_CICLO_TRABAJO) paso = -paso;
// Incrementa o decrementa el ciclo de trabajo
cicloTrabajo += paso;
}
}