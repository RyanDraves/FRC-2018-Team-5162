/*
 * Intake.h
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_SUBSYSTEMS_INTAKE_H_
#define SRC_SUBSYSTEMS_INTAKE_H_

#include "../RobotMap.h"
#include <Commands/Subsystem.h>

class Intake : public frc::Subsystem {
private:
	std::shared_ptr<VictorSP> leftIntake;
	std::shared_ptr<VictorSP> rightIntake;
	std::shared_ptr<Talon> drawbridge;
public:
	Intake();
	void InitDefaultCommand();
	// I trust you can figure this one out
	void RunBothMotors(double power);

	// Breaks up right/left so they can operate separately if needed
	void RunLeftMotor(double power);
	void RunRightMotor(double power);

	// I trust you can figure this one out
	void RunDrawbridge(double power);

	// Gets the current speed of each motor
	double GetLeftCurrent();
	double GetRightCurrent();
};


#endif /* SRC_SUBSYSTEMS_INTAKE_H_ */
