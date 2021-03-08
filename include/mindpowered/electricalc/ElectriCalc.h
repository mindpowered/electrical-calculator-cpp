#pragma once
/*!
 * Copyright Mind Powered Corporation 2020
 * 
 * https://mindpowered.dev/
 */

#include <maglev/MagLev.h>
#include <maglev/MagLevCpp.h>
#include <maglev/CppCallbackPtr.h>
#include <maglev/CppAny.h>
#include <electricalc/ElectricalCalculator.h>
#include <haxecpp/haxe_thread.h>
#include <string>
#include <map>

void __boot_maglev();
void __boot_electricalc();

/*!
 * A library for calculations related to electrical wiring and circuits
 */
class ElectriCalc {
public:
	ElectriCalc()
	{
		run_haxe([](){
			__boot_maglev();
			__boot_electricalc();
			::maglev::MagLev m0 = ::maglev::MagLev_obj::getInstance("default");
			auto o = new ::electricalc::ElectricalCalculator_obj();
			o->__construct(m0);
		});
	}
	~ElectriCalc()
	{
	}

	/*!
	 * Convert from Phase Angle to Power Factor
	 * @param phaseAngle Phase Angle in degrees
	 * @return {double} Power Factor
	*/
	double ConvertPhaseAngleToPowerFactor(double phaseAngle)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,phaseAngle](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(phaseAngle);
			myargs.push_back(param0);
			bus->call("ElectriCalc.ConvertPhaseAngleToPowerFactor", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getDouble();
	}

	/*!
	 * Convert from Power Factor to Phase Angle
	 * @param powerFactor Power Factor
	 * @return {double} Phase Angle in degrees
	*/
	double ConvertPowerFactorToPhaseAngle(double powerFactor)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,powerFactor](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(powerFactor);
			myargs.push_back(param0);
			bus->call("ElectriCalc.ConvertPowerFactorToPhaseAngle", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getDouble();
	}

	/*!
	 * Calcualte single phase power based on measured voltage and current
	 * @param voltage Measured voltage in Volts
	 * @param current Measured current in Amps
	 * @return {double} Apparent Power in VA
	*/
	double CalculateSinglePhasePower(double voltage, double current)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,voltage,current](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(voltage);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setDouble(current);
			myargs.push_back(param1);
			bus->call("ElectriCalc.CalculateSinglePhasePower", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getDouble();
	}

	/*!
	 * Calcualte three phase power based on measured voltage and current
	 * @param voltage Measured voltage in Volts
	 * @param lineTo Which voltage was measured. Must be "line" or "netural"
	 * @param current Measured current in Amps
	 * @return {double} Apparent Power in VA
	*/
	double CalculateThreePhasePower(double voltage, std::string lineTo, double current)
	{
		::maglev::CppAny ret;
		run_haxe([&ret,voltage,lineTo,current](){
			::maglev::MagLevCpp bus = ::maglev::MagLevCpp_obj::getInstance("default");
			std::vector<::maglev::CppAny> myargs;
			::maglev::CppAny param0 = new ::maglev::CppAny_obj();
			param0->setDouble(voltage);
			myargs.push_back(param0);
			::maglev::CppAny param1 = new ::maglev::CppAny_obj();
			param1->setStdString(lineTo);
			myargs.push_back(param1);
			::maglev::CppAny param2 = new ::maglev::CppAny_obj();
			param2->setDouble(current);
			myargs.push_back(param2);
			bus->call("ElectriCalc.CalculateThreePhasePower", myargs, [&ret] (::maglev::CppAny async_ret) { ret = async_ret; });
		});
		return ret->getDouble();
	}

};

