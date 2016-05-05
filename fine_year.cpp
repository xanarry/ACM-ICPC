#include <iostream>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
    for (int i = 1000; i <= 9999; i++)
    {
        set<int> s;
        s.insert(i / 1000);
        s.insert(i / 100 % 10);
        s.insert(i / 10 % 10);
        s.insert(i % 10);
        if (s.size() == 4)
            cout << i << endl;
    }
    return 0;
}