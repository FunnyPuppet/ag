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

class FenwickTree {
private:
    vector<int> tree;
public:
    explicit FenwickTree(int size) : tree(size + 1, 0) {}

    static int lowBit(int index) {
        return index & -index;
    }

    void update(int index, int delta) {
        index++;
        while (index < tree.size()) {
            tree[index] += delta;
            index += lowBit(index);
        }
    }

    int query(int index) {
        index++;
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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n), reversedIndexMapping(n);
        for (int i = 0; i < n; i++) {
            pos2[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reversedIndexMapping[pos2[nums1[i]]] = i;
        }
        FenwickTree tree(n);
        long long res = 0;
        for (int value = 0; value < n; value++) {
            int pos = reversedIndexMapping[value];
            int left = tree.query(pos);
            tree.update(pos, 1);
            int right = (n - 1 - pos) - (value - left);
            res += static_cast<long long>(left) * right;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums1 = {2,0,1,3};
    vector<int> nums2 = {0,1,2,3};
    Solution sl;
    long long res = sl.goodTriplets(nums1, nums2);

    cout << res << endl;

    return 0;
}
