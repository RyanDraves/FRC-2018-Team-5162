/*
 * DriveTrain.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: brrobotics5162
 */

#include "DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TeleopDrive());
}

void DriveTrain::Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right) {
	SmartDashboard::PutNumber("Angle", RobotMap::ahrs->GetAngle());
	SmartDashboard::PutNumber("R_Encoder Units", RobotMap::r_encoder->Get());
	SmartDashboard::PutNumber("L_Encoder Units", RobotMap::l_encoder->Get());
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
	double left_speed = left->GetRawAxis(1);
	double right_speed = right->GetRawAxis(1);
	if (left->GetRawButton(1)) {
		left_speed /= 1.25;
	}
	if (right->GetRawButton(1)) {
		right_speed /= 1.25;
	}
	RobotMap::robot_drive->TankDrive(right_speed, left_speed, true);

	Wait(0.005);
}

void DriveTrain::AutonDrive(double left_speed, double right_speed, double target_angle) {
	left_speed /= 2;
	right_speed /= 2;

	double angle = RobotMap::ahrs->GetAngle();
	double diff = target_angle - angle;
	double dashboardAngle = (double)((int)angle % 360);
	dashboardAngle += angle - (int)angle;
	if (dashboardAngle < 180) {
		dashboardAngle -= 360;
	}
	else if (dashboardAngle < -180) {
		dashboardAngle += 360;
	}
	SmartDashboard::PutNumber("Angle", dashboardAngle);
	SmartDashboard::PutNumber("Error", diff);
	if (diff > 2.0) {
		RobotMap::robot_drive->TankDrive(right_speed + 0.05, left_speed * 1.13, false);
	}
	else if (diff < -2.0) {
		RobotMap::robot_drive->TankDrive(right_speed, (left_speed * 1.13) + 0.05, false);
	}
	else if (diff > 0.1) {
		RobotMap::robot_drive->TankDrive(right_speed + 0.01, left_speed * 1.13, false);
	}
	else if (diff < -0.1) {
		RobotMap::robot_drive->TankDrive(right_speed, (left_speed * 1.13) + 0.01, false);
	}
	else {
		RobotMap::robot_drive->TankDrive(right_speed, left_speed * 1.13, false);
	}

	SmartDashboard::PutNumber("Right Speed", RobotMap::l_motor->GetSpeed());
	SmartDashboard::PutNumber("Left Speed", RobotMap::r_motor->GetSpeed());
	SmartDashboard::PutNumber("R_Encoder Units", RobotMap::r_encoder->Get());
	SmartDashboard::PutNumber("L_Encoder Units", RobotMap::l_encoder->Get());
	SmartDashboard::PutNumber("Lift Enc. Units", RobotMap::lift_encoder->Get());
}

void DriveTrain::ZeroYaw() {
	RobotMap::ahrs->ZeroYaw();
}

double DriveTrain::EncoderToInches(double units) {
	return 0.00621 * units;
}
