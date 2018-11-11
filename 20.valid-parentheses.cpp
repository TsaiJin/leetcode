#include <stack>

#define expect_square_bracket 1
#define expect_brace 2
#define expect_bracket 3

class Solution {
public:
    bool isValid(string s) {
        stack<int> my_stack;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '[':
                    my_stack.push(expect_square_bracket);
                    break;
                case '{':
                    my_stack.push(expect_brace);
                    break;
                case '(':
                    my_stack.push(expect_bracket)
                    break;
                case ')':
                    if (my_stack.top() == expect_bracket) {
                        my_stack.pop();
                        break;
                    } else {
                        return false;
                    }
                case '{':
                    if (my_stack.top() == expect_brace {
                        my_stack.pop();
                        break;
                    } else {
                        return false;
                    }
                case '[':
                    if (my_stack.top() == expect_square_bracket) {
                        my_stack.pop();
                        break;
                    } else {
                        return false;
                    }
                default:
                    return false;
            }
        }
        return false;
    }
};
