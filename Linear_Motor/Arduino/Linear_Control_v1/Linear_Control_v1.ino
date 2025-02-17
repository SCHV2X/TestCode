//리니어 모터 앞/뒤, 속도 조작 아두이노 소스코드 V1

//https://blog.naver.com/PostView.naver?blogId=emperonics&logNo=221834467735

const int ENABLE=10;            // 모터1사용 가능 제어핀과 동시에 속도제어핀 역할
const int DIR1=9;               // 방향제어를 위한 핀1
const int DIR2=8;               // 방향제어를 위한 핀2
const int BUTTON = 3;           // 버튼입력으로 사용할 핀
const int POT = A5;             // 가변저항기와 연결한 핀

//모터2 연결시 DIR3,4 추가 필요

enum MOTOR_DIRECTION{FOWARD=0, BACKWARD=1};         // 모터의 전방, 후방 여부 확인을 위한 자료형
  
enum MOTOR_DIRECTION Direction;                     // 모터의 전방, 후방 여부 확인을 위한 자료형 생성

void setup() { 
  Serial.begin(9600);                   // 시리얼 통신 개시
  pinMode(ENABLE, OUTPUT);              // 모터1사용 가능 제어핀 출력으로 설정
  pinMode(DIR1, OUTPUT);                // 방향제어를 위한 핀1 출력으로 설정
  pinMode(DIR2, OUTPUT);                // 방향제어를 위한 핀2 출력으로 설정
  pinMode(BUTTON, INPUT);               // 버튼핀 입력으로 설정
  digitalWrite(ENABLE, LOW);            // 일단 모터가 작동하지 않도록 초기화
  
}

void loop() {
  if(digitalRead(BUTTON)==0){         // 버튼이 눌렸으면
    delay(100);                       // Debouncing 용도
    if(Direction==FOWARD){            // 이전의 모터 방향이 전방이었다면
      Direction=BACKWARD;             // 후방으로 바꾸고 
      Serial.println("Change Direction to BACKWARD.");          
      }else{                          // 이전의 모터 방향이 후방이었다면
      Direction=FOWARD;               // 전방으로 바꾸기
      Serial.println("Change Direction to FORWARD.");
      }

    delay(100);                       // Debouncing 용도
    }
    
    Serial.print("Direction:");       // 방향출력
    Serial.println(Direction);
  
  int pot_position = analogRead(POT);                  // 가변저항의 값을 읽어서
  int speed = map(pot_position, 0, 1024, 0, 255);      // 범위를 0-255의 PWM출력값으로 환산
   analogWrite(ENABLE, speed);                         // 속도제어핀에 속도를 설정

  if(Direction == FOWARD){                    // 모터의 방향이 전방이면 
    digitalWrite(DIR1, HIGH);                 // 방향제어를 위한 핀1은 HIGH
    digitalWrite(DIR2, LOW);                  // 방향제어를 위한 핀2은 LOW
    
    }else{                                    // 모터의 방향이 후방이면 
    digitalWrite(DIR1, LOW);                  // 방향제어를 위한 핀1은 LOW
    digitalWrite(DIR2, HIGH);                 // 방향제어를 위한 핀1은 HIGH
    }
  }
