/*
* scanRedes.ino
*
* Este programa permite determinar que redes Wifi están
* disponibles y su nivel de intensidad.
*/
#include <WiFi.h>
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
void setup() {
// Inicializa la comunicación serial
Serial.begin(BAUD_RATE);
delay(100);
}
void loop() {
Serial.println("Inicia la busqueda de las redes Wifi");
// Se busca las redes
int n = WiFi.scanNetworks();
Serial.println("Finalizo la busqueda");
// Si no se encontraron redes Wifi
if (n == 0) {
Serial.println("No se encontraron redes");
}
else {
// Si se encontraron redes Wifi
Serial.print("Se encontraron ");
Serial.print(n);
Serial.println(" redes:");
// Para cada red encontrada
for (int i = 0; i < n; ++i) {
// Despliega su SSID
Serial.print(i + 1);
Serial.print(": SSID: ");
Serial.print(WiFi.SSID(i));
// Despliega su RSSI ()
Serial.print(" RSSI: ");
Serial.print(WiFi.RSSI(i));
Serial.print(" Protegida: ");
Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)
? "No": "Si");
delay(10);
}
}
Serial.println("");
// Pausa antes de la siguiente busqueda
delay(5000);
}