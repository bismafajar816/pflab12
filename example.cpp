#include <iostream>
#include <fstream>
using namespace std;
main()
{
   fstream file;
   string line;
   file.open("example.txt", ios::in);
  
   int count = 0;
   while (!file.eof())
   {

      getline(file, line);
      count++;
      // cout <<  line<<endl;
   }
   cout << count;
   file.close();
}