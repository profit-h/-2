#define PIN_LED 9
#define PIN_TRIG 12
#define PIN_ECHO 13

long duration;
float distance;
int brightness;

void setup() {
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);
  distance = (duration * 0.343) / 2;

  if (distance <= 100 || distance >= 300) {
    brightness = 255;
  } else if (distance == 150 || distance == 250) {
    brightness = 128;
  } else if (distance > 100 && distance < 150) {
    brightness = map(distance, 100, 150, 255, 128);
  } else if (distance > 150 && distance < 200) {
    brightness = map(distance, 150, 200, 128, 0);
  } else if (distance > 200 && distance < 250) {
    brightness = map(distance, 200, 250, 0, 128);
  } else {
    brightness = map(distance, 250, 300, 128, 255);
  }

  analogWrite(PIN_LED, brightness);
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" mm, Brightness: ");
  Serial.println(brightness);

  delay(25);
}
