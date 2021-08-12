#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<string> String;
    int n;
    cin >> n;
    for (int i = 0; i<=n; i++) {
        string tmp;
        getline(cin, tmp);
        int len = tmp.length();
        if(len > 10) {
            string s;
            s.push_back(tmp[0]);
            s = s + to_string(len-2);
            s.push_back(tmp.back());
            tmp = s;
        }
        //cout << tmp << endl;
        String.push_back(tmp);
    }

    for (string s : String)
        cout << s << endl;
}
