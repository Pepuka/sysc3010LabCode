/*
  Sysc 3010 lab 3 part 4d
*/

#define var_resistor A0

int var_resistor_value;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  var_resistor_value = analogRead(var_resistor);  // read the value from the variable resistor
  Serial.println(var_resistor_value);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
  digitalWrite(LED_BUILTIN, LOW);
  delay(var_resistor_value);         // wait the amount of time read from the variable resistor
}
