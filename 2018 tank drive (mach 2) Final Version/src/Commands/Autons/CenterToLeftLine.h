/*
 * CenterToLeftLine.h
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_AUTONS_CENTERTOLEFTLINE_H_
#define SRC_COMMANDS_AUTONS_CENTERTOLEFTLINE_H_

#include <Commands/Command.h>
#include "../../RobotMap.h"
#include "../../Robot.h"
#include <iostream>

class CenterToLeftLine : public frc::Command {
private:
	int counter = 0;
public:
	CenterToLeftLine();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


#endif /* SRC_COMMANDS_AUTONS_CENTERTOLEFTLINE_H_ */
