#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> set;

        int res = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                for (int j = i; j < word.size(); j++) {
                    if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
                        set.insert(word[j]);
                        if (set.size() == 5) {
                            res++;
                        }
                    } else {
                        set.clear();
                        break;
                    }
                }
                set.clear();
            }
        }

        return res;
    }
};

int main() {
    Solution sl;
    int res = sl.countVowelSubstrings("aeiouu");

    cout << res << endl;

    return 0;
}
