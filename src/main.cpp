/**
 * @file Ultrasonic_Servo_Control.ino
 * @author Ashish Kumar Yadav
 * @date 2026-02-20
 * @version 1.0
 *
 * @brief Controls a servo motor using an ultrasonic distance sensor.
 *
 * @details
 * This program uses an HC-SR04 ultrasonic sensor to measure distance.
 * If the detected object is within 5 cm, the servo rotates to 180°.
 * Otherwise, the servo resets to 0°.
 *
 * Hardware Used:
 * - Ultrasonic Sensor (HC-SR04)
 * - Servo Motor
 *
 * Connections:
 * - Trig Pin → Digital 9
 * - Echo Pin → Digital 10
 * - Servo Signal → Digital 5
 *
 * @note
 * Ensure proper power supply to servo motor to avoid unstable behavior.
 *
 * @warning
 * Continuous rapid movement may reduce servo lifespan.
 */

#include <Arduino.h>
#include <Servo.h>

/** @brief Servo motor object */
Servo MYSERVO;

/** @brief Ultrasonic sensor trigger pin */
#define TRIG_PIN 9

/** @brief Ultrasonic sensor echo pin */
#define ECHO_PIN 10

/** @brief Servo control pin */
#define SERVO_PIN 5


/**
 * @brief Initializes pins, servo, and serial communication.
 */
void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  MYSERVO.attach(SERVO_PIN);
  Serial.begin(9600);
}


/**
 * @brief Main loop function.
 *
 * @details
 * Sends ultrasonic pulse, calculates distance,
 * and rotates servo based on threshold (5 cm).
 */
void loop()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);      ///< Echo time in microseconds
  long distance = (duration * 0.0343) / 2;      ///< Distance in cm

  if (distance <= 5)
  {
    MYSERVO.write(180);   ///< Rotate servo
  }
  else
  {
    MYSERVO.write(0);     ///< Reset servo
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}