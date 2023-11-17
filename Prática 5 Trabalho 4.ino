void setup()
{
  pinMode(2 , OUTPUT);
  // Define o pino digital 2 como OUTPUT.
  
}

void loop()
{ 
  int valorPot = analogRead(A0);
  // Lê o pino analógico de entrada A0 e é transformado em uma função inteira.
  
  int tempo = map(valorPot, 0, 1023, 1000, 230);
  // Mapeia para 1000 a 230 em uma função inteira

  digitalWrite(2, HIGH);
  //Coloca o pino digital 2 em nível ALTO.
  
  delay(tempo);
  // Atraso no devido tempo da variável tempo em milisegundos.
  
  digitalWrite(2, LOW);
  //Coloca o pino digital 2 em nível BAIXO.
  
  delay(tempo);
  // Atraso no devido tempo da variável tempo em milisegundos.
}
