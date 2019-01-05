/*
 * TeleopDrive.h
 *
 *  Created on: Feb 2, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_COMMANDS_TELEOPDRIVE_H_
#define SRC_COMMANDS_TELEOPDRIVE_H_

#include <Commands/Command.h>
#include "../OI.h"
//#include "../Robot.h" should be here (see source file for details).

/*
	Indefinitely drives the robot with the given joystick inputs
*/

class TeleopDrive : public frc::Command {
private:
public:
	TeleopDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif /* SRC_COMMANDS_TELEOPDRIVE_H_ */
