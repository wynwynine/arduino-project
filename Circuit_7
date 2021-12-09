/* TEMPERATURE SENSOR */
const int temperaturePin = 0;


void setup()
{
  Serial.begin(9600); //시리얼 모니터를 사용하게 한다.
  // 전송 속도는  9600bps로 세팅
}


void loop()
{
  // float는 소수점을 가진 숫자를 저장할 수 있다.

  float voltage, degreesC, degreesF;

  // getVoltage() 전압을 읽어 들인다.


  voltage = getVoltage(temperaturePin);
  
  // 온도센서의 공식에 따라서 전압을 온도로 변환 시킨다.

  degreesC = (voltage - 0.5) * 100.0;
  
  // 화씨온도로 변환 시킨다. 
  
  degreesF = degreesC * (9.0/5.0) + 32.0;
  
  // 시리얼 모니터는 아두이노 프로그램 오른쪽 위에 돋보기 모양 
  // 아이콘을 클릭하면 실행된다.
  // 시리얼 모니터 아래쪽에 전송속도를  9600으로 맞추자


  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF); //println ( print line ) 마지막에 줄을 바꾼다.

  // 이런 식으로 출력 된다.
  // "voltage: 0.73 deg C: 22.75 deg F: 72.96"
  
  delay(1000); // 1초에 한번씩, 맘대로 바뀌보자
}


float getVoltage(int pin)
{  
  return (analogRead(pin) * 0.00488759);
    //0.00488759 = 5/ 1023를 미리 계산 한 값이다.   
}
