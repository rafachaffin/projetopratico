void setup()
{
  pinMode(2, OUTPUT);
  // Define o pino digital 2 como OUTPUT.
}

void loop()
{
  int valorPot = analogRead(A3);
  // Lê o pino analógico de entrada A5 e é transformado em uma função inteira.
  
  int freq = map(valorPot, 0, 1023, 200, 2500);
  // Mapeia para 200 a 2500 em uma função inteira.

  tone(2, freq);
  // Gera um som da frequência específica no pino digital 2.
  
  delay(100);
  // Atraso de 100 miliseguindos.

}
