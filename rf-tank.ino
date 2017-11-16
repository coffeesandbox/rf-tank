#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <printf.h>

#include <Servo.h>

RF24 radio(7, 8); // CE, CSN
Servo escRight, escLeft;

const uint64_t pipes[2] = {
  0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
  
const int escRightPin = 9;
const int escLeftPin = 10;

typedef struct stateUpdate {
  int controlBit = 0;
  int motorLeft;
  int motorRight;
} StateUpdate;

StateUpdate stateUpdate;

void setup() {
  // Initialize serial communication
  Serial.begin(57600);
  Serial.println("System Initializing");
  printf_begin();

  // Initialize radio module
  radio.begin();
  radio.setRetries(15,15);
  radio.openReadingPipe(0,pipes[0]);
  radio.startListening();
  radio.printDetails();  
  
  // Initialize ESC motors
  escRight.attach(escRightPin); //ESC Pin
  escRight.write(86);
  escLeft.attach(escLeftPin); //ESC Pin
  escLeft.write(86);
}

void loop() {
  if (!radio.available())
    return;
    
  radio.read(&stateUpdate, sizeof(stateUpdate)); 
  printf("State update: Left [%d], Right [%d] \n", stateUpdate.motorLeft, stateUpdate.motorRight);
  
  /*
   * Example esc writes
   */

  escRight.write(stateUpdate.motorRight);
  escLeft.write(stateUpdate.motorLeft);
}
