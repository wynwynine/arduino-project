/* 부저로 노래 연주 */
/*
tone()함수는 정해진 주파수로 출력해준다.
도레미파솔라시도에 해당하는 c d e f g a b C로 노래를 연주해 보자.
계명 주파수
도 c 262 Hz
레 d 294 Hz
미 e 330 Hz
파 f 349 Hz
솔 g 392 Hz
라 a 440 Hz
시 b 494 Hz
도 C 523 Hz
*/

const int buzzerPin = 9;
const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf "; // 공백은 쉼표
char beats[] = "111111442111111442";
// tempo : 빠르기, 빨리 연주하려면 값을 줄이자.
int tempo = 150;
void setup()
{
pinMode(buzzerPin, OUTPUT);
}

void loop()
{
int i, duration;
for (i = 0; i < songLength; i++) // step through the song arrays
{
duration = (beats[i]-'0') * tempo; // beats는 수가 아니고 글자로 되어
있다.
//글자 '0'을 빼주면 박자수를 구할 수 있다. ASCII 코드표 참고 할 것.
if (notes[i] == ' ') // 공백은 쉼표
{
delay(duration); // 박자만큼 쉰다
}
else // 아니라면
{
tone(buzzerPin, frequency(notes[i]), duration);
delay(duration); // 박자만큼 연주한다.
}
delay(tempo/10); // 계명사이에 잠깐 멈춘다.
}
  
// 시끄러우니까 한번만 연주하자.
while(true){} //영원히 논다. 실행할 명령 없는 것 무한반복.
}
int frequency(char note)
{
//'a', 'b', 'c', 'd', 'e', 'f', 'g'
int frequencies[] = {440, 494, 262, 294, 330, 349, 392};
//440,494를 앞으로 오게 해서 문자순서로 맞추자
if(note=='C') return (523); // 만약 C라면 523을 돌려주고 함수 종료
//여기에는 else가 필요하지 않다.
return(frequencies[note-'a']); // ASCII 코드표 참고. 숫자로 만들기 위한 쓸데없는 짓.
}
