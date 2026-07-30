// Positive degrees = right; negative degrees = left.
class Car {
  const byte LE=9, LF=12, LB=11, RE=3, RF=8, RB=7;

  void set(byte lf, byte lb, byte rf, byte rb, byte ls, byte rs) {
    digitalWrite(LF, lf); digitalWrite(LB, lb);
    digitalWrite(RF, rf); digitalWrite(RB, rb);
    analogWrite(LE, ls);  analogWrite(RE, rs);
  }

public:
  float metresPerSecond = .25, degreesPerSecond = 100;
  byte driveSpeed = 255, turnSpeed = 255;

  void begin() {
    for (byte pin : {LE, LF, LB, RE, RF, RB}) pinMode(pin, OUTPUT);
    stop();
  }

  void driveForwardMetres(float metres) {
    set(HIGH, LOW, HIGH, LOW, driveSpeed, driveSpeed);
    delay(metres / metresPerSecond * 1000);
    stop();
  }

  void turnDegrees(float degrees) {
    if (degrees > 0) set(HIGH, LOW, LOW, LOW, turnSpeed, 0); // right
    else             set(LOW, LOW, HIGH, LOW, 0, turnSpeed); // left
    delay((degrees > 0 ? degrees : -degrees) / degreesPerSecond * 1000);
    stop();
  }

  void stop() { set(LOW, LOW, LOW, LOW, 0, 0); }
};

Car car;
struct Step { float metres, degrees; };

// {drive metres, turn degrees}; positive degrees = right.
Step route[] = {
  {0.75, 90}, {0.75, 100}, {0.75, 75}, {0.75, 0}
};

void setup() { car.begin(); }

void loop() {
  for (Step step : route) {
    car.driveForwardMetres(step.metres);
    if (step.degrees) car.turnDegrees(step.degrees);
  }
  delay(5000);
}
