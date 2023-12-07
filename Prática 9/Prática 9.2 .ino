#include <IRremote.h>
#include <Servo.h>

#define IR_PIN_RECEIVER 13
#define SERVOX_PIN 9
#define SERVOG_PIN 8
#define SERVOY_PIN 10
#define SERVOZ_PIN 11
const int trigPin = 5; // Pino de trigger do sensor ultrassônico
const int echoPin = 4; // Pino de eco do sensor ultras
const int buttonPin = 2; // Pino do botão de calibragem


int calibrateButtonState = 0;
int calibrado = false;
int minDistancia;
int maxDistancia;


Servo servoX;
Servo servoY;
Servo servoG;
Servo servoZ;

void moveServo(Servo &servo, int angle);
int comandoRecebido(uint8_t comando);

void setup() {
  int distancia = 5;
  servoX.attach(SERVOX_PIN); // inicia o servo
  servoG.attach(SERVOG_PIN); // inicia o servo
  servoY.attach(SERVOY_PIN); // inicia o servo
  servoZ.attach(SERVOZ_PIN); // inicia o servo
  Serial.begin(9600);
   servoX.write(90);
   servoY.write(0);
   servoZ.write(180);
 // Serial.println("Teste de IR no Servo:");
  IrReceiver.begin(IR_PIN_RECEIVER);
}

void loop() {
  int distancia = getDistancia();
  if (IrReceiver.decode()) {
    int comando = comandoRecebido(IrReceiver.decodedIRData.command , distancia);
  }
   // Mede a distância usando o sensor ultrassônico
  
  Serial.print("A distância é:  ");
  Serial.println(distancia);
  delay(30);
  calibrateButtonState = digitalRead(buttonPin);
  if (calibrateButtonState == HIGH && !calibrado) {
    calibrado = true;
    calibrar();
  } else if (calibrateButtonState == LOW) {
    calibrado = false;
  }
  if ( distancia <= 3){
    servoX.write(90);
    servoY.write(0);
    servoZ.write(180);
  }

}
void moveServo(Servo &servo, int angle) {
  int currentPosition = servo.read();
  int targetPosition = constrain(currentPosition + angle, 0, 180);
  servo.write(targetPosition);
  delay(25);//Pequeno atraso para permitir que o servo atinja a posição desejada
}
void veriServo(Servo &servo, int distancia , int inverso) {
  if ( servo.read() <= 3){
    if (inverso > 0){
    servo.write(servo.read() -10);
    }
    else{
      servo.write(servo.read() +10);
  }
 }
 delay(25);//Pequeno atraso para permitir que o servo atinja a posição desejada
}

void calibrar() {
  // Calibração do nível mínimo

  Serial.println("Nivel minimo...");
  delay(5000); 
  minDistancia = getDistancia();
  Serial.print("Menor distancia: ");
  Serial.println(minDistancia);

  // Calibração do nível máx
  Serial.println("Nível máximo...");
  delay(5000); 
  maxDistancia = getDistancia();
  Serial.print("Distância Máxima: ");
  Serial.println(maxDistancia);
}

int getDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int duration = pulseIn(echoPin, HIGH);
  int distancia = duration * 0.034 / 2;

  return distancia;
}


  
int comandoRecebido(uint8_t comando , int distancia){
  Serial.println(comando);
  IrReceiver.resume();
  switch(comando){
      case 68:
      moveServo(servoX,10);
      moveServo(servoY,10);
        IrReceiver.resume(); 
          break;
      case 7:
      moveServo(servoX, -10);
      moveServo(servoY, -10);
        IrReceiver.resume(); 
          break;
      case 64:
      moveServo(servoX,10);
      moveServo(servoZ,10);
        IrReceiver.resume(); 
          break;
      case 21:
      moveServo(servoX, -10);
      moveServo(servoZ, -10);
        IrReceiver.resume(); 
          break;
      case 67:
      moveServo(servoY, -10);
      moveServo(servoZ, -10);
        IrReceiver.resume(); 
          break;
      case 9:
      moveServo(servoY, -10);
      moveServo(servoZ, -10);
        IrReceiver.resume(); 
          break;
      
      case 8:
    
       moveServo(servoX, -10);
       veriServo(servoX, distancia, -10);
        IrReceiver.resume(); 
          break;
          
    case 90:
    
            moveServo(servoX, 10);
            veriServo(servoX, distancia, 10);
        IrReceiver.resume();
        break;
    case 82:
        moveServo(servoY, -10);
        veriServo(servoY, distancia, -10);
        IrReceiver.resume(); 
          break;
    case 24:
        moveServo(servoY, 10);
        veriServo(servoY, distancia, 10);
        IrReceiver.resume(); 
          break;
    case 22:
        moveServo(servoZ, -10);
        veriServo(servoZ, distancia, -10);
     //   if(servoZ.read 
        IrReceiver.resume(); 
          break;
    case 13:
        moveServo(servoZ, 10);
        veriServo(servoZ, distancia, 10);
        IrReceiver.resume(); 
          break;
    case 69:
        moveServo(servoG, -10);
       
        IrReceiver.resume(); 
          break;
    case 71:
            moveServo(servoG, 10);
        IrReceiver.resume(); 
          break;

      
   

    IrReceiver.resume(); // Reinicia o receptor IR para receber o próximo sinal
  }
}

