#include "HelloWorldCmd.h"
#include <maya/MFnPlugin.h>

void* HelloWorldCmd::creator() { return new HelloWorldCmd; }

MStatus HelloWorldCmd::doIt(const MArgList& argList) {
	MGlobal::displayInfo("Hello World!");
	return MS::kSuccess;
}

MStatus initializePlugin(MObject obj) {
	MFnPlugin plugin(obj, "Chad Vernon", "1.0", "Any");
	MStatus status = plugin.registerCommand("helloWorld", HelloWorldCmd::creator);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}

MStatus uninitializePlugin(MObject obj) {
	MFnPlugin plugin(obj);
	MStatus status = plugin.deregisterCommand("helloWorld");
	CHECK_MSTATUS_AND_RETURN_IT(status);
	return status;
}
