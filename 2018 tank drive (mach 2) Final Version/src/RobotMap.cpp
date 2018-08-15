#include "RobotMap.h"
#include "WPILib.h"

std::shared_ptr<AHRS> RobotMap::ahrs;
std::shared_ptr<PWMTalonSRX> RobotMap::l_motor;
std::shared_ptr<PWMTalonSRX> RobotMap::r_motor;
std::shared_ptr<DifferentialDrive> RobotMap::robot_drive;

std::shared_ptr<VictorSP> RobotMap::leftIntake;
std::shared_ptr<VictorSP> RobotMap::rightIntake;

std::shared_ptr<PWMTalonSRX> RobotMap::primaryLift;
//std::shared_ptr<Spark> RobotMap::primaryLift;

std::shared_ptr<Talon> RobotMap::drawbridge;

std::shared_ptr<Encoder> RobotMap::r_encoder;
std::shared_ptr<Encoder> RobotMap::l_encoder;

std::shared_ptr<Encoder> RobotMap::lift_encoder;

void RobotMap::init() {
	LiveWindow::GetInstance()->DisableAllTelemetry();

	ahrs.reset(new AHRS(frc::SPI::Port::kMXP));
	l_motor.reset(new PWMTalonSRX(0));
	r_motor.reset(new PWMTalonSRX(1));
	robot_drive.reset(new DifferentialDrive(*l_motor, *r_motor));

	leftIntake.reset(new VictorSP(2));
	rightIntake.reset(new VictorSP(3));

	primaryLift.reset(new PWMTalonSRX(4));
	//primaryLift.reset(new Spark(4));

	drawbridge.reset(new Talon(5));

	r_encoder.reset(new Encoder(0, 1, false, Encoder::EncodingType::k4X));
	r_encoder->SetReverseDirection(true);
	l_encoder.reset(new Encoder(2, 3, false, Encoder::EncodingType::k4X));

	lift_encoder.reset(new Encoder(4, 5, false, Encoder::EncodingType::k4X));
	lift_encoder->SetReverseDirection(true);
}
