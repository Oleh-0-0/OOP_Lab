#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <memory>
#include <string>
#include "Student.h"
#include "Course.h"
#include "Schedule.h"

class Repository {
private:
    std::vector<std::shared_ptr<Student>> students;
    std::vector<std::shared_ptr<Course>> courses;
    std::vector<std::shared_ptr<Schedule>> schedules;

    std::string studentFile = "students.txt";
    std::string courseFile = "courses.txt";
    std::string scheduleFile = "schedules.txt";

public:
    Repository() = default;
    bool loadStudents();
    bool saveStudents();

    bool loadCourses();
    bool saveCourses();

    bool loadSchedules();
    bool saveSchedules();

    std::shared_ptr<Student> addStudent(const std::string& name, int age, int year);
    bool removeStudentByIndex(size_t index);

    std::shared_ptr<Course> addCourse(const std::string& title, const std::string& teacherName, int credits, const std::string& platform = "");
    bool removeCourseByIndex(size_t index);

    std::shared_ptr<Schedule> addSchedule(const std::string& day, const std::string& time, const std::string& room, size_t courseIndex);
    bool removeScheduleByIndex(size_t index);
    const std::vector<std::shared_ptr<Student>>& getStudents() const { return students; }
    const std::vector<std::shared_ptr<Course>>& getCourses() const { return courses; }
    const std::vector<std::shared_ptr<Schedule>>& getSchedules() const { return schedules; }

    size_t size() const { return students.size(); }
};

#endif
