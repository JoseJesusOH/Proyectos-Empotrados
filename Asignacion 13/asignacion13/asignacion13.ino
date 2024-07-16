
// Este programa controla un conjunto de cuatro LED utilizando comandos recibidos desde un puerto serial.
#include <string.h>
// Define los pines utilizados para cada LED y la tasa de baudios para la comunicación serial
const unsigned int PIN_LED[4] = { 4, 16, 17, 5 };
int auxiliarBarrido = 0;
int ltrRTL = -1;
String mensaje;
char comando[6];
int auxiliar = -1;
const unsigned int BAUD_RATE = 115200;
int comandoActual = 0;
// Configura los pines y inicializa los LED en estado apagado
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(PIN_LED[i], OUTPUT);
  }
  Serial.begin(BAUD_RATE);
  apagaLEDs();
}

//Bucle principal del programa
void loop() {
  if (Serial.available() > 0) {
    int n = Serial.readBytesUntil('\n', comando, 5);
    comando[n] = '\0';
  }

  if ((strcmp(comando, "") != 0) && auxiliar != 0) {
    if (strcmp(comando, "on") == 0) {
      comandoActual = 1;
      Serial.println("LEDs encendidos");
      prendeLEDs();
    } else if (strcmp(comando, "off") == 0) {
      comandoActual = 2;
      Serial.println("LEDs apagados");
      apagaLEDs();
    } else if (strcmp(comando, "ltr") == 0) {
      comandoActual = 3;
      auxiliar = 0;
      Serial.println("LEDs de izquierda a derecha");
      comandoLTR();
    } else if (strcmp(comando, "rtl") == 0) {
      auxiliar = 0 ;
      comandoActual = 4;
      Serial.println("LEDs de derecha a izquierda");
      comandoRTL();
    } else {
      comandoActual = 5;
      Serial.println("El comando no es válido");
       for (int i = 0; i < 4; i++) {
         flashearCuartoSegundo();
       }
    }
    comando[0] = '\0';
  } else if ((strcmp(comando, "") != 0) && auxiliar == 0) {
    if (strcmp(comando, "off") == 0) {
      comandoActual = 1;
      auxiliar = -1;
      Serial.println("Genial has apagado los leds");
    } else {
      Serial.println("Solo Comando Off");
    }
    if (comandoActual == 3) {
      comandoActual = 3;
      comandoLTR();
    } else {
      comandoActual = 4;
      comandoRTL();
    }
    comando[0] = '\0';
  }
}
//ENciende los 4 leds del circuito
void prendeLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(PIN_LED[i], HIGH);
  }
}
//Apaga los 4 leds del circuito
void apagaLEDs() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(PIN_LED[i], LOW);
  }
}
//Leds de izquierda a derecha
void comandoLTR() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(PIN_LED[i], HIGH);
    delay(500);
    digitalWrite(PIN_LED[i], LOW);
  }
}
//Leds de derecha a izquierda
void comandoRTL() {
  for (int i = 4; i >= 0; i--) {
    digitalWrite(PIN_LED[i], HIGH);
    delay(500);
    digitalWrite(PIN_LED[i], LOW);
  }
}


//Flashear leds cuarto de segundo
void flashearCuartoSegundo() {
  prendeLEDs();
  delay(250);
  apagaLEDs();
  delay(250);
}
