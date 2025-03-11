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
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort (people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (auto & i : people) {
            int position = i[1];
            auto it = que.begin();
            while (position--) {
                ++it;
            }
            que.insert(it, i);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};


int main(int argc, char *argv[]) {
    Solution sl;

    vector<vector<int>> people = {{7,1}, {5,0}, {6,2}};
    vector<vector<int>> res = sl.reconstructQueue(people);

    for (auto r : res) {
        cout << r[0] << ":" << r[1] << endl;
    }

    return 0;
}
