/*
* sensorHC_SR04.ino
*
* Este programa usa el sensor ultrasónico HC-SR04 para medir
* la distancia en cm del sensor al objeto.
*
* Escribe los resultados en puerto serie.
*
* Utiliza la biblioteca NewPing, para obtener las lecturas del
* sensor HC-SR04.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NewPing.h>
#include <NoDelay.h>
// Pin a la que esta conectado el pin TRIG del HC-SR04, GPIO5
const unsigned int PIN_TRIGGER = 5;
// Pin a la que esta conectado el pin ECHO del HC-SR04, GPI18
const unsigned int PIN_ECHO = 18;
// Maxima distancia a sensar, en cm
const int DISTANCIA_MAX = 200;
// Periodo en ms entre lecturas de distancia.
// Debe ser al menos 29 ms
const long PERIODO = 500;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PERIODO ms
noDelay pausa(PERIODO);
// Crea una instancia de la clase NewPing
NewPing sonar(PIN_TRIGGER, PIN_ECHO, DISTANCIA_MAX);
// tipoMedicion: 0 - Usando un solo ping
// 1 - Usando la mediana de 5 pings
int tipoMedicion = 0;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
void setup() {
  // Establece la velocidad de transmisión del puerto serie al
  // valor BAUD_RATE
  Serial.begin(BAUD_RATE);
}
void loop() {
  // Verifica si transcurrio el tiempo entre mediciones
  // de la distancia
  if (pausa.update()) {
    if (tipoMedicion == 0) {
      // Mide la distancia en cm usando un solo ping
      distanciaUnPing();
      tipoMedicion = 1;
    } else {
      // Obtiene la mediana de 5 mediciones del tiempo de
      // viaje del sonido entre el sensor y el objeto
      distanciaMediana();
      tipoMedicion = 0;
    }
  }
}
/*
* Esta funcion obtiene la distancia entre el sensor ultrasónico
* HC-SR04 y el objeto en cm, usando un solo ping
*/
void distanciaUnPing() {
  // Mide la distancia en cm usando un solo ping
  int distancia = sonar.ping_cm();
  Serial.println("Distancia medida usando un solo ping");
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
}
/*
* Esta funcion obtiene la distancia entre el sensor ultrasónico
* HC-SR04 y el objeto en cm, usando la mediana de 5 pings
*/
void distanciaMediana() {
  // Obtiene la mediana de 5 mediciones del tiempo de viaje del
  // sonido entre el sensor y el objeto
  int uS = sonar.ping_median();
  // Calcular la distancia a la que se encuentra el objeto
  int distancia = sonar.convert_cm(uS);
Serial.println("Distancia medida usando la mediana de cinco pings");
Serial.print("Distancia: ");
Serial.print(distancia);
Serial.println(" cm");
}