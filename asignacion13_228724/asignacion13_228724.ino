/*
* asignacion13.ino
*
* Este programa hace recibir comandos de Control para un
* conjunto de 4 LEDs mediante el puerto USB
* se enciendan, apaguen o flasheen controlado por comandos recibidos por
* el puerto serie
*/
#include <string.h>
// Pines a los que estan conectados los LEDs, GPIO4, GPI16,  GPI17,  GPIO5  
const unsigned int PIN_LED0 = 4;
const unsigned int PIN_LED1 = 16;
const unsigned int PIN_LED2 = 17;
const unsigned int PIN_LED3 = 5;
// Velocidad de transmisión del puerto serie
const unsigned int BAUD_RATE = 115200;


void setup() {
  // Establece los pines PIN_LED (GPIO4, GPI16,  GPI17,  GPIO5) como de salida.
pinMode(PIN_LED0, OUTPUT);
pinMode(PIN_LED1, OUTPUT);
pinMode(PIN_LED2, OUTPUT);
pinMode(PIN_LED3, OUTPUT);
  // Establece la velocidad de transmisión del puerto
  // serie al valor BAUD_RATE
  Serial.begin(BAUD_RATE);
  apagaLEDs();

}
void loop() {
  char comando[6];
  
 

    // Si hay caracteres disponibles para lectura en el puerto serie
    if (Serial.available() > 0){
       
       // Lee a lo mas 5 caracteres del puero serie o hasta que se
      // presione la tecla Enter y los guarda en el arreglo
      // comando.
      int n = Serial.readBytesUntil('\n', comando, 5);
      // Todas las cadenas en C/C++ terminan en el carácter de fin
      // de cadena, ‘\n’.
      comando[n] = '\0';
      // Escribe el comando al puerto serie
      Serial.print("Comando: ");
      Serial.println(comando);  

      //strcpy(estado,comando);
      // Si se lee el comando "on"    

    }

    if(!strcmp(comando, "") == 0){

        if (strcmp(comando, "on") == 0){
            // Enciende los LEDs
          prendeLEDs();
          // Escribe al puerto serie
          //Serial.println("LEDs encendidos");
        }
        else
        // Si se lee el comando "off"
        if (strcmp(comando, "off") == 0){
          // Apaga los LEDs
          apagaLEDs();
          // Escribe al puerto serie          
          //Serial.println("LEDs apagado");
        }
        else 
        //Si se lee el comando "ltr"
        if (strcmp(comando, "ltr") == 0){
            // Enciende los LEDs de izquierda a derecha
          barridoLTR();
          // Escribe al puerto serie      
          //Serial.println("Encendido de izquierda a derecha");
        }
        else
        //Si se lee el comando "rtl"
        if (strcmp(comando, "rtl") == 0){
            // Enciende los LEDs de derecha a izquierda
          barridoRTL();
          // Escribe al puerto serie         
          //Serial.println("Barrido de derecha a izquierda");
        }
        else
        //Si lee el comando "flash"
        if (strcmp(comando, "flash") == 0){
            // Flashea a medio segundo los LEDs
          flashearMedioSegundo();
          // Escribe al puerto serie           
         //Serial.println("LEDs Flasheando");
        }
        else{
          // Flashea a un cuarto de segundo los LEDs
           
          flashearCuartoSegundo();
          // Escribe al puerto serie         
          //Serial.println("Comando no existe");        
        }    
  }            
  


}//cierre loop


//Enciende los cuatro LEDs
void prendeLEDs(){
  digitalWrite(PIN_LED0, HIGH);
  digitalWrite(PIN_LED1, HIGH);
  digitalWrite(PIN_LED2, HIGH);
  digitalWrite(PIN_LED3, HIGH);
}

//Apaga los cuatro LEDs
void apagaLEDs(){
  digitalWrite(PIN_LED0, LOW);
  digitalWrite(PIN_LED1, LOW);
  digitalWrite(PIN_LED2, LOW);
  digitalWrite(PIN_LED3, LOW);
}

void barridoLTR(){
  apagaLEDs();
  digitalWrite(PIN_LED0, HIGH);
  delay(500);
  digitalWrite(PIN_LED0, LOW);
  digitalWrite(PIN_LED1, HIGH);
  delay(500);
  digitalWrite(PIN_LED1, LOW);    
  digitalWrite(PIN_LED2, HIGH);
  delay(500);
  digitalWrite(PIN_LED2, LOW);   
  digitalWrite(PIN_LED3, HIGH);
  delay(500); 
  digitalWrite(PIN_LED3, LOW);    
}

void barridoRTL(){
  apagaLEDs();
  digitalWrite(PIN_LED3, HIGH);
  delay(500);
  digitalWrite(PIN_LED3, LOW);   
  digitalWrite(PIN_LED2, HIGH);
  delay(500);  
  digitalWrite(PIN_LED2, LOW);   
  digitalWrite(PIN_LED1, HIGH);
  delay(500);
  digitalWrite(PIN_LED1, LOW);   
  digitalWrite(PIN_LED0, HIGH);
  delay(500); 
  digitalWrite(PIN_LED0, LOW);   
}

void flashearMedioSegundo(){
  prendeLEDs();
  delay(500);
  apagaLEDs();
  delay(500);
}

void flashearCuartoSegundo(){
  prendeLEDs();
  delay(250);
  apagaLEDs();
  delay(250);
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

void barrerLTR() {
  tiempoActual = millis();  //Tiempo transcurrido
  led = HIGH;

  for (int i = 0; i <= 3; i++) {
    if ((tiempoActual - tiempoAnterior) > PAUSA_MEDIO) {
      digitalWrite(leds[i], led);
      tiempoAnterior = millis();
    }
    led = LOW;
    digitalWrite(leds[i], led);
  }
}
      