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
	//std::shared_ptr<Spark> primaryMotor;
public:
	Lift();
	void InitDefaultCommand();
	//void GoToHeight(double inputHeight);

	// Sets the lift motor to a given speed (-1.0 to 1.0)
	void UsePrimaryMotor(double speed);
	
	// Converts feets to encoder ticks (how the encoder measures distance)
	int ConvertHeightToTicks(double inputHeight);
};


#endif /* SRC_SUBSYSTEMS_LIFT_H_ */
