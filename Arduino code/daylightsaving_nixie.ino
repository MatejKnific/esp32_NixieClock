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
#include <time.h>  // Za funkciji setenv in tzset

// Zamenjaj z ustreznimi podatki o tvoji omrežju
const char *ssid     = "**";
const char *password = "***";

WiFiUDP ntpUDP;                                        
// Inicializiramo z offsetom 0, ker bomo s sistemskimi funkcijami določili lokalni čas (vključno z DST)
NTPClient timeClient(ntpUDP, "goodtime.ijs.si", 0, 600000);

void IRAM_ATTR onTimer(void* arg) {
  // Funkcija, ki preprečuje izgorelost katod
  for (unsigned int j = 0; j < 10; j++) {
    displayNumber1(j);
    displayNumber2(j);
    displayNumber3(j);
    displayNumber4(j);
    delay(500);
  }
  return;
}
esp_timer_handle_t periodicTimer = NULL;  // Časovnik na globalni ravni

void setup() {
  Serial.begin(115200);

  // Poveži se na WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Nastavi časovni pas za CET/CEST (Centralnoevropski čas) s pravili za DST:
  // - Osnovni čas: CET (UTC+1)
  // - Prehod na poletni čas: zadnja nedelja marca ob 2:00
  // - Prehod na standardni čas: zadnja nedelja oktobra ob 3:00

  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1);
  tzset();

  // Začetek NTP klienta
  timeClient.begin();

  // Inicializacija pinov za display1
  pinMode(d1, OUTPUT);  // D
  pinMode(c1, OUTPUT);  // C
  pinMode(b1, OUTPUT);  // B
  pinMode(a1, OUTPUT);  // A

  // Inicializacija pinov za display2
  pinMode(d2, OUTPUT);  // D
  pinMode(c2, OUTPUT);  // C
  pinMode(b2, OUTPUT);  // B
  pinMode(a2, OUTPUT);  // A

  // Inicializacija pinov za display3
  pinMode(d3, OUTPUT);  // D
  pinMode(c3, OUTPUT);  // C
  pinMode(b3, OUTPUT);  // B
  pinMode(a3, OUTPUT);  // A

  // Inicializacija pinov za display4
  pinMode(d4, OUTPUT);  // D
  pinMode(c4, OUTPUT);  // C
  pinMode(b4, OUTPUT);  // B
  pinMode(a4, OUTPUT);  // A
}

void displayNumber1(int number) {
  switch (number) {
    case 0:
      digitalWrite(d1, LOW);  // D
      digitalWrite(c1, LOW);  // C
      digitalWrite(b1, HIGH); // B
      digitalWrite(a1, LOW);  // A
      break;
    case 1:
      digitalWrite(d1, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(a1, HIGH);
      break;
    case 2:
      digitalWrite(d1, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(a1, LOW);
      break;
    case 3:
      digitalWrite(d1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(a1, HIGH);
      break;
    case 4:
      digitalWrite(d1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(a1, LOW);
      break;
    case 5:
      digitalWrite(d1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(a1, HIGH);
      break;
    case 6:
      digitalWrite(d1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(a1, LOW);
      break;
    case 7:
      digitalWrite(d1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(a1, HIGH);
      break;
    case 8:
      digitalWrite(d1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(a1, LOW);
      break;
    case 9:
      digitalWrite(d1, LOW);
      digitalWrite(c1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(a1, HIGH);
      break;
  }
  delay(20);
}

void displayNumber2(int number) {
  switch (number) {
    case 0:
      digitalWrite(d2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(a2, LOW);
      break;
    case 1:
      digitalWrite(d2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(a2, HIGH);
      break;
    case 2:
      digitalWrite(d2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(a2, LOW);
      break;
    case 3:
      digitalWrite(d2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(a2, HIGH);
      break;
    case 4:
      digitalWrite(d2, HIGH);
      digitalWrite(c2, LOW);
      digitalWrite(b2, LOW);
      digitalWrite(a2, LOW);
      break;
    case 5:
      digitalWrite(d2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(a2, HIGH);
      break;
    case 6:
      digitalWrite(d2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(a2, LOW);
      break;
    case 7:
      digitalWrite(d2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(a2, HIGH);
      break;
    case 8:
      digitalWrite(d2, LOW);
      digitalWrite(c2, HIGH);
      digitalWrite(b2, LOW);
      digitalWrite(a2, LOW);
      break;
    case 9:
      digitalWrite(d2, LOW);
      digitalWrite(c2, LOW);
      digitalWrite(b2, HIGH);
      digitalWrite(a2, HIGH);
      break;
  }
  delay(20);
}

void displayNumber3(int number) {
  switch (number) {
    case 0:
      digitalWrite(d3, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(b3, HIGH);
      digitalWrite(a3, LOW);
      break;
    case 1:
      digitalWrite(d3, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(b3, LOW);
      digitalWrite(a3, HIGH);
      break;
    case 2:
      digitalWrite(d3, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(b3, LOW);
      digitalWrite(a3, LOW);
      break;
    case 3:
      digitalWrite(d3, HIGH);
      digitalWrite(c3, LOW);
      digitalWrite(b3, LOW);
      digitalWrite(a3, HIGH);
      break;
    case 4:
      digitalWrite(d3, HIGH);
      digitalWrite(c3, LOW);
      digitalWrite(b3, LOW);
      digitalWrite(a3, LOW);
      break;
    case 5:
      digitalWrite(d3, LOW);
      digitalWrite(c3, HIGH);
      digitalWrite(b3, HIGH);
      digitalWrite(a3, HIGH);
      break;
    case 6:
      digitalWrite(d3, LOW);
      digitalWrite(c3, HIGH);
      digitalWrite(b3, HIGH);
      digitalWrite(a3, LOW);
      break;
    case 7:
      digitalWrite(d3, LOW);
      digitalWrite(c3, HIGH);
      digitalWrite(b3, LOW);
      digitalWrite(a3, HIGH);
      break;
    case 8:
      digitalWrite(d3, LOW);
      digitalWrite(c3, HIGH);
      digitalWrite(b3, LOW);
      digitalWrite(a3, LOW);
      break;
    case 9:
      digitalWrite(d3, LOW);
      digitalWrite(c3, LOW);
      digitalWrite(b3, HIGH);
      digitalWrite(a3, HIGH);
      break;
  }
  delay(20);
}

void displayNumber4(int number) {
  switch (number) {
    case 0:
      digitalWrite(d4, LOW);
      digitalWrite(c4, LOW);
      digitalWrite(b4, HIGH);
      digitalWrite(a4, LOW);
      break;
    case 1:
      digitalWrite(d4, LOW);
      digitalWrite(c4, LOW);
      digitalWrite(b4, LOW);
      digitalWrite(a4, HIGH);
      break;
    case 2:
      digitalWrite(d4, LOW);
      digitalWrite(c4, LOW);
      digitalWrite(b4, LOW);
      digitalWrite(a4, LOW);
      break;
    case 3:
      digitalWrite(d4, HIGH);
      digitalWrite(c4, LOW);
      digitalWrite(b4, LOW);
      digitalWrite(a4, HIGH);
      break;
    case 4:
      digitalWrite(d4, HIGH);
      digitalWrite(c4, LOW);
      digitalWrite(b4, LOW);
      digitalWrite(a4, LOW);
      break;
    case 5:
      digitalWrite(d4, LOW);
      digitalWrite(c4, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(a4, HIGH);
      break;
    case 6:
      digitalWrite(d4, LOW);
      digitalWrite(c4, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(a4, LOW);
      break;
    case 7:
      digitalWrite(d4, LOW);
      digitalWrite(c4, HIGH);
      digitalWrite(b4, LOW);
      digitalWrite(a4, HIGH);
      break;
    case 8:
      digitalWrite(d4, LOW);
      digitalWrite(c4, HIGH);
      digitalWrite(b4, LOW);
      digitalWrite(a4, LOW);
      break;
    case 9:
      digitalWrite(d4, LOW);
      digitalWrite(c4, LOW);
      digitalWrite(b4, HIGH);
      digitalWrite(a4, HIGH);
      break;
  }
  delay(20);
}

void loop() {
  // Posodobi čas z NTP
  timeClient.update();

  // Pridobi UTC čas
  time_t rawTime = timeClient.getEpochTime();

  // Pretvori UTC čas v lokalni čas glede na nastavljeni TZ (vključno z DST)
  struct tm *timeInfo = localtime(&rawTime);
  unsigned int hours = timeInfo->tm_hour;
  unsigned int minutes = timeInfo->tm_min;

  // Razdeli ure in minute na posamezne števke
  unsigned int hourTens   = hours / 10;
  unsigned int hourOnes   = hours % 10;
  unsigned int minuteTens = minutes / 10;
  unsigned int minuteOnes = minutes % 10;

  // Prikaz števk na posameznih 7-segmentnih prikazovalnikih
  displayNumber1(hourTens);
  displayNumber2(hourOnes);
  displayNumber3(minuteTens);
  displayNumber4(minuteOnes);

  // Timer za preprečevanje izgorelosti katod (anti katode burn)
  if (hours >= 0 && hours <= 12) {
    if (periodicTimer == NULL) {
      const esp_timer_create_args_t timerArgs = {
        .callback = &onTimer,
        .name = "periodicTimer"
      };
      esp_timer_create(&timerArgs, &periodicTimer);
    }
    esp_timer_start_once(periodicTimer, 5 * 60 * 1000000);  // Izvedi onTimer po 5 minutah
  } else {
    if (periodicTimer != NULL) {
      esp_timer_stop(periodicTimer);
      esp_timer_delete(periodicTimer);
      periodicTimer = NULL;
    }
  }

  delay(1000);
}
