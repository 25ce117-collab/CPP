#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GradingSystem
{
protected:
    float marks;
public:
    virtual float computeGrade() const = 0;
    void setMarks(float m) { marks = m; }
    float getMarks() const { return marks; }
};

class Undergraduate : public GradingSystem
{
protected:
    float computeGrade() const override
    {
        if (marks >= 90)
            return 4.0;
        else if (marks >= 80)
            return 3.0;
        else if (marks >= 70)
            return 2.0;
        else
            return 1.0;
    }
};

class Postgraduate : public GradingSystem
{
protected:
    float computeGrade() const override
    {
        if (marks >= 85)
            return 4.0;
        else if (marks >= 75)
            return 3.0;
        else if (marks >= 65)
            return 2.0;
        else
            return 1.0;
    }
};

int main()
{
    vector<GradingSystem*> students;
    Undergraduate* ugStudent = new Undergraduate();
    ugStudent->setMarks(85);
    students.push_back(ugStudent);

    Postgraduate* pgStudent = new Postgraduate();
    pgStudent->setMarks(78);
    students.push_back(pgStudent);

    for (const auto& student : students)
    {
        cout << "Marks: " << student->getMarks()
             << ", Grade: " << student->computeGrade() << endl;
    }

    for (auto& student : students)
    {
        delete student;
    }

    return 0;
}
