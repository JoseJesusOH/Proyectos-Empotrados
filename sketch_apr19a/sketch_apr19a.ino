/*
* relevador.ino
*
* Este programa hace que el relevador conectado al pin 23 se
* cierre o se abra, encendiendo o apagando un dispositivo
* electrico conectado al relevador. El relevador es controlado
* por los siguientes comandos recibidos por el puerto serie:
*
* Comando Operacion
* ----------------------------------------------------------
* "on" Enciende dispositivo conectado al relevador.
* "off" Apaga dispositivo conectado al relevador.
* "toggle" Conmuta el estado del dispositivo conectado al
* relevador.
* "state" Obtiene el estado del dispositivo conectado al
* relevador.
*/
#include <string.h>
#include <NoDelay.h>
// Pin a la que esta conectado el PIR, GPIO4
const unsigned int PIN_PIR = 4;
// Pin a la que esta conectado el relevador, GPIO23
const unsigned int PIN_RELEVADOR = 23;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
const long TIEMPO_TAREA = 4000;
// Define los posibles estados del relevador
typedef enum {
  RELEVADOR_ABIERTO,
  RELEVADOR_CERRADO
} estadoRelevador;
// que determina si han transcurrido TIEMPO_TAREA ms
noDelay pausa(TIEMPO_TAREA);
// Variable que guarda el estado del relevador
estadoRelevador edoRelevador;
void abreRelevador();
void cierraRelevador();
void obtenEstadoRelevador();
void setup() {
  // Establece el pin PIN_RELEVADOR (GPIO23) como de salida.
  pinMode(PIN_RELEVADOR, OUTPUT);
  pinMode(PIN_PIR, INPUT);

  // Establece la velocidad de transmisión del puerto
  // serie al valor BAUD_RATE
  Serial.begin(BAUD_RATE);
  // Establece el estado inicial del relevador
  abreRelevador();
  Serial.println("Teclee on para encender el dispositivo, off para apagarlo, toggle para conmutar su estado o state para obtener su estado");
}
void loop() {



  char comando[11];
  // Si hay caracteres disponibles para lectura en el puerto
  // serie
  if (Serial.available() > 0) {
    // Lee a lo mas 10 caracteres del puerto serie o hasta que
    // se presione la tecla Enter y los guarda en el arreglo
    // comando.
    int n = Serial.readBytesUntil('\n', comando, 10);
    // Todas las cadenas en C/C++ terminan en el carácter de
    // fin de cadena, ‘\n’.
    comando[n] = '\0';
    // Escribe el comando al puerto serie
    Serial.print("Comando: ");
    Serial.println(comando);
    // Cierra/abre el relevador
    switch (edoRelevador) {
      case RELEVADOR_CERRADO:
        if (strcmp(comando, "on") == 0)
          abreRelevador();
        else if (strcmp(comando, "state") == 0)
          obtenEstadoRelevador();
        else {
          // Escribe al puerto serie
          Serial.print("Comando no valido: ");
          Serial.println(comando);
        }
        break;

      case RELEVADOR_ABIERTO:
        if (strcmp(comando, "off") == 0)
          cierraRelevador();
        else if (strcmp(comando, "state") == 0)
          obtenEstadoRelevador();
        else {
          // Escribe al puerto serie
          Serial.print("Comando no valido: ");
          Serial.println(comando);
        }
    }
  }else{
    if (pausa.update()) {
      int valorPir = digitalRead(PIN_PIR);
      if (valorPir == HIGH) {
        abreRelevador();
      } else if (valorPir == LOW) {
        cierraRelevador();
      }
    }}
}
/**
* Esta funcion abre el relevador conectado al pin PIN_RELEVADOR
* También actualiza la variable edoRelevador al valor
* RELEVADOR_ABIERTO y escribe un mensaje al puerto serie con el
* estado del dispositivo conectado al relevador
*/
void abreRelevador() {
  // Abre el relevador
  digitalWrite(PIN_RELEVADOR, LOW);
  // Actualiza la variable que guarda el estado del relevador
  edoRelevador = RELEVADOR_ABIERTO;
  // Escribe mensaje al puerto serie
  Serial.println("Dispositivo encendido");
}
/**
* Esta funcion cierra el relevador conectado al pin PIN_RELEVADOR
* También actualiza la variable edoRelevador al valor
* RELEVADOR_CERRADO y escribe un mensaje al puerto serie con el
* estado del dispositivo conectado al relevador
*/
void cierraRelevador() {
  // Enciende el relevador
  digitalWrite(PIN_RELEVADOR, HIGH);
  // Actualiza la variable que guarda el estado del relevador
  edoRelevador = RELEVADOR_CERRADO;
  // Escribe mensaje al puerto serie
  Serial.println("Dispositivo apagado");
}
/**
* Esta función escribe un mensaje al puerto serie con el
* estado del dispositivo conectado al relevador
*/
void obtenEstadoRelevador() {
  switch (edoRelevador) {
    case RELEVADOR_ABIERTO:
      Serial.println("Dispositivo encendido");

      break;
    case RELEVADOR_CERRADO:
      Serial.println("Dispositivo apagado");
  }
}