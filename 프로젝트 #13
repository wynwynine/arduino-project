/* LIQUID CRYSTAL DISPLAY (LCD) */
#include <LiquidCrystal.h>
// lcd라는 이름으로 객체를 생성한다.
// 핀의 정보를 지정해 준다.
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
// 우리가 사용하는 LCD는 16글자 2줄을 표현할 수 있다.
lcd.begin(16, 2);
// 마지막 실행할 때 남겨진 글자를 지운다.
lcd.clear();
// 한줄 표시 !
lcd.print("hello, world!");
}

void loop()
{
// 1번째줄(두 번째) 0번째 글자 위치에서 글쓰기 준비
lcd.setCursor(0,1);
// 리셋 이후 시간을 초단위로 표기
// millis() 함수 설명은 아두이노를 위한 C언어에 있음.
lcd.print(millis()/1000);
// 만약 글자를 지우고 싶을 때는 공백을 표시시킨다.
// lcd.setCursor(0,1); // 첫글자 위치로 가서
// lcd.print(" "); // 지우고
// lcd.setCursor(0,1); // 다시 첫글자 위치로 가서
// lcd.print(millis()/1000); // 값을 출력한다.
}
