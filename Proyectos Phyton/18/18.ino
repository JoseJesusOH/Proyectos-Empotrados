/*
* pruebaSPIFFS.ino
*
* Este programa prueba el funcionamiento del almacenamiento SPIFFS
*/
#include "SPIFFS.h"
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
void setup() {
// Establece la velocidad de transmisión del puerto
// serie al valor BAUD_RATE
Serial.begin(BAUD_RATE);
if(!SPIFFS.begin(true)){
Serial.println("Ocurrio un error al montar el SPIFFS");
return;
}
File file = SPIFFS.open("/pruebaSPIFFS.txt");
if(!file){
Serial.println("Error al leer el archivo pruebaSPIFFS.txt");
return;
}
Serial.println("Contenido del archivo pruebaSPIFFS.txt:");
while(file.available()){
Serial.write(file.read());
}

file.close();
}
void loop() {
}