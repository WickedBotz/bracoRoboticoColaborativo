#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial serial1(11, 10); // RX, TX

#define SERVO_A 4
#define SERVO_B 5
#define SERVO_C 6
#define SERVO_D 7

Servo servo_a, servo_b, servo_c, servo_d;

String data;
int a = 15, b = 90, c = 90, d = 90, time_servo = 15;

void setup() {
  // put your setup code here, to run once:
  serial1.begin(9600);
  serial1.println("Starting arm...");

  servo_a.attach(SERVO_A);
  servo_b.attach(SERVO_B);
  servo_c.attach(SERVO_C);
  servo_d.attach(SERVO_D);

  servo_a.write(a);
  servo_b.write(b);
  servo_c.write(c);
  servo_d.write(d);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (serial1.available()) {
    data = serial1.readString();
    serial1.println(data);
    char option = data.charAt(0);
    data.remove(0, 1);
    serial1.println(data);
    int var = data.toInt();

    switch (option) {
      case 'a':
        var = constrain(var, 10, 120);
        serial1.print("SERVO_A = ");
        serial1.println(var);
        while (a != var) {
          if (a > var) {
            a--;
          }
          if (a < var) {
            a++;
          }
          servo_a.write(a);
          delay(time_servo);
        }
        break;
      case 'b':
        var = constrain(var, 70, 110);
        serial1.print("SERVO_B = ");
        serial1.println(var);
        while (b != var) {
          if (b > var) {
            b--;
          }
          if (b < var) {
            b++;
          }
          servo_b.write(b);
          delay(time_servo);
        }
        break;
      case 'c':
        var = constrain(var, 0, 140);
        serial1.print("SERVO_C = ");
        serial1.println(var);
        while (c != var) {
          if (c > var) {
            c--;
          }
          if (c < var) {
            c++;
          }
          servo_c.write(c);
          delay(time_servo);
        }
        break;
      case 'd':
        var = constrain(var, 10, 170);
        serial1.print("SERVO_D = ");
        serial1.println(var);
        while (d != var) {
          if (d > var) {
            d--;
          }
          if (d < var) {
            d++;
          }
          servo_d.write(d);
          delay(time_servo);
        }
        break;
    }
  }

}

