/*
 * RightSide.h
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_AUTONS_RIGHTSIDE_H_
#define SRC_COMMANDS_AUTONS_RIGHTSIDE_H_

#include <Commands/Command.h>
#include "../../RobotMap.h"
#include "../../Robot.h"
#include <iostream>

class RightSide : public frc::Command {
private:
	int counter = 0;
public:
	RightSide();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


#endif /* SRC_COMMANDS_AUTONS_RIGHTSIDE_H_ */
