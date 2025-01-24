#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getNext(int x) {
    int sum = 0;

    while (x > 0) {
        int d = x % 10;

        sum += d * d;

        x /= 10;
    }

    return sum;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;

        while (set.find(n) == set.end()) {
            set.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};



int main() {
    Solution sl;
    bool res = sl.isHappy(2);

    cout << res << endl;

    return 0;
}
