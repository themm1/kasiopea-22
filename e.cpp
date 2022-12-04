#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k; 
    vector<vector<int>> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        v[i].resize(p);
        for (int j = 0; j < p; j++) {
            int num;
            cin >> num;
            string s = bitset<32>(num).to_string();
            int c = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '1') c++;
            v[i][j] = c;
        }
    }
    unordered_map<int, ll> counts;
    for (int j = 0; j < v[0].size(); j++) {
        counts[v[0][j]]++;
    }

    for (int i = 1; i < n; i++) {
        unordered_map<int, ll> new_counts;
        for (auto kv : counts) {
            for (int j = 0; j < v[i].size(); j++) {
                new_counts[kv.first + v[i][j]] += kv.second;
            }
        }
        swap(counts, new_counts);
        new_counts.clear();
    }
    cout << counts[k] << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}