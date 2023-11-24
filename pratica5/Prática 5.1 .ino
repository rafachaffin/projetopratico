void setup()
{
    analogReference(EXTERNAL);
  // Configura a referência para as leituras analógicas se baseando na tensão conectada ao pino AREF.
  
    Serial.begin(9600);
  // Inicia a comunicação do Arduino ao computador em uma taxa de 9600 bits.
  
}

void loop()
{
    int valorPot = analogRead(A5);
  // Registra o valor analógico do potenciômetro conectado no pino A5.
  
    float valorTensao = valorPot * (3.3 / 1023.0);
  // Calcula o valor da tensão através do valor analógico registrado do potênciômetro.
  
    Serial.print("Tensão dinâmica: ");
  // Imprime a mensagem no console.
  
    Serial.println(valorTensao);
  // Imprime o valor da tensão no console.
  
}

