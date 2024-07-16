/* 
 * potLEDPWM.ino 
 * 
* Este programa hace que el led conectado al pin 16 del 
 * microcontrolador ESP32 DEVKIT DOIT de 30 pines, encienda 
 * con una intensidad controlada por un canal PWM. El ciclo 
 * de trabajo del canal PWM estara controlado por un 
 * potenciometro 
 * 
 * Cuando la perilla del potenciómetro esté en su posición 
 * media, el ciclo de trabajo será del 50%. 
 * 
 * Al girar la perilla en la dirección antihoraria, el ciclo 
 * de trabajo disminuirá hasta que al girar completamente 
 * la perilla en la dirección antihoraria, el ciclo de 
 * trabajo valdra cero, con lo que el LED disminuira su 
 * brillantes hasta quedar apagado. 
 * 
 * Al girar la perilla en la dirección horaria, el ciclo 
 * de trabajo aumentará hasta que, al girar completamente 
 * la perilla en la dirección horaria, el ciclo de trabajo 
 * valdra 100%, con lo que el LED aumentara su brillantes 
 * hasta quedar encendida. 
 * 
 * No usa la funcion delay(). En lugar de ello utiliza la 
 * biblioteca NoDelay. Esto permite que otro codigo ejecute al 
 * mismo tiempo que se encuentra en el periodo de espera. 
 */

#include <NoDelay.h>
// Pin a la que esta conectado el LED, GPIO16
const unsigned int PIN_LED = 16;
// Pin a la que esta conectado el potenciometro, GPIO34
const unsigned int PIN_POT = 34;
// Numero de valores de salida del ADC. 2**12 = 4096
const unsigned ADC_VALORES = 4096;
// PAUSA en ms que dura encendido el LED en una
// determinada intensidad
const long PAUSA = 20;
// Parametros de la señal PWM
const int FRECUENCIA = 5000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;
// Valor minimo del ciclo de trabajo
const unsigned int CT_MIN = 0;
// Valor maximo del ciclo de trabajo. 2**RESOLUCION - 1
const unsigned int CT_MAX = 255;
// Ciclo de trabajo de la forma de onda PWM
unsigned int cicloTrabajo;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
void actualizaCicloTrabajo(int muestra);
void setup() {
  // Configura los parametros de la señal PWM
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  // Establece el canal PWM al pin PIN_LED (GPIO16).
  ledcAttachPin(PIN_LED, CANAL_PWM);
  // Valor inicial del Ciclo de trabajo de la forma de onda PWM
  unsigned int cicloTrabajo = 0;
}
void loop() {
  // Verifica si ha transcuurido el tiempo dado por PAUSA
  if (pausa.update()) {
    // Lee y digitaliza el valor del voltaje en el potenciometro
    int muestra = analogRead(PIN_POT);
    // Convierte a un valor para el ciclo de trabajo
    actualizaCicloTrabajo(muestra);
    // Cambia la brillantes del LED, cambiando el ciclo
    // de trabajo del canal PWM
    ledcWrite(CANAL_PWM, cicloTrabajo);
  }
}
/** 
 * Esa función establece el valor del ciclo de trabajo de la señal 
PWM 
 * en función del voltaje del potenciometro, dado por muestra 
 */
void actualizaCicloTrabajo(int muestra) {
  // Convierte a un valor para el ciclo de trabajo
  cicloTrabajo = map(muestra, 0, ADC_VALORES - 1, CT_MIN,
                     CT_MAX);
}