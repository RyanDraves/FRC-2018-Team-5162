/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/IntakeSet.h"
#include "Commands/ElevatorSet.h"
#include "Commands/Drawbridge.h"
#include "Commands/IntakeUntilCurrentSpike.h"
#include "Commands/ZeroRobot.h"
#include "OI.h"


// Initialize the joysticks and configure the buttons to commands
// Note that the driving subsystem is not handled here; that's the drivetrain subsystem
OI::OI() {
	// Process operator interface input here.
	leftStick.reset(new Joystick(0));
	rightStick.reset(new Joystick(1));

	JoystickButton* leftButton2 = new JoystickButton(leftStick.get(), 2);
	leftButton2->WhenPressed(new Drawbridge(0.5));
	leftButton2->WhenReleased(new Drawbridge(0));

	JoystickButton* leftButton3 = new JoystickButton(leftStick.get(), 3);
	leftButton3->WhenPressed(new Drawbridge(-0.5));
	leftButton3->WhenReleased(new Drawbridge(0));

	JoystickButton* leftButton4 = new JoystickButton(leftStick.get(), 4);
	leftButton4->WhenPressed(new Drawbridge(0.1));
	leftButton4->WhenReleased(new Drawbridge(0));

	JoystickButton* leftButton5 = new JoystickButton(leftStick.get(), 5);
	leftButton5->WhenPressed(new Drawbridge(-0.1));
	leftButton5->WhenReleased(new Drawbridge(0));

	JoystickButton* rightButton5 = new JoystickButton(rightStick.get(), 5);
	//											0.75
	rightButton5->WhenPressed(new ElevatorSet(1));
	rightButton5->WhenReleased(new ElevatorSet(0.1));
	JoystickButton* rightButton3 = new JoystickButton(rightStick.get(), 3);
	rightButton3->WhenPressed(new ElevatorSet(-1));
	rightButton3->WhenReleased(new ElevatorSet(0));

	JoystickButton* rightButton9 = new JoystickButton(rightStick.get(), 9);
	rightButton9->WhenPressed(new ElevatorSet(0.5));
	rightButton9->WhenReleased(new ElevatorSet(0.05));
	JoystickButton* rightButton11 = new JoystickButton(rightStick.get(), 11);
	rightButton11->WhenPressed(new ElevatorSet(-0.5));
	rightButton11->WhenReleased(new ElevatorSet(0));

	JoystickButton* rightButton1 = new JoystickButton(rightStick.get(), 1);
	rightButton1->WhenPressed(new IntakeSet(0.8));
	rightButton1->WhenReleased(new IntakeSet(0));
	JoystickButton* rightButton6 = new JoystickButton(rightStick.get(), 6);
	rightButton6->WhenPressed(new IntakeSet(1));
	rightButton6->WhenReleased(new IntakeSet(0));
	JoystickButton* rightButton2 = new JoystickButton(rightStick.get(), 2);
	rightButton2->WhenPressed(new IntakeSet(-1));
	rightButton2->WhenReleased(new IntakeSet(0));
}

std::shared_ptr<Joystick> OI::GetLeftStick() {
	return leftStick;
}

std::shared_ptr<Joystick> OI::GetRightStick() {
	return rightStick;
}
