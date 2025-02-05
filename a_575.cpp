#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> hash;

        int n = candyType.size();

        for (int type : candyType) {
            hash.insert(type);
        }

        if (hash.size() * 2 < n) {
            return hash.size();
        }

        return  n / 2;
    }
};



int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    Solution sl;
    int res = sl.distributeCandies(nums);

    cout << res << endl;

    return 0;
}
