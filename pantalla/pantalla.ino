#include <Adafruit_TFTLCD.h>
#include <pin_magic.h>
#include <registers.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>




// Pines de conexion del LCD
#define LCD_CS 14 // Chip Select
#define LCD_CD 27 // Command/Data LCD_RS
#define LCD_WR 26 // LCD Write
#define LCD_RD 25 // LCD Read
#define LCD_RESET 33 // LCD Reset
 
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); // Instancia del LCD

#define BLACK 0x0000 // Definimos los colores para poder referirnos a ellos con su nombre
#define RED 0xF800 // en lugar de usar el código hexadecimal de cada uno.
#define GREEN 0x07E0
#define WHITE 0xFFFF
#define BLUE 0x001F
#define CYAN 0x07FF
#define YELLOW 0xFFE0
#define MAGENTA 0xF81F
 
void setup(void)
{
 tft.begin(0x9325); // Iniciamos el LCD especificando el controlador de nuestro LC. En este caso el ILI9341.
 // Otros controladores: 0x9325, 0x9328,0x7575, 0x9341, 0x8357.
 
 tft.fillScreen(BLACK); // Colocamos el fondo del LCD en Negro
}
 
void loop(void)
{
 tft.setRotation(0); // Establecemos la posición de la pantalla Vertical u Horizontal
 
 tft.setCursor(40, 10); // Situamos el cursor en la posicion del LCD deseada,
 // (X, Y) siendo X el ancho (240 px max.) e Y el alto (320 px max.) 
 
 tft.setTextSize(5); // Definimos tamaño del texto. (Probado tamaños del 1 al 10)
 
 tft.setTextColor(CYAN); // Definimos el color del texto 
 
 tft.println("Texto"); // Escribimos nuestro texto en el LCD. Realizará un salto de linea
 // automatico si el texto es mayor que el tamaño del LCD
 
 tft.drawLine(20, 65, 200, 70, GREEN); // Dibujamos una linea (Punto inicio X, Punto inicio Y, Punto final X, Punto final Y, Color)
 
 int X = tft.width(); // Almacenamos en la variable entera X el ancho del LCD en pixeles mediante tft.width();
 int Y = tft.height(); // Almacenamos en la variable entera Y el alto del LCD en pixeles mediante tft.height();
 
 tft.setCursor(15, 90); // Situamos el cursor en una nueva posicion del LCD
 
 tft.setTextSize(3); // Definimos tamaño del texto.
 
 tft.setTextColor(RED); // Definimos el color del texto 
 
 tft.print("X="); tft.print(X, DEC); // Imprimimos por pantalla el valor de las variables en decimal
 tft.print(" Y="); tft.println(Y, DEC);
 
 tft.drawRect(20, 125, 200, 25, YELLOW); // Dibujamos un cuadrado/rectangulo sin color de relleno
 // (Punto inicial X, Punto inicial Y, Longitud X,Longitud Y, Color)
 
 tft.fillRect(20, 165, 60, 60, BLUE); // Dibujamos un cuadrado/rectangulo relleno de color
 //(Punto inicial X, Punto inicial Y, Longitud X,Longitud Y, Color)
 
 tft.drawCircle(120, 195, 30, WHITE); // Dibujamos un circulo sin color de relleno
 //(Punto inicial X, Punto inicial Y, Radio del circulo, Color)
 
 tft.fillCircle(120, 195, 20, WHITE); // Dibujamos un circulo relleno de color
 //(Punto inicial X, Punto inicial Y, Radio del circulo, Color) 
 
 tft.drawTriangle // Dibujamos un triangulo sin color de relleno
 (190, 163, // (Vertice superior X, Vertice superior Y,
 160, 225, // Vertice inferior izquierdo X, vertice inferior izquierdo Y,
 222, 225, CYAN); // Vertice inferior derecho X, Vertice inferior derecho Y, Color)
 
 tft.fillTriangle // Dibujamos un triangulo relleno de color
 (190, 240, // (Vertice superior X, Vertice superior Y,
 160, 302, // Vertice inferior izquierdo X, vertice inferior izquierdo Y,
 222, 302, MAGENTA); // Vertice inferior derecho X, Vertice inferior derecho Y, Color)
 
 tft.drawRoundRect(20, 245, 130, 60, 20, RED); // Dibujamos un cuadrado/rectangulo con los bordes redondeados sin color de relleno
 // (Punto inicial X, Punto inicial Y, Longitud X,Longitud Y, Radio de los vertices, Color)
 
 tft.fillRoundRect(35, 255, 100, 40, 15, YELLOW); // Dibujamos un cuadrado/rectangulo con los vertices redondeados relleno de color
 // (Punto inicial X, Punto inicial Y, Longitud X,Longitud Y, Radio de los vertices, Color)
 delay(10000);
}