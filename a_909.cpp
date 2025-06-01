#include <algorithm>
#include <complex>
#include <cstdint>
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
#include <string.h>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int8_t> vis(n * n + 1);
        vis[1] = true;
        vector<int> q = {1};
        for (int step = 0; !q.empty(); step++) {
            auto tmp = q;
            q.clear();
            for (int x : tmp) {
                if (x == n * n) {
                    return step;
                }
                for (int y = x + 1; y <= min(x + 6, n * n); y++) {
                    int r = (y - 1) / n, c = (y - 1) % n;
                    if (r % 2) {
                        c = n - 1 - c;
                    }
                    int nxt = board[n - 1 - r][c];
                    if (nxt < 0) {
                        nxt = y;
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push_back(nxt);
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
