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
	void Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);
	void AutonDrive(double left_speed, double right_speed, double target_angle);
	void ZeroYaw();
	double EncoderToInches(double units);
};

#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
