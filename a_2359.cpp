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
#include <string.h>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto get = [&](int x) {
            vector<int> d(n, -1);
            int p = x;
            int dis = 0;
            while (p != -1 && d[p] == -1) {
                d[p] = dis;
                p = edges[p];
                dis++;
            }
            return d;
        };
        auto d1 = get(node1);
        auto d2 = get(node2);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] != -1 && d2[i] != -1 && (ans == -1 || max(d1[ans], d2[ans]) > max(d1[i], d2[i]))) {
                ans = i;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
