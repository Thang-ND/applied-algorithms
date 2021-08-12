#include <bits/stdc++.h>
using namespace std;
//#define NMAX 1000006
//typedef unsigned long long ull;
//const unsigned int MOD =  1e9 + 7;
//ull a, b, c;
//void input() {
//
//}
int n;
void solve() {
    cin >> n;
    vector<string> S;
    for (int i=1; i<=n + 1; i++) {
        string tmp;
        getline(cin, tmp);
        int len = tmp.length();
        if (len > 10) {
            string s = "";
            s = string(1, tmp[0]) + s + to_string(len - 2) + string(1, tmp[len-1]);
            S.push_back(s);
        }
        else S.push_back(tmp);
    }

    for (string a : S) cout << a << endl;
}
main() {
    //input();
    solve();
}
