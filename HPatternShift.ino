// Project by @carbon_gtv support me on instagram


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

const int clutchPin = 2; // Pin für die pneumatische Kupplung
const int gearOutputPin = 3; // Digitaler Ausgang für den eingelegten Gang
const int neutralButton = 4; // Knopf für den Neutralgang
const int paddleShiftUp = 5; // Paddle für Hochschalten
const int paddleShiftDown = 6; // Paddle für Herunterschalten
const int reverseButton = 7; // Knopf für den Rückwärtsgang

int gearPositionsServo1[8] = {150, 200, 250, 300, 350, 400, 450, 500}; // Servo-Positionen für Neutral, 1-6 Gänge, Rückwärtsgang
int gearPositionsServo2[8] = {150, 210, 260, 310, 360, 410, 460, 510}; // Servo-Positionen für Neutral, 1-6 Gänge, Rückwärtsgang
int currentGear = 0; // Aktueller Gang

void setup() {
  pinMode(clutchPin, OUTPUT);
  pinMode(gearOutputPin, OUTPUT);
  pinMode(neutralButton, INPUT_PULLUP);
  pinMode(reverseButton, INPUT_PULLUP);
  pinMode(paddleShiftUp, INPUT_PULLUP);
  pinMode(paddleShiftDown, INPUT_PULLUP);
  pwm.begin();
  pwm.setPWMFreq(60);  // 60 Hz
}

void loop() {
  // Neutralgang einlegen
  if (digitalRead(neutralButton) == LOW) {
    engageClutch();
    shiftGear(0); // Neutral
    disengageClutch();
  }
  // Hochschalten
  if (digitalRead(paddleShiftUp) == LOW && currentGear < 7) {
    engageClutch();
    shiftGear(currentGear + 1);
    disengageClutch();
  }
  // Herunterschalten
  if (digitalRead(paddleShiftDown) == LOW && currentGear > 0) {
    engageClutch();
    shiftGear(currentGear - 1);
    disengageClutch();
  }
  // Rückwärtsgang einlegen
  if (digitalRead(reverseButton) == LOW && currentGear == 0) {
    engageClutch();
    shiftGear(7); // Rückwärtsgang
    disengageClutch();
  }
}

void engageClutch() {
  digitalWrite(clutchPin, HIGH);
  delay(100); // Verzögerung für Kupplungsbetätigung, anpassbar
}

void disengageClutch() {
  digitalWrite(clutchPin, LOW);
  delay(100); // Verzögerung für Kupplungsentlastung, anpassbar
}

void shiftGear(int gear) {
  pwm.setPWM(0, 0, gearPositionsServo1[gear]);
  pwm.setPWM(1, 0, gearPositionsServo2[gear]);
  currentGear = gear;
  digitalWrite(gearOutputPin, gear); // Ausgabe des eingelegten Gangs
}
