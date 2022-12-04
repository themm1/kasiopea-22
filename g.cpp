#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct corner {
    ll x;
    ll y;
    bool start;
    int rect_index;
};

bool compare_x(corner c1, corner c2) {
    if (c1.x == c2.x) {
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}

bool compare_y(corner c1, corner c2) {
    if (c1.y == c2.y) {
        return c1.x < c2.x;
    }
    return c1.y < c2.y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<corner> corners;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        corners.push_back(corner{x - k, y - k, true, i});
        corners.push_back(corner{x + k + 1, y + k + 1, false, i});
    }
    // sorts for sweeping by x
    sort(corners.begin(), corners.end(), compare_x);
    unordered_set<int> active;
    ll sum = 0;
    // sweeps by x
    for (int i = 0; i < corners.size() - 1 && corners.size() != 0;) {
        int x = corners[i].x;
        // adds / removes all squares starting / ending at x coordinate
        while (corners[i].x == x) {
            if (corners[i].start) {
                active.insert(corners[i].rect_index);
            } else {
                active.erase(corners[i].rect_index);
            }
            i++;
        }
        // creates sorted vector with all active squares sorted by y
        vector<corner> v;
        for (corner c : corners) {
            if (active.find(c.rect_index) != active.end())
                v.push_back(c);
        }
        sort(v.begin(), v.end(), compare_y);

        ll current_x_sum = 0;
        int count = 0;
        // sweeps sorted active corners by y
        for (int j = 0; j < v.size() - 1 && v.size() != 0; j++) {
            if (v[j].start) {
                count++;
            } else {
                count--;
            }
            if (count > 0) {
                current_x_sum += v[j + 1].y - v[j].y;
            }
        } 
        sum += current_x_sum * (corners[i].x - x);
    }
    cout << sum << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       solve();
    }
}