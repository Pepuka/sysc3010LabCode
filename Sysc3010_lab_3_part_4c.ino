/*
  Variable Delay Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  modified 25 Sep 2019
  by Scott Malonda
*/

#define var_resistor A0

int var_resistor_value;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  var_resistor_value = analogRead(var_resistor);  // read the value from the variable resistor
  digitalWrite(LED_BUILTIN, HIGH);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
  digitalWrite(LED_BUILTIN, LOW);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
}
