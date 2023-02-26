#include <iostream>
#include <fstream>
using namespace std;
string names[100];
string ages[100];
string matric[100];
string inter[100];
string ecat[100];
int count = 0;
void add(string name, string age, string matricM, string interM, string ecatM);
void store(string name, string age, string matricM, string interM, string ecatM);
main()
{
    while (true)
    {
        string name, age, matricM, interM, ecatM;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Matric marks: ";
        cin >> matricM;
        cout << "Enter Intermediate marks: ";
        cin >> interM;
        cout << "Enter E-CAT marks: ";
        cin >> ecatM;
        add(name, age, matricM, interM, ecatM);
        store(name, age, matricM, interM, ecatM);
    }
}
void add(string name, string age, string matricM, string interM, string ecatM)
{
    names[count] = name;
    ages[count] = age;
    matric[count] = matricM;
    inter[count] = interM;
    ecat[count] = ecatM;
    count++;
}
void store(string name, string age, string matricM, string interM, string ecatM)
{
    fstream file;
    file.open("student.txt", ios ::app);
    file << name << endl;
    file << age << endl;
    file << matricM << endl;
    file << interM << endl;
    file << ecatM << endl;
}
