#include <bits/stdc++.h>

using namespace std;

int main() {
    map <char, int> CHAR;
    CHAR.insert(pair<char, int>('a', 1));
    CHAR.insert(pair<char, int>('d', 1));
    CHAR.insert(pair<char, int>('g', 1));
    CHAR.insert(pair<char, int>('j', 1));
    CHAR.insert(pair<char, int>('m', 1));
    CHAR.insert(pair<char, int>('p', 1));
    CHAR.insert(pair<char, int>('t', 1));
    CHAR.insert(pair<char, int>('w', 1));
    CHAR.insert(pair<char, int>(' ', 1));
    CHAR.insert(pair<char, int>('b', 2));
    CHAR.insert(pair<char, int>('e', 2));
    CHAR.insert(pair<char, int>('h', 2));
    CHAR.insert(pair<char, int>('k', 2));
    CHAR.insert(pair<char, int>('n', 2));
    CHAR.insert(pair<char, int>('q', 2));
    CHAR.insert(pair<char, int>('u', 2));
    CHAR.insert(pair<char, int>('x', 2));
    CHAR.insert(pair<char, int>('c', 3));
    CHAR.insert(pair<char, int>('f', 3));
    CHAR.insert(pair<char, int>('i', 3));
    CHAR.insert(pair<char, int>('l', 3));
    CHAR.insert(pair<char, int>('o', 3));
    CHAR.insert(pair<char, int>('r', 3));
    CHAR.insert(pair<char, int>('v', 3));
    CHAR.insert(pair<char, int>('y', 3));
    CHAR.insert(pair<char, int>('s', 4));
    CHAR.insert(pair<char, int>('z', 4));

    int T;
    cin >> T;
    vector<int> RES(T, 0);
    cin.ignore();
    for(int i = 0; i < T; i++){
        string t;
        getline(cin, t);
        for(int j = 0; j < t.length(); j++)
            RES[i] += CHAR[t[j]];
    }
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": "<<RES[i] << endl;
    }
    return 0;
}
