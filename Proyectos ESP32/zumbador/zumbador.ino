/* 
 * zumbador.ino 
 *
  * Este programa hace que un zumbador conectado al pin 16 
 * del microcontrolador ESP32 DEVKIT DOIT de 30 pines, 
 * emita una secuencia de tonos controlados por un canal PWM. 
 * 
 * No usa la funcion delay(). En lugar de ello utiliza la 
 * biblioteca NoDelay. Esto permite que otro codigo ejecute al 
 * mismo tiempo que se encuentra en el PAUSA de espera. 
 */

#include <NoDelay.h>
// Pin a la que esta conectado el LED, GPIO16
const unsigned int PIN_ZUM = 16;
// Duración en ms de cada tono
const long PAUSA = 1000;
// Parametros de la señal PWM
const int FRECUENCIA = 2000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;
const unsigned int CICLO_TRABAJO = 127;
const int FREC_MIN = 250;
const int FREC_MAX = 5000;
// Pines del LED RGB
const int PIN_ROJO = 15;
const int PIN_VERDE = 4;
const int PIN_AZUL = 2;

// Frecuencia de la señal PWM
unsigned int frecuencia;
// Incremento/decremento en la frecuencia
int paso;
// Define los posibles estados de la frecuencia
typedef enum {
  FRECUENCIA_MIN,
  FRECUENCIA_INT,
  FRECUENCIA_MAX
} estadoFrecuencia;

// Variable que guarda el estado de la frecuencia
estadoFrecuencia edoFrec;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
void actualizaFrecuencia();
void togglePasoFrecuencia();
void setup() {
  // Configura los parametros de la señal PWM
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  // Establece el canal PWM al pin PIN_ZUM (GPIO16).
  ledcAttachPin(PIN_ZUM, CANAL_PWM);
  // Emite una señal PWM en el pin GPIO16
  ledcWrite(CANAL_PWM, CICLO_TRABAJO);
  // Valor inicial de la frecuencia de la señal PWM
  frecuencia = FREC_MIN;
  // Valor inicial del incremento/decremento en la
  // frecuencia
  paso = -250;
  // Configura los pines del LED RGB como salidas
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_AZUL, OUTPUT);
}
void loop() {
  // Verifica si ha transcurrido el tiempo dado por PAUSA
  if (pausa.update()) {
    // Cambia la frecuencia del canal PWM
    ledcWriteTone(CANAL_PWM, frecuencia);
    // Establece la frecuencia
    switch (edoFrec) {
      case FRECUENCIA_MIN:
        togglePasoFrecuencia();
        digitalWrite(PIN_ROJO, HIGH);
        digitalWrite(PIN_VERDE, LOW);
        digitalWrite(PIN_AZUL, LOW);
        break;
      case FRECUENCIA_INT:
        actualizaFrecuencia();
        digitalWrite(PIN_ROJO, LOW);
        digitalWrite(PIN_VERDE, HIGH);
        digitalWrite(PIN_AZUL, LOW);
        break;
      case FRECUENCIA_MAX:
        togglePasoFrecuencia();
        digitalWrite(PIN_ROJO, LOW);
        digitalWrite(PIN_VERDE, LOW);
        digitalWrite(PIN_AZUL, HIGH);
    }
  }
}
/** 
 * Esa función incrementa o decrementa el valor de la frecuencia 
 * de la señal PWM y actualiza dependiendo de su valor, el estado 
 * de la frecuencia 
 */
void actualizaFrecuencia() {
  // Incrementa o decrementa la frecuencia
  frecuencia += paso;

  // Cambia el estado dependiendo del valor de la frecuencia
  if (frecuencia <= FREC_MIN) edoFrec = FRECUENCIA_MIN;
  else if (frecuencia >= FREC_MAX) edoFrec = FRECUENCIA_MAX;
  else edoFrec = FRECUENCIA_INT;
}
/** 
 * Esta funcion cambia de decrementar a incrementar la frecuencia 
 * o viceversa. 
 */
void togglePasoFrecuencia() {
  // Cambia de decrementar a incrementar la frecuencia o
  // viceversa.
  paso = -paso;
  edoFrec = FRECUENCIA_INT;
}