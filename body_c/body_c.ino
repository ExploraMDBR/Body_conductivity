#include <Adafruit_NeoPixel.h>

int sensore = A2; //pin dell'asta di metallo per misurare la resistenza corporea
int val = 0;

// inserisco i valori relativi alle strip led e ai transistor che accendono il led centrale
int led = 11;
int pin = 9; 
int pin2 = 10;
int num2 = 12;
int num   = 12; 
// inizializzo le variabili per fare l'effetto scorrimento sulle strip led
int salto = 4;
int i;
int f;
// pin e stato del pulsante del cortocircuito
int button = 8;
int pulsante;

//dati relativi alla tipologia di strip led
int pixelFormat = NEO_GRB + NEO_KHZ800;
int pixelFormat2 = NEO_GRB + NEO_KHZ800;
Adafruit_NeoPixel *pixels;
Adafruit_NeoPixel *pixel;


void setup() {
  //specifico gli input e gli output
pinMode(sensore,INPUT);
pinMode(led,OUTPUT);
pinMode(button,INPUT);


pixels = new Adafruit_NeoPixel(num, pin, pixelFormat);
pixels->begin(); 
pixel = new Adafruit_NeoPixel(num2, pin2, pixelFormat2);
pixel->begin(); 

Serial.begin(9600);
}

void loop() {
  int pulsante = digitalRead(button); // stato del pulsante
  int val = analogRead(sensore); //valore di tensione letta sull'asta


  // se il pulsante è premuto accende le strip led e il led centrale
if(pulsante == HIGH){

  
// variabili per fare l'effetto scorrimento 
  int d = f - salto;
  int g = f - 2*salto;
  int h = f - 3*salto;
  int j = f + salto;

  //accendo i led centrali
  digitalWrite(led,HIGH);
  

       //spengo tutti i led delle strip
          pixels->clear();
          pixel->clear();
        
      //accendo i led delle strip in sequenza in base alle variabili i e f

      pixel->setPixelColor(i + 3*salto , pixel->Color(0, 0, 255));         
      pixel->setPixelColor(i + 2*salto , pixel->Color(0, 0, 255));

     if((j > 2) && (j < 9)) {pixels->setPixelColor(j  , pixels->Color(0, 0, 255));}
      pixel->setPixelColor(i + salto , pixel->Color(0, 0, 255));

       if((f > 2) && (f < 9)) {pixels->setPixelColor(f  , pixels->Color(0, 0, 255));}
      pixel->setPixelColor(i , pixel->Color(0, 0, 255));

      if((d > 2) && (d < 9)) {pixels->setPixelColor(d  , pixels->Color(0, 0, 255));}
      pixel->setPixelColor(i - salto, pixel->Color(0, 0, 255));

      if((g > 2) && (g < 9)) {pixels->setPixelColor(g  , pixels->Color(0, 0, 255));}
      pixel->setPixelColor(i - 2*salto , pixel->Color(0, 0, 255));

      if((h > 2) && (h < 9)) {pixels->setPixelColor(h  , pixels->Color(0, 0, 255));}
      pixel->setPixelColor(i - 3*salto , pixel->Color(0, 0, 255));
       
      pixel->setPixelColor(i - 4*salto , pixel->Color(0, 0, 255)); 

        
      pixels->show();  
      pixel->show(); 

      //reset dei valori di f e i per rendere l'effetto ciclico
      if(f ==  13){
        f = 1;
      }
     
      if(i == 13){
        i = 1;
      }

     // aumento le variabili di 1 ad ogni ciclo per creare l'effetto scorrimento 
     i++;
     f++;
    delay(70); 
  
  }

  //se il pulsante non è premuto ma è applicata una tensione all'asta accendo una sola strip led e il led centrale
  else if(val > 400){
    // accendo il led centrale
    digitalWrite(led,HIGH);

          //spengo tutti i led delle strip
          pixels->clear();
          pixel->clear();

          // accendo il led di una delle 2 strip in sequenza secondo la variabile i
      pixels->setPixelColor(i + 3*salto , pixels->Color(0, 0, 255));      
      pixels->setPixelColor(i + 2*salto , pixels->Color(0, 0, 255));
      pixels->setPixelColor(i + salto , pixels->Color(0, 0, 255));
      pixels->setPixelColor(i , pixels->Color(0, 0, 255));
      pixels->setPixelColor(i - salto, pixels->Color(0, 0, 255));
      pixels->setPixelColor(i - 2*salto , pixels->Color(0, 0, 255));
      pixels->setPixelColor(i - 3*salto , pixels->Color(0, 0, 255));
      pixels->setPixelColor(i - 4*salto , pixels->Color(0, 0, 255));   
      pixels->show();  
      pixel->show();

      //reset della variabile i per rendere l'effetto ciclico
      if(i == 17){
        i = 1;
      }

      //aumento i di uno ad ogni ciclo
     i++;
    delay(70); 
  
  }
   

  
  else {
    //spengo tutti i led delle strip e il led centrale
      pixels->clear();
       pixels->show();  
       pixel->clear();
       pixel->show();  
 digitalWrite(led,LOW);
  digitalWrite(led2,LOW);
  }

  //stampo sulla seriale il valore della tensione applicata all' asta
Serial.println(val);
}
