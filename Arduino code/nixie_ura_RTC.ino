#define a1 2
#define b1 15
#define c1 32
#define d1 33

#define a2 25
#define b2 26
#define c2 27
#define d2 14

#define a3 12
#define b3 13
#define c3 23
#define d3 19

#define a4 18
#define b4 5
#define c4 17
#define d4 16

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <esp_timer.h>




// Replace with your network credentials
const char *ssid     = "wifiNAME";
const char *password = "PASSWORD";

WiFiUDP ntpUDP;                                        
NTPClient timeClient(ntpUDP, "goodtime.ijs.si", 7200, 120000);//europe.pool.ntp.org,goodtime.ijs.si



void IRAM_ATTR onTimer(void* arg) {
  // krozi- antiS katode burn
    for(unsigned int j=0; j<10; j++){
      displayNumber1(j);
      displayNumber2(j);
      displayNumber3(j);
      displayNumber4(j);
      delay(500);
      } 
      return; 
}
esp_timer_handle_t periodicTimer = NULL;  // Deklaracija časovnika zunaj funkcije loop()


void setup() {

    Serial.begin(115200);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED ) {
        delay (500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    timeClient.begin();





//display1
    pinMode(d1, OUTPUT);// D
    pinMode(c1, OUTPUT);// C
    pinMode(b1, OUTPUT);// B
    pinMode(a1, OUTPUT);// A

//display2
    pinMode(d2, OUTPUT);// D
    pinMode(c2, OUTPUT);// C
    pinMode(b2, OUTPUT);// B
    pinMode(a2, OUTPUT);// A


//display3
    pinMode(d3, OUTPUT);// D
    pinMode(c3, OUTPUT);// C
    pinMode(b3, OUTPUT);// B
    pinMode(a3, OUTPUT);// A


//display4
    pinMode(d4, OUTPUT);// D
    pinMode(c4, OUTPUT);// C
    pinMode(b4, OUTPUT);// B
    pinMode(a4, OUTPUT);// A
    

}


void displayNumber1(int number) {
    
    switch(number){
        case 0:
            //0
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, HIGH); //B
            digitalWrite(a1, LOW);  //A
            break;
        case 1:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, LOW);  //B
            digitalWrite(a1, HIGH); //A
            break;
        case 2:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, LOW);  //B
            digitalWrite(a1, LOW);  //A
            break;
        case 3:
            digitalWrite(d1, HIGH); //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, LOW); //B
            digitalWrite(a1, HIGH);  //A
            break;
        case 4:
            digitalWrite(d1, HIGH); //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, LOW);  //B
            digitalWrite(a1, LOW);  //A
            break;
        case 5:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, HIGH); //C
            digitalWrite(b1, HIGH); //B
            digitalWrite(a1, HIGH); //A
            break;
        case 6:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, HIGH); //C
            digitalWrite(b1, HIGH); //B
            digitalWrite(a1, LOW);  //A
            break;
        case 7:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, HIGH); //C
            digitalWrite(b1, LOW);  //B
            digitalWrite(a1, HIGH); //A
            break;
        case 8:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, HIGH); //C
            digitalWrite(b1, LOW);  //B
            digitalWrite(a1, LOW);  //A
            break;
        case 9:
            digitalWrite(d1, LOW);  //D
            digitalWrite(c1, LOW);  //C
            digitalWrite(b1, HIGH); //B
            digitalWrite(a1, HIGH); //A
            break;
    }
    delay(20);
}
void displayNumber2(int number) {

    switch(number){
        case 0:
            //0
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, HIGH); //B
            digitalWrite(a2, LOW);  //A
            break;
        case 1:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, LOW);  //B
            digitalWrite(a2, HIGH); //A
            break;
        case 2:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, LOW);  //B
            digitalWrite(a2, LOW);  //A
            break;
        case 3:
            digitalWrite(d2, HIGH); //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, LOW); //B
            digitalWrite(a2, HIGH);  //A
            break;
        case 4:
            digitalWrite(d2, HIGH); //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, LOW);  //B
            digitalWrite(a2, LOW);  //A
            break;
        case 5:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, HIGH); //C
            digitalWrite(b2, HIGH); //B
            digitalWrite(a2, HIGH); //A
            break;
        case 6:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, HIGH); //C
            digitalWrite(b2, HIGH); //B
            digitalWrite(a2, LOW);  //A
            break;
        case 7:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, HIGH); //C
            digitalWrite(b2, LOW);  //B
            digitalWrite(a2, HIGH); //A
            break;
        case 8:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, HIGH); //C
            digitalWrite(b2, LOW);  //B
            digitalWrite(a2, LOW);  //A
            break;
        case 9:
            digitalWrite(d2, LOW);  //D
            digitalWrite(c2, LOW);  //C
            digitalWrite(b2, HIGH); //B
            digitalWrite(a2, HIGH); //A
            break;
    }
    delay(20);
}
void displayNumber3(int number) {
    
    switch(number){
        case 0:
            //0
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, HIGH); //B
            digitalWrite(a3, LOW);  //A
            break;
        case 1:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, LOW);  //B
            digitalWrite(a3, HIGH); //A
            break;
        case 2:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, LOW);  //B
            digitalWrite(a3, LOW);  //A
            break;
        case 3:
            digitalWrite(d3, HIGH); //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, LOW); //B
            digitalWrite(a3, HIGH);  //A
            break;
        case 4:
            digitalWrite(d3, HIGH); //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, LOW);  //B
            digitalWrite(a3, LOW);  //A
            break;
        case 5:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, HIGH); //C
            digitalWrite(b3, HIGH); //B
            digitalWrite(a3, HIGH); //A
            break;
        case 6:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, HIGH); //C
            digitalWrite(b3, HIGH); //B
            digitalWrite(a3, LOW);  //A
            break;
        case 7:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, HIGH); //C
            digitalWrite(b3, LOW);  //B
            digitalWrite(a3, HIGH); //A
            break;
        case 8:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, HIGH); //C
            digitalWrite(b3, LOW);  //B
            digitalWrite(a3, LOW);  //A
            break;
        case 9:
            digitalWrite(d3, LOW);  //D
            digitalWrite(c3, LOW);  //C
            digitalWrite(b3, HIGH); //B
            digitalWrite(a3, HIGH); //A
            break;
    }
    delay(20);
}
void displayNumber4(int number) {
    
    switch(number){
        case 0:
            //0
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, HIGH); //B
            digitalWrite(a4, LOW);  //A
            break;
        case 1:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, LOW);  //B
            digitalWrite(a4, HIGH); //A
            break;
        case 2:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, LOW);  //B
            digitalWrite(a4, LOW);  //A
            break;
        case 3:
            digitalWrite(d4, HIGH); //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, LOW); //B
            digitalWrite(a4, HIGH);  //A
            break;
        case 4:
            digitalWrite(d4, HIGH); //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, LOW);  //B
            digitalWrite(a4, LOW);  //A
            break;
        case 5:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, HIGH); //C
            digitalWrite(b4, HIGH); //B
            digitalWrite(a4, HIGH); //A
            break;
        case 6:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, HIGH); //C
            digitalWrite(b4, HIGH); //B
            digitalWrite(a4, LOW);  //A
            break;
        case 7:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, HIGH); //C
            digitalWrite(b4, LOW);  //B
            digitalWrite(a4, HIGH); //A
            break;
        case 8:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, HIGH); //C
            digitalWrite(b4, LOW);  //B
            digitalWrite(a4, LOW);  //A
            break;
        case 9:
            digitalWrite(d4, LOW);  //D
            digitalWrite(c4, LOW);  //C
            digitalWrite(b4, HIGH); //B
            digitalWrite(a4, HIGH); //A
            break;
    }
    delay(20);
}
void krozi(void* arg){
    for(unsigned int j=0; j<10; j++){
      displayNumber1(j);
      displayNumber2(j);
      displayNumber3(j);
      displayNumber4(j);
      delay(500);
      }
     
}




void loop() {
    timeClient.update();

    unsigned int hours = timeClient.getHours();
    unsigned int minutes = timeClient.getMinutes();

    // Split the hours and minutes into digits
    unsigned int hourTens = hours / 10;
    unsigned int hourOnes = hours % 10;
    unsigned int minuteTens = minutes / 10;
    unsigned int minuteOnes = minutes % 10;

    // Display the digits on the displays
    displayNumber1(hourTens);
    displayNumber2(hourOnes);
    displayNumber3(minuteTens);
    displayNumber4(minuteOnes);

    //timer anti katode burn
    if (hours >= 0 && hours <= 12) {
        if (periodicTimer == NULL) {
            const esp_timer_create_args_t timerArgs = {
                .callback = &onTimer,
                .name = "periodicTimer"
            };

            esp_timer_create(&timerArgs, &periodicTimer);
        }

        esp_timer_start_once(periodicTimer, 5 * 60 * 1000000);  // Pokliči funkcijo onTimer enkrat po 5 minutah
    } else {
        if (periodicTimer != NULL) {
            esp_timer_stop(periodicTimer);
            esp_timer_delete(periodicTimer);
            periodicTimer = NULL;
        }
    }

    




    delay(1000);

}
