/*
* servo.ino
*
* Este programa hace que el microcontrolador ESP32 rote
* el servo conectado al pin GPIO13, a los angulos 0, 45,
* 90, 135, 180 y empiece de nuevo.
*
* Utiliza la biblioteca ServoESP32 para controlar el
* movimiento del servo.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NoDelay.h>
#include <Servo.h>
// Pin a la que esta conectado el servo, GPIO13
const unsigned int PIN_SERVO = 13;
// Angulos en los que se posicionara el servo
const int angulos[] = { 0, 45, 90, 135, 180 };
// Numero de angulos en el arreglo
const int nAngulos = 5;
// Pausa entre cada giro del servo.
const long PAUSA = 500;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido PAUSA ms
noDelay pausa(PAUSA);
// Crea una instancia de la clase Servo, que implementa la
// biblioteca servo.
Servo servo;
void posicionaServo();
void setup() {
  // Establece el pin de control del servo
  servo.attach(PIN_SERVO);
  // Establece la velocidad de transmisión del puerto serie al
  // valor BAUD_RATE
  Serial.begin(BAUD_RATE);
}
void loop() {
  // Verifica si es tiempo de cambiar de angulo en el servo
  if (pausa.update()) {
    posicionaServo();
  }
}
/*
* Cada vez que se invoca a esta funcion, la funcion posiciona al
* servo en un angulo diferente de los angulos del arreglo angulos
[].
* La primera vez que se invoque a la funcion el angulo vale 0
* Despues del angulo 180, empezara de nuevo.
*/
void posicionaServo() {
  static int angulo = 0;
  // Posiciona el servo en el angulo
  servo.write(angulos[angulo]);
  // Lee la posicion en la que esta el servo
  int angLeido = servo.read();
  Serial.print("Angulo: ");
  Serial.println(angLeido);
  // Establece el valor del siguiente angulo
  angulo = angulo == nAngulos - 1 ? 0 : angulo + 1;
}