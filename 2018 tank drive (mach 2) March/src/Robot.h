/*
 * Robot.h
 *
 *  Created on: Feb 2, 2018
 *      Author: brrobotics5162
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include "Commands/Auton.h"
#include "Commands/Autons/DriveStraight.h"
#include "Commands/Autons/LeftSide.h"
#include "Commands/Autons/RightSide.h"
#include "Commands/Autons/CenterToLeftLine.h"
#include "Commands/Autons/CenterToRightLine.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Lift.h"
#include "OI.h"
#include "RobotMap.h"

#include "WPILib.h"
#include "AHRS.h"
#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

class Robot : public frc::TimedRobot {
public:

	static std::unique_ptr<DriveTrain> drivetrain;
	static std::unique_ptr<Intake> intake;
	static std::unique_ptr<Lift> lift;
	static std::unique_ptr<OI> oi;

	static void VisionThread();
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

private:
	frc::SendableChooser<frc::Command*> autoChooser;
	std::unique_ptr<frc::Command> selectedMode;
	std::string autonCommand;
	std::string backupCommand;
	std::string position;
	std::string gameData;
};

#endif /* SRC_ROBOT_H_ */
