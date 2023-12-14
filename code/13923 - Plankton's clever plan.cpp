#include <iostream>
#include <queue>
#include <utility>
#include <string>

/// queue ¬O FIFO
/// push
/// empty
/// front
/// pop
/// size

using namespace std;
// should be compiled with c++17

typedef pair<int, int> pii;
// for representing positions on the map

struct Node{
    pii pos;
    int step;
    Node(pii p, int x): pos(p), step(x){}
    // pos: the current position
    // step: the current step count
};

int grid[1005][1005];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

int main(){
    int n, m;
    cin >> n >> m;
    // ed: the end position, i.e. the position of Krabby Patty
    // st: the start position, i.e. the position of Plankton at the beginning
    pii ed, st;
    // input for map
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        // set border (left and right)
        s = '#' + s + '#';
        for(int j = 0; j <= m + 1; j++){
            grid[i][j] = s[j] == '#' ? 1 : 0;
            if(s[j] == '@') ed = pii(i, j);
            if(s[j] == 'P') st = pii(i, j);
        }
    }
    // set border (top and bottom)
    for(int j = 0; j <= m + 1; j++){
        grid[0][j] = grid[n + 1][j] = 1;
    }
    queue <Node> q;
    // emplace the initial position
	// emplace: same as push but automatically construct the elements
    q.emplace(st, 0);
    grid[st.first][st.second] = 1; // set as visited
    while(q.size()){
        Node N = q.front();
        q.pop();
        // reach the destination
        if(N.pos == ed){
            cout << N.step << "\n";
            return 0;
        }
        // move left/right/up/down to the next grid
        for(int i = 0; i < 4; i++){
            // get the position of next grid
            int ti = N.pos.first + di[i];
            int tj = N.pos.second + dj[i];
            // if is visited, continue
            if(grid[ti][tj]) continue;
            // else, set the grid to visited and push into queue
            q.emplace(pii(ti, tj), N.step + 1);
            grid[ti][tj] = 1; // set as visited
        }
    }
    cout << -1 << "\n";
    return 0;
}
