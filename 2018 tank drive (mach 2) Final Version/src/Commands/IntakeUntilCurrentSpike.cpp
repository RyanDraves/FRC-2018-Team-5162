/*
 * IntakeUntilCurrentSpike.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */


#include "IntakeUntilCurrentSpike.h"

IntakeUntilCurrentSpike::IntakeUntilCurrentSpike(double time, double speed, bool currentCheck) {
	Requires(Robot::intake.get());
	timer.reset(new frc::Timer());
	timeCurrent = 0;
	currentThreshold = .5;
	isDone = false;
	inputSpeed = speed;
	timeTarget = time;
	timer->Reset();
	timer->Start();
	currentLeft = 0;
	currentRight = 0;
	isCheckingForCurrentSpike = currentCheck;
}

void IntakeUntilCurrentSpike::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
	isCheckingForCurrentSpike = false;
}

void IntakeUntilCurrentSpike::Execute() {
	currentLeft = Robot::intake->GetLeftCurrent();
	currentRight = Robot::intake->GetRightCurrent();
	if(inputSpeed == 0) {
		Robot::intake->RunBothMotors(0);
		isDone = true;
	}
	else {
		timeCurrent = timer->Get();
		if(timeTarget == 0) {
			Robot::intake->RunBothMotors(inputSpeed);
			isDone = false;
		}
		else {
			if(timeCurrent >= timeTarget) {
				Robot::intake->RunBothMotors(0);
				isDone = true;
			}
			else {
				Robot::intake->RunBothMotors(inputSpeed);
				isDone = false;
			}
		}
	}

	if(isCheckingForCurrentSpike) {
		if(currentLeft >= 1 && currentRight >= 1) {
			isDone = true;
			Robot::intake->RunBothMotors(0);
		}
	}
}

bool IntakeUntilCurrentSpike::IsFinished() {
	return isDone;
}

void IntakeUntilCurrentSpike::End() {

}

void IntakeUntilCurrentSpike::Interrupted() {

}

