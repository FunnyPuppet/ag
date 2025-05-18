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
#include <numeric>
#include <stack>
#include <string.h>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> hash_set({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        vector<int> idxs;
        vector<char> chs;

        for(int i = 0; i < s.size(); i++) {
            if(hash_set.count(s[i]) != 0) {
                idxs.emplace_back(i);
                chs.emplace_back(s[i]);
            }
        }

        sort(chs.begin(), chs.end());

        for(int i = 0; i < chs.size(); i++) s[idxs[i]] = chs[i];

        return s;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
