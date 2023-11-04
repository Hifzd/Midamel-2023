#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>

#define NSS 5
#define RST 14
#define DI0 2

#define GRN 21
#define YLL 19
#define RED 18

#define but_1 3
#define but_2 4
#define but_3 6
#define but_4 7
#define but_sub 8 // Button Submit

#define led1_1 45
#define led1_2 48
#define led1_3 47

int count; 

uint8_t button_status = 0;

struct Package {
    int kelasA,kelasB,kelasC,kelasD;
};


String toSTR(Package paket){
    String str;
    str =  String(paket.kelasA) + ";" + String(paket.kelasB) + ";"  + String(paket.kelasC) + ";" + String(paket.kelasD) + ";" ;
    return str;
}

void IRAM_ATTR ISR() {
  Serial.println("Interrupt triggered");
  button_status = !button_status;
}

void setup() {
  Serial.begin(115200);
  pinMode(but_1, INPUT_PULLUP);
  pinMode(but_2, INPUT_PULLUP);
  pinMode(but_3, INPUT_PULLUP);
  pinMode(but_4, INPUT_PULLUP);
  pinMode(butsub, INPUT_PULLUP);
  pinMode(led1_1, OUTPUT);
  pinMode(led1_2, OUTPUT);
  pinMode(led1_3, OUTPUT);
  

  Serial.println("LoRa Sender");
  LoRa.setPins(NSS, RST, DI0);

  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }

  LoRa.setSyncWord(0xF1);
  Serial.println("LoRa Initializing Successful!");
}

bool but1_state = 0;
int state1 = 0;
bool butsub_state = 0;

void loop() {

unsigned long time = millis();
unsigned long last_time = millis();

Package paket;

if ((digitalRead(but_1)==LOW) && (but1_state == 0))
  {
    but1_state = 1;
    state1 ++;
    if (state1 & 3 == 0){
      digitalWrite(led1_1, HIGH);
      digitalWrite(led1_2, LOW);
      digitalWrite(led1_3, LOW);
      }
    else if (state1 & 3 == 1){
      digitalWrite(led1_1, LOW);
      digitalWrite(led1_2, HIGH);
      digitalWrite(led1_3, LOW);
    }
    else if (state1 & 3 == 2){
      digitalWrite(led1_1, LOW);
      digitalWrite(led1_2, LOW);
      digitalWrite(led1_3, HIGH);}
  } else if (digitalRead(but_1) == HIGH)
  {
    but1_state = 0;
  }


if ((digitalRead(but_sub)==LOW) && (butsub_state == 0))
  {
    butsub_state = 1;
    Serial.print("Saving packet: ");
    
    paket.kelasA = state1 % 3;
    paket.kelasB = 0;
    paket.kelasC = 0;
    paket.kelasD = 0;

    

  } else if (digitalRead(but_4) == HIGH)
  {
    butsub_state = 0;
  }
time = millis();
if (time - last_time > 5000){
  last_time = millis();

  Serial.print("Sending packet: ");
  LoRa.beginPacket();
  LoRa.print(toSTR(paket));
  LoRa.endPacket();
  Serial.println("Sent LoRa packet: on");
}
}