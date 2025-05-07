#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>
#include <numeric>
#include <stack>

using namespace std;

class Solution {
    struct State {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator < (const State &rth) const {
            return dis > rth.dis;
        }
    };
public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;
        priority_queue<State> q;
        q.emplace(0, 0, 0);

        while (q.size()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) {
                continue;
            }
            v[s.x][s.y] = 1;
            for (auto & dir : dirs) {
                int nx = s.x + dir[0];
                int ny = s.y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.emplace(nx, ny, dist);
                }
            }
        }
        return d[n - 1][m - 1];
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
