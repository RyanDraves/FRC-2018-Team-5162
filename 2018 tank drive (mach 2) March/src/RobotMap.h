/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"
#include "Encoder.h"
#include "AHRS.h"
#include "LiveWindow/LiveWindow.h"

class RobotMap {
public:
	static void init();

	static std::shared_ptr<AHRS> ahrs;
	static std::shared_ptr<PWMTalonSRX> l_motor;
	static std::shared_ptr<PWMTalonSRX> r_motor;
	static std::shared_ptr<DifferentialDrive> robot_drive;

	static std::shared_ptr<VictorSP> leftIntake;
	static std::shared_ptr<VictorSP> rightIntake;

	static std::shared_ptr<PWMTalonSRX> primaryLift;

	static std::shared_ptr<Encoder> r_encoder;
	static std::shared_ptr<Encoder> l_encoder;

	static std::shared_ptr<Encoder> lift_encoder;
};

#endif
