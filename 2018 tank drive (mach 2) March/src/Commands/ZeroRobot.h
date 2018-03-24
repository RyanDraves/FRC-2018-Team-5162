/*
 * ZeroRobot.h
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_ZEROROBOT_H_
#define SRC_COMMANDS_ZEROROBOT_H_


#include <Commands/Command.h>
#include "../OI.h"
#include "../Robot.h"

class ZeroRobot : public frc::Command {
private:
	std::shared_ptr<frc::Timer> timer;
public:
	ZeroRobot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif /* SRC_COMMANDS_ZEROROBOT_H_ */
