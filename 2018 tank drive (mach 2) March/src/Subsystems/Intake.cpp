/*
 * Intake.cpp
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */

#include "Intake.h"

Intake::Intake() : Subsystem("Intake") {
	leftIntake = RobotMap::leftIntake;
	rightIntake = RobotMap::rightIntake;
}

void Intake::InitDefaultCommand() {

}

void Intake::RunBothMotors(double power) {
	RunLeftMotor(power);
	RunRightMotor(-power);
}

void Intake::RunLeftMotor(double power) {
	leftIntake->Set(power);
}

void Intake::RunRightMotor(double power) {
	rightIntake->Set(power);
}

double Intake::GetLeftCurrent() {
	return leftIntake->Get();
}

double Intake::GetRightCurrent() {
	return rightIntake->Get();
}

