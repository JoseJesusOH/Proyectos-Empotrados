#include <Bounce2.h>

#define NO_DEFINIDO -1
#define INICIAL 0
#define PREPARADA 1
#define ENCENDIDA 2
#define DESACTIVADA 3
#define PAUSA_SEGUNDO 1000  //Flashea cada segundo
#define PAUSA_MEDIO 500     //Flashea cada 500 ms
#define PAUSA_CUARTO 250    //Flashea cada 250 ms
#define PIN_BOTON 18
#define PIN_LED1 2
#define PIN_LED2 4
#define PIN_LED3 5

// Crea una instancia de la clase Bounce
Bounce debouncer = Bounce();

// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;

unsigned int estado_nuevo, estado_actual;
boolean cambiarEstado;
unsigned long tiempoAnterior, tiempoActual;
unsigned int led;  //Controla el estado del LED
int leds[] = { 2, 4, 5 };
char comando[11];
int contador = 0;
int aux = 0;


void setup() {

  // Establece la velocidad de transmisión del puerto
  // serie al valor BAUD_RATE
  Serial.begin(BAUD_RATE);
  // Establece el interruptor de boton al que se le
  // eliminara el ruido
  debouncer.attach(PIN_BOTON);
  // Establece el intervalo (en ms) de espera para eliminar
  // el ruido
  debouncer.interval(25);


  cambiarEstado = false;
  estado_actual = INICIAL;
  estado_nuevo = NO_DEFINIDO;

  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
  pinMode(PIN_BOTON, INPUT);
}
void loop() {

  checarEvento();
  procesarTransicionEstado();
  procesarEstado();
}


void checarEvento() {
    // Actualiza el estadoBoton de la instancia del objeto Bounce.
  // Debe hacerse frecuentemente. Una vez en cada iteracion de
  // la funcion loop()
  debouncer.update();
  // Cambia el estado del led solo si el estado del boton cambio
  // de HIGH a LOW
  if (debouncer.fell()) {
    Serial.println("Alarma-ON");
  }  

  // Si hay caracteres disponibles para lectura en el puerto serie
  if (Serial.available() > 0) {


    // Lee a lo mas 10 caracteres del puerto serie o hasta que se
    // presione la tecla Enter y los guarda en el arreglo
    // comando.
    int n = Serial.readBytesUntil('\n', comando, 11);
    // Todas las cadenas en C/C++ terminan en el carácter de fin
    // de cadena, ‘\n’.
    comando[n] = '\0';
    // Escribe el comando al puerto serie
    Serial.println(comando);
    cambiarEstado = true;
    delay(500);
  } else {
    cambiarEstado = false;
  }
}

void procesarTransicionEstado() {

  if (estado_actual == INICIAL) {
    estado_nuevo = PREPARADA;
    cambiarEstado = false;
  } else if (!strcmp(comando, "") == 0) {
    if (strcmp(comando, "Alarma-ON") == 0) {
      estado_nuevo = ENCENDIDA;

    } else

      //Si se lee el comando "Alarma-OFF"
      if (strcmp(comando, "Alarma-OFF") == 0) {
        // Enciende los LEDs de izquierda a derecha
        estado_nuevo = DESACTIVADA;
        // Escribe al puerto serie
        //Serial.println("Encendido de izquierda a derecha");
      }  // else {
         //estado_nuevo = DESCONOCIDO;
         // Escribe al puerto serie
         //Serial.println("Comando no existe");
         //}
    cambiarEstado = false;
  }
}

void procesarEstado() {
  if (estado_actual != estado_nuevo) {
    // Ejecuta las poscondiciones para el estado que se abandona
    if (estado_actual == PREPARADA)
      poscondicionPreparada();
    else if (estado_actual == ENCENDIDA)
      poscondicionEncendida();
    else if (estado_actual == DESACTIVADA)
      poscondicionDesactivada();


    // Ejecuta las precondiciones para el nuevo estado
    if (estado_nuevo == PREPARADA)
      precondicionPreparada();
    else if (estado_nuevo == ENCENDIDA)
      precondicionEncendida();
    else if (estado_nuevo == DESACTIVADA)
      precondicionDesactivada();

    estado_actual = estado_nuevo;  // Establece el estado al que se cambió
  }


  if (estado_actual == PREPARADA)
    preparada();
  else if (estado_actual == ENCENDIDA)
    encendida();
  else if (estado_actual == DESACTIVADA)
    desactivada();
}


void precondicionPreparada() {
  tiempoAnterior = 0;
  apagar();
}
void preparada() {
  barrerLTR(PAUSA_MEDIO);
}
void poscondicionPreparada() {
}


void precondicionEncendida() {
  tiempoAnterior = 0;
  apagar();
}
void encendida() {
  barrerAlarma();
}
void poscondicionEncendida() {
}



void precondicionDesactivada() {

  apagar();
  encender();
  delay(PAUSA_SEGUNDO);
  apagar();
  delay(PAUSA_SEGUNDO);
  tiempoAnterior = 0;
}

void desactivada() {
  barrerLTR(PAUSA_MEDIO);
}

void poscondicionDesactivada() {
}


void apagar() {
  led = LOW;  // Se apaga el LED
  for (int i = 0; i <= 2; i++) {
    digitalWrite(leds[i], led);
  }
}

void encender() {

  led = HIGH;  // Se enciende el LED
  for (int i = 0; i <= 2; i++) {
    digitalWrite(leds[i], led);
  }
}

void flashear(int pausa) {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > pausa) {
    led = !led;
    for (int i = 0; i <= 2; i++) {
      digitalWrite(leds[i], led);
    }
    tiempoAnterior = millis();
  }
}

void barrerLTR(int pausa) {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > pausa) {
    apagar();
    if (contador >= 2) {
      contador = 0;
    } else {
      contador++;
    }
    digitalWrite(leds[contador], HIGH);

    tiempoAnterior = millis();
  }
}

void barrerRTL(int pausa) {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > pausa) {
    apagar();
    if (contador <= 0) {
      contador = 2;
    } else {
      contador--;
    }
    digitalWrite(leds[contador], HIGH);

    tiempoAnterior = millis();
  }
}

void barrerAlarma() {
  tiempoActual = millis();  //Tiempo transcurrido

  if ((tiempoActual - tiempoAnterior) > PAUSA_CUARTO) {
    apagar();
    if (aux <= 2) {
      if (contador >= 3) {
        contador = 0;
      } else {
        contador++;
      }
      aux++;
    } else if (aux >= 3 && aux < 6) {
      if (contador <= 0) {
        contador = 2;
      } else {
        contador--;
      }
      aux++;
    } else {
      aux = 0;
    }

    digitalWrite(leds[contador], HIGH);

    tiempoAnterior = millis();
  }
}