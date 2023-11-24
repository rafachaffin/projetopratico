#include <LiquidCrystal.h> // Carrega a biblioteca do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Define os pinos que serão utilizados para ligação ao display

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); // Define o número de colunas e linhas do LCD
  
}
void loop() {
  
    int valorTemp = GetTemp();
    // int tempC = map(valorTemp,20,358,-40,125);
  
    int tempC = valorTemp/10;
    int tempF = (tempC*9/5) + 32;
  
  lcd.clear(); // Limpa a tela
  
  lcd.setCursor(3, 0); // Posiciona o cursor na coluna 3, linha 0;
  
  lcd.print(tempC); // Envia o texto entre aspas para o LCD
  
  lcd.print(" C");
  lcd.setCursor(3, 1);
  lcd.print(tempF);
  lcd.print(" F");
  delay(1000);

}

double GetTemp(void) {
 unsigned int wADC;
 double t;
 // Configura a referência interna de tensão e o canal 8
 
 ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
 ADCSRA |= _BV(ADEN); // habilita o conversor ADC
 
 delay(20); // espera a tensão se estabilizar.
 
 ADCSRA |= _BV(ADSC); // Inicia a conversão ADC
 

 while (bit_is_set(ADCSRA,ADSC));  // Detecta o final da conversão

 wADC = ADCW;  // Faz a leitura do registrador "ADCW" (ADCL + ADCH).
 
 t = (wADC - 300.00 ) / 1.22; //O valor do offset (324.31) deve ser ajustado manualmente
 
 return (t); // A temperatura retornada está em graus Celsius
}
