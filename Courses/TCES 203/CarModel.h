#ifndef CAR_MODEL_H
#define CAR_MODEL_H

#include <string>

/*
 * Motor
 * -----
 * Represents a single DC motor driven by an L298N driver.
 * In this simplified model we only track:
 *  - a human-readable name (e.g., "front-left")
 *  - current speed as a percentage in the range [-100, 100]
 *  - whether the motor is enabled
 *
 * Implementation details (e.g., GPIO pins, PWM signals) are HIDDEN.
 */
class Motor {
private:
    std::string name;
    int speedPercent;   // from -100 to +100
    bool enabled;

public:
    // Default constructor:
    //  - name: "unnamed"
    //  - speedPercent: 0
    //  - enabled: false
    Motor();

    // Overloaded constructor:
    //  - initialize the name from the parameter
    //  - start with speed = 0 and enabled = false
    Motor(const std::string& motorName);

    // Mutator: set the motor speed.
    // Clamp the value to the legal range [-100, 100].
    void setSpeed(int newSpeedPercent);

    // Accessor: current speed.
    int getSpeed() const;

    // Mutators: enable / disable the motor.
    void enable();
    void disable();

    // Accessor: is the motor currently enabled?
    bool isEnabled() const;

    // Accessor: motor name.
    std::string getName() const;
};


/*
 * PiCamera
 * --------
 * Represents a very simple Pi Camera module.
 * We only track whether it is streaming or not.
 */
class PiCamera {
private:
    bool streaming;

public:
    // Default constructor:
    //  - streaming: false
    PiCamera();

    void startStream();
    void stopStream();
    bool isStreaming() const;
};


/*
 * MecanumCar
 * ----------
 * This class models a 4-wheel Mecanum car using object composition:
 *
 *  - four Motor objects (front-left, front-right, rear-left, rear-right)
 *  - one PiCamera object
 *
 * It also stores the car pose in a 2D space used by the visualization GUI:
 *
 *  - x, y: Cartesian coordinates in "map units"
 *  - headingDeg: orientation in degrees, where 0 means "facing up" on the map.
 */
class MecanumCar {
private:
    Motor frontLeft;
    Motor frontRight;
    Motor rearLeft;
    Motor rearRight;
    PiCamera camera;

    double x;           // current x position
    double y;           // current y position
    double headingDeg;  // current heading in degrees [0, 360)

    // Private helper:
    // Update pose by adding dx, dy, dTheta (in degrees).
    // Ensure headingDeg stays in the range [0, 360).
    void updatePose(double dx, double dy, double dThetaDeg);

public:
    // Default constructor:
    //  - initialize all motors with the appropriate names
    //    ("front-left", "front-right", "rear-left", "rear-right")
    //  - initialize camera (default constructor)
    //  - set x = 0, y = 0, headingDeg = 0
    MecanumCar();

    // Movement commands – these will be called by the GUI.
    // For this project we use a very simple motion model:
    //
    //  - moveForward(distance): y increases by distance
    //  - moveBackward(distance): y decreases by distance
    //  - strafeLeft(distance): x decreases by distance
    //  - strafeRight(distance): x increases by distance
    //  - rotateLeft(angleDeg): heading increases by angleDeg
    //  - rotateRight(angleDeg): heading decreases by angleDeg
    //
    // All of them should call updatePose(...).
    void moveForward(double distance);
    void moveBackward(double distance);
    void strafeLeft(double distance);
    void strafeRight(double distance);
    void rotateLeft(double angleDeg);
    void rotateRight(double angleDeg);

    // Stops all motors (speed = 0, enabled = false).
    void stopAllMotors();

    // Turn the Pi Camera on/off.
    void cameraOn();
    void cameraOff();

    // Accessors for the GUI to read the pose.
    double getX() const;
    double getY() const;
    double getHeadingDeg() const;

    // Optional accessors that the GUI may use for debug printing.
    Motor getFrontLeftMotor() const;
    Motor getFrontRightMotor() const;
    Motor getRearLeftMotor() const;
    Motor getRearRightMotor() const;
};

#endif // CAR_MODEL_H