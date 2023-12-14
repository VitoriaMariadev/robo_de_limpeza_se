#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

AF_DCMotor motofr(1);
AF_DCMotor motofl(4);

AF_DCMotor motobr(2);
AF_DCMotor motobl(3);

char command;

void setup()
{
  bluetoothSerial.begin(9600);  //Set the baud rate to your Bluetooth module.
  // Rodas Traseiras
  motobr.setSpeed(0);
  motobl.setSpeed(0);

  // Motores da frente
  motofr.setSpeed(0);
  motofl.setSpeed(0);
}

void loop() {
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    
    switch (command) {
      case 'F':
        motobr.setSpeed(225);
        motobl.setSpeed(225);

        motobr.run(FORWARD);
        motobl.run(BACKWARD);
        Serial.println("Robô andando para a frente");
        break;

      case 'G':
        motobr.setSpeed(225);
        motobl.setSpeed(225);
        motobr.run(BACKWARD);
        motobl.run(FORWARD);
        Serial.println("Robô andando para trás");
        break;

      case 'L':
        motobr.setSpeed(225);
        motobl.setSpeed(0);
        motobr.run(FORWARD);
        motobl.run(RELEASE);
        Serial.println("Robô andando para a esquerda");
        break;

      case 'R':
        motobl.setSpeed(225);
        motobr.setSpeed(0);
        motobl.run(BACKWARD);
        motobr.run(RELEASE);
        Serial.println("Robô andando para direita");
      
        break;

      case 'Y':
        motofr.setSpeed(225);
        motofl.setSpeed(225);
        motofr.run(BACKWARD);
        motofl.run(FORWARD);
        Serial.println("Rodando");
        break;      

      case 'X':
        motobr.setSpeed(0);
        motobl.setSpeed(0);
        motofr.setSpeed(0);
        motofl.setSpeed(0);
        motofr.run(RELEASE);
        motofl.run(RELEASE);
        motobr.run(RELEASE);
        motobl.run(RELEASE);
        Serial.println("Robô parado");
        break;
    }
  }
}
