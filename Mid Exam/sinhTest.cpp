#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("testcase.inp", "w", stdout);
    srand(time(0));
    cout << 10 << endl;
    for (int i=1; i<=10; i++)
        cout << rand()%10+1 << " ";

    return 0;
}
