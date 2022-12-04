#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct edge {
    int target;
    int val;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int u, v, c;
    vector<vector<edge>> graph;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        graph[u - 1].push_back({v - 1, c});
        graph[v - 1].push_back({u - 1, c});
    }
    unordered_set<int> ks;
    for (int i = 0; i < k; i++) {
        cin >> u;
        ks.insert(u - 1); 
    }
    
    int current = -1;
    for (int i = 0; i < n && current == -1; i++) {
        if (ks.find(i) == ks.end())
            current = i;
    }
    if (current == -1) {
        cout << -1 << endl;
        return;
    }

    ll price = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>> min_heap;
    unordered_set<int> visited;
    while (true) {
        visited.insert(current);
        for (auto e : graph[current]) {
            if (ks.find(e.target) == ks.end() &&
                visited.find(e.target) == visited.end()) {
                min_heap.push(make_pair(e.val, e.target));
            }
        }
        int prev = current;
        while (!min_heap.empty()) {
            pair<int, int> next = min_heap.top();
            min_heap.pop();
            current = next.second;
            if (visited.find(current) == visited.end()) {
                price += next.first;
                break;
            }
        }
        if (prev == current) {
            break;
        }
    }
    
    if (visited.size() != n - k) {
        cout << -1 << endl;
        return;
    }

    for (int v : ks) {
        int mmin = INT_MAX;
        for (auto e : graph[v]) {
            if (visited.find(e.target) != visited.end() && e.val < mmin)
                mmin = e.val;
        }
        if (mmin == INT_MAX) {
            cout << -1 << endl;
            return;
        }
        price += mmin;
    }
    cout << price << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}