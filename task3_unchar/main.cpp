#include <iostream>
#include "unschar.h"

using namespace std;

int main()
{
    char char1, char2;
    cout << "Please, input char1" << endl;
    cin >> char1;
    cout << "Please, input char2" << endl;
    cin >> char2;
    unsChar ch1(char1), ch2(char2);
    try
    {
        cout << "-Char1: " << (-ch1).ToChar() << endl;
    }
    catch (int a)
    {
        cout << "-Char in incorrect range" << endl;
    }
    try
    {
        cout << "Char1+Char2: " << (ch1+ch2).ToChar() << endl;
    }
    catch (int a)
    {
        cout << "Char1+Char2 in incorrect range" << endl;
    }
    try
    {
        cout << "Char2*2: " << (ch2 * 2).ToChar() << endl;
    }
    catch (int a)
    {
        cout << "Char2*2 in incorrect range" << endl;
    }
    try
    {
        ch1 = ch2;
        cout << "After ch1=ch2. ch1: " << ch1.ToChar() << endl;
    }
    catch (int a)
    {
        cout << "ch1=ch2 in incorrect range" << endl;
    }
    return 0;
}

