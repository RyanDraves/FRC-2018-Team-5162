/*
 * DrawbridgeAuton.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: brrobotics5162
 */


#include "DrawbridgeAuton.h"

DrawbridgeAuton::DrawbridgeAuton(double speed, double time) {
	Requires(Robot::intake.get());
	timer.reset(new frc::Timer());
	timeCurrent = 0;
	isDone = false;
	timeTarget = time;
	timer->Reset();
	timer->Start();
	motorSpeed = speed;
	isDone = false;
}

void DrawbridgeAuton::Initialize() {
	isDone = false;
	timeCurrent = 0;
	timer->Reset();
	timer->Start();
}

void DrawbridgeAuton::Execute() {
	timeCurrent = timer->Get();
	double clockTest = Timer::GetFPGATimestamp();
	SmartDashboard::PutNumber("Time", clockTest);
	if(timeCurrent >= timeTarget || clockTest < 1) {
		Robot::intake->RunDrawbridge(0);
		isDone = true;
	}
	else {
		Robot::intake->RunDrawbridge(motorSpeed);
		isDone = false;
	}
}

bool DrawbridgeAuton::IsFinished() {
	return isDone;
}

void DrawbridgeAuton::End() {
	Robot::intake->RunDrawbridge(0);
}

void DrawbridgeAuton::Interrupted() {

}

