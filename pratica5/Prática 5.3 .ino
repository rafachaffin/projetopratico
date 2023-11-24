void setup()
{
  Serial.begin(9600);
  // Inicia a comunicação do Arduino ao computador em uma taxa de 9600 bits.
  
  DDRB |= B110000;
  // Configuração dos pinos de saída.
  
  PORTB |= B010000;
  // Incializa um dos pinos em estado alto.
  
}

void loop()
{
    PORTB = (~PORTB) & B110000;
  // Inverte os estados dos pinos digitais 12 e 13 no registrador PORTB, mantendo os outros bits inalterados.
  
    delay(800); 
  // Atraso de 800 milisegundos entre cada inversão. 
  
}
