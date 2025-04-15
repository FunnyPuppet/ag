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
#include <stack>

using namespace std;

class BIT {
private:
    vector<int> tree;
public:
    explicit BIT(int size) : tree(size + 1, 0) {}

    static int lowBit(int index) {
        return index & -index;
    }

    void update(int index, int delta) {
        while (index < tree.size()) {
            tree[index] += delta;
            index += lowBit(index);
        }
    }

    int query(int index) {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= lowBit(index);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        BIT bit(m + n);

        vector<int> pos(m + 1);
        for (int i = 1; i <= m; ++i) {
            pos[i] = n + i;
            bit.update(n + i, 1);
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int& cur = pos[queries[i]];
            bit.update(cur, -1);
            ans.push_back(bit.query(cur));
            cur = n - i;
            bit.update(cur, 1);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums1 = {3,1,2,1};
    Solution sl;
    vector<int> res = sl.processQueries(nums1, 5);

    return 0;
}
