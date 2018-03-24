/*
 * Auton.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: brrobotics5162
 */

#include "Auton.h"
// Another include failure. Oh well!
#include "IntakeUntilCurrentSpike.h"
#include "ElevatorAuton.h"

Auton::Auton(std::string commandInput, std::string backupInput, std::string fieldPosition, std::string gameInfo) {
	Requires(Robot::drivetrain.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	/*
	 * NOTE: Robot is unable to read input left from the last session when
	 * new code is deployed. Make a fix for this.
	 */
	SmartDashboard::PutString("Last Auton", commandInput);
	SmartDashboard::PutString("Last Backup", backupInput);
	SmartDashboard::PutString("Last Position", fieldPosition);
	SmartDashboard::PutString("Field Data", gameInfo);
	input = commandInput;
	backup = backupInput;
	position = fieldPosition;
	gameData = gameInfo;
	index = 0;
	angle = 0;
	firstTime = true;
	commands.push_back("0");
}

// Called just before this Command runs the first time
void Auton::Initialize() {
	SmartDashboard::PutString("Input received:", input);
	commands.clear();
	index = 0;
	angle = 0;
	firstTime = true;
	std::string next;
	//if ((position == "1" && gameData[0] == 'L') || (position == "2" && gameData[0] == 'R') || (position == "3" && gameData[0] == 'R')) {
	if (gameData[0] == 'R') {
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
				Robot::drivetrain->AutonDrive(-0.5, 0.5, gyroAngle);
			}
			else if (turnAngle < 0 && gyroAngle > angle + 4) {
				Robot::drivetrain->AutonDrive(0.5, -0.5, gyroAngle);
			}
			else {
				index++;
				firstTime = true;
				//Robot::drivetrain->AutonDrive(0, 0, gyroAngle);
			}
		}
		else if (commands[index] == "INTAKE") {
			Command *temp = new IntakeUntilCurrentSpike(0.5, 0.5, true);
			temp->Start();
			index++;
		}
		else if (commands[index] == "LIFT") {
			Command *temp = new ElevatorAuton(0.8, 2);
			temp->Start();
			index++;
		}
		else if (commands[index] == "UNLIFT") {
			Command *temp = new ElevatorAuton(-0.8, 2);
			temp->Start();
			index++;
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
					Robot::drivetrain->AutonDrive(-0.7, -0.7, angle);
				}
				else {
					index++;
					firstTime = true;
				}
			}
			else {
				if (distance > std::stod(commands[index])) {
					Robot::drivetrain->AutonDrive(0.7, 0.7, angle);
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

