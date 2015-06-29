#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        string a = "";
        string b = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (i % 2 == 0)
                a += str[i];
            else
                b = str[i] + b;
        }
        cout << a << endl;
        cout << b << endl;
    }
    return 0;
}