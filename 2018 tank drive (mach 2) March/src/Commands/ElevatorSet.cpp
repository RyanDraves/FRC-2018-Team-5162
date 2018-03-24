/*
 * ElevatorSet.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: brrobotics5162
 */


#include "ElevatorSet.h"

ElevatorSet::ElevatorSet(double speed, int buttonNum) {
	Requires(Robot::lift.get());

	motorSpeed = speed;
	button = buttonNum;
	isDone = false;
}

void ElevatorSet::Initialize() {
	isDone = false;
}

void ElevatorSet::Execute() {
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	if ((motorSpeed > 0 && RobotMap::lift_encoder->Get() < 8000) || Robot::oi->GetLeftStick()->GetRawButton(3)) {

	Robot::lift->UsePrimaryMotor(motorSpeed);
	}
	//else if ((motorSpeed < 0 && RobotMap::lift_encoder->Get() > 0) || Robot::oi->GetLeftStick()->GetRawButton(3)) {
	else if (motorSpeed < 0 || Robot::oi->GetLeftStick()->GetRawButton(3)) {
		Robot::lift->UsePrimaryMotor(motorSpeed);
	}
	else {
		Robot::lift->UsePrimaryMotor(0);
	}
	isDone = true;
}

bool ElevatorSet::IsFinished() {
	//return !Robot::oi->GetRightStick()->GetRawButtonPressed(button);
	return false;
}

void ElevatorSet::End() {
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	Robot::lift->UsePrimaryMotor(motorSpeed / 2.0);
	//Robot::lift->UsePrimaryMotor(0);
}

void ElevatorSet::Interrupted() {

}

