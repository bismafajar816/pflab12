#include <iostream>
#include <fstream>
using namespace std;
main()
{
    fstream file;
    char line;
    file.open("task1.txt", ios::in);
    int count = 0;
    while (!file.eof())
    {
       file >> line;
        count++;
    }
    cout << count;
    file.close();
}