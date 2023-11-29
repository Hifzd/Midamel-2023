#include <SPI.h>
#include <LoRa.h>

//LORA
#define NSS 5
#define RST 14
#define DI0 10 // changed from 2

//CONTROL BUTTON
#define but_1 8
#define but_2 38
#define but_3 42
#define but_4 20

int but1_state = 0;
int but1_count = 0;
int but2_state = 0;
int but2_count = 0;
int but3_state = 0;
int but3_count = 0;
int but4_state = 0;
int but4_count = 0;


#define led1_1 15
#define led1_2 16
#define led1_3 17
#define led2_1 37
#define led2_2 36
#define led2_3 35
#define led3_1 41
#define led3_2 40
#define led3_3 39
#define led4_1 19
#define led4_2 48
#define led4_3 47

#define butsub 18
#define led_butsub 6
int butsub_state = 0;
int butsub_on = 0;
String pesan1 = "";

void setup(){
    // LORA
    Serial.begin(115200);
    Serial.println("LoRa Sender");
    LoRa.setPins(NSS, RST, DI0);  
    while (!LoRa.begin(433E6)) {
      Serial.println(".");
      delay(500);
    }
    LoRa.setSyncWord(0xF1);
    Serial.println("LoRa Initializing Successful!");

    // CONTROL BUTTON
    pinMode(but_1, INPUT_PULLUP);
    pinMode(but_2, INPUT_PULLUP);
    pinMode(but_3, INPUT_PULLUP);
    pinMode(but_4, INPUT_PULLUP);
    pinMode(butsub, INPUT_PULLUP);
    pinMode(led1_1, OUTPUT);
    pinMode(led1_2, OUTPUT);
    pinMode(led1_3, OUTPUT);
    pinMode(led2_1, OUTPUT);
    pinMode(led2_2, OUTPUT);
    pinMode(led2_3, OUTPUT);
    pinMode(led3_1, OUTPUT);
    pinMode(led3_2, OUTPUT);
    pinMode(led3_3, OUTPUT);
    pinMode(led4_1, OUTPUT);
    pinMode(led4_2, OUTPUT);
    pinMode(led4_3, OUTPUT);
    pinMode(led_butsub, OUTPUT);
}

void loop(){
    if ((digitalRead(but_1)==LOW) and (but1_state == 0)){
        but1_state = 1;
        but1_count ++;
        Serial.println("but1 pressed");
        
    }
    else if ((digitalRead(but_1)==HIGH)){
        but1_state = 0;
    } 
     if (but1_count % 4 == 0){
         digitalWrite(led1_1, LOW);
         digitalWrite(led1_2, LOW);
         digitalWrite(led1_3, LOW);
         pesan1 = "0;0;0;0;";
     }
     if (but1_count % 4 == 1){
         digitalWrite(led1_1, HIGH);
         digitalWrite(led1_2, LOW);
         digitalWrite(led1_3, LOW);
         pesan1 = "1;0;0;0;";
     } 
     if (but1_count % 4 == 2){
         digitalWrite(led1_1, LOW);
         digitalWrite(led1_2, HIGH);
         digitalWrite(led1_3, LOW);
         pesan1 = "2;0;0;0;";
     } 
     if (but1_count % 4 == 3){
         digitalWrite(led1_1, LOW);
         digitalWrite(led1_2, LOW);
         digitalWrite(led1_3, HIGH);
         pesan1 = "3;0;0;0;";
     } 
    // But 2
    if ((digitalRead(but_2)==LOW) and (but2_state == 0)){
        but2_state = 1;
        but2_count ++;
        Serial.println("but2 pressed");
        
    }
    else if ((digitalRead(but_2)==HIGH)){
        but2_state = 0;
    } 
     if (but2_count % 4 == 0){
         digitalWrite(led2_1, LOW);
         digitalWrite(led2_2, LOW);
         digitalWrite(led2_3, LOW);
         pesan1 = "0;0;0;0;";
     }
     if (but2_count % 4 == 1){
         digitalWrite(led2_1, HIGH);
         digitalWrite(led2_2, LOW);
         digitalWrite(led2_3, LOW);
         pesan1 = "1;0;0;0;";
     } 
     if (but2_count % 4 == 2){
         digitalWrite(led2_1, LOW);
         digitalWrite(led2_2, HIGH);
         digitalWrite(led2_3, LOW);
         pesan1 = "2;0;0;0;";
     } 
     if (but2_count % 4 == 3){
         digitalWrite(led2_1, LOW);
         digitalWrite(led2_2, LOW);
         digitalWrite(led2_3, HIGH);
         pesan1 = "3;0;0;0;";
     } 
     // But 3
     if ((digitalRead(but_3)==LOW) and (but3_state == 0)){
        but3_state = 1;
        but3_count ++;
        Serial.println("but3 pressed");
        
    }
    else if ((digitalRead(but_3)==HIGH)){
        but3_state = 0;
    } 
     if (but3_count % 4 == 0){
         digitalWrite(led3_1, LOW);
         digitalWrite(led3_2, LOW);
         digitalWrite(led3_3, LOW);
         pesan1 = "0;0;0;0;";
     }
     if (but3_count % 4 == 1){
         digitalWrite(led3_1, HIGH);
         digitalWrite(led3_2, LOW);
         digitalWrite(led3_3, LOW);
         pesan1 = "1;0;0;0;";
     } 
     if (but3_count % 4 == 2){
         digitalWrite(led3_1, LOW);
         digitalWrite(led3_2, HIGH);
         digitalWrite(led3_3, LOW);
         pesan1 = "2;0;0;0;";
     } 
     if (but3_count % 4 == 3){
         digitalWrite(led3_1, LOW);
         digitalWrite(led3_2, LOW);
         digitalWrite(led3_3, HIGH);
         pesan1 = "3;0;0;0;";
     } 
     // But 4
     if ((digitalRead(but_4)==LOW) and (but4_state == 0)){
        but4_state = 1;
        but4_count ++;
        Serial.println("but4 pressed");
        
    }
    else if ((digitalRead(but_4)==HIGH)){
        but4_state = 0;
    } 
     if (but4_count % 4 == 0){
         digitalWrite(led4_1, LOW);
         digitalWrite(led4_2, LOW);
         digitalWrite(led4_3, LOW);
         pesan1 = "0;0;0;0;";
     }
     if (but4_count % 4 == 1){
         digitalWrite(led4_1, HIGH);
         digitalWrite(led4_2, LOW);
         digitalWrite(led4_3, LOW);
         pesan1 = "1;0;0;0;";
     } 
     if (but4_count % 4 == 2){
         digitalWrite(led4_1, LOW);
         digitalWrite(led4_2, HIGH);
         digitalWrite(led4_3, LOW);
         pesan1 = "2;0;0;0;";
     } 
     if (but4_count % 4 == 3){
         digitalWrite(led4_1, LOW);
         digitalWrite(led4_2, LOW);
         digitalWrite(led4_3, HIGH);
         pesan1 = "3;0;0;0;";
     } 
    if ((digitalRead(butsub)==LOW) and (butsub_state == 0)){
        but1_count = 0;
        butsub_state = 1;
        butsub_on = 5000;
        LoRa.beginPacket();
        LoRa.print(pesan1);
        LoRa.endPacket();
        Serial.print("Sent LoRa packet:");
        Serial.println(pesan1);
    }
    else if ((digitalRead(butsub)==HIGH)){
        butsub_state = 0;
    }
    if (butsub_on != 0){
      digitalWrite(led_butsub, HIGH);
      butsub_on --;
      
      }
    else{
      digitalWrite(led_butsub,LOW);
      }
    if (butsub_on - 1 == 0){
      butsub_on = 0;
      }
 
    //Serial.println(butsub_on);
    delay(1);
}