/*
 * Lift.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: brrobotics5162
 */

#include "Lift.h"

Lift::Lift() : Subsystem("Lift") {
	primaryMotor = RobotMap::primaryLift;
}

void Lift::InitDefaultCommand() {

}

/*void Lift::GoToHeight(double inputHeight) {
	int ticks = ConvertHeightToTicks(inputHeight);
	//primaryMotor->Set(ControlMode::Position, ticks);
	primaryMotor->Set(0.5);
}*/

void Lift::UsePrimaryMotor(double speed) {
	primaryMotor->Set(speed);
}

int Lift::ConvertHeightToTicks(double inputHeight) {
	int tickSetpoint = 0;
	//tickSetpoint = (inputHeight * 5141); //IF INCHES
	tickSetpoint = (inputHeight * 61692);//IF FEET
	return tickSetpoint;
}

