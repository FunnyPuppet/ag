#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    const string hash[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty()) {
            return res;
        }
        string s;

        backtrack(res, s, 0, digits);

        return res;
    }

    void backtrack(vector<string>& res, string& s, int start, string digits) {
        if (s.length() == digits.length()) {
            res.push_back(s);
            return;
        }

        string t = hash[digits[start] - '0'];

        for (char c : t) {
            s.push_back(c);
            backtrack(res, s, start + 1, digits);
            s.pop_back();
        }
    }
};


int main() {
    Solution sl;

    vector<string> res = sl.letterCombinations("22");

    for (const string& s : res) {
        cout << s << endl;
    }

    return 0;
}
