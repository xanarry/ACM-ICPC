/*
http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=34217
Description
Boudreaux and Thibodeaux are on the road again . . . 

"Boudreaux, we have to get this shipment of mudbugs to Baton Rouge by tonight!" 

"Don't worry, Thibodeaux, I already checked ahead. There are three underpasses and our 18-wheeler will fit through all of them, so just keep that motor running!" 

"We're not going to make it, I say!" 

So, which is it: will there be a very messy accident on Interstate 10, or is Thibodeaux just letting the sound of his own wheels drive him crazy? 
 
Input
Input to this problem will consist of a single data set. The data set will be formatted according to the following description. 

The data set will consist of a single line containing 3 numbers, separated by single spaces. Each number represents the height of a single underpass in inches. Each number will be between 0 and 300 inclusive. 
 
Output
There will be exactly one line of output. This line will be: 

   NO CRASH 

if the height of the 18-wheeler is less than the height of each of the underpasses, or: 

   CRASH X 

otherwise, where X is the height of the first underpass in the data set that the 18-wheeler is unable to go under (which means its height is less than or equal to the height of the 18-wheeler). 
The height of the 18-wheeler is 168 inches. 
 
Sample Input
180 160 170 
 
Sample Output
CRASH 160 
*/
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[3];
    const int stdheight = 168;
    vector<int> v;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
        if (a[i] < stdheight)
            v.push_back(a[i]);
    }
    if (v.empty())
        cout << "NO CRASH" << endl;
    else
        cout << "CRASH " << v[0] << endl;
    return 0;
}