/*
 * UseIntake.h
 *
 *  Created on: Feb 9, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_INTAKEUNTILCURRENTSPIKE_H_
#define SRC_COMMANDS_INTAKEUNTILCURRENTSPIKE_H_


#include "Commands/Command.h"
#include "../Robot.h"

/*
	So, yeah, I stole this from another team's code. I recommend doing so.
	The intake of the 2018 robot ran two wheels to pick up Power Cubes.
	This command will run the intake until there's a "spike" in the current of the motors,
	i.e. the cube has gone in and now the wheels are freely moving much faster.
	Or, it'll run for however long the time input was.
*/

class IntakeUntilCurrentSpike : public Command {
public:
	IntakeUntilCurrentSpike(double time = 0, double speed = 0, bool currentCheck = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double currentThreshold;
	double currentLeft;
	double currentRight;
	double timeTarget;
	double timeCurrent;
	double inputSpeed;
	bool isDone;
	bool isCheckingForCurrentSpike;
	std::shared_ptr<frc::Timer> timer;
};


#endif /* SRC_COMMANDS_INTAKEUNTILCURRENTSPIKE_H_ */
