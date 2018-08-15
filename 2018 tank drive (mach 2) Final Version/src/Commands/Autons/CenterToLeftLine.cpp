/*
 * CenterToLeftLine.cpp
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#include "CenterToLeftLine.h"

CenterToLeftLine::CenterToLeftLine() {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
}

// Called just before this Command runs the first time
void CenterToLeftLine::Initialize() {
	counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void CenterToLeftLine::Execute() {
	float angle = RobotMap::ahrs->GetAngle();
	if (counter < 20) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, 0);
	}
	else if (counter == 20 && (angle > -88 || angle < -90)) {
		Robot::drivetrain->AutonDrive(0.5, -0.5, angle);
		counter--;
	}
	else if (counter < 221) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, -90);
	}
	else if (counter == 221 && (angle < -2 || angle > 0)) {
		Robot::drivetrain->AutonDrive(-0.5, 0.5, angle);
		counter--;
	}
	else if (counter < 322) {
		Robot::drivetrain->AutonDrive(-0.5, -0.5, 0);
	}
	counter++;
	Wait(0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool CenterToLeftLine::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CenterToLeftLine::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CenterToLeftLine::Interrupted() {}

