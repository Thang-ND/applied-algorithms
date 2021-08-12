#include <bits/stdc++.h>
using namespace std;

unsigned int n;
int a[100000];
stack<int> order;
deque <int> halway;
string s;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("testcase.inp", "r", stdin);
    cin >> n;
    for (int i=1; i <= n; i++) cin >> a[i];
    for (int i=n; i >= 1; i--) order.push(a[i]);
    cin >> s;
    int tmp;
    for (int i=0; i < s.length(); i++) {
        if (s[i]=='C') {
            tmp = order.top();
            order.pop();
            halway.push_back(tmp);
        } else {
            tmp = halway.front();
            halway.pop_front();
            order.push(tmp);
        }
    }
    while(!order.empty()) {
        cout <<  order.top() << " ";
        order.pop();
    }
    return 0;
}
