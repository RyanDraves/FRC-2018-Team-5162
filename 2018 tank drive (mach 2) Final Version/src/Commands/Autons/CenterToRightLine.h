/*
 * CenterToRightLine.h
 *
 *  Created on: Feb 8, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_AUTONS_CENTERTORIGHTLINE_H_
#define SRC_COMMANDS_AUTONS_CENTERTORIGHTLINE_H_

#include <Commands/Command.h>
#include "../../RobotMap.h"
#include "../../Robot.h"
#include <iostream>

class CenterToRightLine : public frc::Command {
private:
	int counter = 0;
public:
	CenterToRightLine();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};



#endif /* SRC_COMMANDS_AUTONS_CENTERTORIGHTLINE_H_ */
