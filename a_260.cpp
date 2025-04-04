#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorNum = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            xorNum ^= nums[i];
        }

        long long lowb = (long long)xorNum & (-xorNum);
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (num & lowb) {
                t1 ^= num;
            } else {
                t2 ^= num;
            }
        }

        return {t1, t2};
    }
};

int main(int argc, char *argv[]) {


    return 0;
}
