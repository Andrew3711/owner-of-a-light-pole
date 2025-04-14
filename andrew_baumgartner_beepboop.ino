
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10


#define yellowBlinkTime 500

boolean trafficWest = true;  // west = true, east = false
int flowTime = 10000;
int changeDelay = 2000;

void greenRed(int green, int yellow, int red) {
  delay(flowTime);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(changeDelay);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(changeDelay);
}
void yellowBlink(int direction) {
  digitalWrite(direction, LOW);
  delay(yellowBlinkTime);
  digitalWrite(direction, HIGH);
  delay(yellowBlinkTime);
}
void redGreen(int green, int yellow, int red){
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}
void setup() {
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
}
 
void loop() {
  if (digitalRead(westButton) == HIGH) {
    if (trafficWest != true) {
      trafficWest = true;
      greenRed(eastGreen, eastYellow, eastRed);

      for (int a = 0; a < 5; a++) {
        yellowBlink(westYellow);
      }
      redGreen(westGreen, westYellow, westRed);
    }
  }
  if (digitalRead(eastButton) == HIGH) {
    if (trafficWest == true) {
      trafficWest = false;
      greenRed(westGreen, westYellow, westRed);
      for (int a = 0; a < 5; a++) {
        yellowBlink(eastYellow);
      }
      redGreen(eastGreen, eastYellow, eastRed);
    }
  }
}
