#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a[16];
    while (1)
    {
        int count = 0;
        while (1)
        {
            cin >> a[count];
            if (a[count] == 0)
                break;
            else if (a[count] == -1)
                return 0;
            count++;
        }

        int ans = 0;
        for (int i = 0; i < count; i++)
            for (int j = 0; j < count; j++)
                if (a[i] == 2 * a[j])
                    ans++;
        cout << ans << endl;
    }
    return 0;
}