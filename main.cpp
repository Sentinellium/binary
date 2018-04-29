#include <fstream>
#include <iostream>
using namespace std;

class ex
{
protected:
    char title[80];
    int number;
public:
    void getdata()
    {
        cout << "enter title   "; cin >> title;
        cout << "\n enter number   "; cin >> number;
    }
    void showData()
    {
        cout << "\n title  " << title;
        cout << "\n number:   " << number;
    }
};

int main()
{
    char ch;
    ex example;
    fstream file;
    file.open("1.txt", ios::app | ios::out | ios::in | ios::binary);
    do
    {
        cout << "\n enter  ";
        example.getdata();
        file.write(reinterpret_cast<char*>(&example), sizeof(example));
        cout << "continue (+/-)? ";
        cin >> ch;
    } while (ch == '+');
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&example), sizeof(example));
    while (!file.eof()) //till the end of the file
    {
        example.showData();
        file.read(reinterpret_cast<char*>(&example), sizeof(example));
    }
    cout << endl;
    return 0;
}
