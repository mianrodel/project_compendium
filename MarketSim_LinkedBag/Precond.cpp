#include "PrecondViolatedExcep.h"
//@file PrecondViolatedExcep.cpp* /
PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.