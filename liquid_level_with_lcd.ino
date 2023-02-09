/***************************************************
* Techeonics
* Liquid Level Sensor-XKC-Y25-T12V Sensor
* @author - Gaurav Kumar (Techeonics) 

<thetecheonics@gmail.com>
Youtube- https://www.youtube.com/c/THETECHEONICS
See <http://www.techeonics.com> for details.

* ****************************************************/
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

int Liquid_level=0;

void setup() {
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  
 Serial.begin(9600);
 pinMode(5,INPUT);// sensor pin
 pinMode(2,OUTPUT);// buzzer pin 12 in arduino / 2 in esp
}

void loop() {
 
Liquid_level=digitalRead(5);
Serial.print("Powered By Techeonics ");
Serial.print("Liquid_level= ");
Serial.println(Liquid_level,DEC);

lcd.setCursor(0, 0);
lcd.print("Liquid_level= ");
lcd.print(Liquid_level,DEC);
lcd.setCursor(0, 1);
lcd.print("( TECHEONICS )");

if (Liquid_level == 1){
  digitalWrite(2,HIGH);
}
if (Liquid_level == 0){
  digitalWrite(2,LOW);
}
delay(500);
lcd.clear(); 

}
