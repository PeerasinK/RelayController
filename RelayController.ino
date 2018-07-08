// #Define constants of pin number
const int LIVINGROOM_PIN_NO = 12;
const int BEDROOM_PIN_NO = 13;

// #Define contants of light id
// digit 1 -> floor [1,2]
// digit 2 -> room [1=livingroom, 2=Bedroom, 3=bathroom, 4=utility room, 5=outdoor]
// digit 3,4 -> numbrt [00-99]
const int LIVINGROOM_01_ID = 1101;
const int LIVINGROOM_02_ID = 2101;
const int BEDROOM_01_ID = 2201;
const int BEDROOM_02_ID = 2202;
const int BEDROOM_03_ID = 2203;
const int BATHROOM_01_ID = 1301;
const int BATHROOM_02_ID = 2301;
const int UTILROOM_01_ID = 1401;
const int UTILROOM_02_ID = 2401;
const int OUTDOOR_01_ID = 1501;
const int OUTDOOR_02_ID = 1502;
const int OUTDOOR_03_ID = 1503;
const int OUTDOOR_04_ID = 1504;


// Setup all pin
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Define to pin to output
  pinMode(LIVINGROOM_PIN_NO, OUTPUT);
  pinMode(BEDROOM_PIN_NO, OUTPUT);

  // Finish setup
  while (!Serial);
  Serial.println("Setup done");
}

// Run over and over
void loop()
{
  if (Serial.available())
  {
    // Gets input
    int input = Serial.parseInt();

    switch (input) {
      // Livingroom
      case LIVINGROOM_01_ID: trigger(LIVINGROOM_PIN_NO); break;
      
      // Bedroom
      case BEDROOM_01_ID: trigger(BEDROOM_PIN_NO); break;
      
      // Default -> Do nothing
      default: break;
    }
  }
}

// Turn On/Off the light
void trigger(int pinNo)
{
  // If On then turn off, otherwise turn on
  if (digitalRead(pinNo) == LOW) digitalWrite(pinNo, HIGH);
  else digitalWrite(pinNo, LOW);
}

