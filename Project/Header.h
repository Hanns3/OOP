#pragma once
#include <iostream>
using namespace std;

class Student
{
    Student();
    void AddStudent(string name, float markmath, float markoop, float markeng, float markscheme, float markukranian, float markap);
    void DeleteStudent(int coun);
    void WriteIntoFileMath();
    void ReadFromFileMath();
    void CalculateTotalMark();
    void Sort();
    void Print();
    void SessionResult();
    void Scholarship();
    void EditOne();
    void EditAll();
};