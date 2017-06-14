#pragma once
#include <maya/MArgList.h>
#include <maya/MObject.h>
#include <maya/MGlobal.h>
#include <maya/MPxCommand.h>

class HelloWorldCmd : public MPxCommand {
public:
	HelloWorldCmd() {};
	virtual MStatus doIt(const MArgList& argList);
	static void* creator();
};

