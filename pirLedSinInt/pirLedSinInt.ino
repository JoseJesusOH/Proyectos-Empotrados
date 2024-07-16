/*
* pirLedSinInt.ino
*
* Este programa hace que el led de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2,
* se encienda si el sensor PIR (sensor infrarrojo pasivo)
* detecta movimiento.
*
* Entre checadas del estado del PIR, suponemos que el
* microcontrolador ESP32 realiza una tarea que le lleva
* TIEMPO_TAREA ms. Durante ese tiempo si el PIR detecta un
* movimiento, no es detectado por el microcontrolador ESP32.
*
* No usa la funcion delay(). En lugar de ello utiliza la
* biblioteca NoDelay. Esto permite que otro codigo ejecute al
* mismo tiempo que se encuentra en el periodo de espera.
*/
#include <NoDelay.h>
// Pin a la que esta conectado el PIR, GPIO4
const unsigned int PIN_PIR = 4;
// Pin a la que esta conectado el LED, GPIO2
const unsigned int PIN_LED = 2;
// Duracion en ms de la tarea que ejecuta el Microcontrolador ESP32
const long TIEMPO_TAREA = 4000;
// Estado actual del pin del LED
int estadoLed = LOW;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido TIEMPO_TAREA ms
noDelay enTarea(TIEMPO_TAREA);
void setup() {
// Establece el pin PIN_LED (GPIO2) como de salida.
pinMode(PIN_LED,OUTPUT);
// Establece el pin PIN_PIR (GPIO4) como de entrada.
pinMode(PIN_PIR, INPUT);
// Establece la velocidad de transmisión del puerto serie al
// valor BAUD_RATE
Serial.begin(BAUD_RATE);
digitalWrite(PIN_LED, estadoLed);
Serial.println("Inicia tarea");
}
void loop() {
// Verifica si ss termino de ejecutar la tarea
if (enTarea.update()) {
Serial.println("Termina tarea");
// Se lee el sensor de movimiento
int valorPir = digitalRead(PIN_PIR);
// Si se detecto movimiento
if (valorPir == HIGH)
// Cambia el estado del led a HIGH
estadoLed = HIGH;
else
// Cambia el estado del led a LOW
estadoLed = LOW;
digitalWrite(PIN_LED, estadoLed);
}
Serial.println("Inicia tarea");
}

