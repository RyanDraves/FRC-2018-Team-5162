/*
 * Drawbridge.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: brrobotics5162
 */


#include "Drawbridge.h"

Drawbridge::Drawbridge(double speed) {
	Requires(Robot::intake.get());

	motorSpeed = speed;
}

void Drawbridge::Initialize() {
}

void Drawbridge::Execute() {
	Robot::intake->RunDrawbridge(motorSpeed);
}

bool Drawbridge::IsFinished() {
	return false;
}

void Drawbridge::End() {
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	Robot::lift->UsePrimaryMotor(motorSpeed / 2.0);
	//Robot::lift->UsePrimaryMotor(0);
}

void Drawbridge::Interrupted() {

}

