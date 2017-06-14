//#include <iostream>
//#include <maya\MSimple.h>
//#include <maya\MIOStream.h>
//
//void main()
//{
//	MStatus stat = MLibrary::initialize("myExporter");
//	if (!stat)
//		return false;
//
//	// figure out the file name to open
//	char* fileName = getFileNameToLoad();
//
//	// prepare Maya to read a new scene file
//	MFileIO::newFile(true);
//
//	// read the scene file
//	stat = MFileIO::open(fileName);
//	if (!stat)
//		return false;
//
//	// remove any temporary data created by Maya while loading
//	// things like the undo list which we won't be using
//	stat = MGlobal::executeCommand("delete -ch");
//	if (!stat)
//		return false;
//
//	// iterate through all the nodes in the DAG, and print out their names
//	MItDag dagIter(MItDag::kBreadthFirst, MFn::kInvalid, &stat);
//	for (; !dagIter.isDone(); dagIter.next())
//	{
//		MDagPath dagPath;
//		stat = dagIter.getPath(dagPath);
//
//		cerr << "Found DAG Node: "
//			<< dagPath.fullPathName().asChar()
//			<< endl;
//	}
//
//	// now shut down Maya, or if you want to process another file,
//	// just make another call to MFileIO::newFile(), and MFileIO::open()
//	MLibrary::cleanup();
//}