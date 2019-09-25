/*
  Sysc 3010 lab 3 part 4e
*/

#include <MsTimer2.h>
#define var_resistor A0

int var_resistor_value;

//Function Prototype
void readVariableResistor();

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // start the serial port with 115200 bits per second
  Serial.begin(115200);

  // Configure timer2 interrupt to happen every 20ms, calling readVariableResistor each time
  MsTimer2::set(20, readVariableResistor);
  // Starts timer2
  MsTimer2::start();
}

// the loop function runs over and over again forever
void loop() {
  var_resistor_value = analogRead(var_resistor);  // read the value from the variable resistor
  digitalWrite(LED_BUILTIN, HIGH);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
  digitalWrite(LED_BUILTIN, LOW);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
}

void readVariableResistor() {
  //Read the analog value of the variable resistor and print it on the serial port
  var_resistor_value = analogRead(var_resistor);
  Serial.println(var_resistor_value);
}
