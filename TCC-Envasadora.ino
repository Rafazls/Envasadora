#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// define números de pinos do driver no arduino
const int stepPin = 3;
const int dirPin = 4;

// Define o pino do relê
const int relay_pin = 9;

// define os pinos dos leds
int vermelho = 13;//Atribui o valor 12 a variável vermelho
int azul = 12;//Atribui o valor 10 a variável azul
int verde = 11;//Atribui o valor 9 a variável verde
const int sensor=10;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup () {
// Saídas do motor de passo
pinMode (stepPin, OUTPUT);
pinMode (dirPin, OUTPUT);

// Botão
pinMode (sensor , INPUT);

//Relé da bomba peristautica
pinMode(relay_pin, OUTPUT);

//Saídas do led RGB
pinMode (vermelho, OUTPUT);
pinMode(azul, OUTPUT);
pinMode(verde, OUTPUT);

 // initialize the LCD
 lcd.begin();

 // Turn on the blacklight and print a message.
 lcd.backlight();

}void loop() {
// permite que o motor se mova em uma direção particular
digitalWrite(dirPin, HIGH);

if(digitalRead(sensor) == LOW)
{
 lcd.clear();
  lcd.print("1- Fase ");
  delay(2000);
  for(int x = 0; x < 800; x++)
  {
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin,LOW);
  delayMicroseconds(2000); 
  digitalWrite(vermelho, HIGH);//Coloca vermelho (pino 11) em nível alto, ligando-o
  digitalWrite(azul, LOW);//Coloca azul (pino 9) em nível baixo novamente
  digitalWrite(verde, HIGH);//Coloca azul (pino 9) em nível baixo novamente
  }
  
lcd.clear();
lcd.print("2- Fase");

  delay(3000); 
  digitalWrite(vermelho,  HIGH);//Coloca vermelho (pino 11) em nível alto, ligando-o
  digitalWrite(azul, LOW);//Coloca azul (pino 9) em nível baixo novamente
  digitalWrite(verde, LOW);//Coloca azul (pino 9) em nível baixo novamente
  digitalWrite(relay_pin, HIGH);
  delay(3000);
  digitalWrite(relay_pin, LOW);
  delay(2000);

lcd.clear();
lcd.print("3- Fase");
 
  for(int x = 0; x < 800; x++)
  {
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin,LOW);
  delayMicroseconds(2000);  
  digitalWrite(vermelho, LOW);//Coloca vermelho (pino 11) em nível alto, ligando-o
  digitalWrite(azul, LOW);//Coloca azul (pino 9) em nível baixo novamente
  digitalWrite(verde, HIGH);//Coloca azul (pino 9) em nível baixo novamente
  }

lcd.clear();
lcd.print("4- Fase");
  delay(3000);
  
  for(int x = 0; x < 800; x++)
  {
  digitalWrite(stepPin,HIGH);
  delayMicroseconds(2000);
  digitalWrite(stepPin,LOW);
  delayMicroseconds(2000);  
  digitalWrite(vermelho, LOW);//Coloca vermelho (pino 11) em nível alto, ligando-o
  digitalWrite(azul, LOW);//Coloca azul (pino 9) em nível baixo novamente
  digitalWrite(verde, HIGH);//Coloca azul (pino 9) em nível baixo novamente
  }

lcd.clear();
lcd.print("FIM!!");
delay(3000);
lcd.clear();
}else
 {
  lcd.clear();
  lcd.print("Aguardando");
  lcd.setCursor(1,1);
  lcd.print("Garrafa");

   digitalWrite(stepPin,LOW);
   digitalWrite(relay_pin, LOW);
   digitalWrite(verde, LOW);
   digitalWrite(vermelho, LOW);//Coloca vermelho (pino 11) em nível baixo novamente, desligando-o
   digitalWrite(azul, HIGH);//Coloca azul (pino 9) em nível alto, ligando-o
  }
}
