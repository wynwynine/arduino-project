/*PHOTO RESISTOR */

const int sensorPin = 0;
const int ledPin = 9;

int lightLevel;

void setup()
{

pinMode(ledPin, OUTPUT);
}

void loop()
{
lightLevel = analogRead(sensorPin);

manualTune(); // manually change the range from light to
dark

analogWrite(ledPin, lightLevel);
}

void manualTune()
{
lightLevel = map(lightLevel, 0, 1023, 255, 0);
lightLevel = constrain(lightLevel, 0, 255);
} 
