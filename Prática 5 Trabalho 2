
void setup()
{
  analogReference(EXTERNAL);  
  // Configura a referência para as leituras analógicas se baseando na tensão conectada ao pino AREF.

}

void loop()
{
    int valorPot = analogRead(A5);
  // Lê o pino analógico de entrada A5 e é transformado em uma função inteira.

    int ValorFinal = map(valorPot, 0, 1023, 0, 255);
  // Mapeia para 0 a 255 em uma função inteira.

    analogWrite(3, ValorFinal);
  // Liga o LED com a variação do potenciômetro.

}
