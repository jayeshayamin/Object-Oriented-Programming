#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name;
    string id;
    string address;
    string phonenumber;
    string email;

    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phonenumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phonenumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail) {
        name = n;
        address = addr;
        phonenumber = phone;
        email = mail;
        cout << "Information updated successfully!" << endl;
    }

    virtual ~Person() {}
};

class Student:public Person{
	public:
		int coursesenrolled;
		float gpa;
		int enrollyear;
		
		Student(string n, string i, string addr, string phone, string mail,int ce,float g,int ey):Person(n,i,addr,phone,mail),coursesenrolled(ce),gpa(g),enrollyear(ey){}

	void displayinfo()
	{
		Person::displayInfo();
		cout<<"Courses Enrolled: "<<coursesenrolled<<endl;
		cout<<"GPA: "<<gpa<<endl;
		cout<<"Enrollment Year: "<<enrollyear<<endl;
	}
};
class Professor:public Person{
	public:
		int coursestaught;
		double salary;
		string dept;
		
		Professor(string n, string i, string addr, string phone, string mail,int ce,float g,string ey):Person(n,i,addr,phone,mail),coursestaught(ce),salary(g),dept(ey){}

	void displayinfo()
	{
		Person::displayInfo();
		cout<<"Courses Taught: "<<coursestaught<<endl;
		cout<<"Salary: "<<salary<<endl;
		cout<<"Department: "<<dept<<endl;
	}
};
class Staff:public Person{
	public:
		string dep;
		float salary;
		string position;
		
		Staff(string n, string i, string addr, string phone, string mail,string ce,float g,string ey):Person(n,i,addr,phone,mail),dep(ce),salary(g),position(ey){}

	void displayinfo()
	{
		Person::displayInfo();
		cout<<"Department: "<<dep<<endl;
		cout<<"Salary: "<<salary<<endl;
		cout<<"Position: "<<position<<endl;
	}
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    Student* students[10];  
    int studentCount;

public:
    Course(string id, string name, int cr, Professor* prof)
        : courseId(id), courseName(name), credits(cr), instructor(prof), studentCount(0) {}

    void enrollStudent(Student* student) {
        if (studentCount < 10) {
            students[studentCount++] = student;
            cout << student->id << " enrolled in " << courseName << endl;
        } else {
            cout << "Enrollment limit reached for " << courseName << endl;
        }
    }

    void displayCourseInfo() {
        cout << "\n[Course Details]" << endl;
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->name << " (ID: " << instructor->id << ")" << endl;
        cout << "Enrolled Students: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "- " << students[i]->name << " (ID: " << students[i]->id << ")" << endl;
        }
    }
};

int main() {
    Professor* prof = new Professor("Smith", "P1001", "10 Univ", "555-1234", "smith@univ.edu", 3, 5000.0, "Computer Science");
    Student* stu1 = new Student("Alice", "S2001", "45 Ave", "555-5678", "alice@univ.edu", 2, 3.8, 2023);
    Student* stu2 = new Student("Bob", "S2002", "78 St", "555-9876", "bob@univ.edu", 3, 3.5, 2022);

    Course* course = new Course("CS101", "Introduction to Programming", 3, prof);

    course->enrollStudent(stu1);
    course->enrollStudent(stu2);

    course->displayCourseInfo();

    delete prof;
    delete stu1;
    delete stu2;
    delete course;

    return 0;
}