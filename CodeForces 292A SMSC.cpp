#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, t, c;
    cin >> n;
    int maxsc = -1;
    int pret, prec;
    cin >> pret >> prec;
    maxsc = prec;
    for (int i = 1; i < n; i++)
    {
        cin >> t >> c;
        int dift = t - pret;
        dift = dift >= prec ? prec : dift;
        int restc = c + prec - dift;
        if (restc > maxsc)
            maxsc = restc;
        prec = restc;
        pret = t;
    }
    int resttime = pret + prec;
    cout << resttime << " " << maxsc << endl;
    return 0;
}