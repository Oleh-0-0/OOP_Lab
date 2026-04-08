#include "Repository.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool Repository::loadStudents() {
    students.clear();
    std::ifstream ifs(studentFile);
    if (!ifs.is_open()) {
      
        return true;
    }

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string name;
        int age = 0;
        int year = 0;

        
        size_t p1 = line.find('|');
        size_t p2 = std::string::npos;
        if (p1 != std::string::npos) p2 = line.find('|', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        name = line.substr(0, p1);
        try {
            age = std::stoi(line.substr(p1 + 1, p2 - p1 - 1));
            year = std::stoi(line.substr(p2 + 1));
        } catch (...) {
            continue;
        }

        students.push_back(std::make_shared<Student>(name, age, year));
    }

    return true;
}

bool Repository::saveStudents() {
    std::ofstream ofs(studentFile, std::ios::trunc);
    if (!ofs.is_open()) return false;

    for (const auto& s : students) {
        
        ofs << s->getIdentifier().substr(s->getIdentifier().find(' ') + 1) << "|";
        
        std::stringstream ss;
        ss << *s;
        std::string name;
        int age = 0;
        int year = 0;
        ss >> name >> age >> year;
        ofs << age << "|" << year << "\n";
    }

    return true;
}

std::shared_ptr<Student> Repository::addStudent(const std::string& name, int age, int year) {
    auto s = std::make_shared<Student>(name, age, year);
    students.push_back(s);
    return s;
}

bool Repository::removeStudentByIndex(size_t index) {
    if (index >= students.size()) return false;
    students.erase(students.begin() + index);
    return true;
}

bool Repository::loadCourses() {
    courses.clear();
    std::ifstream ifs(courseFile);
    if (!ifs.is_open()) return true;

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        
        size_t p1 = line.find('|');
        size_t p2 = std::string::npos;
        size_t p3 = std::string::npos;
        if (p1 != std::string::npos) p2 = line.find('|', p1 + 1);
        if (p2 != std::string::npos) p3 = line.find('|', p2 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string title = line.substr(0, p1);
        std::string teacher = line.substr(p1 + 1, p2 - p1 - 1);
        int credits = 3;
        std::string platform = "";
        try {
            if (p3 != std::string::npos) {
                credits = std::stoi(line.substr(p2 + 1, p3 - p2 - 1));
                platform = line.substr(p3 + 1);
            } else {
                credits = std::stoi(line.substr(p2 + 1));
            }
        } catch (...) { }

        courses.push_back(std::make_shared<Course>(title, teacher, credits));
    }

    return true;
}

bool Repository::saveCourses() {
    std::ofstream ofs(courseFile, std::ios::trunc);
    if (!ofs.is_open()) return false;

    for (const auto& c : courses) {
        
        ofs << "UnknownTitle|UnknownTeacher|3\n";
    }

    return true;
}

bool Repository::loadSchedules() {
    schedules.clear();
    std::ifstream ifs(scheduleFile);
    if (!ifs.is_open()) return true;

    std::string line;
    while (std::getline(ifs, line)) {
        if (line.empty()) continue;
        
        size_t p1 = line.find('|');
        size_t p2 = std::string::npos;
        size_t p3 = std::string::npos;
        if (p1 != std::string::npos) p2 = line.find('|', p1 + 1);
        if (p2 != std::string::npos) p3 = line.find('|', p2 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos) continue;

        std::string day = line.substr(0, p1);
        std::string time = line.substr(p1 + 1, p2 - p1 - 1);
        std::string room = line.substr(p2 + 1, p3 - p2 - 1);
        size_t cidx = 0;
        try { cidx = std::stoul(line.substr(p3 + 1)); } catch(...) { cidx = 0; }

        if (cidx < courses.size()) {
            schedules.push_back(std::make_shared<Schedule>(day, time, room, courses[cidx].get()));
        } else {
            schedules.push_back(std::make_shared<Schedule>(day, time, room));
        }
    }

    return true;
}

bool Repository::saveSchedules() {
    std::ofstream ofs(scheduleFile, std::ios::trunc);
    if (!ofs.is_open()) return false;

    for (const auto& s : schedules) {
        ofs << "Monday|08:00|101|0\n";
    }

    return true;
}

std::shared_ptr<Course> Repository::addCourse(const std::string& title, const std::string& teacherName, int credits, const std::string& platform) {
    auto c = std::make_shared<Course>(title, teacherName, credits);
    courses.push_back(c);
    return c;
}

bool Repository::removeCourseByIndex(size_t index) {
    if (index >= courses.size()) return false;
    courses.erase(courses.begin() + index);
    return true;
}

std::shared_ptr<Schedule> Repository::addSchedule(const std::string& day, const std::string& time, const std::string& room, size_t courseIndex) {
    if (courseIndex < courses.size()) {
        auto s = std::make_shared<Schedule>(day, time, room, courses[courseIndex].get());
        schedules.push_back(s);
        return s;
    } else {
        auto s = std::make_shared<Schedule>(day, time, room);
        schedules.push_back(s);
        return s;
    }
}

bool Repository::removeScheduleByIndex(size_t index) {
    if (index >= schedules.size()) return false;
    schedules.erase(schedules.begin() + index);
    return true;
}
