#define PINO_ZC 2
#define PINO_DIM 6

volatile byte luminosidade = 0; // Brilho entre 0 e 100%

void zeroCross() {
  
  byte brilho = luminosidade > 100 ? 100 : luminosidade; // Garante que o valor esteja entre 0 e 100
  long t1 = 8200L * (100L - brilho) / 100L;              // Calcula tempo de atraso
  delayMicroseconds(t1);                                

  digitalWrite(PINO_DIM, HIGH);                          // Pulso no triac
  delayMicroseconds(6);                                  // Pulso curto
  digitalWrite(PINO_DIM, LOW);

}

void setup() {
  pinMode(PINO_DIM, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PINO_ZC), zeroCross, RISING);
}

void pisca() {
  luminosidade = 100;
  delay(500);
  luminosidade = 0;
  delay(500);
}

void efeitoFade() {
  for (byte i = 20; i < 90; i++) {
    luminosidade = i;
    delay(30);
  }
  for (byte i = 90; i > 20; i--) {
    luminosidade = i;
    delay(30);
  }
}

void loop(){efeitoFade();}