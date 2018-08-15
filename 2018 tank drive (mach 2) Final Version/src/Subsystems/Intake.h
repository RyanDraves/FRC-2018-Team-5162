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
	void RunBothMotors(double power);
	void RunLeftMotor(double power);
	void RunRightMotor(double power);
	void RunDrawbridge(double power);
	double GetLeftCurrent();
	double GetRightCurrent();
};


#endif /* SRC_SUBSYSTEMS_INTAKE_H_ */
