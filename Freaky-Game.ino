/*/=============================//
//----Laser Pointer Tripwire----//
///============================///
///--- Baller Mathej | 2025 ---///

  This code is for the ESP32C6-DevKitC6 v1.2
  Should you use other esp32C6 devkit or another chip entirely, please reference the official datasheet for information about avilable pins.

  The pointer can be either a standalone device, or connected to the esp32
  Connecting the pointer makes automatic lighting calibreation possible (wip).
*/

#define CONNECTEDPOINTER 1 //weather the pointer is connected (1 = connected | 0 = NOT connected)

const int pointer = 18; //connection for the laser pointer
const int led = 19;  //connection for the alarm led
const int piezo = 20; //connection for the piezo buzzer
const int photoresistor = 21; //connection for the photoresistor
const int border_brightness = 750;  //controls the brightness at which the alarm goes off

void setup() {
  pinMode(pointer, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(piezo, INPUT);
  pinMode(photoresistor, INPUT);
}

void loop() {
  digitalWrite(pointer, HIGH);
  if (analogRead(photoresistor) < border_brightness) {
    digitalWrite(led, HIGH);
    tone(piezo, 880);// A5
    delay(500);//delay between the beeps
    digitalWrite(led, LOW);
    tone(piezo, 440);// A4
    delay(500);//delay between the beeps
  } else {
    digitalWrite(led, LOW);
    noTone(piezo);
  }

  delay(50); //delay for stability
}