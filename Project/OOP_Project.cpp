#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;
char Alphabet[] = "AaBbCcDdEeFfGgHhIiKLlMmNnOoPpQqRrSsTtVvXxYyZz";


class Student
{
private:
    vector <string> Name;
    vector <float> MarkMath;
    vector <float> MarkOop;
    vector <float> MarkEng;
    vector <float> MarkScheme;
    vector <float> MarkUkranian;
    vector <float> MarkAp;
    vector <float> Total;
    int count;
public:
    Student()
    {
        count = 0;
    }

    void AddStudent(string name, float markmath, float markoop, float markeng, float markscheme, float markukranian, float markap)
    {
        count++;
        Name.push_back(name);
        MarkMath.push_back(markmath);
        MarkOop.push_back(markoop);
        MarkEng.push_back(markeng);
        MarkScheme.push_back(markscheme);
        MarkUkranian.push_back(markukranian);
        MarkAp.push_back(markap);

    }

    void DeleteStudent(int coun)
    {
        coun -= 1;
        {
            Name[coun].erase();
            MarkMath.erase(MarkMath.begin() + coun);
            MarkOop.erase(MarkOop.begin() + coun);
            MarkEng.erase(MarkEng.begin() + coun);
            MarkScheme.erase(MarkScheme.begin() + coun);
            MarkUkranian.erase(MarkUkranian.begin() + coun);
            MarkAp.erase(MarkAp.begin() + coun);
            Total.erase(Total.begin() + coun);
        }
        WriteIntoFileMath();
    }

    void WriteIntoFileMath()
    {
        CalculateTotalMark();

        string MathStudents = "MathStudents.txt";
        string MathMarks = "MathMarks.txt";
        string OopMarks = "OopMarks.txt";
        string EngMarks = "EngMarks.txt";
        string SchemeMarks = "SchemeMarks.txt";
        string UkranianMarks = "UkranianMarks.txt";
        string ApMarks = "ApMarks.txt";
        string TotalMarks = "TotalMarks.txt";

        ofstream sout;
        ofstream mathout;
        ofstream oopout;
        ofstream engout;
        ofstream schemeout;
        ofstream ukranianout;
        ofstream apout;
        ofstream totalout;
        sout.open(MathStudents);
        mathout.open(MathMarks);
        oopout.open(OopMarks);
        engout.open(EngMarks);
        schemeout.open(SchemeMarks);
        ukranianout.open(UkranianMarks);
        apout.open(ApMarks);
        totalout.open(TotalMarks);

        if (!sout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < Name.size(); i++)
            {
                sout << Name[i] << endl;
            }
        }

        if (!mathout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkMath.size(); i++)
            {
                mathout << MarkMath[i] <<endl;
            }
        }

        if (!oopout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkOop.size(); i++)
            {
                oopout << MarkOop[i] << endl;
            }
        }

        if (!engout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkEng.size(); i++)
            {
                engout << MarkEng[i] << endl;
            }
        }
        if (!schemeout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkScheme.size(); i++)
            {
                schemeout << MarkScheme[i] << endl;
            }
        }
        if (!ukranianout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkUkranian.size(); i++)
            {
                ukranianout << MarkUkranian[i] << endl;
            }
        }
        if (!apout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < MarkAp.size(); i++)
            {
                apout << MarkAp[i] << endl;
            }
        }

        if (!totalout.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; i < Total.size(); i++)
            {
                totalout << Total[i] << endl;
            }
        }

        sout.close();
        mathout.close();
        oopout.close();
        engout.close();
        schemeout.close();
        ukranianout.close();
        apout.close();
        totalout.close();

    }
    void ReadFromFileMath()
    {
        string MathStudents = "MathStudents.txt";
        string MathMarks = "MathMarks.txt";
        string OopMarks = "OopMarks.txt";
        string EngMarks = "EngMarks.txt";
        string SchemeMarks = "SchemeMarks.txt";
        string UkranianMarks = "UkranianMarks.txt";
        string ApMarks = "ApMarks.txt";
        string TotalMarks = "TotalMarks.txt";

        ifstream sin;
        ifstream mathin;
        ifstream oopin;
        ifstream engin;
        ifstream schemein;
        ifstream ukranianin;
        ifstream apin;
        ifstream totalin;

        sin.open(MathStudents);
        mathin.open(MathMarks);
        oopin.open(OopMarks);
        engin.open(EngMarks);
        schemein.open(SchemeMarks);
        ukranianin.open(UkranianMarks);
        apin.open(ApMarks);
        totalin.open(TotalMarks);

        char text[200] = { };
        char ch;
        if (!sin.is_open())
        {
            cout << "Error";
        }
        else
        {
            for (int i = 0; sin.get(ch); i++)
            {

                text[i] = ch;
            }
            Name.clear();
            char* pch = strtok(text, "\n");
            while (pch != nullptr)
            {
                Name.push_back(pch);
                pch = strtok(NULL, "\n");
            }
        }

        MarkMath.clear();
        float x;
        if (!mathin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (mathin >> x)
            {
                MarkMath.push_back(x);
            }
        }

        MarkOop.clear();
        float c;
        if (!oopin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (oopin >> c)
            {
                MarkOop.push_back(c);
            }
        }


        MarkEng.clear();
        float v;
        if (!engin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (engin >> v)
            {
                MarkEng.push_back(v);
            }
        }
 
        MarkScheme.clear();
        float b;
        if (!schemein.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (schemein >> b)
            {
                MarkScheme.push_back(b);
            }
        }

        MarkUkranian.clear();
        float n;
        if (!ukranianin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (ukranianin >> n)
            {
                MarkUkranian.push_back(n);
            }
        }

        MarkAp.clear();
        float m;
        if (!apin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (apin >> m)
            {
                MarkAp.push_back(m);
            }
        }


        Total.clear();
        float l;
        if (!totalin.is_open())
        {
            cout << "Error";
        }
        else
        {
            while (totalin >> l)
            {
                Total.push_back(l);
            }
        }


        sin.close();
        mathin.close();
        oopin.close();
        engin.close();
        schemein.close();
        ukranianin.close();
        apin.close();
        totalin.close();
    }

    void CalculateTotalMark()
    {
        Total.clear();
        for (int i = 0; i < MarkMath.size(); i++)
        {
            float result = (MarkMath[i] * 8 + MarkOop[i] * 5 + MarkEng[i] * 3 + MarkScheme[i] * 6 + MarkUkranian[i] * 3 + MarkAp[i] * 5) / 30;
            Total.push_back(result);
        }
    }



    void Sort()
    {
        for (int i = 0; i < Name.size(); i++)
        {
            for (int j = 1; j < Name.size(); j++)
            {
                if (Total[j] > Total[j-1])
                {
                    float temp = Total[j];
                    Total[j] = Total[j - 1];
                    Total[j - 1] = temp;

                    temp = MarkMath[j];
                    MarkMath[j] = MarkMath[j - 1];
                    MarkMath[j - 1] = temp;

                    temp = MarkOop[j];
                    MarkOop[j] = MarkOop[j - 1];
                    MarkOop[j - 1] = temp;

                    temp = MarkEng[j];
                    MarkEng[j] = MarkEng[j - 1];
                    MarkEng[j - 1] = temp;

                    temp = MarkScheme[j];
                    MarkScheme[j] = MarkScheme[j - 1];
                    MarkScheme[j - 1] = temp;

                    temp = MarkUkranian[j];
                    MarkUkranian[j] = MarkUkranian[j - 1];
                    MarkUkranian[j - 1] = temp;

                    temp = MarkAp[j];
                    MarkAp[j] = MarkAp[j - 1];
                    MarkAp[j - 1] = temp;

                    string tmp = Name[j];
                    Name[j] = Name[j - 1];
                    Name[j - 1] = tmp;               
                }
            }
        }
        WriteIntoFileMath();
    }

    void Print()
    {
        for (int i = 0; i < Name.size(); i++)
        {
            cout << i + 1 << ". Name: " << Name[i] << "\t  Math: " << MarkMath[i] << "\t  OOP: " << MarkOop[i] << "\t  Eng: " << MarkEng[i] << "\t  Scheme: " << MarkScheme[i] << "\t  Ukr: " << MarkUkranian[i] << "\t  AP: " << MarkAp[i] << "\t  Total: "<< Total[i] << endl;
        }
            
    }

    void SessionResult()
    {
        for (int i = 0; i < MarkMath.size(); i++)
        {
            if (MarkMath[i] < 50 || MarkOop[i] < 50 || MarkEng[i] < 50 || MarkScheme[i] < 50 || MarkUkranian[i] < 50 || MarkAp[i] < 50)
            {
                cout <<"\n"<< Name[i] << " didn't complete the session" << endl;
                if (MarkMath[i] < 50)
                { 
                    cout << Name[i] << " must repass Math\n";
                }
                if (MarkOop[i] < 50)
                {
                    cout << Name[i] << " must repass OOP\n";
                }
                if (MarkEng[i] < 50)
                {
                    cout << Name[i] << " must repass English\n";
                }
                if (MarkScheme[i] < 50)
                {
                    cout << Name[i] << " must repass Scheme\n";
                }
                if (MarkUkranian[i] < 50)
                {
                    cout << Name[i] << " must repass Ukranian\n";
                }
                if (MarkAp[i] < 50)
                {
                    cout << Name[i] << " must repass AP\n";
                }
            }
            else
            {
                cout <<endl<< Name[i] << " completed the session succesfully! Congratulations!" << endl;
            }
            
        }

    }
    void Scholarship()
    {
        Sort();
        int count = Name.size();
        count *= 0.4;
        for (int i = 0; i < count; i++)
        {
            if (MarkMath[i] > 88 && MarkOop[i] > 88 && MarkEng[i] > 88 && MarkScheme[i] > 88 && MarkUkranian[i] > 88 && MarkAp[i] > 88)
            {
                cout << Name[i] << " has increased scholarship! " << endl;
            }
            else if(MarkMath[i] > 50 && MarkOop[i] > 50 && MarkEng[i] > 50 && MarkScheme[i] > 50 && MarkUkranian[i] > 50 && MarkAp[i] > 50)
            {
                cout << Name[i] << " has default scholarship! " << endl;
            }
        }
    }

    void EditOne()
    {
        int num;
        int subject;
        float math, oop, eng, scheme, ukranian, ap;
        string name;
        cout << "\nEnter number to change: ";
        cin >> num;
        num -= 1;
        cout << "\nEnter subject to change";
        cout << "\n1.Math\n";
        cout << "2.OOP\n";
        cout << "3.English\n";
        cout << "4.Scheme\n";
        cout << "5.Ukranian\n";
        cout << "6.AP\n";
        cout << "7.Name\n";
        cin >> subject;
        switch (subject)
        {

        case 1:
        {
            cout << "\nEnter Math Mark: ";
            cin >> math;
            MarkMath[num] = math;
            break;
        }
        case 2:
        {
            cout << "\nEnter OOP Mark: ";
            cin >> oop;
            MarkOop[num] = oop;
            break;
        }
        case 3:
        {
            cout << "\nEnter English Mark: ";
            cin >> eng;
            MarkEng[num] = eng;
            break;
        }
        case 4:
        {
            cout << "\nEnter Scheme Mark: ";
            cin >> scheme;
            MarkScheme[num] = scheme;
            break;
        }
        case 5:
        {
            cout << "\nEnter Ukranian Mark: ";
            cin >> ukranian;
            MarkUkranian[num] = ukranian;
            break;
        }
        case 6:
        {
            cout << "\nEnter AP Mark: ";
            cin >> ap;
            MarkAp[num] = ap;
            break;
        }
        case 7:
        {
            cout << "\nEnter Name and SurName: ";
            cin >> name;
            Name[num] = name;
            break;
        }
        default:
        {
            cout << "\nWrong number";
            break;
        }
        }
        WriteIntoFileMath();
    }

    void EditAll()
    {
        int num;
        cout << "\nEnter number to change: ";
        cin >> num;
        num -= 1;
        string nam;
        float math, oop, eng, scheme, ukranian, ap;
        cout << "Enter Name and SurName of student: ";
        cin >> nam;
        cout << "\nEnter mark for Math: ";
        cin >> math;
        cout << "\nEnter mark for OOP: ";
        cin >> oop;
        cout << "\nEnter mark for English: ";
        cin >> eng;
        cout << "\nEnter mark for Scheme: ";
        cin >> scheme;
        cout << "\nEnter mark for Ukranian Language: ";
        cin >> ukranian;
        cout << "\nEnter mark for AP: ";
        cin >> ap;
        MarkMath[num] = math;
        MarkOop[num] = oop;
        MarkEng[num] = eng;
        MarkScheme[num] = scheme;
        MarkUkranian[num] = ukranian;
        MarkAp[num] = ap;
        Name[num] = nam;
        WriteIntoFileMath();
    }
    
};



int main()
{
    Student Students;

    int g = 10;
    while (g != 0)
    {
        Students.ReadFromFileMath();
        cout << endl;
        Students.Sort();
        Students.Print();
        cout << endl;
        cout << "\n1.Add student and all the marks\n";
        cout << "2.Delete student and all the marks\n";
        cout << "3.Session result\n";
        cout << "4.Scholarship\n";
        cout << "5.Calculate Total Marks\n";
        cout << "6.Edit one mark\n";
        cout << "7.Edit all student\n";
        cout << "0.Exit\n\n";
        cin >> g;
        switch (g)
        {
        case 1:
        {
            string nam;
            float math, oop, eng, scheme, ukranian, ap;
            cout << "Enter Name and SurName of student: ";
            cin >> nam;
            cout << "\nEnter mark for Math: ";
            cin >> math;
            cout << "\nEnter mark for OOP: ";
            cin >> oop;
            cout << "\nEnter mark for English: ";
            cin >> eng;
            cout << "\nEnter mark for Scheme: ";
            cin >> scheme;
            cout << "\nEnter mark for Ukranian Language: ";
            cin >> ukranian;
            cout << "\nEnter mark for AP: ";
            cin >> ap;
            Students.AddStudent(nam, math, oop, eng, scheme, ukranian, ap);
           
            Students.WriteIntoFileMath();
            break;
        }
        case 2:
        {
            int num;
            cout << "\nEnter number of student you want to delete: ";
            cin >> num;
            Students.DeleteStudent(num);
            break;
        }
        case 3:
        {
            Students.SessionResult();
            break;
        }
        case 4:
        {
            Students.Scholarship();
            break;
        }
        case 5:
        {
            Students.CalculateTotalMark();
            Students.WriteIntoFileMath();
            break;
        }
        case 6:
        {
            Students.EditOne();
            break;
        }
        case 7:
        {
            Students.EditAll();
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "\nWrong number\n";
            break;
        }
        }
    }
}
