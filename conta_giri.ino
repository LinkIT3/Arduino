#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

    void scrivi(String m)
    {
      int l=m.length();

      for (int i=0; i<l; i++)
      {
        lcd.print(m[i]);
      }
    }
    
  int tempo=0, t, giroI=0, giroD=0, gI=0, gD=0;
  String r1="Regola velocita'";
  String r2=" g/m";
  bool val;

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(10, INPUT);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  scrivi(r1);
}

void loop() 
{
  do
  {
    val=digitalRead(10);
  }
  while (val ==LOW);

  do
  {
    val=digitalRead(10);
  }
  while (val==HIGH);

  t=millis();
    
  do
  {
    val=digitalRead(10);
  }
  while (val==LOW);

  do
  {
    val=digitalRead(10);
  }
  while (val==HIGH);
  
  tempo=millis()-t;
  
  giroI=60000/tempo;
  giroD=60000%tempo;
  
  
  if (giroI!=gI && giroD!=gD)
  {
    gI=giroI;
    gD=giroD;
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(gI);
    lcd.print(".");
    lcd.print(gD);
    scrivi (r2);
  } 
}
