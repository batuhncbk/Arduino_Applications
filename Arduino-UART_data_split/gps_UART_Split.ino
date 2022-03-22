String veri;
String utc = "";  // hhmmss.00
String latt = "";  // DDMM.MMMM N/S
String lonn = "";  // DDMM.MMMM E/W
String alt = "";  // x meters
String sat = "";
String irr = "";

void setup()
{
  Serial1.begin(115200);
  Serial2.begin(250000);
}

void loop()
{
  if (Serial2.available() > 0)
  {
    getGPS();
  }

  Serial1.print("time = ");
  Serial1.println(utc);

  Serial1.print("latude = ");
  Serial1.println(latt);

  Serial1.print("longtude = ");
  Serial1.println(lonn);

  Serial1.print("Altitude = ");
  Serial1.println(alt);

  Serial1.print("uydu = ");
  Serial1.println(sat);

  Serial1.println("");

}

void getGPS() {

  if ( Serial2.find("$GPGGA,") ) {

    utc = Serial2.readStringUntil(',');                 //saat
    latt = Serial2.readStringUntil(',');                //latude
    irr.concat(Serial2.readStringUntil(','));           //latude işareti
    lonn = Serial2.readStringUntil(',');                //longtude
    irr.concat(Serial2.readStringUntil(','));           //longtude işareti
    irr = Serial2.readStringUntil(',');                 //fix
    sat = Serial2.readStringUntil(',');                 //uydu sayısı


    Serial2.readStringUntil('\r');
  }


}
