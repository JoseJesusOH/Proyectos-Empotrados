#include <Servo.h>

const int servoPin = 32;
Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  // Mueve el servo a 90 grados gradualmente
  for (int pos = 0; pos <= 90; pos += 1) {
    myServo.write(pos);
    delay(15);
  }

  // Espera un segundo antes de devolver el servo a la posición cero
  delay(1000);

  // Devuelve el servo a la posición cero gradualmente
  for (int pos = 90; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }

  // Espera un segundo antes de comenzar el ciclo nuevamente
  delay(1000);
}
