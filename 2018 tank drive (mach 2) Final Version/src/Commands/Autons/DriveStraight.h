/*
 * DriveStraight.h
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_AUTONS_DRIVESTRAIGHT_H_
#define SRC_COMMANDS_AUTONS_DRIVESTRAIGHT_H_

#include <Commands/Command.h>
#include "../../RobotMap.h"
#include "../../Robot.h"
#include <iostream>

class DriveStraight : public frc::Command {
private:
	double target = 0;
public:
	DriveStraight(double inches);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


#endif /* SRC_COMMANDS_AUTONS_DRIVESTRAIGHT_H_ */
