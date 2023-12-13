//Bibliotecas 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int pulPin    = 3;
const int dirPin    = 4;
const int enablePin = 5;
const int relay_pin = 9;
const int sensorA    = 10;
const int ledblue   = 12;
const int ledred    = 13;

int cont = 0;

void setup () {
  pinMode (pulPin,    OUTPUT);
  pinMode (dirPin,    OUTPUT);
  pinMode (sensorA,    INPUT);
  pinMode (relay_pin, OUTPUT);

  pinMode (ledred,    OUTPUT);
  pinMode (ledblue,   OUTPUT);
  Serial.begin(9600);
  // Inicialização do LCD
  lcd.init();
  lcd.backlight();

}

void loop() {
  // permite que o motor se mova em uma direção particular - Direita
  digitalWrite(dirPin, HIGH);

  if (digitalRead(sensorA) == LOW)// Caso o sensor identifique, ele executará essa função:
  {
    digitalWrite(ledblue, LOW);
    digitalWrite(ledred, HIGH);

    delay(2000);
    Serial.println("A esteira Rodou!");
    RotacaoDaEsteiraPrincipal();
    delay(3000);

    Serial.println("Enchimento da garrafa");
    digitalWrite(relay_pin, HIGH);
    delay(10000);
    digitalWrite(relay_pin, LOW);
    delay(5000);



  } else
  {
  digitalWrite(ledred, LOW);
  digitalWrite(ledblue, HIGH);
 Serial.println("Aguardando garrafa");

  }
}

void RotacaoDaEsteiraPrincipal() {
  for (int x = 0; x < 100; x++)
  {
    digitalWrite(pulPin, HIGH);
    delayMicroseconds(10000);
    digitalWrite(pulPin, LOW);
    delayMicroseconds(10000);
  }
  digitalWrite(enablePin, LOW);
}
