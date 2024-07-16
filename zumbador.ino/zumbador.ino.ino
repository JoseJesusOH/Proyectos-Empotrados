/*
* zumbador.ino
*
* Este programa hace que un zumbador conectado al pin 16
* del microcontrolador ESP32 DEVKIT DOIT de 30 pines,
* emita uan secuencia de tonos controlados por un canal PWM.
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
const unsigned int PIN_ZUM = 16;
// Duración en ms de cada tono
const long PAUSA = 1000;
// Parametros de la señal PWM
const int FRECUENCIA = 2000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;
const unsigned int CICLO_TRABAJO = 127;
const int FRECUENCIA_MIN = 250;
const int FRECUENCIA_MAX = 5000;
// Incremento/decremento en la frecuencia
unsigned int paso = -250;
int frecuencia = FRECUENCIA_MIN;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
void setup() {
// Configura los parametros de la señal PWM
ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
// Establece el canal PWM al pin PIN_ZUM (GPIO16).
ledcAttachPin(PIN_ZUM, CANAL_PWM);
// Emite una señal PWM en el pin GPIO16
ledcWrite(CANAL_PWM, CICLO_TRABAJO);
Serial.begin(115200);
}
void loop() {
// Verifica si ha transcuurido el tiempo dado por PAUSA
if (pausa.update()) {
// Cambia la frecuencia del canal PWM
ledcWriteTone(CANAL_PWM, frecuencia);
Serial.print("Frecuencia: ");
Serial.println(frecuencia);
// Si la frecuencia se hace cero o excede el valor maximo
if(frecuencia <= FRECUENCIA_MIN ||
frecuencia >= FRECUENCIA_MAX) paso = -paso;
// Incrementa o decrementa el ciclo de trabajo
frecuencia += paso;
}
}