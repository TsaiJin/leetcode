class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string first_str = strs[0];
        int min_common = first_str.length();
        int len;
        for (int i = 1; i < strs.size(); i++) {
            len = 0;
            for (int p = 0; p < strs[i].length() && p < first_str.length(); p++) {
                if (strs[i][p] != first_str[p])
                    break;
                len++;
            }
            if (len < min_common)
                min_common = len;
        }
        if (min_common == 0)
            return "";
        else
            return first_str.substr(0, min_common);
    }
};

