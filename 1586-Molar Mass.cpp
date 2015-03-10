/*
An organic compound is any member of a large class of chemical compounds whose molecules contain carbon. The molar mass of an organic compound is the mass of one mole of the organic compound. The molar mass of an organic compound can be computed from the standard atomic weights of the elements.

\epsfbox{p3900.eps}
When an organic compound is given as a molecular formula, Dr. CHON wants to find its molar mass. A molecular formula, such as C3 H4 O3 , identifies each constituent element by its chemical symbol and indicates the number of atoms of each element found in each discrete molecule of that compound. If a molecule contains more than one atom of a particular element, this quantity is indicated using a subscript after the chemical symbol.

In this problem, we assume that the molecular formula is represented by only four elements, `C' (Carbon), `H' (Hydrogen), `O' (Oxygen), and `N' (Nitrogen) without parentheses.

The following table shows that the standard atomic weights for `C', `H', `O', and `N'.

Atomic Name Carbon  Hydrogen    Oxygen  Nitrogen
Standard Atomic Weight  12.01 g/mol 1.008 g/mol 16.00 g/mol 14.01 g/mol

For example, the molar mass of a molecular formula C6 H5 OH is 94.108 g/mol which is computed by 6 × (12.01 g/mol) + 6 × (1.008 g/mol) + 1 × (16.00 g/mol).

Given a molecular formula, write a program to compute the molar mass of the formula.

Input 

Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case is given in a single line, which contains a molecular formula as a string. The chemical symbol is given by a capital letter and the length of the string is greater than 0 and less than 80. The quantity number n which is represented after the chemical symbol would be omitted when the number is 1 (2$ \le$n$ \le$99) .

Output 

Your program is to write to standard output. Print exactly one line for each test case. The line should contain the molar mass of the given molecular formula.

Sample Input 

4 
C 
C6H5OH 
NH2CH2COOH 
C12H22O11
Sample Output 

12.010 
94.108 
75.070 
342.296

http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=448&problem=4461&mosmsg=Submission+received+with+ID+15115917
*/
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    string keys = "CHON";
    double v[4] = {12.01, 1.008, 16.00, 14.01};
    cin >> n;
    while (n--)
    {
        string chem;
        cin >> chem;
        chem += "E";
        double sum = 0;
        int s = 1, e = 0;
        for (int i = 1; i < chem.length(); i++)
        {
            if (keys.find(chem[i]) != string::npos || chem[i] == 'E')//finded
            {
                e = i;
                if (e > s)
                {
                    int m = atoi(chem.substr(s, e - s).c_str());
                    sum += v[keys.find(chem[s - 1])] * m;
                }
                else
                    sum += v[keys.find(chem[s - 1])];
                s = e + 1;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}