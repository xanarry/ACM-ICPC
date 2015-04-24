/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19105
给出树的中序和后序遍历，构建出二叉树，然后找出从跟节点到哪一个子树叶的所有节点值最小
*/
#include <iostream>
#include <sstream>
using namespace std;

int inorder[10000];
int postorder[10000];
int lch[10000];
int rch[10000];
int n;

bool getinput(int *a)
{
    string in;
    if (!getline(cin, in))
        return false;
    stringstream ss(in);
    n = 0;
    while (ss >> a[n])
        n++;
    return n;
}

int build_tree(int l1, int r1, int l2, int r2)
{
    if (l1 > r1)
        return 0;
    int root = postorder[r2];
    int p = l1;
    while (inorder[p] != root)
        p++;
    int cnt = p - l1;
    lch[root] = build_tree(l1, p - 1,  l2, l2 + cnt - 1);
    rch[root] = build_tree(p + 1, r1,  l2 + cnt, r2 - 1);
    return root;
}

int best, best_sum;
void dfs(int root, int sum)
{
    sum += root;
    if (!lch[root] && !rch[root])
    {
        if (best_sum > sum || (sum == best_sum) && root < best)
        {
            best = root;
            best_sum = sum;
        }
    }
    if (lch[root])
        dfs(lch[root], sum);
    if (rch[root])
        dfs(rch[root], sum);
}

int main(int argc, char const *argv[])
{
    while (getinput(inorder))
    {
        getinput(postorder);
        int t =  build_tree(0, n - 1, 0, n - 1);

        best = best_sum = 1000000;
        dfs(t, 0);
        cout << best << endl;
    }
    
    return 0;
}