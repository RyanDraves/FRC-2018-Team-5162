/*
 * ElevatorAuton.h
 *
 *  Created on: Mar 23, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_ELEVATORAUTON_H_
#define SRC_COMMANDS_ELEVATORAUTON_H_

#include "Commands/Command.h"
#include "../Robot.h"

class ElevatorAuton : public frc::Command {
public:
	ElevatorAuton(double speed = 0, double time = 1);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double timeTarget;
	double timeCurrent;
	std::shared_ptr<frc::Timer> timer;
	double motorSpeed;
	bool isDone;
};


#endif /* SRC_COMMANDS_ELEVATORAUTON_H_ */
