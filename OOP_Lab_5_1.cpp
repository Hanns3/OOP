#include <iostream>
#include <Windows.h>

using namespace std;

class D3
{
public:
    D3()
    {
        cout << "Конструктор классу D3" << endl;
    }
    ~D3()
    {
        cout << "Деструктор классу D3" << endl;
    }
    void Show()
    {

    }
};

class D1 : public D3
{
public:
    D1()
    {
        cout << "Конструктор классу D1" << endl;
    }
    ~D1()
    {
        cout << "Деструктор классу D1" << endl;
    }
};

class D2 : protected D3
{
public:
    D2()
    {
        cout << "Конструктор классу D2" << endl;
    }
    ~D2()
    {
        cout << "Деструктор классу D2" << endl;
    }
};

class B3 : private D2
{
public:
    B3()
    {
        cout << "Конструктор классу B3" << endl;
    }
    ~B3()
    {
        cout << "Деструктор классу B3" << endl;
    }
};

class B1 :public D1
{
public:
    B1()
    {
        cout << "Конструктор классу B1" << endl;
    }
    ~B1()
    {
        cout << "Деструктор классу B1" << endl;
    }
};

class B2 : private D1
{
public:
    B2()
    {
        cout << "Конструктор классу B2" << endl;
    }
    ~B2()
    {
        cout << "Деструктор классу B2" << endl;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    B1 pt;
    cout << endl;
    B2 kt;
    cout << endl;
    B3 lt;
    cout << endl;
}

