
/*
El programa que he escrito es un controlador de brillo de 
dos LEDs utilizando señales PWM. Uno de los LEDs (LED-A) se 
enciende con su máximo brillo mientras que el otro (LED-B) está
 completamente apagado al inicio del programa. Hay dos botones, 
 BOTON-A y BOTON-B, que permiten aumentar y disminuir el brillo 
 del LED-A y del LED-B respectivamente. Cada vez que se presiona
  un botón, el ciclo de trabajo de la señal PWM se incrementa o 
  decrementa en 25 unidades, permitiendo un control fino del brillo
   de los LEDs. El programa cumple con una serie de reglas específicas descritas anteriormente.
*/
#include <NoDelay.h>
#include <Bounce2.h>

// Pin a la que esta conectado el LED, GPIO16
const unsigned int PIN_LED = 2;
const unsigned int BOTON_PIN = 4;

const unsigned int PIN_LED2 = 16;
const unsigned int BOTON_PIN2 = 17;
// Parametros de la señal PWM
const int FRECUENCIA = 5000;
const int CANAL_PWM = 0;
const int RESOLUCION = 8;

// Valor minimo del ciclo de trabajo
const unsigned int CT_MIN = 0;
// Valor maximo del ciclo de trabajo. 2**RESOLUCION - 1
const unsigned int CT_MAX = 250;

// Ciclo de trabajo led a de la forma de onda PWM
unsigned int cicloTrabajoA = CT_MAX;
// Ciclo de trabajo led b de la forma de onda PWM
unsigned int cicloTrabajoB = CT_MIN;

int contadorA = 10;  // variable de contador para contar las pulsaciones
int contadorB = 0;

// Incremento en el ciclo de trabajo al presionar el botón
unsigned int incrementoCT = 25;


// Crea instancias de la clase Bounce para los botones
Bounce boton = Bounce();
Bounce boton2 = Bounce();

void setup() {
  // Configura los parametros de la señal PWM
  ledcSetup(CANAL_PWM, FRECUENCIA, RESOLUCION);
  // Establece el canal PWM al pin PIN_LED (GPIO16).
  ledcAttachPin(PIN_LED, CANAL_PWM);

  // Establece el ciclo de trabajo inicial
  ledcWrite(CANAL_PWM, cicloTrabajoA);
  ledcAttachPin(PIN_LED2, CANAL_PWM + 1);
  ledcWrite(CANAL_PWM + 1, cicloTrabajoB);

  // Configura los botones
  pinMode(BOTON_PIN, INPUT_PULLUP);
  boton.attach(BOTON_PIN);
  boton.interval(5);

  pinMode(BOTON_PIN2, INPUT_PULLUP);
  boton2.attach(BOTON_PIN2);
  boton2.interval(5);
}

void loop() {
  // Actualiza los estados de los botones
  boton.update();
  boton2.update();

  // Verifica si ha transcurrido el tiempo dado por PAUSA
  // Cambia la brillantes del LED, cambiando el ciclo
  // de trabajo del canal PWM
  ledcWrite(CANAL_PWM, cicloTrabajoA);
  ledcWrite(CANAL_PWM + 1, cicloTrabajoB);

  // Si el botón A está presionado, aumenta el ciclo de trabajo de B y disminuye el de A
  if (boton.fell()) {
    if (cicloTrabajoA > CT_MIN && cicloTrabajoB < CT_MAX) {
      cicloTrabajoA -= incrementoCT;
      cicloTrabajoB += incrementoCT;
    }
  }

  // Si el botón B está presionado, aumenta el ciclo de trabajo de A y disminuye el de B
  if (boton2.fell()) {
    if (cicloTrabajoB > CT_MIN && cicloTrabajoA < CT_MAX) {
      cicloTrabajoA += incrementoCT;
      cicloTrabajoB -= incrementoCT;
    }
  }
}
