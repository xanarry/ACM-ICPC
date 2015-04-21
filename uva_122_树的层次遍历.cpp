/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19630
层次遍历树
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Leaf
{
    string val;
    string pos;
    bool operator< (const Leaf a) const
    {
        if (pos.length() < a.pos.length())
            return true;
        else if (pos.length() > a.pos.length())
            return false;
        else
            for (int i = 0; i < pos.length(); i++)
                if (pos[i] != a.pos[i])
                    return pos[i] < a.pos[i];
        return false;
    }
};

int main(int argc, char const *argv[])
{
    vector<Leaf> v;
    string in;
    while (cin >> in)
    {
        if (in != "()")
        {
            Leaf leaf;
            int mid = in.find(',');
            leaf.val = in.substr(1, mid - 1);
            leaf.pos = in.substr(mid + 1, in.length() - mid - 2);
            v.push_back(leaf);
        }
        else
        {
            sort(v.begin(), v.end());
            set<Leaf> s;
            int i = 0;
            while (i < v.size())
            {
                if (v[i].val.length() == 0)
                    break;
                if (!s.count(v[i]))
                {
                    if (v[i].pos.length() == 0)
                        s.insert(v[i]);
                    else
                    {
                        Leaf temp;
                        temp.val = v[i].val;
                        temp.pos = v[i].pos.substr(0, v[i].pos.length() - 1);
                        if (s.count(temp))
                            s.insert(v[i]);
                        else
                            break;
                    }
                }
                else
                    break;
                i++;
            }
            if (i != v.size())
                cout << "not complete" << endl;
            else
            {
                for (int j = 0; j < v.size() - 1; j++)
                    cout << v[j].val << " ";
                cout << v[v.size() - 1].val << endl;
            }
            v.clear();
        }
    }
    return 0;
}
