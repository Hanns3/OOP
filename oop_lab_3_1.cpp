#include <iostream>
#include <Windows.h>
using namespace std;

class Vector
{
private:
    int x, y, z;
public:
    void Print()
    {
        cout << "x = " << x<<"\t";
        cout << "y = " << y<<"\t";
        cout << "z = " << z<<"\t";
        cout << "\n\n";
    }

    Vector (int x = 0, int y = 0, int z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ~Vector()
    {
    }
    friend Vector operator + (Vector &v1, Vector &v2)
    {
        int TempX = v1.x + v2.x;
        int TempY = v1.y + v2.y;
        int TempZ = v1.z + v2.z;
        Vector Temp(TempX, TempY, TempZ);
        return Temp;
    }
    friend Vector operator * (Vector & v1, Vector &v2)
    {
        int TempX = (v1.y * v2.z) - (v1.z * v2.y);
        int TempY = -((v1.x * v2.z) - (v1.z * v2.x));
        int TempZ = (v1.x * v2.y) - (v1.y * v2.x);
        Vector Temp(TempX, TempY, TempZ);
        return Temp;
    }
    Vector operator= (const Vector & v1)
    {
        if (this == &v1)
            return *this;
        else
        {
            x = v1.x;
            y = v1.y;
            z = v1.z;
            return *this;
        }
    }
    

};

int main()
{
    SetConsoleOutputCP(1251);
    Vector v1(4, 5, 7);
    cout << "Вектор 1:  ";
    v1.Print();
    Vector v2(5, 3);
    cout << "Вектор 2:  ";
    v2.Print();
    Vector v3,v4;
    v3 = v1 + v2;
    v4 = v2 * v1;
    cout << "Результат додавання вектора 1 та вектора 2: ";
    v3.Print();
    cout << "Результат векторного добутку вектора 1 та 2: ";
    v4.Print();
    v2 = v1;
    cout << "Результат присвоєння значень вектора 1 вектору 2:  ";
    v2.Print();
    return 0;
}