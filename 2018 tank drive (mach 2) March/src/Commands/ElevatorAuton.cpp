/*
 * ElevatorAuton.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: brrobotics5162
 */


#include "ElevatorAuton.h"

ElevatorAuton::ElevatorAuton(double speed, double time) {
	Requires(Robot::lift.get());
	timer.reset(new frc::Timer());
	timeCurrent = 0;
	isDone = false;
	timeTarget = time;
	timer->Reset();
	timer->Start();
	motorSpeed = speed;
	isDone = false;
}

void ElevatorAuton::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void ElevatorAuton::Execute() {
	//if ((motorSpeed > 0 && RobotMap::lift_encoder->Get() < 1000) || Robot::oi->GetLeftStick()->GetRawButton(3)) {
	//}
	//else if ((motorSpeed < 0 && RobotMap::lift_encoder->Get() > 0) || Robot::oi->GetLeftStick()->GetRawButton(3)) {	timeCurrent = timer->Get();
	//}
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	timeCurrent = timer->Get();
	if(timeCurrent >= timeTarget) {
		Robot::lift->UsePrimaryMotor(0);
		isDone = true;
	}
	else {
		Robot::lift->UsePrimaryMotor(motorSpeed);
		isDone = false;
	}
}

bool ElevatorAuton::IsFinished() {
	//return !Robot::oi->GetRightStick()->GetRawButtonPressed(button);
	return isDone;
}

void ElevatorAuton::End() {
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	Robot::lift->UsePrimaryMotor(0);
}

void ElevatorAuton::Interrupted() {

}



