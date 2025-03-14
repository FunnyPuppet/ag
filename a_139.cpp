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
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> fs;
        for (const auto& word_dict : wordDict) {
            fs.insert(word_dict);
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && fs.find(s.substr(j, i - j)) != fs.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    vector<string> wordDict = {"cats","dog","sand","and","cat"};
    bool res = sl.wordBreak("abcd", wordDict);

    return 0;
}
