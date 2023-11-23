// define números de pinos do driver no arduino
const int stepPin = 3;
const int dirPin = 4;

void setup () {
// Saídas do motor de passo
pinMode (stepPin, OUTPUT);
pinMode (dirPin, OUTPUT);
Serial.begin(9600);

}void loop() {
// permite que o motor se mova em uma direção particular
digitalWrite(dirPin, HIGH);
Serial.println("Vai começar a rodar");
   for (int x = 0; x < 200; x++)
    {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
    delay(2000);
}
