#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>
using namespace std;

#define NSS 5
#define RST 14
#define DI0 2

#define BUTTON 4
#define GRN 21
#define YLL 19
#define RED 18

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
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(GRN, OUTPUT);
  pinMode(YLL, OUTPUT);
  pinMode(RED, OUTPUT);





//   attachInterrupt(BUTTON, ISR, FALLING);

//   Serial.println("LoRa Sender");
//   LoRa.setPins(NSS, RST, DI0);

//   while (!LoRa.begin(433E6)) {
//     Serial.println(".");
//     delay(500);
//   }

//   LoRa.setSyncWord(0xF1);
//   Serial.println("LoRa Initializing Successful!");
}

bool pencet = 1;
void loop() {
  // Serial.print("Sending packet: ");
  
  Package paket;
  paket.kelasA = 0;
  paket.kelasB = 1;
  paket.kelasC = 2;
  paket.kelasD = 3;
//   count = 0;
//     if (count == 0) {
//       LoRa.beginPacket();
//       LoRa.print(toSTR(paket));
//       LoRa.endPacket();
//       Serial.println("Sent LoRa packet: on");

  if ((digitalRead(BUTTON)==LOW)&&(pencet)){
     Serial.println(toSTR(paket));     
     pencet = 0;
  }
  if(digitalRead(BUTTON) == HIGH) {
    pencet = 1;
  }
}
//     }
    
//     delay(100);
    
    // if (count == 0) {
    //   LoRa.beginPacket();
    //   LoRa.print("off_blue");
    //   LoRa.endPacket();
    //   Serial.println("Sent LoRa packet: off");
    // }
    // delay(10000);

//  if (button_status == 1) {
//    LoRa.beginPacket();
//    LoRa.print("on");
//    LoRa.endPacket();
//    Serial.println("Sent LoRa packet: on");
//  }
//
//  if (button_status == 0) {
//    LoRa.beginPacket();
//    LoRa.print("off");
//    LoRa.endPacket();
//    Serial.println("Sent LoRa packet: off");
//  }