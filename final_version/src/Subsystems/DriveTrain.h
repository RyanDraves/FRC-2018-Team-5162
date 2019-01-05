/*
 * DriveTrain.h
 *
 *  Created on: Feb 2, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include <Commands/Subsystem.h>
#include "../RobotMap.h"
#include "Commands/TeleopDrive.h"
#include <iostream>

class DriveTrain : public frc::Subsystem {
public:
	DriveTrain();
	void InitDefaultCommand() override;
	
	// Tank drive with the given joystick inputs
	void Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);

	// Autonomously drive with the given speed inputs and desired angle
	// Note: it'll correct itself to maintain that angle! Very nice
	void AutonDrive(double left_speed, double right_speed, double target_angle);

	// Resets the gyro (the compass thing) to have an angle of 0
	void ZeroYaw();

	// Converts encoder units (its measurements) to inches
	double EncoderToInches(double units);
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
