/*
 * LeftSide.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#include "LeftSide.h"

LeftSide::LeftSide() {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
}

// Called just before this Command runs the first time
void LeftSide::Initialize() {
	counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void LeftSide::Execute() {
	float angle = RobotMap::ahrs->GetAngle();
	if (counter < 300) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, 0);
	}
	else if (counter == 300 && (angle < 88 || angle > 90)) {
		Robot::drivetrain->AutonDrive(-0.5, 0.5, angle);
		counter--;
	}
	else if (counter < 401) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, 90);
	}
	counter++;
	Wait(0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool LeftSide::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LeftSide::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftSide::Interrupted() {}


