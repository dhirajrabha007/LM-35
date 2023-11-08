
float temp= 30.0; // Temperature set.
int LM35Pin = A0;// As per assignment Lm35 is connected with analog pin A0.

// Define the onboard LED pin
int LEDPin = 13; // Led is connected in pin 13

// Define the threshold temperature for blinking the LED
float temp= 30.0; // Temperature set.

void setup() {
  Serial.begin(9600);// baud rate
  pinMode(LEDPin, OUTPUT);
  }

void loop() {
  // Read the analog voltage from the LM35 temperature sensor
  int sensorValue = analogRead(LM35Pin);// reading analog voltage form lm35
  float temperature = (sensorValue * 5.0) / 1024.0;// conversion of analog voltage to temperature in degree celsius.

  // Check if the temperature is below the threshold
  if (temperature < thresholdTemperature) {
    blinkLED(250);// LED blink after every every 250 milliseconds
  } else {
    blinkLED(500); // LED blink after every every 500 milliseconds
  }
}

void blinkLED(int interval) {
  digitalWrite(LEDPin, HIGH);// LED is On.
  delayMicroseconds(interval * 1000);// waiting time.
  digitalWrite(LEDPin, LOW);// LEd is Off.

  // Wait for the specified interval
  delayMicroseconds(interval * 1000);
}
