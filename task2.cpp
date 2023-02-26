#include <iostream>
#include <fstream>
using namespace std;
main()
{
    fstream file;
    char line;
    char ch;
    cout << "Enter the character to find frequency: ";
    cin >> ch;
    file.open("task1.txt", ios::in);
    int count = 0;
    while (!file.eof())
    {
        file >> line;
        if (line == ch)
        {
            count++;
        }
    }
    cout << count;
    file.close();
}