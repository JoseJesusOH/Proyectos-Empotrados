/*
* conexionWifi_ESP32.ino
*
* Este programa permite conectar un microcontrolador ESP32 a una
* red Wifi.
*
* Despliega la dirección IP asignada al microcontrolador ESP32 al
* conectarse a la red Wifi
*/
#include <WiFi.h>
// Substituya "SSID" por el nombre del SSID de la red Wifi a
// conectarse
const char* ssid = "IoT_LV323";
// Substituya "contraseña" por la contraseña de la red Wifi a
// conectarse
const char* password = "@dm1nLV323";
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
void conectaRedWifi(const char* ssid, const char* password);
void setup() {
// Inicializa la comunicación serial
Serial.begin(BAUD_RATE);
delay(100);
Serial.println();
// Conecta a una red Wifi
conectaRedWiFi(ssid, password);
}
void loop() {
}
/*
* Conecta el microcontrolador ESP32 a una red WiFi
*/
void conectaRedWiFi(const char* ssid, const char* password) {
// Conexion a la red
WiFi.begin(ssid, password);
Serial.print("Conectandose a la red ");
Serial.print(ssid);
Serial.println(" ...");
// Mientras no se ha conectado a la red WiFi
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.print(".");
}
Serial.println('\n');
Serial.println("Connexion establecida");
// Obten la direccion IP del microcontrolador ESP32
Serial.print("Direccion IP del servidor web: ");
Serial.println(WiFi.localIP());
}