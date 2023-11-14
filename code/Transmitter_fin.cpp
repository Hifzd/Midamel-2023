#include <SPI.h>
#include <LoRa.h>

#define but_1 4
int but1_state = 0;
int but1_count = 0;

#define led1_1 15
#define led1_2 16
#define led1_3 17

#define butsub 5
#define led_butsub 6
int butsub_state = 0;
int butsub_on = 0;


void setup(){
    pinMode(but_1, INPUT_PULLUP);
    pinMode(butsub, INPUT_PULLUP);
    pinMode(led1_1, OUTPUT);
    pinMode(led1_2, OUTPUT);
    pinMode(led1_3, OUTPUT);
    pinMode(led_butsub, OUTPUT);
    Serial.begin(115200);
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
     }
     if (but1_count % 4 == 1){
         digitalWrite(led1_1, HIGH);
         digitalWrite(led1_2, LOW);
         digitalWrite(led1_3, LOW);
     } 
     if (but1_count % 4 == 2){
         digitalWrite(led1_1, LOW);
         digitalWrite(led1_2, HIGH);
         digitalWrite(led1_3, LOW);
     } 
     if (but1_count % 4 == 3){
         digitalWrite(led1_1, LOW);
         digitalWrite(led1_2, LOW);
         digitalWrite(led1_3, HIGH);
     } 

    if ((digitalRead(butsub)==LOW) and (butsub_state == 0)){
        but1_count = 0;
        butsub_state = 1;
        butsub_on = 5000;
        Serial.println("but1 mode submitted");
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
 
    Serial.println(butsub_on);
    delay(1);
}