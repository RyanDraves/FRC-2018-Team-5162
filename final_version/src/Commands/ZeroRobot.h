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

/*
	This command is supposed to quickly move the robot to angle zero. DO NOT USE IT.
	This should have something called a PID Loop (Google it) to get it safely to angle zero.
	It does not have a PID Loop and is VERY prone to freaking out and damaging the robot and
	any objects nearby
*/

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
