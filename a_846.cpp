#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> map;

        for (int num : hand) {
            map[num]++;
        }

        unsigned long long count = hand.size() / groupSize;

        for (int num : hand) {
            if (map[num]-- > 0) {
                int cnt = 1;
                while (cnt < groupSize && map[++num]-- > 0) {
                    cnt++;
                }
                if (cnt != groupSize) return false;
                count--;
            }
        }

        return count == 0;
    }
};


int main() {
    vector<int> nums = {1,1,3,3,4,4,5,6};
    Solution sl;

    bool res = sl.isNStraightHand(nums, 4);

    cout << res << endl;

    return 0;
}
