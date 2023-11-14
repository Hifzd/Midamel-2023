#include <SPI.h>
#include <LoRa.h>

#define NSS 4
#define RST 5
#define DI0 2
#define LED 22
#define LED2 21

String LoRaData;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
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
      digitalWrite(LED, HIGH);
    } 
    if (LoRaData == "on_orange"){
      digitalWrite(LED2, HIGH);
    }
    if (LoRaData == "off_blue") {
      digitalWrite(LED, LOW);
    }
    if (LoRaData == "off_orange") {
      digitalWrite(LED2, LOW);
    }
  }
}