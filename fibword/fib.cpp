#include <bits/stdc++.h>
using namespace std;

//long long fib;
map <long long, long long> memory;

long long fib(long long n)
{
    if (n<=2) return 1;
    if (memory.find(n) != memory.end())
        return memory[n];
    long long res = fib(n-1) + fib(n-2);
    memory[n] = res;
    return res;
}

//main()
//{
//    long long n = 9;
//    while(n--) cout << n << " " << fib(n) << endl;
//    cout << fib(3) << endl;
//}
