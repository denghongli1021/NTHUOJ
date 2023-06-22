#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// G[i] is the neighbor towns of town i
vector<int> diamondTowns;
vector<int> G[100005];
int Dist[100005];

struct node {
    int id;
    int dist;
    node(int id, int l) {
        this->id = id;
        this->dist = l;
    }
};

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        diamondTowns.push_back(x);
    }
    fill(Dist, Dist+100005, -1);

    queue<node> Q;

    // [TODO] complete the task!
    for (auto start : diamondTowns) {
        // for every diamond town the distance is 0
        Dist[start] = 0;
        Q.push(node(start, 0));

        while (Q.size()) {
            // Q.size() 回傳 0 代表 沒有東西
            for (auto curr_town : G[Q.front().id]) {
                // the following method can ensure
                // that every node will be traversed less than once
                if (Dist[curr_town] == -1 || Dist[curr_town] > Q.front().dist + 1) {
                    Dist[curr_town] = Q.front().dist + 1;
                    Q.push(node(curr_town, Q.front().dist + 1));
                }
            }
            Q.pop();
        }
    }

    // Output
    for (int i = 1; i <= N; i++) {
        cout << Dist[i] << '\n';
    }
    return 0;
}
