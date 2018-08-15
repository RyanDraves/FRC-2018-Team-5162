/*
 * Auton.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: brrobotics5162
 */

#include "Auton.h"
// Another include failure. Oh well.
#include "IntakeUntilCurrentSpike.h"
#include "ElevatorAuton.h"
#include "DrawbridgeAuton.h"

Auton::Auton(std::string commandInput, std::string backupInput, std::string fieldPosition, std::string scale, std::string gameInfo) {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	/*
	 * NOTE: Robot is unable to read input left from the last session when
	 * new code is deployed. Make a fix for this.
	 */
	SmartDashboard::PutString("Last Right", commandInput);
	SmartDashboard::PutString("Last Left", backupInput);
	SmartDashboard::PutString("Last Position", fieldPosition);
	SmartDashboard::PutString("Attempt Scale?", scale);
	SmartDashboard::PutString("Field Data", gameInfo);
	input = commandInput;
	backup = backupInput;
	position = fieldPosition;
	if (scale == "Y") {
		doScale = true;
	}
	else {
		doScale = false;
	}
	gameData = gameInfo;
	index = 0;
	angle = 0;
	firstTime = true;
	sitCount = 0;
	commands.push_back("0");
}

// Called just before this Command runs the first time
void Auton::Initialize() {
	SmartDashboard::PutString("Input Received", input);
	commands.clear();
	index = 0;
	angle = 0;
	firstTime = true;
	std::string next;
	sitCount = 0;
	//if ((position == "1" && gameData[0] == 'L') || (position == "2" && gameData[0] == 'R') || (position == "3" && gameData[0] == 'R')) {
	if (doScale) {
		if ((gameData[1] == 'L' && position == "1") || (gameData[1] == 'R' && position == "3")) {
			for (unsigned int i = 0; i < input.length(); i++) {
				if (input[i] == ',') {
					commands.push_back(next);
					next = "";
				}
				else if (input[i] == ' ') {
					continue;
				}
				else {
					next = next + input[i];
					if (i == input.length() - 1) {
						commands.push_back(next);
					}
				}
			}
		}
		else if ((gameData[0] == 'L' && position == "1") || (gameData[0] == 'R' && position == "3")) {
			for (unsigned int i = 0; i < backup.length(); i++) {
				if (backup[i] == ',') {
					commands.push_back(next);
					next = "";
				}
				else if (backup[i] == ' ') {
					continue;
				}
				else {
					next = next + backup[i];
					if (i == backup.length() - 1) {
						commands.push_back(next);
					}
				}
			}
		}
		else {
			commands.push_back("200");
		}
	}
	else if (gameData[0] == 'R') {
		for (unsigned int i = 0; i < input.length(); i++) {
			if (input[i] == ',') {
				commands.push_back(next);
				next = "";
			}
			else if (input[i] == ' ') {
				continue;
			}
			else {
				next = next + input[i];
				if (i == input.length() - 1) {
					commands.push_back(next);
				}
			}
		}
	}
	else {
		for (unsigned int i = 0; i < backup.length(); i++) {
			if (backup[i] == ',') {
				commands.push_back(next);
				next = "";
			}
			else if (backup[i] == ' ') {
				continue;
			}
			else {
				next = next + backup[i];
				if (i == backup.length() - 1) {
					commands.push_back(next);
				}
			}
		}
	}
}

// Called repeatedly when this Command is scheduled to run
void Auton::Execute() {
	if (index < commands.size()) {
		if (commands[index][commands[index].length()-1] == 't') {
			std::string temp = commands[index];
			temp.pop_back();
			double turnAngle = std::stod(temp);

			if (firstTime) {
				firstTime = false;
				angle += turnAngle;
			}

			double gyroAngle = RobotMap::ahrs->GetAngle();
			if (turnAngle > 0 && gyroAngle < angle - 4) {
				Robot::drivetrain->AutonDrive(-0.65, 0.65, gyroAngle);
			}
			else if (turnAngle < 0 && gyroAngle > angle + 4) {
				Robot::drivetrain->AutonDrive(0.65, -0.65, gyroAngle);
			}
			else {
				index++;
				firstTime = true;
				//Robot::drivetrain->AutonDrive(0, 0, gyroAngle);
			}
		}
		else if (commands[index] == "INTAKE") {
			Command *temp = new IntakeUntilCurrentSpike(1, 0.5, true);
			temp->Start();
			index++;
		}
		else if (commands[index] == "SUPERINTAKE") {
			Command *temp = new IntakeUntilCurrentSpike(1, 1, true);
			temp->Start();
			index++;
		}
		else if (commands[index] == "LIFT") {
			Command *temp = new ElevatorAuton(0.8, 2.8);
			temp->Start();
			index++;
		}
		else if (commands[index] == "UNLIFT") {
			Command *temp = new ElevatorAuton(-0.8, 2.8);
			temp->Start();
			index++;
		}
		else if (commands[index] == "DRAWBRIDGE") {
			Command *temp = new DrawbridgeAuton(-0.5, 1.7);
			temp->Start();
			index++;
		}
		else if (commands[index] == "UNDRAWBRIDGE") {
			Command *temp = new DrawbridgeAuton(0.5, 1.7);
			temp->Start();
			index++;
		}
		else if (commands[index] == "LIFTSIT") {
			sitCount++;
			if (RobotMap::primaryLift->GetSpeed() < 0.1 && sitCount > 100) {
				sitCount = 0;
				index++;
			}
		}
		else {
			if (firstTime) {
				firstTime = false;
				RobotMap::r_encoder->Reset();
				RobotMap::l_encoder->Reset();
			}

			//double distance = Robot::drivetrain->EncoderToInches(RobotMap::r_encoder->Get());
			double r_distance = Robot::drivetrain->EncoderToInches(RobotMap::r_encoder->Get());
			double l_distance = Robot::drivetrain->EncoderToInches(RobotMap::l_encoder->Get());
			double distance = (r_distance + l_distance) / 2;
			if (std::stod(commands[index]) >= 0) {
				if (distance < std::stod(commands[index])) {
					Robot::drivetrain->AutonDrive(-0.8, -0.8, angle);
				}
				else {
					index++;
					firstTime = true;
				}
			}
			else {
				if (distance > std::stod(commands[index])) {
					Robot::drivetrain->AutonDrive(0.8, 0.8, angle);
				}
				else {
					index++;
					firstTime = true;
				}
			}
		}
	}
	Wait(0.005);
}

// Make this return true when this Command no longer needs to run execute()
bool Auton::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Auton::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Auton::Interrupted() {}

