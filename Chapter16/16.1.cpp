#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

bool is_feasible(vector<vector<int> > &m, int cx, int cy) {
    int Y = (int)m.size();
    int X = (int)m[0].size();
    return 0 <= cx && cx < X && 0 <= cy && cy < Y && m[cy][cx] == 0;
}


/**
 *  Time Complexity:  O(XY)
 *  Space Complexity: O(H)
 *  H is depth.
 */
bool dfs(vector<vector<int> > &m, int cx, int cy, int ex, int ey, vector<pair<int, int>> &path) {
    if (cx == ex && cy == ey)
        return true;
    m[cy][cx] = 2;
    for (int i=0; i<4; ++i) {
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        path.emplace_back(nx, ny);
        if (is_feasible(m, nx, ny) && dfs(m, nx, ny, ex, ey, path)) {
            return true;
        }
        path.pop_back();
    }
    return false;
}

vector<pair<int, int>> find(vector<vector<int> > &m, int sx, int sy, int ex, int ey) {
    vector<pair<int, int>> path;
    if (!dfs(m, sx, sy, ex, ey, path)) {
        path.clear();
    }
    return path;
}

/**
 *  Time Complexity:  O(XY)
 *  Space Complexity: O(XY)
 */
bool bfs(vector<vector<int> > &m, int sx, int sy, int ex, int ey) {
    queue<pair<int, int>> que;
    que.emplace(sx, sy);
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        for (int i=0; i<4; ++i) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (is_feasible(m, nx, ny)) {
                if (nx == ex && ny == ey) {
                    return true;
                }
                m[ny][nx] = 2;
                que.emplace(nx, ny);
            }
        }
    }
    return false;
}

// 0:white
// 1:black
int main() {
    vector<vector<int> > m = {
        {1,1,1,1,0},
        {1,1,1,0,0},
        {1,1,0,0,1},
        {1,0,0,1,1},
        {0,0,1,1,1}
    };
    int sx = 0, sy = 4;
    int ex = 4, ey = 0;
//  cout << bfs(m, sx, sy, ex, ey) << endl;
    vector<pair<int, int>> path(find(m, sx, sy, ex, ey));
    for (auto p: path) {
        cout << p.first << "," << p.second << endl;
    }
}