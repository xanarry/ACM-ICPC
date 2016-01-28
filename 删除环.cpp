/*
有一个用数字连接成的环, 数字的大小在1-100直接, 环的长度在1到1000之间,环的每个数字唯一, 现在指定一个起点, 并从这个点的下一个位置开始删除, 只到环中只有一个数字, 假如起点的值是n, 那么删除从n开始后面的第n个元素m, 再从m开始, 删除后面第m个数字, 如此不断删除, 只到最后只剩下一个数字, 输出这个数字
假如环是1 2 3 4 5, 起点为1, 那么依次得到
1 3 4 5
1 3 5
1 3
3
所以最后得到3

输入
8 7
8 3 4 2 9 7 1 6
输出
2
*/
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







