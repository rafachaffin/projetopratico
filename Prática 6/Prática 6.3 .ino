#include <IRremote.h> //Carrega a biblioteca IRremote

const byte IR_RECEIVE_PIN = 4; // Utiliza o pino digital quatro para receber o sinal do sensor infravermelho

void setup()
{
   Serial.begin(9600); //Inicia comunicação Serial
   Serial.println("IR receive test");
   IrReceiver.begin(IR_RECEIVE_PIN);// onboard LED blinks with received IR signal
}

void loop()
{
   if (IrReceiver.decode())// Recebe o sinal e decodifica retornando uma string com o valor correspondente no controle
   {
      unsigned long keycode = IrReceiver.decodedIRData.command;
      switch(keycode){
        case 16:
          Serial.println("1");
          break;
        case 17:
          Serial.println("2");
          break;
        case 18:
          Serial.println("3");
          break;
        case 20:
          Serial.println("4");
          break;
        case 21:
          Serial.println("5");
          break;
        case 22:
          Serial.println("6");
          break;
        case 25:
          Serial.println("8");
          break;
        case 12:
          Serial.println("0");
          break;
        case 10:
          Serial.println("^");
          break;
        case 6:
          Serial.println(">");
          break;
        case 8:
          Serial.println("v");
          break;
        case 4:
          Serial.println("<");
          break;
        case 5:
          Serial.println("OK");
          break;
        case 24:
          Serial.println("7");
          break;
        case 26:
          Serial.println("9");
          break;
        default:
          break;
      }
      if ((IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) // ignore repeat code
      {
         IrReceiver.resume();
         return;
      }
      IrReceiver.resume();
   }
}
