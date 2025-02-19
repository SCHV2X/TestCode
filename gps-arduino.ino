GPS/아두이노/소스코드
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Create TinyGPS++ instance for GPS module
TinyGPSPlus gpsParser1;

// Define software serial port for GPS module
SoftwareSerial gps1(10, 11);   // TX = 10, RX = 11

void setup() {
    Serial.begin(9600); // Serial monitor baud rate (matching with Serial Monitor setting)
    gps1.begin(9600);   // Initialize GPS module (matching with GPS module's baud rate)
}

void loop() {
    // GPS 데이터를 읽고 출력
    readGPS(gps1, gpsParser1, "GPS 1");

    Serial.println("--------------------");
    delay(3000); // 3초로 지연 시간을 늘려서 GPS 데이터 수신을 기다림
}

void readGPS(SoftwareSerial &gpsSerial, TinyGPSPlus &gpsParser, const char *gpsName) {
    // GPS 모듈로부터 수신한 데이터를 파싱
    while (gpsSerial.available()) {
        gpsParser.encode(gpsSerial.read());
    }

    Serial.print(gpsName);
    Serial.print(": ");

    // 위치 데이터가 유효한지 확인
    if (gpsParser.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.print(gpsParser.location.lat(), 6);  // 위도 (소수점 6자리까지 출력)
        Serial.print(", Longitude: ");
        Serial.print(gpsParser.location.lng(), 6);  // 경도 (소수점 6자리까지 출력)
    } else {
        Serial.print("No GPS signal");
    }
    Serial.println(); // 줄 바꿈
}
