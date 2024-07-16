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
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;
// Define los posibles estados del LED
typedef enum {
  LED_APAGADO,
  LED_ENCENDIDO
} estadoLed;
// Variable que guarda el estado del LED
estadoLed edoLed;
// Crea una instancia de la clase noDelay
// que determina si han transcurrido TIEMPO_TAREA ms
noDelay pausa(TIEMPO_TAREA);
void apagaLED();
void enciendeLED();
void setup() {
  // Establece el pin PIN_LED (GPIO2) como de salida.
  pinMode(PIN_LED, OUTPUT);
  // Establece el pin PIN_PIR (GPIO4) como de entrada.
  pinMode(PIN_PIR, INPUT);
  // Establece la velocidad de transmisión del puerto serie al
  // valor BAUD_RATE
  Serial.begin(BAUD_RATE);
  // Establece el estado inicial del LED
  apagaLED();
  // Inicializa la tarea simulada
  Serial.println("Inicia tarea");
}
void loop() {
  // Verifica si ss termino de ejecutar la tarea
  if (pausa.update()) {
    Serial.println("Termina tarea");
    // Se lee el sensor de movimiento
    int valorPir = digitalRead(PIN_PIR);
    // Prender/apagar el LED
    switch (edoLed) {
      case LED_APAGADO:
        // Si se detecto movimiento
        // enciende el LED
        if (valorPir == HIGH)
          enciendeLED();
        break;
      case LED_ENCENDIDO:
        // Si no se detecto movimiento
        // apaga el LED
        if (valorPir == LOW)
          apagaLED();
    }
    Serial.println("Inicia tarea");
  }
}
/**
* Esta funcion apaga el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2
* También actualiza la variable edoLed al valor LED_APAGADO
*/
void apagaLED() {
  // Apaga el LED
  digitalWrite(PIN_LED, LOW);
  // Actualiza la variable que guarda el estado del LED
  edoLed = LED_APAGADO;
}
/**
* Esta funcion enciende el LED de status del microcontrolador
* ESP32 DEVKIT DOIT de 30 pines o un LED conectado al pin 2
* También actualiza la variable edoLed al valor ENCENDIDO
*/
void enciendeLED() {
  // Enciende el LED
  digitalWrite(PIN_LED, HIGH);
  // Actualiza la variable que guarda el estado del LED
  edoLed = LED_ENCENDIDO;
}