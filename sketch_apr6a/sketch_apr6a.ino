// Definimos los pines del LED RGB
#define LED_R 5
#define LED_G 6
#define LED_B 7

// Definimos el pin del zumbador
#define BUZZER 8

// Definimos la velocidad de transmisión de datos por el puerto serial
#define BAUD_RATE 115200

// Variables para almacenar la secuencia de notas y su duración
int notas[50];
int duraciones[50];
int num_notas = 0;

void setup() {
  // Configuramos los pines del LED RGB como salidas
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  // Configuramos el pin del zumbador como salida
  pinMode(BUZZER, OUTPUT);

  // Inicializamos la comunicación serial a la velocidad especificada
  Serial.begin(BAUD_RATE);
}

void loop() {
  // Esperamos a recibir la secuencia de notas desde la PC mediante el puerto serial
  while (Serial.available() <= 0) {
    // No hacemos nada mientras no se reciba nada
  }

  // Leemos el número de notas que se van a reproducir
  num_notas = Serial.parseInt();

  // Leemos la secuencia de notas y sus duraciones
  for (int i = 0; i < num_notas; i++) {
    while (Serial.available() <= 0) {
    }
    notas[i] = Serial.parseInt();
    duraciones[i] = random(2, 65535);
  }
  // Reproducimos la secuencia de notas
  for (int i = 0; i < num_notas; i++) {
    // Encendemos el LED RGB correspondiente al valor de la frecuencia de la nota
    int frecuencia = notas[i];
    if (frecuencia >= 1 && frecuencia <= 21845) {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
    } else if (frecuencia > 21845 && frecuencia <= 43690) {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
    } else if (frecuencia > 43690 && frecuencia <= 65535) {
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
    }
    // Reproducimos la nota en el zumbador por el tiempo especificado en la duración
    tone(BUZZER, frecuencia, duraciones[i]);
    delay(duraciones[i]);  // Esperamos a que termine la duración de la nota
  }

  // Apagamos el LED RGB y el zumbador
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  noTone(BUZZER);

  Serial.println("FIN-REPRODUCCION");
}
