int a = 13; // Correspondente ao LED a
int b = 12; // Correspondente ao LED b
int c = 11; // Correspondente ao LED c
int d = 10; // Correspondente ao LED d
int e = 9;  // Correspondente ao LED e
int f = 8;  // Correspondente ao LED f
int g = 7;  // Correspondente ao LED g
int b1Pin = 2; // Correspondente ao botão +
int b2Pin = 3; // Correspondente ao botão -
int leitura1 = 0; // Leitura do botão +
int leitura2 = 0; // Leitura do botão -
int ultleitura1 = 0; // Última leitura do botão +
int ultleitura2 = 0; // Última leitura do botão -
int contador = 0; // Correspondente ao contador

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(a, OUTPUT); // Define a como saída
  pinMode(b, OUTPUT); // Define b como saída
  pinMode(c, OUTPUT); // Define c como saída
  pinMode(d, OUTPUT); // Define d como saída
  pinMode(e, OUTPUT); // Define e como saída
  pinMode(f, OUTPUT); // Define f como saída
  pinMode(g, OUTPUT); // Define g como saída
  pinMode(b1Pin, INPUT); // Define b1Pin como entrada
  pinMode(b2Pin, INPUT); // Define b2Pin como entrada
  Serial.begin(9600); // Inicia a comunicação serial
}

// Funções para escrever os números no display
void zero() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
  delay(100);
}

void um() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void dois() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
  delay(100);
}

void tres() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
  delay(100);
}

void quatro() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void cinco() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void seis() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void sete() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void oito() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void nove() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void loop() {
  leitura1 = digitalRead(b1Pin); // Lê o estado de b1Pin e armazena em leitura1
  leitura2 = digitalRead(b2Pin); // Lê o estado de b2Pin e armazena em leitura2
  
  if (leitura1 != ultleitura1) {
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (leitura1 != leitura2) {
      leitura1 = ultleitura1;
      if (leitura1 == HIGH) {
        contador++;
      }
    }
  }

  ultleitura1 = leitura1; // Atribui a ultleitura1 o conteúdo de leitura1

  if (leitura2 != ultleitura2) {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (leitura2 != ultleitura2) {
      leitura2 = ultleitura2;
      if (leitura2 == HIGH) {
        contador--;
      }
    }
  }

  ultleitura2 = leitura2; // Atribui a ultleitura2 o conteúdo de leitura2

  switch (contador) {
    case 0:
      zero();
      break;
    case 1:
      um();
      break;
    case 2:
      dois();
      break;
    case 3:
      tres();
      break;
    case 4:
      quatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      sete();
      break;
    case 8:
      oito();
      break;
    case 9:
      nove();
      break;
  }

  Serial.println(contador); // Imprime na serial o conteúdo de contador

  if (contador >= 10) {
    contador = 0;
  }

  if (contador <= -1) {
    contador = 9;
  }
}




int a = 13; // Correspondente ao LED a
int b = 12; // Correspondente ao LED b
int c = 11; // Correspondente ao LED c
int d = 10; // Correspondente ao LED d
int e = 9;  // Correspondente ao LED e
int f = 8;  // Correspondente ao LED f
int g = 7;  // Correspondente ao LED g
int b1Pin = 2; // Correspondente ao botão +
int b2Pin = 3; // Correspondente ao botão -
int leitura1 = 0; // Leitura do botão +
int leitura2 = 0; // Leitura do botão -
int ultleitura1 = 0; // Última leitura do botão +
int ultleitura2 = 0; // Última leitura do botão -
int contador = 0; // Correspondente ao contador

void setup() {
  pinMode(a, OUTPUT); // Define a como saída
  pinMode(b, OUTPUT); // Define b como saída
  pinMode(c, OUTPUT); // Define c como saída
  pinMode(d, OUTPUT); // Define d como saída
  pinMode(e, OUTPUT); // Define e como saída
  pinMode(f, OUTPUT); // Define f como saída
  pinMode(g, OUTPUT); // Define g como saída
  pinMode(b1Pin, INPUT); // Define b1Pin como entrada
  pinMode(b2Pin, INPUT); // Define b2Pin como entrada
  Serial.begin(9600); // Inicia a comunicação serial
}

// Funções para escrever os números no display
void zero() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
  delay(100);
}

void um() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void dois() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
  delay(100);
}

void tres() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 1);
  delay(100);
}

void quatro() {
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void cinco() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void seis() {
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void sete() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  delay(100);
}

void oito() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void nove() {
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  delay(100);
}

void loop() {
  leitura1 = digitalRead(b1Pin); // Lê o estado de b1Pin e armazena em leitura1
  leitura2 = digitalRead(b2Pin); // Lê o estado de b2Pin e armazena em leitura2
  
      if (leitura1 == HIGH) {
        contador++;
      }

  

      if (leitura2 == HIGH) {
        Serial.print("click");
        contador--;
      }
    
    
  
  switch (contador) {
    case 0:
      zero();
      break;
    case 1:
      um();
      break;
    case 2:
      dois();
      break;
    case 3:
      tres();
      break;
    case 4:
      quatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      sete();
      break;
    case 8:
      oito();
      break;
    case 9:
      nove();
      break;
  }

  Serial.println(contador); // Imprime na serial o conteúdo de contador

  if (contador >= 10) {
    contador = 0;
  }

  if (contador <= -1) {
    contador = 9;
  }
}
