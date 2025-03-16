#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a > b) {
                pq.push(a - b);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<int> stones = {2,7,4,1,8,1};
    int res = sl.lastStoneWeight(stones);

    cout << res << endl;

    return 0;
}
