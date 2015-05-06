#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P
{
    int price;
    string name;
    bool operator< (P a) const
    {
        if (price < a.price)
            return true;
        else if (price > a.price)
            return false;
        else
            return name < a.name;
    }
};

int main(int argc, char const *argv[])
{
    int n, m, prices, price;
    string name;
    while (cin >> n >> m)
    {
        vector<P> v;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> prices;
            int sum = 0;
            for (int j = 0; j < prices; j++)
            {
                cin >> price;
                if (price < m)
                    sum++;
            }
            P t;
            t.price = sum;
            t.name = name;
            v.push_back(t);
        }   
        sort(v.begin(), v.end());
        cout << v[0].name << endl;
    }
    return 0;
}
