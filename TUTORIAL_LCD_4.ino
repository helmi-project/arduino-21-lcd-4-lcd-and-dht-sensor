/*
   TUTORIAL LCD 1602 PADA ARDUINO
   MENGGUNAKAN I2C
   MENAMPILKAN SUHU DAN KELEMBABAN UDARA

   Pinout LCD :
   SDA -> SDA
   SCL -> SCL
   VCC -> VCC
   GND -> GND

   DHT signal -> D12
*/

#include <Wire.h>
// include library yang dibutuhkan
#include <dht.h>


#include <LiquidCrystal_I2C.h>
//set I2C address untuk Modul I2C LCD, beberapa modul menggunakan 0x3F atau 0x27

//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//inisiasi dht
dht SENSOR_DHT;

//definisikan DHT_PIN untuk pin 12
#define DHT_PIN 12

void setup()
{
  Serial.begin(115200);  // memulai komunikasi serial untuk debug
  Serial.println("Mencoba Sensor Suhu dan Kelembaban Udara DHT11 pada Arduino");

  lcd.begin(16, 2);  // inisiasi lcd
}

void loop()
{
  int cek = SENSOR_DHT.read11(DHT_PIN);
  lcd.setCursor(0, 0); //set cursor untuk mulai pada kolom 0 di baris 0
  lcd.print("Temp.  : ");
  lcd.print(SENSOR_DHT.temperature, 0); //data suhu udara
  lcd.print(char(223));//simbol derajat
  lcd.print("C");//simbol C
  lcd.setCursor(0, 1);
  lcd.print("Humid. : ");
  lcd.print(SENSOR_DHT.humidity, 0); //data kelembaban udara
  lcd.print("%");//simbol C
  delay(2000);
}
