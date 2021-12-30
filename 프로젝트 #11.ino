/* RELAYS 계전기*/
/* 프로그래밍에는 별다른 게 없다!*/
const int relayPin = 2; // 트랜지스터를 작동
const int timeDelay = 1000; // 지연시간
void setup()
{
pinMode(relayPin, OUTPUT);
}
void loop()
{
digitalWrite(relayPin, HIGH); // 릴레이 작동
delay(timeDelay);
digitalWrite(relayPin, LOW); // 릴레이 정지
delay(timeDelay);
}
