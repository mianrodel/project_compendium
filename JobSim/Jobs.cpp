#include "Jobs.h"
bool jobs::operator ==(const jobs& obj) const
{
	if (priority == obj.priority)
		return true;
	else
		return false;
}
/*
void jobs::operator = (const jobs& obj)
{
	name = obj.name;
	department = obj.department;
	age = obj.age;
	position = obj.position;
	id = obj.id;
	//return obj;
}
*/
bool jobs::operator >(const jobs& obj) const
{
	if (priority > obj.priority)
		return true;
	else
		return false;
}
bool jobs::operator <(const jobs& obj) const
{
	if (priority > obj.priority)
		return true;
	else
		return false;
}
bool jobs::operator >=(const jobs& obj) const
{
	if (priority >= obj.priority)
		return true;
	else
		return false;
}
bool jobs::operator <=(const jobs& obj) const
{
	if (priority <= obj.priority)
		return true;
	else
		return false;
}
bool jobs::operator !=(const jobs& obj) const
{
	if (priority != obj.priority)
		return true;
	else
		return false;
}
