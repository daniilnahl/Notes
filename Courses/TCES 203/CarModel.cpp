#include "CarModel.h"
#include <cmath>   // std::fmod (optional)

// --------------------
// Motor implementation
// --------------------

Motor::Motor()
    : name("unnamed"), speedPercent(0), enabled(false)
{
    // Nothing else to do.
}

Motor::Motor(const std::string& motorName)
    : name(motorName), speedPercent(0), enabled(false)
{
    // Optional: you may add debug prints while testing, but not required.
}

void Motor::setSpeed(int newSpeedPercent)
{
    // TODO:
    // 1) Clamp newSpeedPercent to the range [-100, 100] using if/else.
    // 2) Store the clamped value in speedPercent.

    // Example style (you should complete it):
    // if (newSpeedPercent > 100) {
    //     speedPercent = 100;
    // } else if (newSpeedPercent < -100) {
    //     speedPercent = -100;
    // } else {
    //     speedPercent = newSpeedPercent;
    // }
    if (newSpeedPercent > 100) speedPercent = 100;
    else if( newSpeedPercent < -100) speedPercent = -100;
    else speedPercent = newSpeedPercent;
}

int Motor::getSpeed() const
{
    // TODO: return the current speedPercent.
    return speedPercent; 
}

void Motor::enable()
{    // TODO: set enabled to true.
    enabled = true;
}

void Motor::disable()
{
    // TODO:
    // 1) set enabled to false
    // 2) set speedPercent to 0.
    enabled = false;
    speedPercent = 0;
}

bool Motor::isEnabled() const
{
    // TODO: return the current enabled flag.
    return enabled; 
}

std::string Motor::getName() const
{
    // TODO: return the motor name.
    return name; // temporary placeholder
}


// -----------------------
// PiCamera implementation
// -----------------------

PiCamera::PiCamera()
    : streaming(false)
{
    // Nothing else to do.
}

void PiCamera::startStream()
{
    streaming = true;
    // TODO: set streaming to true.
}

void PiCamera::stopStream()
{
    // TODO: set streaming to false.
    streaming = false;
}

bool PiCamera::isStreaming() const
{
    // TODO: return streaming.
    return streaming;
}


// ------------------------
// MecanumCar implementation
// ------------------------

MecanumCar::MecanumCar()
    // TODO:
    // Use a member-initialization list to:
    MecanumCar(Motor frontLeft(), Motor frontLeft(), Motor frontLeft(), Motor frontLeft(), PiCamera camera(), double x, double y, double headingDeg)
    :   frontLeft("front-left"),
        frontRight("front-right"),
        rearLeft("rear-left"),
        rearRight("rear-right"),
        camera(),
        x(0.0), y(0.0), headingDeg(0.0)
        
    //  - call the Motor(string) constructor with the appropriate names:
    //      frontLeft("front-left"), frontRight("front-right"),
    //      rearLeft("rear-left"), rearRight("rear-right")
    //  - default-construct the PiCamera
    //  - set x, y, headingDeg to 0.0
    //
    // Example pattern:
    //   : frontLeft("front-left"),
    //     frontRight("front-right"),
    //     rearLeft("rear-left"),
    //     rearRight("rear-right"),
    //     camera(),
    //     x(0.0), y(0.0), headingDeg(0.0)
{
    // Constructor body can be empty once the member-initialization list is complete.
}

void MecanumCar::updatePose(double dx, double dy, double dThetaDeg)
{
    // TODO:
    // 1) Update x and y by adding dx and dy.
    // 2) Update headingDeg by adding dThetaDeg.
    // 3) Make sure headingDeg stays in the range [0, 360).
    //
    //    You can either use std::fmod or simple while logic:
    //      while (headingDeg >= 360.0) headingDeg -= 360.0;
    //      while (headingDeg < 0.0)    headingDeg += 360.0;
}

void MecanumCar::moveForward(double distance)
{
    // TODO: Use updatePose so that the car moves "up" on the map.
    // According to the comment in the header:
    //   - moving forward increases y by distance.
    //
    // After updating the pose, set all four motors to a non-zero
    // positive speed (for example 50) and enable them.
}

void MecanumCar::moveBackward(double distance)
{
    // TODO: moving backward decreases y by distance.
    // Use updatePose(0, -distance, 0).
    // Then configure all four motors with a negative speed (for example -50)
    // and enable them.
}

void MecanumCar::strafeLeft(double distance)
{
    // TODO: strafing left decreases x by distance.
    // Use updatePose(-distance, 0, 0).
    // Then set motor speeds in a pattern that suggests strafing.
}

void MecanumCar::strafeRight(double distance)
{
    // TODO: strafing right increases x by distance.
    // Use updatePose(distance, 0, 0).
}

void MecanumCar::rotateLeft(double angleDeg)
{
    // TODO: rotating left increases headingDeg by angleDeg
    //       (use updatePose with dx = 0, dy = 0).
    // Also set motor speeds in a pattern that suggests rotation.
}

void MecanumCar::rotateRight(double angleDeg)
{
    // TODO: rotating right decreases headingDeg by angleDeg.
}

void MecanumCar::stopAllMotors()
{
    // TODO:
    // 1) set the speed of all four motors to 0.
    // 2) disable all four motors.
}

void MecanumCar::cameraOn()
{
    // TODO: use the PiCamera member to start streaming.
}

void MecanumCar::cameraOff()
{
    // TODO: use the PiCamera member to stop streaming.
}

double MecanumCar::getX() const
{
    // TODO: return x.
    return 0.0; // placeholder
}

double MecanumCar::getY() const
{
    // TODO: return y.
    return 0.0; // placeholder
}

double MecanumCar::getHeadingDeg() const
{
    // TODO: return headingDeg.
    return 0.0; // placeholder
}

Motor MecanumCar::getFrontLeftMotor() const
{
    // TODO: return a copy of frontLeft.
    return Motor(); // placeholder
}

Motor MecanumCar::getFrontRightMotor() const
{
    // TODO: return a copy of frontRight.
    return Motor(); // placeholder
}

Motor MecanumCar::getRearLeftMotor() const
{
    // TODO: return a copy of rearLeft.
    return Motor(); // placeholder
}

Motor MecanumCar::getRearRightMotor() const
{
    // TODO: return a copy of rearRight.
    return Motor(); // placeholder
}