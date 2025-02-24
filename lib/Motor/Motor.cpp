#include "Motor.h"

Motor::Motor() {
  // Initialize motor control pins as outputs using PinDef values
  pinMode(PinDef::ENA, OUTPUT);
  pinMode(PinDef::ENB, OUTPUT);
  pinMode(PinDef::IN1, OUTPUT);
  pinMode(PinDef::IN2, OUTPUT);
  pinMode(PinDef::IN3, OUTPUT);
  pinMode(PinDef::IN4, OUTPUT);
  
  // Start with motors off
  digitalWrite(PinDef::IN1, LOW);
  digitalWrite(PinDef::IN2, LOW);
  digitalWrite(PinDef::IN3, LOW);
  digitalWrite(PinDef::IN4, LOW);
  analogWrite(PinDef::ENA, 0);
  analogWrite(PinDef::ENB, 0);
}

void Motor::enable() {
  // Reset motor control pins to an inactive state
  digitalWrite(PinDef::IN1, LOW);
  digitalWrite(PinDef::IN2, LOW);
  digitalWrite(PinDef::IN3, LOW);
  digitalWrite(PinDef::IN4, LOW);
  analogWrite(PinDef::ENA, 0);
  analogWrite(PinDef::ENB, 0);
}

void Motor::disable() {
  // Stop the motors and disable outputs
  digitalWrite(PinDef::IN1, LOW);
  digitalWrite(PinDef::IN2, LOW);
  digitalWrite(PinDef::IN3, LOW);
  digitalWrite(PinDef::IN4, LOW);
  analogWrite(PinDef::ENA, 0);
  analogWrite(PinDef::ENB, 0);
}

void Motor::left(int pwm) {
  // Control the left motor (controlled by IN1/IN2 and ENA)
  if (pwm >= 0) {
    // Forward: IN1 HIGH, IN2 LOW
    digitalWrite(PinDef::IN1, HIGH);
    digitalWrite(PinDef::IN2, LOW);
    analogWrite(PinDef::ENA, pwm);
  } else {
    // Reverse: IN1 LOW, IN2 HIGH
    digitalWrite(PinDef::IN1, LOW);
    digitalWrite(PinDef::IN2, HIGH);
    analogWrite(PinDef::ENA, -pwm);
  }
}

void Motor::right(int pwm) {
  // Control the right motor (controlled by IN3/IN4 and ENB)
  if (pwm >= 0) {
    // Forward: IN3 LOW, IN4 HIGH
    digitalWrite(PinDef::IN3, LOW);
    digitalWrite(PinDef::IN4, HIGH);
    analogWrite(PinDef::ENB, pwm);
  } else {
    // Reverse: IN3 HIGH, IN4 LOW
    digitalWrite(PinDef::IN3, HIGH);
    digitalWrite(PinDef::IN4, LOW);
    analogWrite(PinDef::ENB, -pwm);
  }
}

void Motor::brake() {
  // Engage active braking by setting all motor control pins HIGH
  digitalWrite(PinDef::IN1, HIGH);
  digitalWrite(PinDef::IN2, HIGH);
  digitalWrite(PinDef::IN3, HIGH);
  digitalWrite(PinDef::IN4, HIGH);
  
  // Ensure PWM outputs are off
  analogWrite(PinDef::ENA, 0);
  analogWrite(PinDef::ENB, 0);
  // Optionally, add a delay if you want the brake to engage for a set period:
  // delay(500);
}
