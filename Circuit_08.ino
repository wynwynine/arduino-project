/* Example sketch 08 SINGLE SERVO */

#include <Servo.h>  // servo 라이브로리를 사용한다.


Servo servo1;  // 서보 모터 제어를 위한 객체변수 생성


void setup()
{
  servo1.attach(9); //9번 핀에 서보 모터를 연결
}

void loop()
{
  int position;  

  servo1.write(90);    // 90도로 서보 모터 이동, 
  // 이동 가능 각도는 보통 0~180이지만 모터마다 다르다.

  delay(1000);         // 실제로 움직일 때 까지 기다린다.

  servo1.write(170);   // 170도로 서보 모터 이동

  delay(1000);         // 실제로 움직일 때 까지 기다린다.

  servo1.write(10);     // 10도로 서보 모터 이동

  delay(1000);         // 실제로 움직일 때 까지 기다린다.
  
 
  for(position = 10; position < 170; position += 2)
  {
    servo1.write(position);  // 다음 위치 까지 이동
    delay(20);               // 약간 기다림
  }

  for(position = 170; position >= 10; position -= 1) //거꾸로 움직이자
  {                                
    servo1.write(position);  
    delay(20);               
  }
}
