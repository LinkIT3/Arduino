#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);      //Si deve inserire, nella parentesi, l'indirizzo del display lcd

    void scrivi(String m)                 //Funzione che permette di scrivere
    {                                     //delle stringhe sul display lcd
      int l=m.length();

      for (int i=0; i<l; i++)
      {
        lcd.print(m[i]);
      }
    }
    
  int tempo=0;                            //Durata del giro
  int t;                                  //Tempo di inizio del giro
  int giroI=0;                            //Cifra intera di giri al minuto (giroI = giro intero)
  int giroD=0;                            //Cifra decimale di giri al minuto (giroD = giro decimale)
  int gI=0;                               //Variabile che contiene il valore precedente di giroI
  int gD=0;                               //Variabile che contiene il valore precedente di giroD
  String r1="Regola velocita'";           //Stringa di testo che viene stampata sul display lcd
  String r2=" g/m";                       //"                                                  "
  bool val;                               //Variabile booleana per la verifica della chiusura del contatto

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(10, INPUT);                     //Il pin 10 viene impostato come pin di input
  
  lcd.clear();
  lcd.setCursor(0, 0);
  scrivi(r1);
}

void loop() 
{
  do                                      //Viene verificata la chiusura del contatto all'inizio del giro
  {
    val=digitalRead(10);
  }
  while (val==LOW);

  do                                      //Viene verificata l'apertura del contatto all'inizio del giro
  {
    val=digitalRead(10);
  }
  while (val==HIGH);                    

  t=millis();                             //Viene salvato il tempo attuale
    
  do                                      //Viene verificata la chiusura del contatto alla fine del giro
  {
    val=digitalRead(10);
  }
  while (val==LOW);

  do                                     //Viene verificata l'apertura del contatto alla fine del giro
  {
    val=digitalRead(10);
  }
  while (val==HIGH);
  
  tempo=millis()-t;                      //Viene calcolato il tempo di durata del giro
  
  giroI=60000/tempo;                     //Viene calcolata la parte intera del giro al minuto
  giroD=60000%tempo;                     //Viene calcolata la parte decimale del giro al minuto
  
  
  if (giroI!=gI && giroD!=gD)            //Si verifica che gli attuali valori (sia interi che decimali) del giro aò minuto non siano uguali a quelli precedenti
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
