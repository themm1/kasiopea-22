#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int c1, v1, c2, v2;
    cin >> c1 >> v1 >> c2 >> v2;
    if ((float)c1 / (float)v1 > (float)c2 / (float)v2) {
        cout << "MENSI" << endl; 
    } else {
        cout << "VETSI" << endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}