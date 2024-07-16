#define NO_DEFINIDO -1
#define INICIAL 0
#define APAGADO 1
#define ENCENDIDO 2
#define FLASHING 3
#define BARRIENDO_LTR 4
#define BARRIENDO_RTL 5
#define DESCONOCIDO 6
#define PAUSA_MEDIO 500   //Flashea cada 500 ms
#define PAUSA_CUARTO 250  //Flashea cada 250 ms
#define PIN_BOTON 12
#define PIN_LED0 4
#define PIN_LED1 16
#define PIN_LED2 17
#define PIN_LED3 5

// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;

unsigned int estado_nuevo, estado_actual;
boolean cambiarEstado;
unsigned long tiempoAnterior, tiempoActual;
unsigned int led;  //Controla el estado del LED
int leds[] = { 4, 16, 17, 5 };
char comando[6];
int contador = 0;


void setup() {

  // Establece la velocidad de transmisión del puerto
  // serie al valor BAUD_RATE
  Serial.begin(BAUD_RATE);


  cambiarEstado = false;
  estado_actual = INICIAL;
  estado_nuevo = NO_DEFINIDO;

  pinMode(PIN_LED0, OUTPUT);
  pinMode(PIN_LED1, OUTPUT);
  pinMode(PIN_LED2, OUTPUT);
  pinMode(PIN_LED3, OUTPUT);
}
void loop() {
  checarEvento();
  procesarTransicionEstado();
  procesarEstado();
 
}

void checarEvento() {

  // Si hay caracteres disponibles para lectura en el puerto serie
  if (Serial.available() > 0) {

    // Lee a lo mas 5 caracteres del puerto serie o hasta que se
    // presione la tecla Enter y los guarda en el arreglo
    // comando.
    int n = Serial.readBytesUntil('\n', comando, 5);
    // Todas las cadenas en C/C++ terminan en el carácter de fin
    // de cadena, ‘\n’.
    comando[n] = '\0';
    // Escribe el comando al puerto serie
    Serial.print("Comando: ");
    Serial.println(comando);
    cambiarEstado = true;
    delay(500);
  } else {
    cambiarEstado = false;
  }
}

void procesarTransicionEstado() {

  if (estado_actual == INICIAL) {
    estado_nuevo = APAGADO;
    cambiarEstado = false;
  } else if (!strcmp(comando, "") == 0) {
    if (strcmp(comando, "on") == 0) {
      estado_nuevo = ENCENDIDO;

    } else
      // Si se lee el comando "off"
      if (strcmp(comando, "off") == 0) {
        // Apaga los LEDs
        estado_nuevo = APAGADO;
        // Escribe al puerto serie
        //Serial.println("LEDs apagado");
      } else
        //Si se lee el comando "ltr"
        if (strcmp(comando, "ltr") == 0) {
          // Enciende los LEDs de izquierda a derecha
          estado_nuevo = BARRIENDO_LTR;
          // Escribe al puerto serie
          //Serial.println("Encendido de izquierda a derecha");
        } else
          //Si se lee el comando "rtl"
          if (strcmp(comando, "rtl") == 0) {
            // Enciende los LEDs de derecha a izquierda
            estado_nuevo = BARRIENDO_RTL;
            // Escribe al puerto serie
            //Serial.println("Barrido de derecha a izquierda");
          } else
            //Si lee el comando "flash"
            if (strcmp(comando, "flash") == 0) {

              estado_nuevo = FLASHING;
              // Escribe al puerto serie
              //Serial.println("LEDs Flasheando");
            } else {
              estado_nuevo = DESCONOCIDO;
              // Escribe al puerto serie
              //Serial.println("Comando no existe");
            }
    cambiarEstado = false;
  }
}

void procesarEstado() {
  if (estado_actual != estado_nuevo) {
    // Ejecuta las poscondiciones para el estado que se abandona
    if (estado_actual == APAGADO)
      poscondicionApagado();
    else if (estado_actual == ENCENDIDO)
      poscondicionEncendido();
    else if (estado_actual == FLASHING)
      poscondicionFlashing();
    else if (estado_actual == BARRIENDO_LTR)
      poscondicionBarrerLTR();
    else if (estado_actual == BARRIENDO_RTL)
      poscondicionBarrerRTL();
    else if (estado_actual == DESCONOCIDO)
      poscondicionDesconocido();

    // Ejecuta las precondiciones para el nuevo estado
    if (estado_nuevo == APAGADO)
      precondicionApagado();
    else if (estado_nuevo == ENCENDIDO)
      precondicionEncendido();
    else if (estado_nuevo == FLASHING)
      precondicionFlashing();
    else if (estado_nuevo == BARRIENDO_LTR)
      precondicionBarrrerLTR();
    else if (estado_nuevo == BARRIENDO_RTL)
      precondicionBarrrerRTL();
    else if (estado_nuevo == DESCONOCIDO)
      precondicionDesconocido();

    estado_actual = estado_nuevo;  // Establece el estado al que se cambió
  }
  if (estado_actual == APAGADO)
    apagado();
  else if (estado_actual == ENCENDIDO)
    encendido();
  else if (estado_actual == FLASHING)
    flashing();
  else if (estado_actual == BARRIENDO_LTR)
    barrerLTR();
  else if (estado_actual == BARRIENDO_RTL)
    barrerRTL();
  else if (estado_actual == DESCONOCIDO)
    desconocido();
}
void precondicionApagado() {
}
void apagado() {
  led = LOW;  // Se apaga el LED
  for (int i = 0; i <= 3; i++) {
    digitalWrite(leds[i], led);
  }
}
void poscondicionApagado() {
}
void precondicionEncendido() {
}
void encendido() {
  led = HIGH;  // Se enciende el LED
  for (int i = 0; i <= 3; i++) {
    digitalWrite(leds[i], led);
  }
}
void poscondicionEncendido() {
}

void precondicionFlashing() {
  encendido();
  tiempoAnterior = 0;
}
void flashing() {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > PAUSA_MEDIO) {
    led = !led;
    for (int i = 0; i <= 3; i++) {
      digitalWrite(leds[i], led);
    }
    tiempoAnterior = millis();
  }
}

void poscondicionFlashing() {
}

void precondicionDesconocido() {

  tiempoAnterior = 0;
  encendido();
}
void desconocido() {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > PAUSA_CUARTO) {
    led = !led;
    for (int i = 0; i <= 3; i++) {
      digitalWrite(leds[i], led);
    }
    tiempoAnterior = millis();
  }
}

void poscondicionDesconocido() {
}

void precondicionBarrrerLTR() {

  tiempoAnterior = 0;
  apagado();
}

void barrerLTR() {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > PAUSA_MEDIO) {
    apagado();
    if (contador >= 3) {
      contador = 0;
    } else {
      contador++;
    }
    digitalWrite(leds[contador], HIGH);

    tiempoAnterior = millis();
  }
}

void poscondicionBarrerLTR() {
}

void precondicionBarrrerRTL() {

  tiempoAnterior = 0;
  apagado();
}

void barrerRTL() {
  tiempoActual = millis();  //Tiempo transcurrido
  if ((tiempoActual - tiempoAnterior) > PAUSA_MEDIO) {
    apagado();
    if (contador <= 0) {
      contador = 3;
    } else {
      contador--;
    }
    digitalWrite(leds[contador], HIGH);

    tiempoAnterior = millis();
  }
  
}


void poscondicionBarrerRTL() {
}