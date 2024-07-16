// C++ code
//
#define NO_DEFINIDO -1
#define INICIAL 0
#define APAGADO 1
#define ENCENDIDO 2
#define FLASHING 3
#define PAUSA 300 //Flashea cada 100 ms
#define PIN_BOTON 12
#define PIN_LED 4
unsigned int estado_nuevo, estado_actual;
boolean botonPresionado;
unsigned long tiempoAnterior, tiempoActual;
unsigned int led; //Controla el estado del LED
void setup()
{
botonPresionado = false;
estado_actual = INICIAL;
estado_nuevo = NO_DEFINIDO;
pinMode(PIN_LED, OUTPUT);
pinMode(PIN_BOTON, INPUT);
}
void loop()
{
checarEvento();
procesarTransicionEstado();
procesarEstado();

}

void checarEvento()
{
unsigned int entradaBoton = digitalRead(PIN_BOTON);

if (entradaBoton == HIGH)
{
botonPresionado = true; //Triguer
delay(500);
}else
{
botonPresionado = false;
}
}



void procesarTransicionEstado()
{
if( estado_actual == INICIAL )
  {
  estado_nuevo = FLASHING;
  botonPresionado = false;
}else if( estado_actual == APAGADO )
    {
    if( botonPresionado ) //Este es el triger
    {
    estado_nuevo = ENCENDIDO;
    botonPresionado = false;
    }
}else if( estado_actual == ENCENDIDO )
    {
    if( botonPresionado ) //Triguer
    {
    estado_nuevo = FLASHING;
    botonPresionado = false;
    }
}else if( estado_actual == FLASHING )
    {
    if( botonPresionado ) //Triguer
    {
    estado_nuevo = APAGADO;
    botonPresionado = false;
    }

    }
}//end class procesarTransicionEstado

void procesarEstado()
{
  if( estado_actual != estado_nuevo )
  {
    // Ejecuta las poscondiciones para el estado que se abandona
    if (estado_actual == APAGADO )
    poscondicionApagado();
      else if ( estado_actual == ENCENDIDO )
      poscondicionEncendido();
      else if ( estado_actual == FLASHING )
      poscondicionFlashing();
    // Ejecuta las precondiciones para el nuevo estado
  if (estado_nuevo == APAGADO )
      precondicionApagado();
      else if ( estado_nuevo == ENCENDIDO )
      precondicionEncendido();
      else if ( estado_nuevo == FLASHING )
      precondicionFlashing();
      estado_actual = estado_nuevo; // Establece el estado al que se cambió
}
if ( estado_actual == APAGADO )
apagado();
else if ( estado_actual == ENCENDIDO )
encendido();
else if (estado_actual == FLASHING )
flashing();
}
void precondicionApagado()
{
led = LOW; // Se apaga el LED
digitalWrite(PIN_LED, led); //Apaga el LED
}
void apagado()
{

}
void poscondicionApagado()
{
}
void precondicionEncendido()
{
led = HIGH; // Se enciende el LED
digitalWrite(PIN_LED, led ); //Enciende el LED
}
void encendido()
{

}
void poscondicionEncendido()
{
}

void precondicionFlashing()
{
led = HIGH; // Inicia encendido
tiempoAnterior = 0;
digitalWrite(PIN_LED, led);
}
void flashing()
{
tiempoActual = millis(); //Tiempo transcurrido
if( (tiempoActual - tiempoAnterior) > PAUSA )
{
led = ! led;
digitalWrite(PIN_LED, led);
tiempoAnterior = millis();
}
}

void poscondicionFlashing()
{

}