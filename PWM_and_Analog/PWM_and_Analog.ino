#define PWM_LED 4   // GPIO 4 used for PWM output (controls LED brightness)
#define ANALOG 7    // Analog input pin (e.g., GPIO 7/A0) for reading sensor or potentiometer value

void setup() {
  pinMode(PWM_LED, OUTPUT);        // Set GPIO 4 as an output for the LED
  ledcAttach(PWM_LED, 2000, 12);   // Attach PWM to GPIO 4 with 2 kHz frequency and 12-bit resolution
  Serial.begin(115200);            // Initialize serial communication at 115200 baud
}

void loop() {
  // Read the analog input value (0–4095 for 12-bit ADC)
  // and send it directly as PWM duty cycle to control LED brightness
  ledcWrite(PWM_LED, analogRead(ANALOG));

  // Print the analog input value to the Serial Monitor
  Serial.println(analogRead(ANALOG));

  delay(50);  // Short delay to smooth updates and reduce serial output frequency
}
