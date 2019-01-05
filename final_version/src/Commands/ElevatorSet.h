/*
 * ElevatorSet.h
 *
 *  Created on: Feb 12, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_ELEVATORSET_H_
#define SRC_COMMANDS_ELEVATORSET_H_

#include "Commands/Command.h"
#include "../Robot.h"

/*
	Sets the speed of the elevator motors
*/

class ElevatorSet : public frc::Command {
public:
	ElevatorSet(double speed = 0, int buttonNum = 2);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double motorSpeed;
	int button;
	bool isDone;
};


#endif /* SRC_COMMANDS_ELEVATORSET_H_ */
