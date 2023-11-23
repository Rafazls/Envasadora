//Bibliotecas do LCD I2C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Variáveis do motor principal - nema23
const int pulPin    = 3;
const int dirPin    = 4;
const int enablePin = 5;

//Variável da bomba
const int relay_pin = 9;

int       vermelho  = 13;//Atribui o valor 12 a variável vermelho
int       verde     = 12;//Atribui o valor 10 a variável verde
int       azul      = 11;//Atribui o valor 9 a variável azul

//Variável do sensor
const int sensor    = 10;


void setup () {
  pinMode (pulPin,    OUTPUT);
  pinMode (dirPin,    OUTPUT);
  pinMode (sensor,    INPUT);
  pinMode (relay_pin, OUTPUT);
  pinMode (vermelho,  OUTPUT);
  pinMode (azul,      OUTPUT);
  pinMode (verde,     OUTPUT);

  // Inicialização do LCD
  lcd.begin();
  lcd.backlight();

}

void loop() {
  // permite que o motor se mova em uma direção particular - Direita
  digitalWrite(dirPin, HIGH);

  if (digitalRead(sensor) == LOW)// Caso o sensor identifique, ele executará essa função:
  {
    //Bloco 1
    delay(1000);
    lcd.clear();
    lcd.print("1- Fase ");
    delay(3000);
    RotacaoDaEsteira();
    Serial.println("Travou");
    digitalWrite(enablePin, LOW);

    //Bloco 2
    delay(2000);
    lcd.clear();
    lcd.print("2- Fase");
    delay(3000);
    digitalWrite(relay_pin, HIGH);
    delay(10000);
    digitalWrite(relay_pin, LOW);
    digitalWrite(enablePin, LOW);
    delay(3000);

    
    //Bloco 3
    lcd.clear();
    lcd.print("3- Fase");
    delay(3000);
    RotacaoDaEsteira();
    Serial.println("Travou");
    digitalWrite(enablePin, LOW);


    //Bloco 4
    delay(3000);
    lcd.clear();
    lcd.print("4- Fase");
    delay(1000);
    RotacaoDaEsteira();


    lcd.clear();
    lcd.print("FIM!!");
    delay(3000);
    lcd.clear();


  } else
  {
    lcd.clear();
    lcd.print("Aguardando");
    lcd.setCursor(1, 1);
    lcd.print("Garrafa");

    digitalWrite(pulPin, LOW);
    digitalWrite(relay_pin, LOW);

  }
}


void RotacaoDaEsteira() {
  for (int x = 0; x < 100; x++)
  {
    digitalWrite(pulPin, HIGH);
    delayMicroseconds(3000);
    digitalWrite(pulPin, LOW);
    delayMicroseconds(3000);
  }
}
