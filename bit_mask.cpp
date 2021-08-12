#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> M;
    int n, m;
    int x = (1 << 0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        x = x | (1<<tmp);
    }
    cin >> m;
    bool flat = true;
    for (int i = 1; i <= m; i++){
        int tmp;
        cin >> tmp;
        M.push_back(tmp);
    }

    for (int a : M){
        if(!(x & (1 << a))){
            flat = false;
        }
    }
    if(!flat) cout << 0;
    else cout << 1;

    return 0;
}
