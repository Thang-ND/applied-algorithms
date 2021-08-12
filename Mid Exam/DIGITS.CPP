#include <bits/stdc++.h>
using namespace std;
#define NMAX 1000007
//#define int long long
bool visited[NMAX];
long long N;
map<long long, long long> DIGIT; // C T D L G U --> 1 2 3 4 5 6
long long res;
long long solution() {
    if (DIGIT[1] ==0 || DIGIT[2]==0) return 0;
    long long a = DIGIT[1]*100000+DIGIT[2]*10000+DIGIT[3]*1000+DIGIT[4]*100+DIGIT[5]*10+DIGIT[2];
    long long b = DIGIT[2]*1000+DIGIT[2]*100+DIGIT[6]*10+DIGIT[3];
    //cout << a << "+" << b << endl;
    //if((a+b)==N[1]) cout << a << " " << b << endl;
    return a+b;
}
void TRY(int k) {
    for (int i=0; i<=9; i++) {
        if (visited[i]==false) {
            visited[i] = true;
            DIGIT[k] = i;
            if (k==6) {
                long long tmp = solution();
                 if( tmp == N) {
                    //cout << tmp << endl;
                    res++;
                 }

            }
            else
                TRY(k+1);
            visited[i] = false;
        }
    }
}
int main() {
    //freopen("testcase.inp", "r", stdin);
    cin >> N;
    //cout << N;
    TRY(1);
    cout << res << endl;
    return 0;
}

