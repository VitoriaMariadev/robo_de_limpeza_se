#include <AFMotor.h>

AF_DCMotor motobr(1);
AF_DCMotor motobl(4);

AF_DCMotor motofr(2);
AF_DCMotor motofl(3);

void setup() {
  Serial.begin(9600);

  // Rodas Traseiras
  motobr.setSpeed(0);
  motobl.setSpeed(0);

  // Motores da frente
  motofr.setSpeed(0);
  motofl.setSpeed(0);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    // Verifica o comando recebido pelo Monitor Serial
    switch (command) {
      case 'w':
        motobr.setSpeed(225);
        motobl.setSpeed(225);
        motobr.run(BACKWARD);
        motobl.run(BACKWARD);
        Serial.println("Robô andando para a frente");
        break;

      case 's':
        motobr.setSpeed(225);
        motobl.setSpeed(225);
        motobr.run(FORWARD);
        motobl.run(FORWARD);
        Serial.println("Robô andando para trás");
        break;

      case 'a':
        motobr.setSpeed(225);
        motobl.setSpeed(0);
        motobr.run(BACKWARD);
        motobl.run(RELEASE);
        Serial.println("Robô andando para a esquerda");
        break;

      case 'd':
        motobl.setSpeed(225);
        motobr.setSpeed(0);
        motobl.run(BACKWARD);
        motobr.run(RELEASE);
        Serial.println("Robô andando para direita");
        break;

      case '0':
        motobr.setSpeed(0);
        motobl.setSpeed(0);
        motobr.run(RELEASE);
        motobl.run(RELEASE);
        Serial.println("Robô parado");
        break;
        
      default:
        Serial.println("Comando inválido. Use 'w' para frente, 's' para trás, e '0' para parar.");
    }
    
    delay(500); // Adiciona um pequeno atraso para evitar leituras múltiplas do Monitor Serial
  }
}
