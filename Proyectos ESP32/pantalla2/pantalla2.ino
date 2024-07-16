#include <Adafruit_ILI9341.h>

// Definir los pines correspondientes a la pantalla
#define TFT_CS 14
#define TFT_DC 27

// Declarar un objeto de la clase Adafruit_ILI9341
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  // Inicializar la pantalla
  tft.begin();
}

void loop() {
  // Dibujar un rectángulo de color azul
  tft.fillRect(0, 0, 50, 50, ILI9341_BLUE);

  // Esperar un segundo antes de borrar el rectángulo
  delay(1000);

  // Borrar el rectángulo
  tft.fillRect(0, 0, 50, 50, ILI9341_BLACK);

  // Esperar un segundo antes de volver a dibujar el rectángulo
  delay(1000);
}