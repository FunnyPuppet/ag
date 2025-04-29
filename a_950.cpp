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

using namespace std;


class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int n = static_cast<int>(deck.size());

        deque<int> dq;
        for(int i = n -1; i >= 0; i--){
            if(!dq.empty()){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }

        vector<int> ans(dq.begin(), dq.end());

        return ans;
    }
};

int main(int argc, char *argv[]) {

    return 0;
}
