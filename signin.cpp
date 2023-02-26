#include <iostream>
#include <fstream>
using namespace std;
string usernames[100];
string passwords[100];
string roles[100];
int usercount = 0;

// sign in sign up
int menu();
void add(string name, string password, string role);
bool signin(string name, string password);
void store(string name, string password, string role);
void viewall();
bool isValidName(string name);
void loaddatafromfile();

void header();
void adminheader();

main()
{
    system("cls");
    header();
    loaddatafromfile();
    string name;
    string password;
    string role;
    int option = 3;

    while (option != 0)
    {
        option = menu();
        if (option == 1)
        {
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            cout << "Enter your role: ";
            cin >> role;

            bool decision = isValidName(name);
            if (decision == true)
            {
                add(name, password, role);
                store(name, password, role);
                cout << "Account created successfully" << endl;
            }
            else
            {
                cout << " Name Not available " << endl;
            }
        }
        else if (option == 2)
        {
            system("cls");
            header();
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your password: ";
            cin >> password;
            bool decision = signin(name, password);
            {
                string role1;
                if (decision == true)
                {
                    for (int index = 0; index < usercount; index++)
                    {
                        if (usernames[index] == name && passwords[index] == password)
                        {
                            role1 = roles[index];
                        }
                    }
                    cout << "You are " << role1 << endl;
                    cout << "LogIn successful" << endl;
                }
                else
                {
                    cout << "Invalid Credentials" << endl;
                }
            }
        }
        else if (option == 3)
        {
            system("cls");
            header();
            viewall();
        }
        else
        {
            cout << "invalid option";
        }
    }
}

void add(string name, string password, string role)
{
    usernames[usercount] = name;
    passwords[usercount] = password;
    roles[usercount] = role;
    usercount++;
}
void store(string name, string password, string role)
{
    fstream file;
    file.open("bus.txt", ios::app);
    file << name << endl;
    file << password << endl;
    file << role << endl;
    file.close();
}
void viewall()
{

    cout << "Names \t\t Password \t Role" << endl;
    for (int index = 0; index < usercount; index++)
    {
        cout << usernames[index] << "\t\t" << passwords[index] << "\t\t" << roles[index] <<"\n";
      
    }
}
bool signin(string name, string password)
{
    bool flag = false;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] == name && passwords[index] == password)
        {

            flag = true;
            break;
        }
    }
    return flag;
}
bool isValidName(string name)
{
    bool flag = true;
    for (int index = 0; index < usercount; index++)
    {
        if (usernames[index] == name)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
int menu()
{
    int choice;
    cout << "1. SignUp" << endl;
    cout << "2. SignIn" << endl;
    cout << "3. View Users" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;
    return choice;
}
void loaddatafromfile()
{
    string name;
    string password;
    fstream file;
    file.open("bus.txt", ios::in);
    while (getline(file, name) && getline(file, password))
    {

        usernames[usercount] = name;
        passwords[usercount] = password;
        usercount++;
    }
    file.close();
}
// Design Functions
void header()
{
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*         WELCOME TO AL- FAJAR MOTORS            *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << endl;
}
void adminheader()
{
     system("cls");
    cout << "**************************************************" << endl;
    cout << "*                                                *" << endl;
    cout << "*         WELCOME DEAR ADMIN                     *" << endl;
    cout << "*                                                *" << endl;
    cout << "**************************************************" << endl;
    cout << endl;
    cout << endl;
}