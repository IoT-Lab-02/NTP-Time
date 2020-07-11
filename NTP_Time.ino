#include <NTPClient.h>
#include <ESP8266WiFi.h>
//#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>

const char *ssid     = "melon";
const char *password = "deitcs3217";
WiFiUDP udp;

NTPClient timeClient(udp, "kr.pool.ntp.org", 32400, 3600000);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  timeClient.begin();
}
void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}
