#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    int includedCount;  // New field to track inclusion count
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.w < e2.w;
}

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int N, E;
    cin >> N >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].includedCount = 0;  // Initialize inclusion count
    }

    sort(edges.begin(), edges.end(), compareEdges);

    UnionFind uf(N);
    int totalCost = 0;
    int essentialLinks = 0;
    int secondaryLinks = 0;

    for (Edge& edge : edges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);

        if (rootU != rootV) {
            uf.unionSets(rootU, rootV);
            totalCost += edge.w;
            if (edge.includedCount == 0) {
                essentialLinks++;
            }
        } else if (edge.includedCount == 0) {
            secondaryLinks++;
        }
        edge.includedCount = 1;  // Mark as included in the current minimal-cost route
    }

    cout << totalCost << endl;
    cout << essentialLinks << endl;
    cout << secondaryLinks << endl;

    return 0;
}
