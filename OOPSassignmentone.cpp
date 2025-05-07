#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {
        if (age <= 0) throw std::invalid_argument("Age must be positive.");
        if (name.empty()) throw std::invalid_argument("Name cannot be empty.");
    }

    std::string getName() const { return name; }
    void setName(const std::string& newName) {
        if (!newName.empty()) name = newName;
        else throw std::invalid_argument("Name cannot be empty.");
    }

    int getAge() const { return age; }
    void setAge(int newAge) {
        if (newAge > 0) age = newAge;
        else throw std::invalid_argument("Age must be positive.");
    }

    virtual void displayDetails() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    virtual double calculatePayment() const = 0; // Pure virtual method for polymorphism
};

class Student : public Person {
private:
    double GPA;

public:
    Student(const std::string& name, int age, double GPA) : Person(name, age), GPA(GPA) {
        if (GPA < 0.0 || GPA > 4.0) throw std::invalid_argument("GPA must be between 0.0 and 4.0.");
    }

    double getGPA() const { return GPA; }
    void setGPA(double newGPA) {
        if (newGPA >= 0.0 && newGPA <= 4.0) GPA = newGPA;
        else throw std::invalid_argument("GPA must be between 0.0 and 4.0.");
    }

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "GPA: " << GPA << std::endl;
    }

    double calculatePayment() const override {
        return GPA * 100.0;
    }
};

class Professor : public Person {
private:
    std::string department;

public:
    Professor(const std::string& name, int age, const std::string& department) : Person(name, age), department(department) {}

    std::string getDepartment() const { return department; }
    void setDepartment(const std::string& newDepartment) { department = newDepartment; }

    void displayDetails() const override {
        Person::displayDetails();
        std::cout << "Department: " << department << std::endl;
    }

    double calculatePayment() const override {
        return 5000.0;
    }
};

int main() {
    try {
        Student student("Jane Doe", 20, 3.5);
        Professor professor("John Smith", 40, "Mathematics");

        student.displayDetails();
        professor.displayDetails();

        std::cout << "Student Payment: " << student.calculatePayment() << std::endl;
        std::cout << "Professor Payment: " << professor.calculatePayment() << std::endl;

        Person* people[] = {&student, &professor};
        for (Person* person : people) {
            person->displayDetails();
            std::cout << "Payment: " << person->calculatePayment() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}