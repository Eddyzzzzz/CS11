#include <iostream>

using namespace std;

int main()
{
    int    m, n;
    int   *p1, *p2;

    p1 = &m;
    p2 = &n;
    *p1 = 3;
    *p2 = 5;
    cout << m << " " << n << endl;

    return 0;                     
} 