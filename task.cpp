#include <iostream>
#include <fstream>
using namespace std;
main()
{
    fstream file;
    string line;
    string ch = "T";
    file.open("story.txt", ios ::in);
    getline(file, line);
    int linelength = line.length();

    int count = 0;

    if (line[0] != 'T')
    {
        count++;
    }

    for (int index = 0; index < linelength - 1; index++)
        if (line[index] == '.' && line[index + 1] != 'T')

        {
            count++;
        }

    cout << count;
    file.close();
}
