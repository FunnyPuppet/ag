#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> map;
        for (const auto& word : words1) {
            map[word]++;
        }
        for (const auto& word : words2) {
            if (map[word] < 2) {
                map[word]--;
            }
        }

        int res = 0;
        for (const auto& pair : map) {
            if (pair.second == 0) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    vector<string> words1 = {"leetcode","is","amazing","as","is"};
    vector<string> words2 = {"amazing","leetcode","is"};
    Solution sl;
    int res = sl.countWords(words1, words2);

    cout << res << endl;

    return 0;
}
