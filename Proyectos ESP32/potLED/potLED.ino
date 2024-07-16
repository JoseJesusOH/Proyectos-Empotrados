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
long periodoOn;
// Periodo en ms que dura apagado el LED
long periodoOff;
// Define los posibles estados del LED
typedef enum {
  LED_APAGADO,
  LED_ENCENDIDO
} estadoLed;
// Variable que guarda el estado del LED
estadoLed edoLed;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PERIODO ms
noDelay pausa(periodoOff);
void apagaLED();
void enciendeLED();
int obtenPeriodoOn(int muestra);
int obtenPeriodoOff(int muestra);
void setup() {
  // Establece el pin PIN_LED (GPIO16) como de salida.
  pinMode(PIN_LED, OUTPUT);
  // Valor inicial del periodo en ms que dura encendido el LED
  long periodoOn = PERIODO;
  // Valor inicial del periodo en ms que dura apagado el LED
  long periodoOff = PERIODO;
  // Establece el estado inicial del LED
  apagaLED();
}
void loop() {
  // Verifica si es tiempo de prender/apagar el LED
  if (pausa.update()) {
    // Lee y digitaliza el valor del voltaje en el
    // potenciometro
    int muestra = analogRead(PIN_POT);
    // Convierte a valores para los tiempos de encendido y
    // apagado
    periodoOn = obtenPeriodoOn(muestra);
    periodoOff = obtenPeriodoOff(muestra);

    // Prender/apagar el LED
    switch (edoLed) {
      case LED_APAGADO:
        enciendeLED();
        break;
      case LED_ENCENDIDO:
        apagaLED();
    }
  }
}
/** 
 * Esta funcion apaga el LED conectado al pin 16 del 
 * microcontrolador ESP32 DEVKIT DOIT de 30 pines. 
 * También actualiza la variable edoLed al valor LED_APAGADO 
 */
void apagaLED() {
  // Apaga el LED
  digitalWrite(PIN_LED, LOW);
  // Actualiza la variable que guarda el estado del LED
  edoLed = LED_APAGADO;
  // Cambia el valor de la pausa a PERIODO_OFF
  pausa.setdelay(periodoOff);
}
/** 
 * Esta funcion enciende el LED conectado al pin 16 del 
 * microcontrolador ESP32 DEVKIT DOIT de 30 pines. 
 * También actualiza la variable edoLed al valor ENCENDIDO 
 */
void enciendeLED() {
  // Enciende el LED
  digitalWrite(PIN_LED, HIGH);
  // Actualiza la variable que guarda el estado del LED
  edoLed = LED_ENCENDIDO;
  // Cambia el valor de la pausa a PERIODO_ON
  pausa.setdelay(periodoOn);
}
/** 
 * Esta función determina el tiempo en el que estara encendido 
 * el LED en funcion del valor de la resistencia del potenciometro 
 */
int obtenPeriodoOn(int muestra) {
  return muestra < ADC_VALORES / 2 ? map(muestra, 0, ADC_VALORES / 2, 0, PERIODO) : PERIODO;
}
/** 
 * Esta función determina el tiempo en el que estara apagado 
 * el LED en funcion del valor de la resistencia del potenciometro 
 */
int obtenPeriodoOff(int muestra) {
  return muestra > ADC_VALORES / 2 ? map(muestra, ADC_VALORES / 2, ADC_VALORES, PERIODO, 0) : PERIODO;
}