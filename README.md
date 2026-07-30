We have our Class which is named 'Car' with our most important functions inside this class. We made the pins controlling the motors unable to be changed, even though nobody would even want to change
that.

We do not have a constructor for our Class, our 2 functions in our class are:
car.driveForwardMetres(1.0);
and
car.turnDegrees(step.degrees);

The former controls the amount of distance travelled by the car, which is measured in meters, the latter controls the degrees the car turns. Converting these from the normal analog.write()
needed the car to be calibrated because distance and turns are heavily influenced by the environment and the mass of the car itself.

Step route[] = {
  {0.75, 90}, {0.75, 100}, {0.75, 75}, {0.75, 0} 
};

Controls the amount of degrees turned and the amount of distance travelled throughout 4 separate junctions, which are made possible by the functions above.

The former value controls the amount of distance the car travels, which is measured in meters, while the latter value controls the angle the car turns, with a negative value
turning left, and a positive value right.

After completing a successful circuit, the car would wait for 5 seconds before looping the circuit.


Note: Pull off L298N Jumper Caps, or the motor speed would not be controllable.
