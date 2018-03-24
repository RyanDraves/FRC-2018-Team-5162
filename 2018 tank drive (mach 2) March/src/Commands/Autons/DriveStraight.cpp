/*
 * DriveStraight.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#include "DriveStraight.h"

DriveStraight::DriveStraight(double inches) {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	target = inches;
}

// Called just before this Command runs the first time
void DriveStraight::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute() {
	double distance = Robot::drivetrain->EncoderToInches(RobotMap::r_encoder->Get());
	if (distance < target) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, 0);
	}
	Wait(0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveStraight::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted() {}
