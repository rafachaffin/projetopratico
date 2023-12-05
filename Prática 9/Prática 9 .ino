#include <IRremote.h>
#include <Servo.h>

#define IR_PIN_RECEIVER 13
#define SERVOX_PIN 9
#define SERVOY_PIN 10
#define SERVOZ_PIN 11

Servo servoX;
Servo servoY;
Servo servoZ;

void moveServo(Servo &servo, int angle);
int comandoRecebido(uint8_t comando);

void setup() {
  servoX.attach(SERVOX_PIN); // inicia o servo
  servoY.attach(SERVOY_PIN); // inicia o servo
  servoZ.attach(SERVOZ_PIN); // inicia o servo
  Serial.begin(9600);
 
  IrReceiver.begin(IR_PIN_RECEIVER);
}

void loop() {
  if (IrReceiver.decode()) {
    int comando = comandoRecebido(IrReceiver.decodedIRData.command);
  }
}
void moveServo(Servo &servo, int angle) {
  int currentPosition = servo.read();
  int targetPosition = constrain(currentPosition + angle, 0, 180);
  servo.write(targetPosition);
  delay(15); // Pequeno atraso para permitir que o servo atinja a posição desejada
}
  
int comandoRecebido(uint8_t comando){
  Serial.println(comando);
  IrReceiver.resume();
  switch(comando){
      case 4:
          	moveServo(servoX, -10);
    		IrReceiver.resume(); 
        	break;
    case 6:
          	moveServo(servoX, 10);
    		IrReceiver.resume();
    		break;
    case 1:
          	moveServo(servoY, -10);
    		IrReceiver.resume(); 
        	break;
    case 9:
          	moveServo(servoY, 10);
    		IrReceiver.resume(); 
        	break;
    case 8:
         	moveServo(servoZ, -10);
    		IrReceiver.resume(); 
        	break;
    case 10:
          	moveServo(servoZ, 10);
    		IrReceiver.resume(); 
        	break;
   

    IrReceiver.resume(); // Reinicia o receptor IR para receber o próximo sinal
  }
}
