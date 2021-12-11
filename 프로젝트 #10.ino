* 모터 회전 */
/*
아두이노 디지털 출력은 40 milliAmps 까지 보낼 수 있다.
그러나 모터는 50-100mA 까지 필요하다.
그래서 트랜지스터를 사용하여 모터를 제어한다. (2N2222 200mA)
*/
const int motorPin = 9;
void setup()
{
pinMode(motorPin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
//다음 함수의 주석 기호를 없애면 함수를 시험해 볼 수 있다.
// motorOnThenOff();
// motorOnThenOffWithSpeed();
// motorAcceleration();
serialSpeed();
}

// 모터를 작동후 정지
void motorOnThenOff()
{
int onTime = 3000; // 작동시간
int offTime = 3000; // 정지시간
digitalWrite(motorPin, HIGH); // 최대 속도로 회전
delay(onTime);
digitalWrite(motorPin, LOW); // 정지
delay(offTime);
}

// 2가지 속도로 모터 회전
void motorOnThenOffWithSpeed()
{
int Speed1 = 200; // 0 ~ 255중 200, 약 78% 출력
int Time1 = 3000; // milliseconds for speed 1
int Speed2 = 50; // 50 / 255 출력, 약 20% 출력
int Time2 = 3000; // milliseconds to turn the motor off
analogWrite(motorPin, Speed1); // turns the motor On
delay(Time1); // delay for onTime milliseconds
analogWrite(motorPin, Speed2); // turns the motor Off
delay(Time2); // delay for offTime milliseconds
}

// 점점 빠르게 점점 느리게
void motorAcceleration()
{
int speed;
int delayTime = 20; // milliseconds between each speed step
// 점점 빠르게 모터 회전
for(speed = 0; speed <= 255; speed++)
{
analogWrite(motorPin,speed);
delay(delayTime);
}
  
// 점점 느리게
for(speed = 255; speed >= 0; speed--)
{
analogWrite(motorPin,speed); // set the new speed
delay(delayTime); // delay between speed steps
}
}

// 0~255 값을 시리얼 모니터로 주면 그 속도로 모터 회전
void serialSpeed()
{
int speed;
Serial.println("Type a speed (0-255) into the box above,");
Serial.println("and [send] or press [return]");
Serial.println(); // Print a blank line
while(true) // 영원히 반복
{
// 시리얼로 입력받은 값이 있으면
while (Serial.available() > 0)
{
// 글자를 읽어서 수 (정수, int)로 변환하자.
speed = Serial.parseInt();
speed = constrain(speed, 0, 255);
// 시리얼로 읽은 값을 알려줌
Serial.print("Setting speed to ");
Serial.println(speed);
// 읽은 값으로 모터 회전
analogWrite(motorPin, speed);
}
}
}
