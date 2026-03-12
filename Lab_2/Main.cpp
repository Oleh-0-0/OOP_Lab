#include "Student.h"
#include "Schedule.h"
#include "Course.h"

int main()
{
	Student s1;
	Student s2("Damir", "Rozhman", 17)
	
	Schedule sc1;
	Schedule sc2("Tuesday", "11:30", 116 );

	Course c1;
	Course c2("English", "Mudra", 2 );

	Student s3 = s2;
	Student s4 = s1 + s2;
	Student s5 = !s1;
	cout << Student::getCount() << endl;


	s1.display();
	s2.display();

	sc1.display();
	sc2.display();

	c1.display();
	c2.display();

	return 0;
}