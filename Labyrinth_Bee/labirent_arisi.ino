#define sol_motor_hiz 3 // Sol motor hız pini
#define sag_motor_hiz 5// Sağ motor hız pini
#define sol_motor_1 10  // Sol motor pin 1
#define sol_motor_2 11// Sol motor pin 2
#define sag_motor_1 6 //Sağ motor pin 1
#define sag_motor_2 9 // Sağ motor pin 2

int sag_sensor_echo = 4;// sağ sensör
int sag_sensor_trigger = 2;// sağ sensör
int sol_sensor_echo = 13;// sol sensör
int sol_sensor_trigger = 12;// sol sensör
int on_sensor_echo = 8; // Ön sensör
int on_sensor_trigger = 7; // Ön sensör

void setup()
{
  pinMode(on_sensor_trigger, OUTPUT);
  pinMode(on_sensor_echo, INPUT);
  pinMode(sol_sensor_trigger, OUTPUT);
  pinMode(sol_sensor_echo, INPUT);
  pinMode(sag_sensor_trigger, OUTPUT);
  pinMode(sag_sensor_echo, INPUT);
  pinMode(sol_motor_hiz, OUTPUT);
  pinMode(sag_motor_hiz, OUTPUT);
  pinMode(sol_motor_1, OUTPUT);
  pinMode(sol_motor_2, OUTPUT);
  pinMode(sag_motor_1, OUTPUT);
  pinMode(sag_motor_2, OUTPUT);
  delay(1000);
}

void loop()
{
  long on_sensor_zaman, sol_sensor_zaman, sag_sensor_zaman, sag_mesafe, sol_mesafe, on_mesafe;
  digitalWrite(on_sensor_trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(on_sensor_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(on_sensor_trigger, LOW);
  on_sensor_zaman = pulseIn(on_sensor_echo, HIGH);
  on_mesafe = on_sensor_zaman / 29 / 2;

  digitalWrite(sol_sensor_trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(sol_sensor_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sol_sensor_trigger, LOW);
  sol_sensor_zaman = pulseIn(sol_sensor_echo, HIGH);
  sol_mesafe = sol_sensor_zaman / 29 / 2;

  digitalWrite(sag_sensor_trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(sag_sensor_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sag_sensor_trigger, LOW);
  sag_sensor_zaman = pulseIn(sag_sensor_echo, HIGH);
  sag_mesafe = sag_sensor_zaman / 29 / 2;

  analogWrite(sol_motor_hiz, 100);
  analogWrite(sag_motor_hiz, 130);
  analogWrite(sol_motor_1, 0);
  analogWrite(sol_motor_2, 0);
  analogWrite(sag_motor_1, 0);
  analogWrite(sag_motor_2, 0);

   ileri();
   delay(4000);
   sag();
   delay(4000);
  //  if (on_mesafe > 10) //önü açıksa
  //  {
  //    if (sag_mesafe > 8 && sag_mesafe < 13) //sağ mesafe uygun aralıktaysa
  //    {
  //      analogWrite(sol_motor_hiz, 100);
  //      analogWrite(sag_motor_hiz, 130);
  //      analogWrite(sol_motor_1, 255);
  //      analogWrite(sol_motor_2, 0);
  //      analogWrite(sag_motor_1, 255);
  //      analogWrite(sag_motor_2, 0);
  //
  //    }
  //    if (sag_mesafe >= 13 && sag_mesafe < 20) //sağ açıksa
  //    {
  //      analogWrite(sol_motor_hiz, 120);
  //      analogWrite(sag_motor_hiz, 90);
  //      analogWrite(sol_motor_1, 255);
  //      analogWrite(sol_motor_2, 0);
  //      analogWrite(sag_motor_1, 255);
  //      analogWrite(sag_motor_2, 0);
  //    }
  //    if (sag_mesafe <= 8) //sağ kapalıysa sola dönüş
  //    {
  //      analogWrite(sol_motor_hiz, 60);
  //      analogWrite(sag_motor_hiz, 150);
  //      analogWrite(sol_motor_1, 255);
  //      analogWrite(sol_motor_2, 0);
  //      analogWrite(sag_motor_1, 255);
  //      analogWrite(sag_motor_2, 0);
  //    }
  //    if (sag_mesafe >=20 && sol_mesafe>=20) //
  //    {
  //      analogWrite(sol_motor_hiz, 100);
  //      analogWrite(sag_motor_hiz, 130);
  //      analogWrite(sol_motor_1, 255);
  //      analogWrite(sol_motor_2, 0);
  //      analogWrite(sag_motor_1, 255);
  //      analogWrite(sag_motor_2, 0);
  //
  //      delay(500);
  //
  //     sag();
  //    }
  //  }
  //  if (sol_mesafe <= 20 && sag_mesafe > 20 && on_mesafe <= 10) {
  //    sag(); //solu kapalı sağı açık
  //  }
  //  if (sol_mesafe > 20 && sag_mesafe > 20 && on_mesafe <= 10) {
  //    sag();  //sağ ve sol açık
  //  }
  //  if (sag_mesafe <= 20 && sol_mesafe > 20 && on_mesafe <= 10) {
  //    sol();  //sağ kapalı sol açık
  //  }
  //  if (sag_mesafe <= 20 && sol_mesafe <= 20 && on_mesafe <= 10) {
  //    tam_donus();  //her tarafı kapalı
  //  }
  ////  if (sag_mesafe >= 20 && sol_mesafe >= 20 && on_mesafe >= 10) {
  ////    sag();
  ////  }
  //
 }
 
  void sol()
  {
    analogWrite(sol_motor_hiz, 120);
    analogWrite(sag_motor_hiz, 150);
    analogWrite(sol_motor_1, 0);
    analogWrite(sol_motor_2, 255);
    analogWrite(sag_motor_1, 255);
    analogWrite(sag_motor_2, 0);
    delay(500);
  }

  void sag()
  {
    analogWrite(sol_motor_hiz, 120);
    analogWrite(sag_motor_hiz, 150);
    analogWrite(sol_motor_1, 255);
    analogWrite(sol_motor_2, 0);
    analogWrite(sag_motor_1, 0);
    analogWrite(sag_motor_2, 255);
    delay(500);
  }

  void tam_donus()
  {
    analogWrite(sol_motor_hiz, 120);
    analogWrite(sag_motor_hiz, 150);
    analogWrite(sol_motor_1, 0);
    analogWrite(sol_motor_2, 255);
    analogWrite(sag_motor_1, 255);
    analogWrite(sag_motor_2, 0);
    delay(900);
  }
  void ileri()
  {
    analogWrite(sol_motor_hiz, 100);
    analogWrite(sag_motor_hiz, 130);
    analogWrite(sol_motor_1, 255);
    analogWrite(sol_motor_2, 0);
    analogWrite(sag_motor_1, 255);
    analogWrite(sag_motor_2, 0);

  }
