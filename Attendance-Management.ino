#include <SPI.h>
#include <MFRC522.h>
#include<SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
#define RST_PIN         9
#define SS_PIN          10
MFRC522 mfrc522(SS_PIN, RST_PIN);
int led = 13;
int RfidNo = 0;
int x = 0;
int x1 = 0;
int y = 0;
int y1 = 0;
int z = 0;
int z1 = 0;
int v = 0;
int v1 = 0;
int w = 0;
int w1 = 0;
int a;
void setup()
{
  SPI.begin();
  Serial.begin(9600);
  mySerial.begin(9600);
  mfrc522.PCD_Init();
  Serial.println("   ATTENDANCE MANAGEMENT SYSTEM");
  Serial.println();
  Serial.println("Total Student List");
  Serial.println("1.Sidharth");
  Serial.println("2.Naveen");
  Serial.println("3.Nandith");
  Serial.println("4.Vimal");
  Serial.println("5.abhay");
  Serial.println();
}

void loop() {
  RfidScan();
  a = (millis() / 1000);
  //Serial.println(a);
  if ((a > 60) && (x == 0) && (x1 == 0))
  {
    Serial.println("1.Sidharth absent");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919654408563\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("1.Sidharth absent");
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
    x1 = 1;
  }
  //  if((a=='1')&&(x==1))
  //  {
  //    Serial.println("Sidharth present");
  //  }
  if ((a > 70) && (y == 0) && (y1 == 0))
  {
    Serial.println("2.Naveen absent");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919654408563\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("2.Naveen absent");
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
    y1 = 1;
  }
  if ((a > 80) && (z == 0) && (z1 == 0))
  {
    Serial.println("3.Nandith absent");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919654408563\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("3.Nandith absent");
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
    z1 = 1;
  }
  if ((a > 90) && (v == 0) && (v1 == 0))
  {
    Serial.println("4.Vimal absent");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919654408563\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("4.Vimal absent");
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
    v1 = 1;
  }
  if ((a > 100) && (w == 0) && (w1 == 0))
  {
    Serial.println("5.abhay absent");
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919654408563\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("5.abhay absent");
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);
    w1 = 1;
  }
}
void dump_byte_array(byte *buffer, byte bufferSize)
{
  if ((buffer[0] == 185) && (x == 0)&&(a < 60))
  {
    Serial.println("1.Sidharth present ");
    delay(500);
    x = 2;
  }
  if ((buffer[0] == 107 ) && (y == 0)&&(a < 70))
  {
    Serial.println("2.Naveen present ");
    delay(500);
    y = 1;
  }
  if ((buffer[0] == 201) && (z == 0)&&(a < 80))
  {
    Serial.println("3.Nandith present ");
    delay(500);
    z = 1;

  }
  if ((buffer[0] == 220) && (v == 0)&&(a < 90))
  {
    Serial.println("4.Vimal present ");
    delay(500);
    v = 1;

  }
  if ((buffer[0] == 211) && (w == 0)&&(a < 100))
  {
    Serial.println("5.abhay present ");
    delay(500);
    w = 1;

  }

}
void RfidScan()
{
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;

  if ( ! mfrc522.PICC_ReadCardSerial())
    return;
  dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
}
