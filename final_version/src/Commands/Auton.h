/*
 * Auton.h
 *
 *  Created on: Feb 16, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_AUTON_H_
#define SRC_COMMANDS_AUTON_H_

#include <Commands/Command.h>
//#include "IntakeUntilCurrentSpike.h" should be here
#include "../RobotMap.h"
#include "../Robot.h"
#include <iostream>

/*
	Autonomously drives the robot to fulfill the input command from the dashboard.
	This did not work well, due to some connection issues between the robot and the dashboard.
	You should look up more traditional methods of autnomous modes, or, for 2019, look into
	manually driving using the camera (as that's an option!)
*/

class Auton : public frc::Command {
private:
	std::string input;
	std::vector<std::string> commands;
	std::string backup;
	std::string position;
	bool doScale;
	std::string gameData;
	double angle;
	unsigned int index;
	bool firstTime;
	int sitCount;
public:
	Auton(std::string commandInput, std::string backupInput, std::string fieldPosition, std::string scale, std::string gameInfo);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


#endif /* SRC_COMMANDS_AUTON_H_ */
