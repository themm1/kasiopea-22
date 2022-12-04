#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int min_x, max_x, min_y, max_y;

ll dfs(map<pair<int, int>, int> &trees, int x, int y) {
    trees[make_pair(x, y)] = 2;
    min_x = min(min_x, x);
    max_x = max(max_x, x);
    min_y = min(min_y, y);
    max_y = max(max_y, y);
    // up
    if (trees[make_pair(x, y + 1)] == 1)
        dfs(trees, x, y + 1);
    // right
    if (trees[make_pair(x + 1, y)] == 1)
        dfs(trees, x + 1, y);
    // down
    if (trees[make_pair(x, y - 1)] == 1)
        dfs(trees, x, y - 1);
    // left
    if (trees[make_pair(x - 1, y)] == 1)
        dfs(trees, x - 1, y);
    return (max_x - min_x + 1) * (max_y - min_y + 1);
}

void reset_globals() {
    min_x = INT_MAX;
    max_x = 0;
    min_y = INT_MAX;
    max_y = 0;
}

void solve() {
    int m, n, l;
    cin >> m >> n >> l;
    map<pair<int, int>, int> trees;
    vector<pair<int, int>> positions;
    for (int i = 0; i < l; i++) {
        int x, y;
        cin >> x >> y;
        trees[make_pair(x - 1, y - 1)] = 1;
        positions.push_back(make_pair(x - 1, y - 1));
    } 
    
    ll sum = 0;
    for (auto p : positions) {
        if (trees[p] == 1) {
            sum += dfs(trees, p.first, p.second);
            reset_globals();
        }
    }
    cout << sum << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        reset_globals();
        solve();
    }
}