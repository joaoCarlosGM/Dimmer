const int pin2 = 2; // define o pino 2 como entrada

unsigned long pulse_count = 0; // contador de pulsos
unsigned long start_time = 0; // tempo inicial da contagem
unsigned long sample_time = 1000; // tempo de amostragem em milissegundos

void setup() {
  Serial.begin(9600); // inicializa a comunicação serial a 9600 baud
  attachInterrupt(digitalPinToInterrupt(pin2), countPulse, RISING); // ativa a interrupção no pino 2
}

void loop() {

  if (millis() - start_time >= sample_time) { // verifica se o tempo de amostragem acabou
          
          float frequency = (float)pulse_count / ((float)sample_time / 1000.0); // calcula a frequência em hertz
    
          Serial.print("Frequencia: ");
          Serial.print(frequency);
          Serial.println("Hz");

          pulse_count = 0; // zera o contador de pulsos

  start_time = millis(); // reinicia o tempo inicial da contagem
  }

}

void countPulse() { 
  
  // função de interrupção chamada quando o pino 2 recebe um pulso
  pulse_count++; // incrementa o contador de pulsos

}
