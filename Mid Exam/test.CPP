#include <bits/stdc++.h>

using namespace std;
int n;
const int MAX = 1e6 + 5;
int h[MAX];
int l1[MAX] = {0}, r1[MAX] = {0};
int l2[MAX] = {0}, r2[MAX] = {0};

void input(){
    cin>>n;
    for (int i = 1; i<=n; i++) cin>>h[i];
}

void solver(){
    for (int i = 2; i<= n;i++){
        if(h[i]> h[i-1]) l1[i] = l1[i-1] +1;
        else if(h[i] < h[i-1]) l2[i] = l2[i-1] + 1;
    }

    for (int i = n-1; i>=1; i--){
        if(h[i] >h[i+1]) r1[i] = r1[i+1] +1;
        else if (h[i] < h[i+1]) r2[i] = r2[i+1] + 1;
    }

    int height = 0, depth = 0;

    for (int i =1 ;i<=n;i++){
        height = max(height, min(l1[i], r1[i]));
        depth = max(depth, min(l2[i], r2[i]));
    }

    cout<<height<<" "<<depth<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("testcase.inp", "r", stdin);
    input();
    solver();
    return 0;
}
