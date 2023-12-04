#include <Servo.h>
#include <IRremote.h>

#define PIN_X_SERVO 9  // Pino do servo para o eixo X
#define PIN_Y_SERVO 10 // Pino do servo para o eixo Y
#define PIN_Z_SERVO 11 // Pino do servo para o eixo Z

Servo servoX;
Servo servoY;
Servo servoZ;

int RECV_PIN = 13; // Pino de recepção do sensor infravermelho
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Inicializa o receptor infravermelho
  servoX.attach(PIN_X_SERVO);
  servoY.attach(PIN_Y_SERVO);
  servoZ.attach(PIN_Z_SERVO);
}

void loop() {
  if (irrecv.decode(&results)) {
    // Imprime o valor recebido pelo controle remoto
    Serial.println(results.value, HEX);

    // Mapeia os valores recebidos para movimentos nos eixos
    switch (results.value) {
      case 0xFF629D: // Botão de seta para a esquerda (X-)
        moveServo(servoX, -10);
        break;
      case 0xFFA857: // Botão de seta para a direita (X+)
        moveServo(servoX, 10);
        break;
      case 0xFF22DD: // Botão de seta para cima (Y+)
        moveServo(servoY, 10);
        break;
      case 0xFFC23D: // Botão de seta para baixo (Y-)
        moveServo(servoY, -10);
        break;
      case 0xFF02FD: // Botão *
        moveServo(servoZ, 10);
        break;
      case 0xFF52AD: // Botão #
        moveServo(servoZ, -10);
        break;
      // Adicione outros casos conforme necessário para padrões de combinação de botões
    }

    irrecv.resume(); // Recebe o próximo valor
  }
}

void moveServo(Servo &servo, int angle) {
  int currentPosition = servo.read();
  int targetPosition = constrain(currentPosition + angle, 0, 180);
  servo.write(targetPosition);
  delay(15); // Pequeno atraso para permitir que o servo atinja a posição desejada
}
