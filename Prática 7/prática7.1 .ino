#include <IRremote.h>
#include <Servo.h>
#define IR_PIN_RECEIVER 7
#define SERVO_PIN 4

Servo servomotor;

int numeroRecebido(uint8_t clique);
int contador = 0;//número de dígitos recebidos
int numero = 0;//número recebido
unsigned long ultDecod = 0;//tempo do último dígito recebido
int digito1 = 1000;
int digito2 = 1000;
int digito3 = 1000;
int numeroRecebido(uint8_t comando);

void setup() {
  servomotor.attach(SERVO_PIN); // inicia o servo
  Serial.begin(9600);
  Serial.println("Teste de IR no Servo:");
  IrReceiver.begin(IR_PIN_RECEIVER);
}

void loop() {
  if (IrReceiver.decode()) {
    int digito = numeroRecebido(IrReceiver.decodedIRData.command);
    if (digito != -1) {
      if (digito1 == -1) {
        Serial.println("Digite o Primeiro Dígito");
        digito1 = digito;
        
      } else if (digito2 == -1) {
        Serial.println("Digite o Segundo Dígito");
        digito2 = digito;
        
      } else if (digito3 == -1) {
        Serial.println("Digite o Terceiro Dígito");
        digito3 = digito;
        
      }
    }
    IrReceiver.resume();
  }

  if (digito1 != -1 && digito2 != -1 && digito3 != -1) {
    int numero = digito1 * 100 + digito2 * 10 + digito3;
    if (numero > 180) numero = 180;

    servomotor.write(numero);
    Serial.println("Ângulo ajustado para: " + String(numero));

    // Resetando os dígitos
    digito1 = -1;
    digito2 = -1;
    digito3 = -1;

    delay(1000); // Aguarda um pouco para evitar que a mensagem seja exibida muito rapidamente
  }
}
int numeroRecebido(uint8_t comando){
  switch(comando){
      case 0xC:
          return 0;
    case 0x10:
          return 1;
    case 0x11:
          return 2;
    case 0x12:
          return 3;
    case 0x14:
          return 4;
    case 0x15:
          return 5;
    case 0x16:
          return 6;
    case 0x18:
          return 7;
    case 0x19:
          return 8;
    case 0x1A:
          return 9;
    default:
        return -1;
    Serial.print("Valor: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX); // Mostra o valor em hexadecimal

    IrReceiver.resume(); // Reinicia o receptor IR para receber o próximo sinal
  }
}

