/*----- PROTECTED REGION ID(PowerPMACBox.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        PowerPMACBox.cpp
//
// description : C++ source for the PowerPMACBox and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               PowerPMACBox are implemented in this file.
//
// project :     PowerPMACTangoDev.
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source:  $
// $Log:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================

#include <sstream>
#include <vector>
#include <PowerPMACBox.h>
#include <PowerPMACBoxClass.h>

/* Some versions of MS Visual Studio don't have stdint.h,
   so define uint32_t and uint64_t here */
#ifdef _MSC_VER
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif


/*----- PROTECTED REGION END -----*/


/**
 *	PowerPMACBox class description:
 *	
 */

//================================================================
//
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//----------------------------------------------------------------
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  Reset         |  reset
//  Download      |  download
//  EnablePlc     |  enable_plc
//  DisablePlc    |  disable_plc
//  RunMprog      |  run_mprog
//  AbortMprog    |  abort_mprog
//  GetVariable   |  get_variable
//  SetVariable   |  set_variable
//  Abort         |  abort
//================================================================

namespace PowerPMACBox_ns
{
	/*----- PROTECTED REGION ID(PowerPMACBox::namespace_starting) ENABLED START -----*/

	//	static initializations

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::namespace_starting



//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::PowerPMACBox()
 *	Description : Constructors for a Tango device
 *	              implementing the class PowerPMACBox
 */
//--------------------------------------------------------
PowerPMACBox::PowerPMACBox(Tango::DeviceClass *cl, string &s)
 	: Tango::Device_4Impl(cl, s.c_str())
{
    // ppmaccontrol=0; pac
	/*----- PROTECTED REGION ID(PowerPMACBox::constructor_1) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::constructor_1
}
//--------------------------------------------------------
PowerPMACBox::PowerPMACBox(Tango::DeviceClass *cl, const char *s)
 	: Tango::Device_4Impl(cl, s)
{
    // ppmaccontrol=0; pac
	/*----- PROTECTED REGION ID(PowerPMACBox::constructor_2) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::constructor_2
}
//--------------------------------------------------------
PowerPMACBox::PowerPMACBox(Tango::DeviceClass *cl, const char *s, const char *d)
 	: Tango::Device_4Impl(cl, s, d)
{
    // ppmaccontrol=0; pac
	/*----- PROTECTED REGION ID(PowerPMACBox::constructor_3) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::constructor_3
}


//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::delete_device()()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void PowerPMACBox::delete_device()
{
	/*----- PROTECTED REGION ID(PowerPMACBox::delete_device) ENABLED START -----*/

	//	Delete device allocated objects

    //std::cout << "PowrePMACBox::delete_device called" << std::endl;
    if (ppmaccontrol!=0)
    {
        //std::cout << "PowrePMACBox ppmaccontrol!=0" << std::endl;
        if (ppmaccontrol != 0)
        {
            //std::cout << "PowrePMACBox calling disconnect" << std::endl;
            int ret = ppmaccontrol->PowerPMACcontrol_disconnect();
        }
        // delete ppmaccontrol; pac fix to avoid memory leak
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::delete_device
	delete[] attr_P1000_read;
	delete[] attr_GeneralStatus_read;
	delete[] attr_Version_read;
	delete[] attr_Plc8Status_read;
	delete[] attr_CS1ProgStatus_read;
	delete[] attr_P1_read;
	delete[] attr_Buffer_read;
	
}


//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::init_device()
 *	Description : //	will be called at device initialization.
 */
//--------------------------------------------------------
void PowerPMACBox::init_device()
{
	DEBUG_STREAM << "PowerPMACBox::init_device() create device " << device_name << endl;

	/*----- PROTECTED REGION ID(PowerPMACBox::init_device_before) ENABLED START -----*/

	//	Initialization before get_device_property() call

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::init_device_before
	
	//	Get the device properties (if any) from database
	get_device_property();
	
	attr_P1000_read = new Tango::DevFloat[1];
	attr_GeneralStatus_read = new Tango::DevULong[1];
	attr_Version_read = new Tango::DevString[1];
	attr_Plc8Status_read = new Tango::DevString[1];
	attr_CS1ProgStatus_read = new Tango::DevString[1];
	attr_P1_read = new Tango::DevFloat[1];
	attr_Buffer_read = new Tango::DevString[256];
	
	/*----- PROTECTED REGION ID(PowerPMACBox::init_device) ENABLED START -----*/
    ppmaccontrol = PowerPMACcontrol_ns::PowerPMACcontrol::getInstance(); // pac
    printf("\nIn Box class: ppmaccontrol address = %p", ppmaccontrol);
    // if (ppmaccontrol == 0) pac
    // { pac
    //    ppmaccontrol = new PowerPMACcontrol_ns::PowerPMACcontrol(); pac
    // } pac
    
    //std::cout << "PowerPMACBox::init_device calling disconnect" << endl;
	//	Initialize device
    //ppmaccontrol->PowerPMACcontrol_disconnect();

    //std::cout << "PowerPMACBox::Calling connect with " << ipAddress << ", " << username << ", " << password << endl;
    int ret = ppmaccontrol->PowerPMACcontrol_connect(ipAddress.c_str(), username.c_str(), password.c_str());
    DEBUG_STREAM << "PowerPMACBox::on() ppmaccontrol->connect return is  " << ret << endl;
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        this->set_status("Failed to connect to the Power PMAC.");
        this->set_state(Tango::OFF);
    }
    else
    {
        this->set_status("Connected to the Power PMAC.");
        this->set_state(Tango::ON);
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::init_device
}



//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::get_device_property()
 *	Description : //	Add your own code to initialize
 */
//--------------------------------------------------------
void PowerPMACBox::get_device_property()
{
	/*----- PROTECTED REGION ID(PowerPMACBox::get_device_property_before) ENABLED START -----*/

	//	Initialize property data members

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("IpAddress"));
	dev_prop.push_back(Tango::DbDatum("Username"));
	dev_prop.push_back(Tango::DbDatum("Password"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on PowerPMACBoxClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		PowerPMACBoxClass	*ds_class =
			(static_cast<PowerPMACBoxClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize IpAddress from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  ipAddress;
		else {
			//	Try to initialize IpAddress from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  ipAddress;
		}
		//	And try to extract IpAddress value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  ipAddress;

		//	Try to initialize Username from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  username;
		else {
			//	Try to initialize Username from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  username;
		}
		//	And try to extract Username value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  username;

		//	Try to initialize Password from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  password;
		else {
			//	Try to initialize Password from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  password;
		}
		//	And try to extract Password value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  password;


	}
	/*----- PROTECTED REGION ID(PowerPMACBox::get_device_property_after) ENABLED START -----*/

	//	Check device property data members init

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::get_device_property_after

}

//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void PowerPMACBox::always_executed_hook()
{
	INFO_STREAM << "PowerPMACBox::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::always_executed_hook) ENABLED START -----*/

	//	code always executed before all requests
        printf("\nPAC DEBUG: In Box");
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::always_executed_hook
}



//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::read_attr_hardware()
 *	Description : Hardware acquisition for attributes.
 */
//--------------------------------------------------------
void PowerPMACBox::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "PowerPMACBox::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_attr_hardware) ENABLED START -----*/

	//	Add your own code
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_attr_hardware

}


//--------------------------------------------------------
/**
 *	Read P1000 attribute
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_P1000(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_P1000(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_P1000) ENABLED START -----*/


    float f = 0.0;
    
    int ret =  ppmaccontrol->PowerPMACcontrol_getVariable("P1000", f);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        *attr_P1000_read = f;
        //	Set the attribute value
        attr.set_value(attr_P1000_read);
    }
    else
    {
        std::ostringstream s;
        s << "Failed to get P1000 variable. Error number is " << ret << endl;
        this->set_status(s.str());
    }

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_P1000
}

//--------------------------------------------------------
/**
 *	Write P1000 attribute values to hardware.
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::write_P1000(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::write_P1000(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevFloat	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(PowerPMACBox::write_P1000) ENABLED START -----*/
    int ret =ppmaccontrol->PowerPMACcontrol_setVariable("P1000", w_val);
	if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        std::ostringstream s;
        s << "Failed to set P1000 variable. Error number is " << ret << endl;
        this->set_status(s.str());
    }
	

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::write_P1000
}

//--------------------------------------------------------
/**
 *	Read GeneralStatus attribute
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_GeneralStatus(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_GeneralStatus(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_GeneralStatus) ENABLED START -----*/
    uint32_t st = 0.0;
    int ret =  ppmaccontrol->PowerPMACcontrol_getGlobalStatus(st);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        *attr_GeneralStatus_read = st;
        //	Set the attribute value
        attr.set_value(attr_GeneralStatus_read);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get general status. Error number is " << ret << endl;
        this->set_status(s.str());
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_GeneralStatus
}
//--------------------------------------------------------
/**
 *	Read Version attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_Version(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_Version(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_Version) ENABLED START -----*/
    std::string vers;
    int ret =  ppmaccontrol->PowerPMACcontrol_getVers(vers);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        *attr_Version_read = Tango::string_dup(vers.c_str());
        //	Set the attribute value
        attr.set_value(attr_Version_read);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get version. Error number is " << ret << endl;
        this->set_status(s.str());
    }
    


	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_Version
}
//--------------------------------------------------------
/**
 *	Read Plc8Status attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_Plc8Status(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_Plc8Status(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_Plc8Status) ENABLED START -----*/
    bool active, running;
    int ret = ppmaccontrol->PowerPMACcontrol_plcState(8, active, running);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        std::string s;
        if (active)
            s = "Active,";
        else
            s = "Inactive,";
        
        if (running)
            s += "Running";
        else
            s += "Not running";
        *attr_Plc8Status_read = Tango::string_dup(s.c_str());

        //	Set the attribute value
        attr.set_value(attr_Plc8Status_read);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get PLC 8 program status. Error number is " << ret << endl;
        this->set_status(s.str());
    }

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_Plc8Status
}
//--------------------------------------------------------
/**
 *	Read CS1ProgStatus attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_CS1ProgStatus(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_CS1ProgStatus(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_CS1ProgStatus) ENABLED START -----*/

	//	Set the attribute value
	attr.set_value(attr_CS1ProgStatus_read);
    bool active, running;
    int ret = ppmaccontrol->PowerPMACcontrol_mprogState(1, active, running);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        std::string s;
        if (active)
            s = "Active,";
        else
            s = "Inactive,";
        
        if (running)
            s += "Running";
        else
            s += "Not running";
        *attr_CS1ProgStatus_read = Tango::string_dup(s.c_str());
        //	Set the attribute value
        attr.set_value(attr_CS1ProgStatus_read);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get CS1 program status. Error number is " << ret << endl;
        this->set_status(s.str());
    }

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_CS1ProgStatus
}
//--------------------------------------------------------
/**
 *	Read P1 attribute
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void PowerPMACBox::read_P1(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_P1(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_P1) ENABLED START -----*/


    float f = 0.0;
    int ret =  ppmaccontrol->PowerPMACcontrol_getVariable("P1", f);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        *attr_P1_read = f;
	//	Set the attribute value
	attr.set_value(attr_P1_read);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get P1 variable. Error number is " << ret << endl;
        this->set_status(s.str());
    }

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_P1
}
//--------------------------------------------------------
/**
 *	Read Buffer attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum  max = 256
 */
//--------------------------------------------------------
void PowerPMACBox::read_Buffer(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PowerPMACBox::read_Buffer(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::read_Buffer) ENABLED START -----*/
    std::vector<std::string> buff;
    int num;
    int ret = ppmaccontrol->PowerPMACcontrol_getProgNames(num, buff);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        size_t limit = 250; //Max length set in POGO
        if (limit > buff.size())
            limit = buff.size();
        for(size_t i = 0; i<limit; i++)
            attr_Buffer_read[i] = Tango::string_dup(buff.at(i).c_str());
        //	Set the attribute value
        //cout << "read_buffer num is " << num << endl;
        attr.set_value(attr_Buffer_read, num);
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get buffer. Error number is " << ret << endl;
        this->set_status(s.str());
    }


	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::read_Buffer
}

//--------------------------------------------------------
/**
 *	Method      : PowerPMACBox::PowerPMACBoxClass::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *	              for specified device.
 */
//--------------------------------------------------------
void PowerPMACBox::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(PowerPMACBox::Class::add_dynamic_attributes) ENABLED START -----*/

	//	Add your own code to create and add dynamic attributes if any

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::Class::add_dynamic_attributes

}



//========================================================
//	Command execution methods
//========================================================

//--------------------------------------------------------
/**
 *	Execute the Reset command:
 *	Description: Reset the Power PMAC.
 *
 *	@param argin 
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::reset()
{
	DEBUG_STREAM << "PowerPMACBox::Reset()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::reset) ENABLED START -----*/
    //	Add your own code
    
    //std::cout << "reset  called" << endl;
    this->set_state(Tango::UNKNOWN);
    
    int ret = ppmaccontrol->PowerPMACcontrol_reset();
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        std::ostringstream s;
        s << "Failed to reset. Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Reset successful");
    }
    this->set_state(Tango::ON);
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::reset

}

//--------------------------------------------------------
/**
 *	Execute the Download command:
 *	Description: Remote download of Motion and PLC programs
 *
 *	@param argin filepath
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::download(Tango::DevString argin)
{
	DEBUG_STREAM << "PowerPMACBox::Download()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::download) ENABLED START -----*/

	//	Add your own code
    int ret =  ppmaccontrol->PowerPMACcontrol_progDownload(argin);
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to download a program (" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Download successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::download

}

//--------------------------------------------------------
/**
 *	Execute the EnablePlc command:
 *	Description: Start the embedded PLC program.
 *
 *	@param argin PLC number
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::enable_plc(Tango::DevLong argin)
{
	DEBUG_STREAM << "PowerPMACBox::EnablePlc()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::enable_plc) ENABLED START -----*/

	//	Add your own code
    int ret =  ppmaccontrol->PowerPMACcontrol_enablePlc(argin);
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to enable a PLC program (" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Enable PLC successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::enable_plc

}

//--------------------------------------------------------
/**
 *	Execute the DisablePlc command:
 *	Description: Stop the embedded PLC program.
 *
 *	@param argin PLC number
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::disable_plc(Tango::DevLong argin)
{
	DEBUG_STREAM << "PowerPMACBox::DisablePlc()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::disable_plc) ENABLED START -----*/

	//	Add your own code
	//	Add your own code
    int ret =  ppmaccontrol->PowerPMACcontrol_disablePlc(argin);
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to disable a PLC program (" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Disable PLC successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::disable_plc

}

//--------------------------------------------------------
/**
 *	Execute the RunMprog command:
 *	Description: Start the embedded motion program for the specified coordinate system.
 *
 *	@param argin Coordinate System number
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::run_mprog(Tango::DevLong argin)
{
	DEBUG_STREAM << "PowerPMACBox::RunMprog()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::run_mprog) ENABLED START -----*/

	//	Add your own code
	//	Add your own code
    int ret =  ppmaccontrol->PowerPMACcontrol_runMprog(argin);
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to start a motion program for the coordinate system (" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Run motion program successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::run_mprog

}

//--------------------------------------------------------
/**
 *	Execute the AbortMprog command:
 *	Description: Stop the embedded motion program for the specified coordinate system
 *
 *	@param argin Coordinate system number
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::abort_mprog(Tango::DevLong argin)
{
	DEBUG_STREAM << "PowerPMACBox::AbortMprog()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::abort_mprog) ENABLED START -----*/

	//	Add your own code
    int ret =  ppmaccontrol->PowerPMACcontrol_abortMprog(argin);
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to abort motion programs for the coordinate system(" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Abort motion program successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::abort_mprog

}

//--------------------------------------------------------
/**
 *	Execute the GetVariable command:
 *	Description: Read global internal variables.
 *
 *	@param argin Variable Name
 *	@returns Variable Value
 */
//--------------------------------------------------------
Tango::DevFloat PowerPMACBox::get_variable(Tango::DevString argin)
{
	Tango::DevFloat argout;
	DEBUG_STREAM << "PowerPMACBox::GetVariable()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::get_variable) ENABLED START -----*/
	//	Add your own code
    float f = 0.0;
    int ret =  ppmaccontrol->PowerPMACcontrol_getVariable(argin, f);
    if (ret == PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        argout = f;
        this->set_status("Get variable command successful");
    }
    else
    {
        
        
        std::ostringstream s;
        s << "Failed to get variable (" << argin << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }


	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::get_variable

	return argout;
}

//--------------------------------------------------------
/**
 *	Execute the SetVariable command:
 *	Description: Set a new value to the specified variable. Only works for one variable.
 *
 *	@param argin A set of a string (Variable Name) and a double (new value)
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::set_variable(const Tango::DevVarDoubleStringArray *argin)
{
	DEBUG_STREAM << "PowerPMACBox::SetVariable()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::set_variable) ENABLED START -----*/

	//	Add your own code
    std::string name(argin->svalue[0]);
    float newval = argin->dvalue[0];
    int ret =ppmaccontrol->PowerPMACcontrol_setVariable(name, newval);
	if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        
        
        std::ostringstream s;
        s << "Failed to set new value to variable(" << name << "). Error number is " << ret << endl;
        this->set_status(s.str());
    }
    else
    {
        this->set_status("Set variable successful");
    }
	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::set_variable

}

//--------------------------------------------------------
/**
 *	Execute the Abort command:
 *	Description: Abort (Abrupt stop of all axis)
 *
 *	@param argin 
 *	@returns 
 */
//--------------------------------------------------------
void PowerPMACBox::abort()
{
	DEBUG_STREAM << "PowerPMACBox::Abort()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PowerPMACBox::abort) ENABLED START -----*/

	//	Add your own code
    int ret = ppmaccontrol->PowerPMACcontrol_stopAllAxes();
    if (ret != PowerPMACcontrol_ns::PowerPMACcontrol::PPMACcontrolNoError)
    {
        this->set_status("Failed to stop all axes.");
        
    }
    else
    {
        this->set_status("Abort all axes successful");
    }

	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::abort

}


	/*----- PROTECTED REGION ID(PowerPMACBox::namespace_ending) ENABLED START -----*/


	/*----- PROTECTED REGION END -----*/	//	PowerPMACBox::namespace_ending
} //	namespace
