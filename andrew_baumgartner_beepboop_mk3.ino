// Andrew's crying in the club mix
// This program manages traffic
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedLight 8
#define ped 9
#define grum 6

#define yellowBlinkTime 500

boolean trafficWest = true;
int flowTime = 3000;
int changeDelay = 2000;
void weewoo(){ // Makes the light change with haste
  if (trafficWest != true) {
      trafficWest = true;
      greenRed(eastGreen, eastYellow, eastRed);
      redGreen(westGreen, westYellow, westRed);
    }
  else{
  trafficWest = false;
      greenRed(westGreen, westYellow, westRed);
      redGreen(eastGreen, eastYellow, eastRed);
  }
  }

void greenRed(int green, int yellow, int red) {  // this turns the green light red
  delay(flowTime);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(changeDelay);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(changeDelay);
}
void yellowBlink(int direction) {  //this makes the yellow lights flash between the lights changing from green to red
  digitalWrite(direction, LOW);
  delay(yellowBlinkTime);
  digitalWrite(direction, HIGH);
  delay(yellowBlinkTime);
}
void redGreen(int green, int yellow, int red) {  // this turns the red lights green
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
}
void pedGo(bool active) { // adds a pedestrian button
  if (trafficWest == HIGH) {
    greenRed(westGreen, westYellow, westRed);
  } else {
    greenRed(eastGreen, eastYellow, eastRed);
  }
  digitalWrite(pedLight, active);
  delay(2000);
  digitalWrite(pedLight, !active);
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
  if (digitalRead(westButton) == HIGH) {  // checks to see if the west has traffic
    if (trafficWest != true) {
      trafficWest = true;
      greenRed(eastGreen, eastYellow, eastRed);

      for (int a = 0; a < 5; a++) {
        yellowBlink(westYellow);
      }
      redGreen(westGreen, westYellow, westRed);
    }
  }
  if (digitalRead(eastButton) == HIGH) {  // checks to see of the east has traffic
    if (trafficWest == true) {
      trafficWest = false;
      greenRed(westGreen, westYellow, westRed);
      for (int a = 0; a < 5; a++) {
        yellowBlink(eastYellow);
      }
      redGreen(eastGreen, eastYellow, eastRed);
    }
  }
  if (digitalRead(ped) == HIGH) {//sees if the pedestrian button has been pressed
    pedGo(HIGH);
    delay(2000);
    if (trafficWest == HIGH) {
      redGreen(westGreen, westYellow, westRed);
    } else {
      redGreen(eastGreen, eastYellow, eastRed);
    }
  }
  if (digitalRead(grum) == HIGH){
    weewoo();
  }
}
