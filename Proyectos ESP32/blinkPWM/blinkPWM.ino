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
const unsigned int CT_MIN = 0;
// Valor maximo del ciclo de trabajo. 2**RESOLUCION - 1
const unsigned int CT_MAX = 255;
// Ciclo de trabajo de la forma de onda PWM
unsigned int cicloTrabajo;
// Incremento/decremento en el ciclo de trabajo
unsigned int paso;
// Define los posibles estados del ciclo de trabajo
typedef enum {
  CICLO_TRABAJO_MIN,
  CICLO_TRABAJO_INT,
  CICLO_TRABAJO_MAX
} estadoCT;

// Variable que guarda el estado del ciclo de trabajo
estadoCT edoCT;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
void actualizaCicloTrabajo();
void togglePasoCicloTrabajo();
void setup() {
  // Configura los parametros de la señal PWM
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  // Establece el canal PWM al pin PIN_LED (GPIO16).
  ledcAttachPin(PIN_LED, CANAL_PWM);

  // Valor inicial del Ciclo de trabajo de la forma de onda PWM
  cicloTrabajo = CT_MIN;
  // Valor inicial del incremento/decremento en el ciclo de
  // trabajo
  paso = -1;
  // Establece el estado inicial
  togglePasoCicloTrabajo();
}
void loop() {
  // Verifica si ha transcuurido el tiempo dado por PAUSA
  if (pausa.update()) {
    // Cambia la brillantes del LED, cambiando el ciclo
    // de trabajo del canal PWM
    ledcWrite(CANAL_PWM, cicloTrabajo);
    // Establece el ciclo de trabajo
    switch (edoCT) {
      case CICLO_TRABAJO_MIN:
        togglePasoCicloTrabajo();
        break;
      case CICLO_TRABAJO_INT:
        actualizaCicloTrabajo();
        break;
      case CICLO_TRABAJO_MAX:
        togglePasoCicloTrabajo();
    }
  }
}
/** 
 * Esa función incrementa o decrementa el valor del ciclo de 
 * trabajo de la señal PWM y actualiza dependiendo de su valor, el 
 * estado del ciclo de trabajo 
 */
void actualizaCicloTrabajo() {
  // Incrementa o decrementa el ciclo de trabajo
  cicloTrabajo += paso;

  // Cambia el estado dependiendo del valor del ciclo de trabajo
  if (cicloTrabajo <= CT_MIN) edoCT = CICLO_TRABAJO_MIN;
  else if (cicloTrabajo >= CT_MAX) edoCT = CICLO_TRABAJO_MAX;
  else edoCT = CICLO_TRABAJO_INT;
}
/** 
 * Esta funcion cambia de decrementar a incrementar el 
 * ciclo de trabajo o viceversa. 
 */
void togglePasoCicloTrabajo() {
  // Cambia de decrementar a incrementar el ciclo de trabajo
  paso = -paso;
  edoCT = CICLO_TRABAJO_INT;
}