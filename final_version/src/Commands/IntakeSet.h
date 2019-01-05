/*
 * IntakeSet.h
 *
 *  Created on: Feb 16, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_INTAKESET_H_
#define SRC_COMMANDS_INTAKESET_H_

#include "Commands/Command.h"
#include "../Robot.h"

/*
	Sets the speed of the intake motors
*/

class IntakeSet : public frc::Command {
public:
	IntakeSet(double speed = 0, int buttonNum = 2);
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


#endif /* SRC_COMMANDS_INTAKESET_H_ */
