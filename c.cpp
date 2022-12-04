#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, ll> map;    
    for (int i = 0; i < n; i++) {
        int c;
        string s;
        cin >> s >> c;
        map[s] += c;
    }
    cout << map.size() << endl;
    for (auto kv : map) {
        cout << kv.first << " " << kv.second << endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}