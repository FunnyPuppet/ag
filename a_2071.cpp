#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto check = [&](int mid) -> bool {
            int p = pills;
            deque<int> ws;
            int ptr = m - 1;

            for (int i = mid - 1; i >= 0; --i) {
                while (ptr >= m - mid && workers[ptr] + strength >= tasks[i]) {
                    ws.push_front(workers[ptr]);
                    --ptr;
                }
                if (ws.empty()) {
                    return false;
                }
                if (ws.back() >= tasks[i]) {
                    ws.pop_back();
                } else {
                    if (!p) {
                        return false;
                    }
                    --p;
                    ws.pop_front();
                }
            }
            return true;
        };

        int left = 1, right = min(m, n), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sl;
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    sl.maxTaskAssign(tasks, workers, 1, 1);
    return 0;
}
