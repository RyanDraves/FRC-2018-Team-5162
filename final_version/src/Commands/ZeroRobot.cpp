/*
 * ZeroRobot.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */


#include "ZeroRobot.h"

ZeroRobot::ZeroRobot() {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	timer.reset(new frc::Timer());
	timer->Reset();
	timer->Start();
}

// Called just before this Command runs the first time
void ZeroRobot::Initialize() {
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void ZeroRobot::Execute() {
	// This is commented out because the command is dangerous and should not be used
	// without a PID Loop (see ZeroRobot.h and Google "PID Loop")

	/*
	double m_angle = (int)RobotMap::ahrs->GetAngle() % 360;
	if ((m_angle < 180 && m_angle > 0) || m_angle < -180) {
		Robot::drivetrain->AutonDrive(0.9, -0.9, RobotMap::ahrs->GetAngle());
	}
	else {
		Robot::drivetrain->AutonDrive(-0.9, 0.9, RobotMap::ahrs->GetAngle());
	}*/
}

// Make this return true when this Command no longer needs to run execute()
bool ZeroRobot::IsFinished() {
	return true;

	// This is part of disabling the command; read above.
	// Once it's fixed, remove the above "return true;" and uncomment the below segment.

	/*
	if ((int)RobotMap::ahrs->GetAngle() % 360 < 2 && (int)RobotMap::ahrs->GetAngle() % 360 > -2) {
		return true;
	}
	else if (timer->Get() >= 1) {
		return true;
	}
	return false;*/
}

// Called once after isFinished returns true
void ZeroRobot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ZeroRobot::Interrupted() {

}


