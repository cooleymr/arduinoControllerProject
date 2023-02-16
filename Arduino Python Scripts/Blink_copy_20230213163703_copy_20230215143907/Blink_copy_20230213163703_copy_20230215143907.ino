#include <Keyboard.h>

//INPUTS for buttons
const int butIn1 = 7;
const int butIn2 = 8;
const int butIn3 = 9;
const int butIn4 = 10;
const int butIn5 = 16;
const int butIn6 = 14;

int dialPin = A2;     // Pin connected to the potentiometer dial
int dialValue = 0;    // Variable to store the dial value
int outputValue = 0;  // value read from the pot

const int indiLight1 = 3; //Dial indicator lights
const int indiLight2 = 4;

void setup() {
  pinMode(butIn1, INPUT_PULLUP); //Setting button pinmodes to read
  pinMode(butIn2, INPUT_PULLUP);
  pinMode(butIn3, INPUT_PULLUP);
  pinMode(butIn4, INPUT_PULLUP);
  pinMode(butIn5, INPUT_PULLUP);
  pinMode(butIn6, INPUT_PULLUP);

  pinMode(dialPin, INPUT); // Dial pin reader

  pinMode(3, OUTPUT); //Indicator light output
  pinMode(4, OUTPUT);

  Keyboard.begin(); //Starting keyboard reader
  Serial.begin(9600); //Starting serial reader for dial
}

void loop() {

  readDialValue();

  // wait 2 milliseconds before the next loop for the analog-to-digital converter to settle after the last reading:
  delay(2);

  switch (outputValue) { //Runs different functions depending on dial
    case 0:
      digitalWrite(indiLight1, HIGH); //Turning on/off proper indicator lights
      digitalWrite(indiLight2, LOW);

      if (digitalRead(butIn1) == LOW) {
        openLinkOne();
        Serial.print("Case 0 button 0");
        delay(1000);
      }
      if (digitalRead(butIn2) == LOW) {
        openAppOne();
        Serial.print("Case 0 button 1");
        delay(1000);
      }
      if (digitalRead(butIn3) == LOW) {
        makeCallOne();
        Serial.print("Case 0 button 2");
        delay(1000);
      }
      if (digitalRead(butIn4) == LOW) {
        sendEmailOne();
        Serial.print("Case 0 button 3");
        delay(1000);
      }
      if (digitalRead(butIn5) == LOW) {
        sendIMessageOne();
        Serial.print("Case 0 button 4");
        delay(1000);
      }
      if (digitalRead(butIn6) == LOW) {
        Serial.print("ANOTHER FUNCTION 1");
        Serial.print("Case 0 button 5");
        delay(1000);
      }
      break;

    case 1:
      digitalWrite(indiLight1, LOW);
      digitalWrite(indiLight2, HIGH); 

      if (digitalRead(butIn1) == LOW) {
        openLinkTwo();
        Serial.print("Case 1 button 0");
        delay(1000);
      }
      if (digitalRead(butIn2) == LOW) {
        openAppTwo();
        Serial.print("Case 1 button 1");
        delay(1000);
      }
      if (digitalRead(butIn3) == LOW) {
        makeCallTwo();
        Serial.print("Case 1 button 2");
        delay(1000);
      }
      if (digitalRead(butIn4) == LOW) {
        sendEmailTwo();
        Serial.print("Case 1 button 3");
        delay(1000);
      }
      if (digitalRead(butIn5) == LOW) {
        sendIMessageTwo();
        Serial.print("Case 1 button 4");
        delay(1000);
      }
      if (digitalRead(butIn6) == LOW) {
        Serial.print("ANOTHER FUNCTION 2");
        Serial.print("Case 1 button 5");
        delay(1000);
      }

      break;
    default:
      // run a default function
      break;
  }
}

//Printing dial results to the Serial Monitor
void readDialValue(){
  dialValue = analogRead(dialPin);              // Reading the dial value
  outputValue = map(dialValue, 0, 1023, 0, 2);  // Map the dial value to 0-1
  Serial.print("dialValue = ");
  Serial.print(dialValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
}

//TYPING FUNCTIONS THAT OCCUR ON COMPUTER WITH KEYBOARD

//Opens Terminal
void openTerminal() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(32);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("terminal");
  Keyboard.press(KEY_KP_ENTER);
  delay(500);
  Keyboard.releaseAll();
  delay(750);
}

//Opening links
void openLinkOne() {
  openTerminal();
  Keyboard.print("Python3 openLinkOne.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
void openLinkTwo() {
  openTerminal();
  Keyboard.print("Python3 openLinkTwo.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}

//Opens apps
void openAppOne() {
  openTerminal();
  Keyboard.print("Python3 openAppOne.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
void openAppTwo() {
  openTerminal();
  Keyboard.print("Python3 openAppTwo.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}

//Makes phone calls
void makeCallOne() {
  openTerminal();
  Keyboard.print("Python3 makeCallOne.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
void makeCallTwo() {
  openTerminal();
  Keyboard.print("Python3 makeCallTwo.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}

//Opens black email on Outlook app
void sendEmailOne() {
  openTerminal();
  Keyboard.print("Python3 sendEmailOne.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
void sendEmailTwo() {
  openTerminal();
  Keyboard.print("Python3 sendEmailTwo.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}

//Sends Imessage text
void sendIMessageOne() {
  openTerminal();
  Keyboard.print("Python3 sendImessageOne.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
void sendIMessageTwo() {
  openTerminal();
  Keyboard.print("Python3 sendImessageTwo.py");
  Keyboard.press(KEY_KP_ENTER);
  Keyboard.releaseAll();
}
