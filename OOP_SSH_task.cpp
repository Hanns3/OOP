#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course
{
private:
    string name;
    int credits;
    vector<string> StudentList;

public:
    Course(string name, int credits)
    {
        this->name = name;
        this->credits = credits;
    }

    string getCourse()
    {
        return name;
    }

    void addStudents(string studentName)
    {
        StudentList.push_back(studentName);
    }

    ~Course()
    {

    }
};

class Person
{

protected:
    string name;
    string contact_info;
    int age;
    vector<string> courses;


public:
    void setName(string name)
    {
        this->name = name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setContactInfo(string contact_info)
    {
        this->contact_info = contact_info;
    }
    
    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    string setContactInfo()
    {
        return contact_info;
    }

    virtual void get_info()
    {

    }

    ~Person()
    {

    }
};

class Student : public Person
{

private:
    vector<int> marks;

public:
    Student(string name, int age, string contact_info)
    {
        this->name = name;
        this->age = age;
        this->contact_info = contact_info;
    }

    void addCourse(Course course, int mark)
    {
        courses.push_back(course.getCourse());
        marks.push_back(mark);
        course.addStudents(this->name);
    }

    void get_info() override
    {
        cout << "Name of this student is: " << name << ". Age of this student is: " << age << ". Here is contact info: " << contact_info;
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "\nStudent studies at course " << courses[i] << " and has " << marks[i] << " mark";
        }
    }

    ~Student()
    {

    }
};


class Professor : public Person
{

private:
    string department;

public:
    Professor(string name, int age, string contact_info,string department)
    {
        this->name = name;
        this->age = age;
        this->contact_info = contact_info;
        this->department = department;
    }

    void addCourse(Course course)
    {
        courses.push_back(course.getCourse());
    }

    void get_info() override
    {
        cout << "Name of this professor is: " << name << ". Age of this professor is: " << age << ". Here is contact info: " << contact_info;
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "\nProfessor teaches course " << courses[i]<<endl;
        }
    }
    
    ~Professor()
    {

    }
};


int main()
{
    Student st("John", 18, "097");
    Professor pr("Alex", 60, "033", "programming");
    Course course("Math", 8);
    st.addCourse(course, 96);
    pr.addCourse(course);
    st.get_info();
    cout << endl;
    pr.get_info();

    return 0;
}

