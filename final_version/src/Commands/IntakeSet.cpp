/*
 * IntakeSet.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: brrobotics5162
 */

#include "IntakeSet.h"

IntakeSet::IntakeSet(double speed, int buttonNum) {
	Requires(Robot::intake.get());

	motorSpeed = speed;
	button = buttonNum;
	isDone = false;
}

void IntakeSet::Initialize() {
	isDone = false;
}

void IntakeSet::Execute() {
	Robot::intake->RunBothMotors(motorSpeed);
	isDone = true;
}

bool IntakeSet::IsFinished() {
	//return Robot::oi->GetRightStick()->GetRawButtonPressed(button);
	return false;
}

void IntakeSet::End() {
	Robot::intake->RunBothMotors(0);
}

void IntakeSet::Interrupted() {

}


