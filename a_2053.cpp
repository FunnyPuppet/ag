#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;

        for (const string& str : arr) {
            map[str]++;
        }

        string res;
        int pos = 1;
        for (const auto& str : arr) {
            if (map[str] == 1) {
                if (pos == k) {
                    res = str;
                    break;
                }
                pos ++;
            }
        }

        return res;
    }
};

int main() {
    vector<string> arr;
    arr.push_back("aaa");
    arr.push_back("aa");
    arr.push_back("a");

    Solution sl;
    sl.kthDistinct(arr, 1);
    return 0;
}
