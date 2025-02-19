#define SENSOR_PIN 2  // Black wire connected to D2

void setup() {
    pinMode(SENSOR_PIN, INPUT);
    Serial.begin(9600);
}

void loop() {
    int sensorState = digitalRead(SENSOR_PIN);
    
    if (sensorState == LOW) { // NPN Sensor: LOW when activated
        Serial.println("Metal detected!");
    } else {
        Serial.println("No metal detected.");
    }

    delay(500);
}
