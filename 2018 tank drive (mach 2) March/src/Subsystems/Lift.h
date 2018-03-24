/*
 * Lift.h
 *
 *  Created on: Feb 10, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_SUBSYSTEMS_LIFT_H_
#define SRC_SUBSYSTEMS_LIFT_H_


#include "../RobotMap.h"
#include <Commands/Subsystem.h>
#include "WPILib.h"

class Lift : public frc::Subsystem {
private:
	std::shared_ptr<PWMTalonSRX> primaryMotor;
public:
	Lift();
	void InitDefaultCommand();
	//void GoToHeight(double inputHeight);
	void UsePrimaryMotor(double speed);
	int ConvertHeightToTicks(double inputHeight);
};


#endif /* SRC_SUBSYSTEMS_LIFT_H_ */
