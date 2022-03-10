#include <iostream>

using  namespace std;

int main()
{
    int    m, n;
    int   *p1, *p2;

    p1 = &m;
    p2 = &n;
    *p1 = 8;
    *p2 = (*p1) + 1;
    *p2 += *p2;

    cout << m << " " << n << " "
         << *p1 << " " << *p2 << endl;

    return 0;
}