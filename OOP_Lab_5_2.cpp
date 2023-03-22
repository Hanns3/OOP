#include <iostream>
using namespace std;

class UsersOfLocalNetwork
{
protected:
    string name[10];
    string surName[10];
    string fatherName[10];
    string group[10];
    string account[10];
    string typeAccount[10];
    int Size = 0;

};

class ExternalUsers : public UsersOfLocalNetwork
{
private:
    int phoneNumber[10];
    string email[10];
public:
    ExternalUsers(string name, string surName, string fatherName, string group, string account, string typeAccount, int phoneNumber, int email)
    {
        this->name[0] = name;
        this->surName[0] = surName;
        this->fatherName[0] = fatherName;
        this->group[0] = group;
        this->account[0] = account;
        this->typeAccount[0] = typeAccount;
        this->phoneNumber[0] = phoneNumber;
        this->email[0] = email;
        Size = 1;
    }
    ExternalUsers()
    {
        name[0] = "Ihor";
        surName[0] = "Holovko";
        fatherName[0] = "Vasilovych";
        group[0] = "KN-108";
        account[0] = "Ihor";
        typeAccount[0] = "private";
        phoneNumber[0] = 7777;
        email[0] = "ihor.holovko@lpnu.ua";
        Size = 1;

    }

    void Show()
    {
        for (int i = 0; i < Size; i++)
        {
            cout << "|-----------------------------------------------------------------------------------------|" << endl;
            cout << "\t\t\t\t\t"<<i<< endl;
            cout << "Name: " << name[i] << endl;
            cout << "Surname: " << surName[i] << endl;
            cout << "Fathername: " << fatherName[i] << endl;
            cout << "Group: " << group[i] << endl;
            cout << "Account: " << account[i] << endl;
            cout << "Type of account: " << typeAccount[i] << endl;
            cout << "Phone Number: " << phoneNumber[i] << endl;
            cout << "Email: " << email[i] << endl;
            cout << endl<<"|-----------------------------------------------------------------------------------------|" << endl;
        }
    }
    void Add()
    {

        cout << "Enter name: " << endl;
        cin >> name[Size];
        cout << "Enter Surname: "<< endl;
        cin >> surName[Size];
        cout << "Enter Fathername: "<< endl;
        cin >> fatherName[Size];
        cout << "Enter Group: "<< endl;
        cin >> group[Size];
        cout << "Enter Account: "<< endl;
        cin >> account[Size];
        cout << "Enter Type of account: " << endl;
        cin >> typeAccount[Size];
        cout << "Enter Phone Number: "<< endl;
        cin >> phoneNumber[Size];
        cout << "Enter Email: "<< endl;
        cin >> email[Size];
        Size++;
    }
    void Destroy(int Size)
    {
        name[Size] = "";
        surName[Size] = "";
        fatherName[Size] = "";
        group[Size] = "";
        account[Size] = "";
        typeAccount[Size] = "";
        phoneNumber[Size] = NULL;
        email[Size] = "";
        this->Size--;
    }

};

void Menu()
{
    ExternalUsers b;
    int ch= 0;
    while (ch != 5)
    {
        cout << "1.Show all users"<<endl;
        cout << "2.Add new user" << endl;
        cout << "3. Destroy some user: " << endl;
        //cout << "4. Edit some information about user: " << endl;
        cout << "5. Quit the program\n$ ";
        cin >> ch;
       switch (ch)
       {
       case 1:
           {  
             b.Show();
             break;
           }
       case 2:
           {
             b.Add();
             break;
           }
       case 3:
           {
           int choice;
           cout << "Enter number of user you want to destroy: ";
           cin >> choice;
           b.Destroy(choice);
           break;
           }

       }
    }
}

int main()
{
    Menu();
}


