#include <string>
#include <map>
#include <iostream>
using namespace std;

static map<char, int> CharMaps = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

class Solution {
public:
    int romanToInt(string s) {
        int final_val = 0;
        int current_val, pre_val;
        for (int i = s.length() - 1; i >= 0;) {
            if (i >= 1) {
                current_val = CharMaps[s[i]];
                pre_val = CharMaps[s[i - 1]];
                if (current_val == pre_val * 5 ||
                        current_val  == pre_val * 10) {
                    final_val += current_val - pre_val;
                    i -= 2;
                } else {
                    final_val += current_val;
                    i--;
                }
            } else {
                current_val = CharMaps[s[i]];
                final_val += current_val;
                i--;
            }
        }
        return final_val;
    }
};

int main() {
    Solution A;
    cout << A.romanToInt("LVIII") << endl;
    cout << A.romanToInt("MCMXCIV") << endl;
    return 0;
}
