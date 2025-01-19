#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        vector<string> result;

        string current = {pressedKeys[0]};

        for (size_t i = 1; i < pressedKeys.size(); ++i) {
            if (pressedKeys[i] == pressedKeys[i - 1]) {
                current += pressedKeys[i];
            } else {
                result.push_back(current);
                current = {pressedKeys[i]};
            }
        }

        result.push_back(current);

        long long res = 1;
        int m = 1000000007;
        for (size_t i = 0; i < result.size(); i++) {
            string str = result[i];

            int len = str.length();

            long long cnt;

            if (len > 3) {
                long long dp[len];

                dp[0] = 1;
                dp[1] = 2;
                dp[2] = 4;
                if (str[0] == '7' || str[0] == '9') {
                    dp[3] = 8;
                } else {
                    dp[3] = 7;
                }

                for (size_t j = 4; j < len; j++) {
                    if (str[0] == '7' || str[0] == '9') {
                        dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3] + dp[j - 4]) % m;
                    } else {
                        dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % m;
                    }
                }

                cnt = dp[len - 1];
            } else {
                cnt = 1 << (len - 1);
            }

            cnt = cnt % m;
            res = res * cnt % m;
        }

        return res % m;
    }
};

int main(){
    Solution sl;
    int res = sl.countTexts("88888888888888888888888888888999999999999999999999999999994444444444444444444444444444488888888888888888888888888888555555555555555555555555555556666666666666666666666666666666666666666666666666666666666222222222222222222222222222226666666666666666666666666666699999999999999999999999999999888888888888888888888888888885555555555555555555555555555577777777777777777777777777777444444444444444444444444444444444444444444444444444444444433333333333333333333333333333555555555555555555555555555556666666666666666666666666666644444444444444444444444444444999999999999999999999999999996666666666666666666666666666655555555555555555555555555555444444444444444444444444444448888888888888888888888888888855555555555555555555555555555555555555555555555555555555555555555555555555555555555999999999999999555555555555555555555555555554444444444444444444444444444444555");

    cout << res << endl;

    return 0;
}
