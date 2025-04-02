#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <list>

using namespace std;

class Solution {
public:

    string reverseWords(string s) {
        vector<string> words;
        int i = s.size() - 1, j = i;

        while (i >= 0) {
            while (i >= 0 && s[i] != ' ') {
                i--;
            }

            if (i != j) {
                words.push_back(s.substr(i + 1, (j - i)));
            }

            while (i >= 0 && s[i] == ' ') {
                i--;
                j = i;
            }
        }

        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += ' ';
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution sl;

    sl.reverseWords("the sky is blue");

    return 0;
}
