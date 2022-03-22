#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;

double baseline;
int basinc_dizisi[4];

void setup()
{
  Serial.begin(9600);
  Serial.println("REBOOT");

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {
    Serial.println("BMP180 init fail (disconnected?)\n\n");
    while (1);
  }
  baseline = getPressure();
}

void loop()
{
  double irtifa_1, irtifa_2, irtifa_3, irtifa_4, irtifa_5, P;
  double irtifa_veri[4];

  P = getPressure();
  irtifa_1 = pressure.altitude(P, baseline);
  //Serial.println(irtifa_1);

  P = getPressure();
  irtifa_2 = pressure.altitude(P, baseline);
  //Serial.println(irtifa_2);

  P = getPressure();
  irtifa_3 = pressure.altitude(P, baseline);
  //Serial.println(irtifa_3);

  P = getPressure();
  irtifa_4 = pressure.altitude(P, baseline);
  //Serial.println(irtifa_4);

  P = getPressure();
  irtifa_5 = pressure.altitude(P, baseline);
  //Serial.println(irtifa_5);


  irtifa_veri[0] = irtifa_1;
  irtifa_veri[1] = irtifa_2;
  irtifa_veri[2] = irtifa_3;
  irtifa_veri[3] = irtifa_4;
  irtifa_veri[4] = irtifa_5;

  int temp;
  for (int i = 0; i < 5 - 1; i++)
  {
    for (int j = 0; j < 5 - 1; j++)
    {
      if (irtifa_veri[j] > irtifa_veri[j + 1])
      {
        temp = irtifa_veri[j];
        irtifa_veri[j] = irtifa_veri[j + 1];
        irtifa_veri[j + 1] = temp;
      }
    }
  }
//  Serial.print(irtifa_veri[0]);
//  Serial.print(" ");
//  Serial.print(irtifa_veri[1]);
//  Serial.print(" ");
  Serial.print(irtifa_veri[2]);
//  Serial.print(" ");
//  Serial.print(irtifa_veri[3]);
//  Serial.print(" ");
//  Serial.print(irtifa_veri[4]);
  Serial.println("");
}

double getPressure()
{
  char status;
  double T, P, p0, irtifa;

  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0)
    {
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0)
        {
          return (P);
        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
}
