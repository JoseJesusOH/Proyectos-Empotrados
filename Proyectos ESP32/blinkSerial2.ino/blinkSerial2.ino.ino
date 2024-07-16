/*
* blinkSerial2.ino
*
* Este programa hace que el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* se encienda o apague controlado por comandos recibidos por
* el puerto serie
*/
#include <string.h>
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED, OUTPUT);
// Establece la velocidad de transmisión del puerto
// serie al valor BAUD_RATE
Serial.begin(BAUD_RATE);
}
void loop() {
char comando[6];
// Si hay caracteres disponibles para lectura en el puerto serie
if (Serial.available() > 0){
// Lee a lo mas 5 caracteres del puero serie o hasta que se
// presione la tecla Enter y los guarda en el arreglo
// comando.
int n = Serial.readBytesUntil('\n', comando, 5);
// Todas las cadenas en C/C++ terminan en el carácter de fin
// de cadena, ‘\n’.
comando[n] = '\0';
// Escribe el comando al puerto serie
Serial.print("Comando: ");
Serial.println(comando);
// Si se lee el comando "on"
if (strcmp(comando, "on") == 0){
  // Enciende el led conectado al pin PIN_LED
digitalWrite(PIN_LED, HIGH);
// Escribe al puerto serie
Serial.println("LED encendido");
}
else
// Si se lee el comando "off"
if (strcmp(comando, "off") == 0){
// Apaga el led conectado al pin PIN_LED
digitalWrite(PIN_LED, LOW);
// Escribe al puerto serie
Serial.println("LED apagado");
}
else {
// Escribe al puerto serie
Serial.print("Comando desconocido: ");
Serial.println(comando);
}
}
}