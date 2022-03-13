#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
	PrecondViolatedExcep(const string& message = "");
};
// end PrecondViolatedExcep .h
 //file PrecondViolatedExcep.cpp */
PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor
// End of implementation file.
