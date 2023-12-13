#define RXp2 16
#define TXp2 17
const int sensorB = 15;
const int pulPin = 2;
const int dirPin = 4;
String ident;
int cont;
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode (sensorB, INPUT);

}
void loop() {
  

    digitalWrite(dirPin, HIGH);

  if (digitalRead(sensorB) == HIGH) {
    for (int x = 0; x < 200; x++) {
      digitalWrite(pulPin, LOW);
      delayMicroseconds(3000);
      digitalWrite(pulPin, HIGH);
      delayMicroseconds(300);
    }

   
    delay(2000);
    Serial.println("Lacrou");
ident = Serial2.readString();

  }
}