#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
Servo escRight, escLeft;

const uint64_t pipes[2] = {
  0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
  
const int escRightPin = 9;
const int escLeftPin = 10;

void setup() {
  // init radio pins
  Serial.begin(57600);
  Serial.println("INIT");
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(0,pipes[0]);
  radio.startListening();
  radio.printDetails();  
  // init esc motor pins
  // escRight.attach(escRightPin); //ESC Pin
  // escRight.write(86);
  // escLeft.attach(escLeftPin); //ESC Pin
  // escLeft.write(86);
}

void loop() {
  /**
   * Example radio read
   */

  char data[12];   
  radio.read(&data, sizeof(data)); 
  Serial.print("Received: "); Serial.println(data);
  
  /*
   * Example esc write
   */
  
   /* 
    delay(1000);
    escRight.write(70);
    escLeft.write(70);
    delay(5000);
    escRight.write(65);
    escLeft.write(65);
    delay(2000);
  */
}
