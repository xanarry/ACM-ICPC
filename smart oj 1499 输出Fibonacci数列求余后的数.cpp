/*
/*
著名的斐波那契数列
f[n]=1 n=1,2
f[n-1]+f[n-2] n>2
现在求第n项，由于f[n]可能很大，你只需要输出mod 32768的值即可。
*/
#include <iostream>
using namespace std;

const unsigned MN = 32768;
struct MATRIX
{
    unsigned a11, a12;
    unsigned a21, a22;
    MATRIX(unsigned a, unsigned b, unsigned c, unsigned d) : a11(a), a12(b), a21(c), a22(d){}
    MATRIX() : a11(0), a12(0), a21(0), a22(0){} 
};

MATRIX matrix_mult(const MATRIX a, const MATRIX b)
{
    MATRIX result = MATRIX();
    result.a11 = a.a11 * b.a11 + a.a12 * b.a21;
    result.a11 = result.a11 % MN;
    result.a12 = a.a11 * b.a12 + a.a12 * b.a22;
    result.a12 = result.a12 % MN;
    result.a21 = a.a21 * b.a11 + a.a22 * b.a21;
    result.a21 = result.a21 % MN;
    result.a22 = a.a21 * b.a12 + a.a22 * b.a22;
    result.a22 = result.a22 % MN;
    return result;
}

MATRIX matrix_pow(unsigned n)
{
    MATRIX result;
    if (n == 1)
        result = MATRIX(1, 1, 1, 0);
    else if (n % 2 == 0)
    {
        MATRIX temp = matrix_pow(n / 2);
        result = matrix_mult(temp, temp);
    }
    else
    {
        MATRIX temp = matrix_pow((n - 1) / 2);
        result = matrix_mult(temp, temp);
        result = matrix_mult(result, MATRIX(1, 1, 1, 0));
    }
    return result;
}

unsigned fibonacci(int n)
{
    if (n <= 1)
        return 1;
    else
        return matrix_pow(n).a11;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fibonacci(n - 1) << endl;
    return 0;
}