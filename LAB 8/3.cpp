#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student {
private:
    string name;
    float grades[3];

public:
    Student(string n, float g1, float g2, float g3) {
        name = n;
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    friend class Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher {
public:
    void showGrades(Student s) {
        cout << "grades of " << s.name << ": ";
        for (int i = 0; i < 3; i++) {
            cout << s.grades[i] << " ";
        }
        cout << endl;
    }

    void updateGrade(Student& s, int index, float newGrade) {
        if (index >= 0 && index < 3) {
            s.grades[index] = newGrade;
        }
    }
};

float calculateAverageGrade(Student s) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += s.grades[i];
    }
    return sum / 3;
}

int main() {
    Student s("alex", 78, 85, 90);
    Teacher t;

    t.showGrades(s);
    cout << "average: " << calculateAverageGrade(s) << endl;

    t.updateGrade(s, 1, 95);
    t.showGrades(s);
    cout << "new average: " << calculateAverageGrade(s) << endl;

    return 0;
}
