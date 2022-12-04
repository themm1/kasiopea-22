#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int j, prev = -INT_MAX, max = -1;
    for (int i = 0; i < n; i++) {
        cin >> j;
        if (prev != -INT_MAX && abs(j - prev) > max)        
            max = abs(j - prev);
        prev = j;
    }
    cout << max << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}