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
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> us;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) {
                        continue;
                    }

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && (num & 1) == 0) {
                        us.insert(num);
                    }
                }
            }
        }

        vector<int> ans;

        for (int u : us) {
            ans.emplace_back(u);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
