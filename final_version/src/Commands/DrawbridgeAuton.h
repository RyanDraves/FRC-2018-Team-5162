/*
 * DrawbridgeAuton.h
 *
 *  Created on: Apr 2, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_DRAWBRIDGEAUTON_H_
#define SRC_COMMANDS_DRAWBRIDGEAUTON_H_

#include "Commands/Command.h"
#include "../Robot.h"

/*
	Autonomously runs the drawbridge at a given speed for a given amount of time
*/

class DrawbridgeAuton : public frc::Command {
public:
	DrawbridgeAuton(double speed = 0, double time = 1);
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



#endif /* SRC_COMMANDS_DRAWBRIDGEAUTON_H_ */
