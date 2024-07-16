
#include <NoDelay.h>
#define BAUD_RATE 115200

const unsigned int PIN_ZUM = 16;
const long PAUSA = 1000;
const int FRECUENCIA = 2000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;
const unsigned int CICLO_TRABAJO = 127;
const int FREC_MIN = 250;
const int FREC_MAX = 5000;
const int PIN_ROJO = 15;
const int PIN_VERDE = 4;
const int PIN_AZUL = 2;

int notas[50];
int duraciones[50];
int num_notas = 0;

void setup() {
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  ledcAttachPin(PIN_ZUM, CANAL_PWM);
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  pinMode(PIN_AZUL, OUTPUT);
  Serial.begin(BAUD_RATE);
}
void loop() {
  while (Serial.available() <= 0) {
  }

  num_notas = Serial.parseInt();

  for (int i = 0; i < num_notas; i++) {
    duraciones[i] = random(2, 65535);
  }
  for (int i = 0; i < num_notas; i++) {
    int frecuencia = duraciones[i];
    ledcWriteTone(CANAL_PWM, frecuencia/10);
    if (frecuencia >= 1 && frecuencia <= 21845) {
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_VERDE, HIGH);
      digitalWrite(PIN_AZUL, LOW);
    } else if (frecuencia > 21845 && frecuencia <= 43690) {
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_VERDE, LOW);
      digitalWrite(PIN_AZUL, HIGH);
    } else if (frecuencia > 43690 && frecuencia <= 65535) {
      digitalWrite(PIN_ROJO, HIGH);
      digitalWrite(PIN_VERDE, LOW);
      digitalWrite(PIN_AZUL, LOW);
    }
    delay(1000);
  }
  ledcWriteTone(CANAL_PWM, 0);
  digitalWrite(PIN_ROJO, LOW);
  digitalWrite(PIN_VERDE, LOW);
  digitalWrite(PIN_AZUL, LOW);
  Serial.println("FIN-REPRODUCCION");
}

