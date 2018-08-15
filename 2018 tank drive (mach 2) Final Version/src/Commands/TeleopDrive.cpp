/*
 * TeleopDrive.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: brrobotics5162
 */

#include "TeleopDrive.h"
/*
 * Throughout each of the source files, I tried to keep includes limited to only
 * the respective header file, and leave the includes I needed in said header file.
 * For some reason not worth investigation, the compiler fails to recognize the
 * "DriveTrain" subsystem as a class if it's included in "TeleopDrive.h". There's
 * probably a deep-rooted issue in my include methodology and compilation order,
 * but the important thing to know is that working > organization.
 */
#include "../Robot.h"

TeleopDrive::TeleopDrive() {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void TeleopDrive::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void TeleopDrive::Execute() {
	Robot::drivetrain->Drive(Robot::oi->GetLeftStick(), Robot::oi->GetRightStick());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDrive::Interrupted() {

}
