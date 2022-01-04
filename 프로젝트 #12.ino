/*SHIFT REGISTER */
/*
74HC595 pin LED pin Arduino pin
1 (QB) LED 2 +
2 (QC) LED 3 +
3 (QD) LED 4 +
4 (QE) LED 5 +
5 (QF) LED 6 +
6 (QG) LED 7 +
7 (QH) LED 8 +
8 (GND) GND
9 (QH*)
10 (SRCLR*) 5V
11 (SRCLK) Digital 3
12 (RCLK) Digital 4
13 (OE*) GND
14 (SER) Digital 2
15 (QA) LED 1 +
16 (VCC) 5V
*/

// 74HC595는 SPI(Serial Peripheral Interface)통신을 하는데
// 3개의 핀이 필요하다.
int datapin = 2; //데이터
int clockpin = 3; // 클록
int latchpin = 4; // 랫치(빗장)
byte data = 0; //8비트를 저장하는 공간
void setup()
{
// 3핀 다 출력
pinMode(datapin, OUTPUT);
pinMode(clockpin, OUTPUT);
pinMode(latchpin, OUTPUT);
}

void loop()
{
// Circuit 4번에서 했던 동일한 구성!
oneAfterAnother(); // All on, all off
//oneOnAtATime(); // Scroll down the line
//pingPong(); // Like above, but back and forth
//randomLED(); // Blink random LEDs
//marquee();
//binaryCount(); // 4번보다 추가된 부분 2진수가 증가하는 모양
}

//digitalWrite함수와 비슷한 개념으로 쉬프트 레지스터에 기록
void shiftWrite(int desiredPin, boolean desiredState)
{
// byte 값에 원하는 비트를 설정하는 함수
bitWrite(data,desiredPin,desiredState);
// 쉬프트 레지스터에 값을 보내줌
shiftOut(datapin, clockpin, MSBFIRST, data);
// Most Significant Bit First, 최상위 비트 먼저 레지스터로 보냄
// 쉬프트 레지스터의 빗장을 열어서 출력
// 빗장은 HIGH상태에서 열리고(출력되고) LOW상태로 변경될 때 닫
힘
digitalWrite(latchpin, HIGH);
digitalWrite(latchpin, LOW);
}

//순서대로 전부 켰다가 반대 순서로 꺼짐
void oneAfterAnother()
{
int index;
int delayTime = 100;
for(index = 0; index <= 7; index++)
{
shiftWrite(index, HIGH);
delay(delayTime);
}
for(index = 7; index >= 0; index--)
{
shiftWrite(index, LOW);
delay(delayTime);
}
}

//LED가 한번에 하나씩만 순서대로 켜짐
void oneOnAtATime()
{
int index;
int delayTime = 100; // Time (milliseconds) to pause between LEDs
// Make this smaller for faster switching
for(index = 0; index <= 7; index++)
{
shiftWrite(index, HIGH); // turn LED on
delay(delayTime); // pause to slow down the sequence
shiftWrite(index, LOW); // turn LED off
}
}

/*
pingPong()
This function will step through the LEDs, lighting one at at time,
in both directions.
*/
void pingPong()
{
int index;
int delayTime = 100; // time (milliseconds) to pause between LEDs
// make this smaller for faster switching
oneOnAtATime();
// 반대 순서로 껴짐
for(index = 7; index >= 0; index--)
{
shiftWrite(index, HIGH); // turn LED on
delay(delayTime); // pause to slow down the sequence
shiftWrite(index, LOW); // turn LED off
}
}

// 지맘대로 켜짐
void randomLED()
{
int index;
int delayTime = 100;
index = random(8); // 0 ~ 7사이 임의 값
shiftWrite(index, HIGH); // turn LED on
delay(delayTime); // pause to slow down the sequence
shiftWrite(index, LOW); // turn LED off
}

/*
marquee()
This function will mimic "chase lights" like those around signs.
*/
void marquee()
{
int index;
int delayTime = 200; // Time (milliseconds) to pause between LEDs
// Make this smaller for faster switching
// Step through the first four LEDs
// (We'll light up one in the lower 4 and one in the upper 4)
for(index = 0; index <= 3; index++)
{
shiftWrite(index, HIGH); // Turn a LED on
shiftWrite(index+4, HIGH); // Skip four, and turn that LED on
delay(delayTime); // Pause to slow down the sequence
shiftWrite(index, LOW); // Turn both LEDs off
shiftWrite(index+4, LOW);
}
}

/* 2진수의 증가를 보여줌. 10진수를 shiftOut() 인자로 입력*/
void binaryCount()
{
//data가 0에서 255까지 증가하는 동안 어떻게 LED가 켜지는지 관찰하자
for(data=0; data<256; data++){
shiftOut(datapin, clockpin, MSBFIRST, data);
// 빗장을 연다.
digitalWrite(latchpin, HIGH);
digitalWrite(latchpin, LOW);
delay(1000);
}
}
