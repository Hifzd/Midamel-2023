#include <SPI.h>
#include <LoRa.h>
#include <Arduino.h>

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include  <string>
using namespace std;

#define NSS 4
#define RST 5
#define DI0 2
#define LED 22
#define LED2 21
#define Relayed 12

String LoRaData;

struct Package {
    int kelasA,kelasB,kelasC,kelasD;
};

// Package toPack(string str){
//     Package pack;
//     stringstream ss(str);
//     for (int i = 0; !ss.eof(); i++){
//         getline(ss,str,';');
//         if (i == 0){
//             pack.kelasA = stoi(str);
//         }if (i == 1){
//             pack.kelasB = stoi(str);
//         }if (i == 2){
//             pack.kelasC = stoi(str);
//         }if (i == 3){
//             pack.kelasD = stoi(str);
//         }
//     }
// }

Package toPack(string str){
    Package pack;
    stringstream ss(str);
        getline(ss,str,';');
        pack.kelasA = stoi(str);
        getline(ss,str,';');
        pack.kelasB = stoi(str);
        getline(ss,str,';');
        pack.kelasC = stoi(str);
        getline(ss,str,';');
        pack.kelasD = stoi(str);
    }

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(Relayed, OUTPUT);
  Serial.println("LoRa Receiver");

  LoRa.setPins(NSS, RST, DI0);

  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }

  LoRa.setSyncWord(0xF1);
  Serial.println("LoRa Initializing Successful!");
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    Serial.print("Received packet: ");

    while (LoRa.available()) {
      LoRaData = LoRa.readString();

    }
    Serial.println(LoRaData);

    if (LoRaData == "on_blue") {
      digitalWrite(Relayed, HIGH);
      digitalWrite(LED, HIGH);
      digitalWrite(LED2,HIGH);
    }
    }
    if (LoRaData == "off_blue") {
      digitalWrite(Relayed, LOW);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, LOW);
    }
  }