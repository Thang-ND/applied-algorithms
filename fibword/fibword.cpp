#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NMAX 102
int n;
string p;
struct fibword {
    int cnt;
    string left, right;
}F[NMAX];

void solve(int n_case) {
    F[0].cnt = (p=="0");
    F[0].left = F[0].right = "0";
    F[1].cnt = (p=="1");
    F[1].left = F[1].right = "1";

    for (int i=2; i<=n; i++) {
        string mid = F[i-1].right + F[i-2].left;
        F[i].cnt = F[i-1].cnt + F[i-2].cnt+ (mid.find(p) != string::npos);

        if (F[i-1].left.length() == p.length()-1) F[i].left = F[i-1].left;
        else {
            string tmp = F[i-1].left + F[i-2].left;
            if (tmp.length() > p.length()-1) tmp = tmp.substr(0, p.length()-1);
            F[i].left = tmp;
        }

        if (F[i-2].right.length() == p.length()-1) F[i].right = F[i-2].right;
        else {
            string tmp = F[i-1].right + F[i-2].right;
            if (tmp.length() > p.length()-1) tmp = tmp.substr(tmp.length()-p.length()+1,p.length()-1);
            F[i].right = tmp;
        }
    }
     cout<<"Case "<<n_case+1<<": "<<F[n].cnt<<'\n';
}

main(){
    int n_case = 0;
    while (cin >> n) {
        cin >> p;
        solve(n_case);
        n_case++;
    }
}
