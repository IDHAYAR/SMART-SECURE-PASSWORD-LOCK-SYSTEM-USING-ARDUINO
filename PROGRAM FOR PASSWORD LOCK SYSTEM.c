#include <Keypad.h> 
#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

#define PASSWORD_LENGTH 5 // Enough room for 4 chars + NULL char
#define MAX_ATTEMPTS 3
#define LOCKOUT_PERIOD 1800000 // 30 minutes in milliseconds
#define BUZZER_PIN 11 // Pin for the buzzer

int pos = 0; // Variable to store the servo position

char data[PASSWORD_LENGTH]; // Array for user input
char master[PASSWORD_LENGTH] = "1234"; // Default password
byte data_count = 0;
byte attempt_count = 0; // Counter for failed attempts
unsigned long lockout_start_time = 0; // Start time of lockout
bool is_locked_out = false; // Flag for lockout status
bool doorOpen = false; // Use a boolean to manage door state
bool lcd_on = true; // Flag to manage LCD state

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {1, 2, 3, 4}; // Connect to row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7, 8}; // Connect to column pinouts of the keypad

Keypad customKeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // Initialize Keypad

void setup() {
  pinMode(10, OUTPUT); // Indicator pin
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer pin
  myservo.attach(9);
  servoClose();
  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  displayWelcomeMessage();
}

void loop() {
  unsigned long current_time = millis();

  if (is_locked_out) {
    if (current_time - lockout_start_time >= LOCKOUT_PERIOD) {
      // Lockout period has ended
      is_locked_out = false;
      attempt_count = 0; // Reset attempt counter
      lcd_on = true; // Ensure LCD is turned on
      lcd.clear();
      displayWelcomeMessage(); // Show welcome message after lockout
    } else {
      // Still in lockout period
      if (lcd_on) {
        lcd.clear();
        lcd.print("TOO MANY ATTEMPTS");
        lcd.setCursor(0, 1);
        lcd.print("WAIT 30 MINUTES");
        lcd_on = false; // Set flag to indicate LCD should stay off
      }
      return; // Skip the rest of the loop
    }
  }

  if (doorOpen) {
    handleOpenDoor();
  } else {
    handleClosedDoor();
  }
}

void displayWelcomeMessage() {
  lcd.clear();
  lcd.print("  WELCOME TO  ");
  lcd.setCursor(0, 1);
  lcd.print(" HIDDEN TESLA ");
  delay(3000);
  lcd.clear();
  lcd.print(" ENTER PASSWORD");
}

void clearData() {
  memset(data, 0, PASSWORD_LENGTH); // Clear array using memset
  data_count = 0;
}

void servoOpen() {
  for (pos = 0; pos <= 180; pos += 5) {
    myservo.write(pos);
    delay(15);
  }
}

void servoClose() {
  for (pos = 180; pos >= 0; pos -= 5) {
    myservo.write(pos);
    delay(15);
  }
}

void handleOpenDoor() {
  char customKey = customKeypad.getKey();
  if (customKey) {
    if (customKey == '#') {
      // Close the door
      servoClose();
      lcd.clear();
      lcd.print("DOOR IS CLOSED");
      digitalWrite(10, LOW); // Assuming this pin controls an indicator or similar
      delay(3000);
      doorOpen = false; // Set door state to closed
      lcd.clear();
      displayWelcomeMessage(); // Show welcome message after door closes
    }
  }
}

void handleClosedDoor() {
  char customKey = customKeypad.getKey();
  if (customKey) {
    if (customKey != '#') {
      if (data_count < PASSWORD_LENGTH - 1) {
        data[data_count++] = customKey; // Store character in data array
        lcd.setCursor(data_count - 1, 1); // Move cursor
        lcd.print(customKey); // Display character
      }

      if (data_count == PASSWORD_LENGTH - 1) {
        data[data_count] = '\0'; // Null-terminate the string

        if (strcmp(data, master) == 0) {
          lcd.clear();
          digitalWrite(10, HIGH); // Assuming this pin controls an indicator or similar
          servoOpen();
          lcd.print("DOOR IS OPEN");
          delay(2000);
          lcd.clear();
          lcd.print("PRESS # TO CLOSE");
          lcd.setCursor(0, 1);
          lcd.print("THE DOOR");
          doorOpen = true; // Set door state to open
          clearData(); // Clear the entered data after successful attempt
        } else {
          attempt_count++;

          lcd.clear();
          if (attempt_count < MAX_ATTEMPTS) {
            lcd.print("WRONG PASSWORD!");
            delay(2000);
            lcd.clear();
            lcd.print("  PLEASE");
            lcd.setCursor(0, 1);
            lcd.print(" TRY AGAIN");
            delay(2000);
            clearData(); // Clear the entered data for next attempt
            lcd.clear();
            lcd.print(" ENTER PASSWORD"); // Prompt to enter password again
          } else {
            lcd.clear();
            lcd.print("  TOO MANY");
            lcd.setCursor(0, 1);
            lcd.print("  ATTEMPTS!");
            delay(4000);
            lcd.clear();
            lcd.print("TRY AGAIN LATER");
            delay(5000);
            is_locked_out = true; // Lock out the system
            lockout_start_time = millis(); // Start the lockout timer
            digitalWrite(10, LOW); // Turn off any indicator
            lcd_on = false; // Set flag to indicate LCD should stay off
            
            // Activate buzzer for 10 seconds
            digitalWrite(BUZZER_PIN, HIGH); // Turn on buzzer
            delay(10000); // Buzzer on for 10 seconds
            digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
            
            lcd.clear(); // Clear LCD after displaying the message
            // Continue to skip LCD updates until lockout period is over
          }
        }
      }
    }
  }
}
