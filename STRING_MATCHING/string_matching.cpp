#include <bits/stdc++.h>
using namespace std;

string P, T;
int last[256];
int ans;

void computeLast(string p) {
    for (int c=0; c<256; c++) last[c]=0;
    int k=p.length();
    for (int i=k-1; i>=0; i--){
        if (last[p[i]]==0) last[p[i]] = i;
    }
}
int boyerMoore(string P, string T) {
    computeLast(P);
}

main() {
    getline(cin, P);
    getline(cin, T);

}
