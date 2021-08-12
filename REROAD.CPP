#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int N, Q;
int T[MAX];
vector<int> Res;
int res;
main(){
    cin >> N;
    for (int i=1; i<=N; i++) cin >> T[i];
    int cnt=1;
    int j=1;
    while(j<N) {
        if(T[j] != T[j+1]) {cnt++;}
        j++;
    }
    res = cnt;
    cin >> Q;
    int pi, ci;
    for (int i=1; i<=Q; i++) {

        cin >> pi >> ci;
        if ((pi>1) && (T[pi]!=T[pi-1])) res--;
        if ((pi<N) && (T[pi]!=T[pi+1])) res--;
        T[pi] = ci;
        if ((pi>1) && (T[pi]!=T[pi-1])) res++;
        if ((pi<N) && (T[pi]!=T[pi+1])) res++;
        Res.push_back(res);
    }
    for(int e:Res) cout << e << endl;
}
