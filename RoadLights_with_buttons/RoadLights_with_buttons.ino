#define RED 4        // GPIO 4 connected to the red light
#define YELLOW 5     // GPIO 5 connected to the yellow light
#define GREEN 6      // GPIO 6 connected to the green light
#define BUTTON1 7    // GPIO 7 connected to button 1
#define BUTTON2 15   // GPIO 15 connected to button 2

int Time = 100;      // Variable to store delay time for light changes (in milliseconds)

void setup() {
  pinMode(RED, OUTPUT);           // Set red light pin as output
  pinMode(YELLOW, OUTPUT);        // Set yellow light pin as output
  pinMode(GREEN, OUTPUT);         // Set green light pin as output
  pinMode(BUTTON1, INPUT_PULLUP); // Set button 1 pin as input with internal pull-up resistor
  pinMode(BUTTON2, INPUT_PULLUP); // Set button 2 pin as input with internal pull-up resistor
}

void loop() {
  // Adjust delay time based on button states:
  // BUTTON1 released & BUTTON2 pressed → Time = 200 ms
  if (digitalRead(BUTTON1) == 1 && digitalRead(BUTTON2) == 0) {
    Time = 200;
  } 
  // BUTTON1 pressed & BUTTON2 released → Time = 100 ms
  else if (digitalRead(BUTTON1) == 0 && digitalRead(BUTTON2) == 1) {
    Time = 100;
  } 
  // Both BUTTON1 and BUTTON2 pressed → Time = 50 ms
  else if (digitalRead(BUTTON1) == 0 && digitalRead(BUTTON2) == 0) {
    Time = 50;
  }

  // Step 1: Red ON, Yellow OFF, Green OFF (Stop)
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(Time);  
  
  // Step 2: Red ON, Yellow ON, Green OFF (Get ready)
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(Time);  
  
  // Step 3: Red OFF, Yellow OFF, Green ON (Go)
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(Time);  
  
  // Step 4: Red OFF, Yellow ON, Green OFF (Prepare to stop)
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(Time);  
}
