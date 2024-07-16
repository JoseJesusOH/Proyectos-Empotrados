//Bibliotecas
#include <TFT_eSPI.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <HX711.h>
#include <Bounce2.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSerial.h>
#include <NoDelay.h>

//Sonico
#define ECHO_PIN 17
#define TRIG_PIN 16

//Pantalla
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 15
#define TFT_DC 2

//Sensor PEso
#define DATA_PIN 4
#define CLOCK_PIN 14

//PIN
#define BOTON_VACIAR 27
#define BOTON_FINALIZAR 26
#define BOTON_BAJAR 25
#define BOTON_SUBIR 33
#define BOTON_SIMULADOR 35

// variables volatiles
volatile float units;

//Variables float
float basura_maxima = 5.0;
float basura_actual = 0.0;

//Variables int
int pos = 0;
int estado_motor = 0;
int contadorLLenado = 0;
int contadorObjetos = 0;

//Variables
String comandoAnterior = "";
String vaciado = "";
String cerrado = "";

//Web server
AsyncWebServer server(80);

//Constantes
const int servoPin = 32;
const char* ssid = "IoT_LV323";
const char* password = "@dm1nLV323";

//Botones o actuadores
Bounce boton_vaciar = Bounce();
Bounce boton_finalizar = Bounce();
Bounce boton_bajar = Bounce();
Bounce boton_subir = Bounce();
Bounce boton_simulador = Bounce();
Servo servo;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
HX711 hx711;


//Funciones
void imprimirTexto(String texto);
void establecerPosicion(int x, int y, uint16_t color, int tamano);
void pantalla();
void imprimirDTTMD(String a, String b);
void imprimirTTTMT(String a, String b, String c);
void pintarNegra();
void modoVaciado();
void estadoAbierto();
void cerrando();
float readDistanceCM();
void conectaRedWiFi(const char* ssid, const char* password);
void procesaComando(uint8_t* data, size_t len);

void setup() {
  //Serial
  Serial.begin(115200);

  //Wifi
  conectaRedWiFi(ssid, password);
  WebSerial.begin(&server);
  WebSerial.msgCallback(procesaComando);
  server.begin();


  //Pantalla
  tft.begin();

  //Botones
  pinMode(BOTON_VACIAR, INPUT);
  pinMode(BOTON_FINALIZAR, INPUT);
  pinMode(BOTON_BAJAR, INPUT);
  pinMode(BOTON_SUBIR, INPUT);
  pinMode(BOTON_SIMULADOR, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  boton_vaciar.attach(BOTON_VACIAR);
  boton_vaciar.interval(25);
  boton_finalizar.attach(BOTON_FINALIZAR);
  boton_finalizar.interval(25);
  boton_bajar.attach(BOTON_BAJAR);
  boton_bajar.interval(25);
  boton_subir.attach(BOTON_SUBIR);
  boton_subir.interval(25);
  boton_simulador.attach(BOTON_SIMULADOR);
  boton_simulador.interval(25);

  //Peso
  hx711.begin(DATA_PIN, CLOCK_PIN);
  hx711.set_scale(434.f);

  //Servo
  servo.attach(servoPin, 500, 2400);

  //Obtencion de peso y muestra pantalla
  basura_actual = hx711.get_units();
  units = hx711.get_units();
  pantalla();
}
int simulacion = 1;
void loop() {
  /*

  if (simulacion != 0) {
    if (units != basura_actual) {
      basura_actual = units;
      pantalla();
    } else if (units >= 4.9) {
      modoVaciado();
    }
  }

  */

  boton_subir.update();
  if (boton_subir.fell()) {
    estadoAbierto();
    /*
    //Sacar de la condicional simulacion==0
    //if (simulacion == 0) {
      units = hx711.get_units();
      if (units != basura_actual) {
        basura_actual = units;
        pantalla();
      } else if (units >= 4.9) {
        modoVaciado();
      }
      */
    //}
    //
  }
  boton_vaciar.update();
  if (boton_vaciar.fell()) {
    modoVaciado();
  }
  servo.write(estado_motor);
  /*
  float distance = readDistanceCM();
  if (distance <= 10) {
    contadorLLenado = contadorLLenado + 1;
  }
  if (contadorLLenado == 20) {
    contadorLLenado = 0;
    modoVaciado();
  }
  */
  if (comandoAnterior == "abrir") {
    estadoAbierto();
  }
  if (comandoAnterior == "vaciar") {
    modoVaciado();
  }
}
int estadoVaciado = 0;
void modoVaciado() {
  // se immprime mensaje de que se entro en ese modo de vaciado
  imprimirTTTMT("Entrando en", "Modo de", "Vaciado");
  estadoVaciado = 1;
  while (true) {
    //Seimulacion
    boton_finalizar.update();
    if (boton_finalizar.fell()) {
      units = 0.0;
      if (units == 0.0 || units <= 0.1) {
        basura_actual = units;
        imprimirDTTMD("Vaciado", "Exitoso");
        delay(2000);
        pantalla();
        vaciado = "Vaciado";
        comandoAnterior = "";
        estadoVaciado = 0;
        contadorObjetos = 0;
        break;
      } else {
        imprimirTTTMT("Vaciado", "Erroneo", "........");
        delay(2000);
        imprimirDTTMD("Presione", "De nuevo");
        vaciado = "Erroneo";
      }
    }
    if (comandoAnterior == "fin") {
      units = 0.0;
      if (units == 0.0 || units <= 0.1) {
        basura_actual = units;
        imprimirDTTMD("Vaciado", "Exitoso");
        delay(2000);
        pantalla();
        vaciado = "Vaciado";
        comandoAnterior = "";
        estadoVaciado = 0;
        contadorObjetos = 0;
        break;
      } else {
        imprimirTTTMT("Vaciado", "Erroneo", "........");
        delay(2000);
        imprimirDTTMD("Presione", "De nuevo");
        vaciado = "Erroneo";
      }
    }

    /*  Si estuviera el sensor de peso     
    boton_finalizar.update();
    if (boton_finalizar.fell()) {
      units = hx711.get_units();
      if (units == 0.0 || units <= 0.1) {
        basura_actual = units;
        imprimirDTTMD("Vaciado", "Exitoso");
        delay(2000);
        pantalla();
        vaciado = "Vaciado"; 
        comandoAnterior = "";
           estadoVaciado = 0;
           contadorObjetos=0;
        break;
      } else {
        imprimirTTTMT("Vaciado", "Erroneo", "........");
        delay(2000);
        imprimirDTTMD("Presione", "De nuevo");
        vaciado = "Erroneo"
      }
    }
      */

    servo.write(estado_motor);
  }
}

//Simulacion
int enCicloAbierto = 0;

void estadoAbierto() {
  //Se abre contenedor o se muestra mensaje
  imprimirDTTMD("Contenedor", "Abierto");
  //Se abre el servo
  estado_motor = 90;
  int estado = 0;
  //for (pos = 0; pos <= 90; pos += 1) {
  servo.write(estado_motor);
  delay(1000);
  //}

  //Se verifica si se ingreso algo en ese lapso
  int contadorA = 0;

  while (true) {
    float distance = readDistanceCM();
    if (distance <= 20) {
      contadorObjetos = contadorObjetos + 1;
      estado = 1;
      break;
    }
    contadorA = contadorA + 1;
    if (contadorA == 20) {
      break;
    }
  }

  //}
  // se valida si se ingreso algo
  if (estado != 0) {
    cerrando();
  } else {
    //Simulacion del sensor de peso+para gregar algo
    if (simulacion != 0) {
      float contador = 0.0;
      while (true) {
        boton_bajar.update();
        if (boton_bajar.fell() && contador != 0.0) {
          break;
        }
        boton_simulador.update();
        if (boton_simulador.fell() && contador <= 4.9) {
          contador = contador + 0.1;
        }
      }
      units = contador;
    }
    //Mensaje de ciere contenedor
    imprimirTTTMT("Porfavor", "Cierre", "Contenedor");

    //Simulacion
    enCicloAbierto = 1;
    while (true) {
      //se vaida si se ingreso algo
      float distance = readDistanceCM();
      //y se cierra
      if (distance <= 20) {
        contadorObjetos = contadorObjetos + 1;
        cerrando();
        break;
      }
      //Si no se espera a que se presione el boton de bajar
      boton_bajar.update();
      if (boton_bajar.fell()) {
        cerrando();
        break;
      }
      //si se ingresa el comando de cerrar en el web serial se cierra
      if (comandoAnterior == "cerrar") {
        cerrando();
        break;
      }
      servo.write(estado_motor);
    }
  }
}

//Funcion de cerrar Servo
void cerrando() {
  //se imprime mensaje de cerrar
  imprimirDTTMD("Cerrando", "Contenedor");
  //se cierra servo
  estado_motor = 0;
  servo.write(estado_motor);
  delay(1000);
  //for (pos = 90; pos >= 0; pos -= 1) {
  //  servo.write(pos);
  //  delay(1000);
  //}

  //se imprime pantalla
  pantalla();
  cerrado = "Cerrado";
  comandoAnterior = "";
  int contadorLLeno = 0;
  int contadorRepeticiones = 0;
  while (true) {
    //se vaida si se ingreso algo
    float distance = readDistanceCM();
    //y se cierra
    if (distance <= 10) {
      contadorRepeticiones = contadorRepeticiones + 1;
    }
    contadorLLeno = contadorLLeno + 1;
    if (contadorLLeno == 20) {
      break;
    }
  }
  if (contadorRepeticiones <= 20 && contadorRepeticiones >= 8) {
    modoVaciado();
    comandoAnterior = "vaciar";
  }
}

//Funcion de Sonico
float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}



void conectaRedWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  Serial.print("Conectandose a la red ");
  Serial.print(ssid);
  Serial.println(" ...");
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


void procesaComando(uint8_t* data, size_t len) {
  String comando = "";
  for (int i = 0; i < len; i++) {
    comando += char(data[i]);
  }

  // Verifica que el comando sea válido
  if (comando == "abrir" || comando == "cerrar" || comando == "vaciar" || comando == "fin" || comando == "state") {

    if (comando == "state") {
      pintarNegra();
      WebSerial.println("Basura");
      WebSerial.println("Actual");
      //Si estuvier el sensor
      //units = hx711.get_units();
      WebSerial.println(String(units) + " KG");
    }
    if (comando == "abrir" && comandoAnterior == "") {
      comandoAnterior = comando;
    }
    if (comando == "vaciar" && comandoAnterior == "") {
      comandoAnterior = comando;
    }
    if (comandoAnterior == "vaciar" && comando == "fin" && estadoVaciado == 1) {
      comandoAnterior = "fin";
    } else if (comandoAnterior == "vaciar" && comando == "fin" && estadoVaciado != 1) {
      WebSerial.println("Entrando en modo de vaciado, espere un momento.");
    } else if (comandoAnterior == "vaciar" && comando != "fin" && estadoVaciado != 1) {
      WebSerial.println("Modo de vaciado en ejecucion, se requiere vaciar.");
    }
    if (comandoAnterior == "abrir" && comando == "cerrar" && enCicloAbierto == 1) {
      comandoAnterior = "cerrar";
    } else if (comandoAnterior == "abrir" && comando == "cerrar" && enCicloAbierto != 1) {
      WebSerial.println("Contenedor cerrandose");
    } else if (comandoAnterior == "abrir" && comando != "cerrar" && enCicloAbierto != 1) {
      WebSerial.println("Contenedor abierto, se requiere cerrar");
    }
  } else {
    WebSerial.println("El comando " + comando + " es inválido");
  }
}

void pintarNegra() {
  tft.fillScreen(ILI9341_BLACK);
  delay(2000);
}


void imprimirTTTMT(String a, String b, String c) {
  pintarNegra();
  establecerPosicion(32, 40, ILI9341_RED, 3);
  imprimirTexto(a);
  Serial.println(a);
  WebSerial.println(a);
  establecerPosicion(32, 120, ILI9341_RED, 3);
  imprimirTexto(b);
  Serial.println(b);
  WebSerial.println(b);
  establecerPosicion(32, 200, ILI9341_GREEN, 3);
  imprimirTexto(c);
  Serial.println(c);
  WebSerial.println(c);
}

void imprimirTexto(String texto);
void establecerPosicion(int x, int y, uint16_t color, int tamano);
void pantalla();
void imprimirDTTMD(String a, String b);


void imprimirDTTMD(String a, String b) {
  pintarNegra();
  establecerPosicion(32, 40, ILI9341_RED, 3);
  imprimirTexto(a);
  Serial.println(a);
  WebSerial.println(a);
  establecerPosicion(32, 120, ILI9341_RED, 3);
  imprimirTexto(b);
  Serial.println(b);
  WebSerial.println(b);
}

void pantalla() {
  pintarNegra();
  establecerPosicion(32, 40, ILI9341_RED, 5);
  imprimirTexto("Basura");
  Serial.println("Basura");
  WebSerial.println("Basura");
  establecerPosicion(32, 120, ILI9341_RED, 5);
  imprimirTexto("Actual");
  Serial.println("Actual");
  WebSerial.println("Actual");
  establecerPosicion(32, 200, ILI9341_GREEN, 4);
  imprimirTexto(String(units) + " KG");
  Serial.println(String(units) + " KG");
  WebSerial.println(String(units) + " KG");
}


void establecerPosicion(int x, int y, uint16_t color, int tamano) {
  //Si hubiera pantalla
  //tft.setCursor(x, y);
  //tft.setTextColor(color);
  //tft.setTextSize(tamano);
}

void imprimirTexto(String texto) {
  //Si hubiera pantalla
  //tft.println(texto);
}