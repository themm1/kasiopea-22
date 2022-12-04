#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct node {
    int weight = 0;
    vector<int> edges;
    ll start_dist = -1;
    ll target_dist = -1;
} empty_node;

vector<node> graph;

vector<ll> djikstra(int current) {
    vector<ll> distances;
    int n = graph.size();
    for (int i = 0; i < n; i++)
        distances.push_back(-1);        
    
    unordered_set<int> visited; 
    priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                   greater<pair<ll, int>>> min_heap;
    ll distance = graph[current].weight;
    while (true) {
        visited.insert(current);
        distances[current] = distance;
        for (int e : graph[current].edges) {
            if (visited.find(e) == visited.end()) {
                min_heap.push(make_pair(distance + graph[e].weight, e));
            }
        }
        int prev = current;
        while (!min_heap.empty()) {
            pair<ll, int> next = min_heap.top();
            min_heap.pop(); 
            if (visited.find(next.second) == visited.end()) {
                current = next.second;
                distance = next.first;
                break;
            }
        }
        if (current == prev)
            break;
    }
    return distances;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        graph.push_back(empty_node);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].edges.push_back(v - 1);
        graph[v - 1].edges.push_back(u - 1);
    } 
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        graph[i].weight = c;
    }
    // meassures distance from start and target of every node
    vector<ll> start_distances = djikstra(0);
    vector<ll> target_distances = djikstra(n - 1);
    for (int i = 0; i < n; i++) {
        graph[i].start_dist = start_distances[i];
        graph[i].target_dist = target_distances[i];
    }
    
    int o = n - k;
    // BFS
    unordered_set<int> visited({0});
    vector<int> prev, next({0});
    while (true) {
        swap(next, prev);
        next.clear();

        for (int u : prev) {
            for (int e : graph[u].edges) {
                if (graph[e].start_dist + graph[e].target_dist -
                    graph[e].weight == graph[0].target_dist &&
                    visited.find(e) == visited.end()) {

                    next.push_back(e);                    
                    visited.insert(e);
                }
            }
        }
        int c = prev.size() + next.size();
        bool ended = false;
        for (int u : next) {
            if (u == n - 1 && c > k && c > o) {
                cout << -1 << endl;
                return;
            }
        }
        if (k >= c || o >= c)
            break;
    }

    unordered_set<int> kasi, opea;
    for (int i = 0; i < prev.size() + next.size(); i++) {
        int u;
        if (i < prev.size()) {
            u = prev[i];
        } else {
            u = next[i - prev.size()];
        }
        if (k >= o) {
            kasi.insert(u);
        } else {
            opea.insert(u);
        }
    }
    for (int i = 0; kasi.size() < k; i++) {
        if (opea.find(i) == opea.end())
            kasi.insert(i);
    }
    for (auto a : kasi) {
        cout << a + 1 << " ";
    }
    cout << endl;
}

int main() {
    int t = 1;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
       graph.clear();
       solve();
    }
}