#include "Student.h"
#include "Schedule.h"
#include "Course.h"

int main()
{
	Student s1;
	Student s2("Damir", "Rozhman", "17");

	Schedule sc1;
	Schedule sc2("Tuesday", "11:30", "116");

	Course c1;
	Course c2("English", "Mudra", "2");

	s1.display();
	s2.display();

	sc1.display();
	sc2.display();

	c1.display();
	c2.display();

	return 0;
}