#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

struct Node
{
    int key;
    Node *next;
    Node *pre;
};

Node *insert(Node *h, int key)
{
    Node *t = new Node();
    t->key = key;

    if (h == NULL)
    {
        h = t;
        h->next = h;
        h->pre = h;
    }
    else
    {
        t->next = h->next;
        h->next->pre = t;
        h->next = t;
        t->pre = h;
        h = t;
    }
    return h;
}

int main(int argc, char const *argv[])
{  
    int n, dest, k;
    Node *h = NULL, *start;
    cin >> n >> dest;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        h = insert(h, k);
        if (i == dest)
            start = h;
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    while (start->next != start)
    {
        int t = start->key;
        while (t--)
            start = start->next;
        
        Node *pre = start->pre;
        pre->next = start->next;
        start->next->pre = pre;
    }   
    cout << start->key << endl;
    return 0;
}