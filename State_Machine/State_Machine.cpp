#include <Arduino.h>

const int dFlipFlopPins[] = {2, 3, 4, 5}; // Pins connected to D flip-flops
const int prePin = 6; // Preset pin

class DecadeCounter {
public:
    DecadeCounter() {
        current_state = 0;
    }

    void transition() {
        // Define transitions explicitly for a decade counter
        switch (current_state) {
            case 0:
                current_state = 1;
                break;
            case 1:
                current_state = 2;
                break;
            case 2:
                current_state = 3;
                break;
            case 3:
                current_state = 4;
                break;
            case 4:
                current_state = 5;
                break;
            case 5:
                current_state = 6;
                break;
            case 6:
                current_state = 7;
                break;
            case 7:
                current_state = 8;
                break;
            case 8:
                current_state = 9;
                break;
            case 9:
                current_state = 0;
                break;
            default:
                // Handle unexpected state
                break;
        }
    }

    int get_current_state() {
        return current_state;
    }

private:
    int current_state;
};

void displayStateOnLEDs(int state) {
    // Display the binary representation of the state on LEDs
    for (int i = 0; i < 4; ++i) {
        digitalWrite(dFlipFlopPins[i], (state >> i) & 1);
    }
}

DecadeCounter counter;

void setup() {
    for (int i = 0; i < 4; ++i) {
        pinMode(dFlipFlopPins[i], OUTPUT); // Set D flip-flop pins as outputs
    }

    pinMode(prePin, OUTPUT); // Set Preset pin as output
    digitalWrite(prePin, HIGH); // Set Preset pin to HIGH initially
}

void loop() {
    int current_state = counter.get_current_state();

    for (int i = 3; i >= 0; --i) {
        Serial.print((current_state >> i) & 1);
    }

    displayStateOnLEDs(current_state);

    // Add a brief preset pulse to ensure consistent behavior
    digitalWrite(prePin, LOW);
    delay(1);
    digitalWrite(prePin, HIGH);

    counter.transition();

    delay(1000);  // Adjust delay based on your needs
}