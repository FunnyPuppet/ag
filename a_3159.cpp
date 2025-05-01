#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, int> hash;

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                hash[++cnt] = i;
            }
        }

        vector<int> ans;

        for (int querie : queries) {
            if (hash.find(querie) != hash.end()) {
                ans.push_back(hash[querie]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};

int main(){
    Solution sl;
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    sl.occurrencesOfElement(tasks, workers, 1);
    return 0;
}
