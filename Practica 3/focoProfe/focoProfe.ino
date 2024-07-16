const int PIN_LED=2;
const int PAUSA=100;
void setup() {
  // put your setup code here, to run once:
pinMode(PIN_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(PIN_LED,HIGH);
delay(PAUSA);
digitalWrite(PIN_LED,LOW);
delay(PAUSA);
}