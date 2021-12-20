/*버튼 사용하기 */
const int button1Pin = 2; // 1번 버튼은 2번핀에
const int button2Pin = 3; // 2번 버튼은 3번핀에
const int ledPin = 13; // LED pin은 13번에

void setup()
{
  // 버튼은 인풋!
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  
  // LED는 아웃풋!
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int button1State, button2State; // variables to hold the pushbutton states
  
button1State = digitalRead(button1Pin);
button2State = digitalRead(button2Pin);
  
// 버튼은 눌리면 LOW, 안눌리면 HIGH
// 접지(땅에 연결, 보통 음극)
  
// A == B 는 A와 B의 값이 같다
// A && B 는 A도 참 B도 참이면 참 . "그리고"
// A || B 는 A 또는 B가 참이면 참. "또는"
// !A 는 A가 참이면 거짓, 거짓이면 참. "아님"
  
if (((button1State == LOW) || (button2State == LOW)) // 버튼 둘중 하나가 눌렸고
&& !
((button1State == LOW) && (button2State == LOW))) // 동시에 눌린 상태가 아니라면
{ // 여기서
digitalWrite(ledPin, HIGH); // turn the LED on
} //여기 까지 하고
else //아니라면
{
digitalWrite(ledPin, LOW); // 꺼라
}
  
}
