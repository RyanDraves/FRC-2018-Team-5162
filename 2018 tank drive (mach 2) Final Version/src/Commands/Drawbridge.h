/*
 * Drawbridge.h
 *
 *  Created on: Apr 2, 2018
 *      Author: brrobotics5162
 */


#ifndef SRC_COMMANDS_DRAWBRIDGE_H_
#define SRC_COMMANDS_DRAWBRIDGE_H_

#include "Commands/Command.h"
#include "../Robot.h"

class Drawbridge : public frc::Command {
public:
	Drawbridge(double speed = 0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double motorSpeed;
};


#endif /* SRC_COMMANDS_DRAWBRIDGE_H_ */

