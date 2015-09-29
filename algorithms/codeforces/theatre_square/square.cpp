#include <cstdio>
#include <iostream>

using namespace std;

int main () {
    int n, m, a;
    scanf("%d%d%d", &n, &m, &a);
    unsigned long long x = n / a;
    if (n % a)
        x++;
    unsigned long long y = m / a;
    if (m % a)
        y++;
    cout<<x*y<<endl;
    return 0;
}
