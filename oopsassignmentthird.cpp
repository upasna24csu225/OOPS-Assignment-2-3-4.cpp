#include <iostream>
#include <string>
#include <vector> 

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    virtual void displayDetails() const { 
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual ~Person() {} 
};


class Student : public Person {
private:
    std::string program;

public:
    Student(const std::string& name, int age, const std::string& program)
        : Person(name, age), program(program) {}

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Program: " << program << std::endl;
    }
};


class Professor : public Person {
private:
    std::string department;

public:
    Professor(const std::string& name, int age, const std::string& department)
        : Person(name, age), department(department) {}

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Department: " << department << std::endl;
    }
};


class Course {
private:
    std::string title;
    Professor* instructor;

public:
    Course(const std::string& title, Professor* instructor)
        : title(title), instructor(instructor) {}

    void displayDetails() const {
        std::cout << "Course Title: " << title << std::endl;
        std::cout << "Instructor: ";
        instructor->displayDetails();
    }
};

class Department {
private:
    std::vector<Professor*> professors;

public:
    void addProfessor(Professor* professor) {
        professors.push_back(professor);
    }

    void displayProfessors() const {
        std::cout << "Professors in Department:" << std::endl;
        for (const auto& professor : professors) {
            professor->displayDetails();
        }
    }
};

int main() {
    Professor professor1("John Smith", 40, "Mathematics");
    Professor professor2("Jane Doe", 35, "Computer Science");

    Course course1("Math 101", &professor1);
    Course course2("CS 101", &professor2);

    Student student1("Bob Johnson", 20, "Mathematics");
    Student student2("Alice Brown", 22, "Computer Science");

    Department mathDepartment;
    mathDepartment.addProfessor(&professor1);

    course1.displayDetails();
    course2.displayDetails();

    student1.displayDetails();
    student2.displayDetails();

    mathDepartment.displayProfessors();

    return 0;
}

