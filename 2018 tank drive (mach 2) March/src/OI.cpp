/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/IntakeSet.h"
#include "Commands/ElevatorSet.h"
#include "Commands/IntakeUntilCurrentSpike.h"
#include "Commands/ZeroRobot.h"
#include "OI.h"


OI::OI() {
	// Process operator interface input here.
	leftStick.reset(new Joystick(0));
	rightStick.reset(new Joystick(1));

	JoystickButton* leftButton2 = new JoystickButton(leftStick.get(), 2);
	leftButton2->WhenPressed(new IntakeUntilCurrentSpike(0.5, 0.5, true));

	//JoystickButton* rightButton2 = new JoystickButton(rightStick.get(), 2);
	//rightButton2->WhenPressed(new ZeroRobot());
	//rightButton2->WhileActive(new IntakeSet(leftStick->GetRawAxis(2)));
	//rightButton2->WhenReleased(new IntakeSet(0));

	JoystickButton* rightButton5 = new JoystickButton(rightStick.get(), 5);
	rightButton5->WhenPressed(new ElevatorSet(0.75));
	rightButton5->WhenReleased(new ElevatorSet(0.05));
	JoystickButton* rightButton3 = new JoystickButton(rightStick.get(), 3);
	rightButton3->WhenPressed(new ElevatorSet(-0.75));
	rightButton3->WhenReleased(new ElevatorSet(0));

	JoystickButton* rightButton6 = new JoystickButton(rightStick.get(), 6);
	rightButton6->WhenPressed(new IntakeSet(0.9));
	rightButton6->WhenReleased(new IntakeSet(0));
	JoystickButton* rightButton4 = new JoystickButton(rightStick.get(), 4);
	rightButton4->WhenPressed(new IntakeSet(-0.9));
	rightButton4->WhenReleased(new IntakeSet(0));
}

std::shared_ptr<Joystick> OI::GetLeftStick() {
	return leftStick;
}

std::shared_ptr<Joystick> OI::GetRightStick() {
	return rightStick;
}
