#include <Stepper.h>

const int trigPin = 9; // Pino de trigger do sensor ultrassônico
const int echoPin = 10; // Pino de eco do sensor ultras
const int buttonPin = 2; // Pino do botão de calibragem
const int stepsPerRevolution = 100; // Número de passos por revolução do motor de passo

Stepper myStepper(stepsPerRevolution, 8, 11, 12, 13);

int calibrateButtonState = 0;
int calibrado = false;
int minDistancia;
int maxDistancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);

  // Inicialização do motor de passo
  myStepper.setSpeed(100);
}

void loop() {
  // Verifica se o botão de calibragem foi pressionado
  calibrateButtonState = digitalRead(buttonPin);
  if (calibrateButtonState == HIGH && !calibrado) {
    calibrado = true;
    calibrar();
  } else if (calibrateButtonState == LOW) {
    calibrado = false;
  }

  // Mede a distância usando o sensor ultrassônico
  int distancia = getDistancia();
  Serial.print("A distância é:  ");
  Serial.println(distancia);
  delay(500);


  // Converte a distância em passos para o motor de passo
  unsigned int steps = map(distancia, minDistancia, maxDistancia, 0, stepsPerRevolution);
  Serial.print("Os passos são de: ");
  Serial.println(steps);
  // Gira o motor de passo
  myStepper.step(steps*5);

  
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
