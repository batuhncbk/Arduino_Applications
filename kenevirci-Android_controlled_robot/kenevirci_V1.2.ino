#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial bt_iletisim (5, 6);

Servo servo_agiz;
Servo servosol;
Servo servosag;

int data;
int samg = 8;
int sami = 7;
int smi = 2;
int smg = 4;
int buzzer = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode (smg, OUTPUT);
  pinMode (smi, OUTPUT);
  pinMode (sami, OUTPUT);
  pinMode (samg, OUTPUT);
  pinMode (buzzer, OUTPUT);
  servo_agiz.attach(3);
  servosol.attach(9);
  servosag.attach(10);
  bt_iletisim.begin(9600);

}

void loop()
{
  if (bt_iletisim.available())
  {

    int data = bt_iletisim.read();

    if (data == '4') {
      digitalWrite(smi, 1);
      digitalWrite(smg, 0);
      digitalWrite(sami, 1);
      digitalWrite(samg, 0);
    }
    if (data == '1') {
      digitalWrite(smi, 0);
      digitalWrite(smg, 0);
      digitalWrite(sami, 0);
      digitalWrite(samg, 0);
    }
    if (data == '6') {
      digitalWrite(smi, 0);
      digitalWrite(smg, 1);
      digitalWrite(sami, 0);
      digitalWrite(samg, 1);
    }
    if (data == '0') {
      digitalWrite(smi, 0);
      digitalWrite(smg, 1);
      digitalWrite(sami, 1);
      digitalWrite(samg, 0);
    }
    if (data == '2') {
      digitalWrite(smi, 1);
      digitalWrite(smg, 0);
      digitalWrite(sami, 0);
      digitalWrite(samg, 1);
    }
    if (data == '9') {
      servo_agiz.write(125);
    }
    if (data == '8') {
      servo_agiz.write(65);
    }
    if (data == 'q') {
      servosag.write(0);
      servosol.write(180);
    }
    if (data == 'w') {
      servosag.write(22);
      servosol.write(150);
    }
    if (data == 'e') {
      servosag.write(44);
      servosol.write(125);
    }
    if (data == 'r') {
      servosag.write(66);
      servosol.write(102);
    }
    if (data == 'y') {
      digitalWrite(buzzer,HIGH);
      servo_agiz.write(95);
    }
    if (data == 't') {
      digitalWrite(buzzer,LOW);
      servo_agiz.write(110);
    }
    

  }

}
