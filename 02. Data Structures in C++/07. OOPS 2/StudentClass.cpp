#include <iostream>
#include <cstring>
using namespace std;

class Student {
    private:

    int age;
    char* name;
    const int rollNumber;
    int &a;    // age reference variable
    static int totalStudents;  // total no of students present

    public:

    Student(int age, char* n, int r) : rollNumber(r), a(this->age) {
        this->age = age;
        //   Shallow copy
        //this->name = name;
        //   Deep copy
        this->name = new char[strlen(n) + 1];
        for (int i=0; i<=strlen(n); i++) {
            name[i] = n[i];
        }
        totalStudents++;  // maintaining student count
    }

    static int getTotalStudents() {  // this function can be only called by Student class
        return totalStudents;
    }

    // Copy constructor
    Student(Student &s) : rollNumber(s.rollNumber) {
        this->age = s.age;
        //   Shallow copy
        //this->name = s.copy
        //   Deep copy
        this->name = new char[strlen(s.name) + 1];
        for (int i=0; i<=strlen(s.name); i++) {
            this->name[i] = s.name[i];
        }
    }

    void display() {
        cout << name << " " << age << endl;
    }
};


int Student :: totalStudents = 0;  // initializing static data members