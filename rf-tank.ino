#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";


Servo escRight, escLeft;

const int escRightPin = 9;
const int escLeftPin = 10;

void setup() {
  // init radio pins
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

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
   
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
  
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
