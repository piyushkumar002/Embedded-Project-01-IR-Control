#include <IRremote.h>

int irPin = 7;
int command;
int relayStatus = 1;

// Motor pins
int IN1 = 9;  
int IN2 = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  Serial.begin(9600);
  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()){
    Serial.print("Button code: ");

    // printing ir button code
    Serial.println(IrReceiver.decodedIRData.command);
    command = IrReceiver.decodedIRData.command;
    
    if (command == 25){
      if (relayStatus == 1){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      Serial.println("LED strip ON!!");
      relayStatus = 0;
      }
      else{
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      Serial.println("LED strip OFF!!");
      relayStatus = 1;
      }
    }
    else{
      delay(1000);
    }
    delay(1000);
    IrReceiver.resume();
  }
}


