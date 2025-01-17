#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            map[sortedStr].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(move(pair.second));
        }

        return result;
    }
};


int main(){
    std::vector<std::string> strs = {"tea", "ate", "eat"};

    Solution sl;
    sl.groupAnagrams(strs);

    return 0;
}
