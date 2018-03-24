/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

std::unique_ptr<DriveTrain> Robot::drivetrain;
std::unique_ptr<Intake> Robot::intake;
std::unique_ptr<Lift> Robot::lift;
std::unique_ptr<OI> Robot::oi;

void Robot::VisionThread() {
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	//cv::VideoCapture cap(0);
	camera.SetResolution(640, 480);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
	cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
	cv::Mat source;
	cv::Mat output;
	while(true) {
		//cap.read(source);
		cvSink.GrabFrame(source);
        //cv::cvtColor(source, output, CV_BGR2HSV);
		//cvtColor(source, output, cv::COLOR_BGR2GRAY);
		outputStreamStd.PutFrame(output);
	}
}

void Robot::RobotInit() {
	RobotMap::init();

	drivetrain.reset(new DriveTrain());
	intake.reset(new Intake());
	lift.reset(new Lift());
	oi.reset(new OI());

	std::thread visionThread(VisionThread);
	visionThread.detach();

	/*autoChooser.AddDefault("DriveStraight", new DriveStraight(50));
	autoChooser.AddObject("Left Side", new LeftSide());
	autoChooser.AddObject("Right Side", new RightSide());
	autoChooser.AddObject("Mid: Left Line", new CenterToLeftLine());
	autoChooser.AddObject("Mid: Right Line", new CenterToRightLine());
	SmartDashboard::PutData("Auton Selections", &autoChooser);*/

	SmartDashboard::PutString("Auton Command", "");
	SmartDashboard::PutString("Backup Command", "");
	SmartDashboard::PutString("Start Position", "");
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit() {
}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
	if (SmartDashboard::GetString("Auton Command", "200") == "") {
		SmartDashboard::PutString("Auton Command", "");
	}
	if (SmartDashboard::GetString("Backup Command", "200") == "") {
		SmartDashboard::PutString("Backup Command", "");
	}
	if (SmartDashboard::GetString("Start Position", "2") == "") {
		SmartDashboard::PutString("Start Position", "");
	}
	autonCommand = SmartDashboard::GetString("Auton Command", "200");
	backupCommand = SmartDashboard::GetString("Backup Command", "200");
	position = SmartDashboard::GetString("Start Position", "1");
	SmartDashboard::PutString("Last Auton", autonCommand);
	SmartDashboard::PutString("Last Backup", backupCommand);
	SmartDashboard::PutString("Last Position", position);
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
	drivetrain->ZeroYaw();
	RobotMap::r_encoder->Reset();
	RobotMap::l_encoder->Reset();
	RobotMap::lift_encoder->Reset();
	/*selectedMode.reset(autoChooser.GetSelected());
	if(selectedMode != nullptr) {
		selectedMode->Start();
	}*/
	/*std::string temp;
	temp = SmartDashboard::GetString("Auton Command", "200");
	if (temp != "") {
		autonCommand = temp;
	}
	temp = SmartDashboard::GetString("Backup Command", "200");
	if (temp != "") {
	backupCommand = temp;
	}
	temp = SmartDashboard::GetString("Start Position", "2");
	if (temp != "") {
		position = temp;
	}*/
	selectedMode.reset(new Auton(autonCommand, backupCommand, position, gameData));
	selectedMode->Start();
}

void Robot::AutonomousPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	SmartDashboard::PutString("Auton Command", "");
	SmartDashboard::PutString("Backup Command", "");
	SmartDashboard::PutString("Start Position", "");
	RobotMap::r_encoder->Reset();
	RobotMap::l_encoder->Reset();
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	if (selectedMode != nullptr) {
		selectedMode->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
