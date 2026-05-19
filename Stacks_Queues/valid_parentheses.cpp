/*
 * PROBLEM: Valid Parentheses
 * PLATFORM: LeetCode #20
 * LINK: https://leetcode.com/problems/valid-parentheses/
 *
 * PROBLEM STATEMENT:
 * Given a string s containing just '(', ')', '{', '}', '[', ']',
 * determine if the input string is valid.
 * A string is valid if:
 * - Open brackets are closed by the same type of bracket
 * - Open brackets are closed in the correct order
 *
 * APPROACH: Stack
 * - Push every opening bracket onto the stack
 * - For every closing bracket, check if top of stack is its matching open
 * - If not matched or stack empty when closing → invalid
 * - At end, stack must be empty for valid string
 *
 * TIME COMPLEXITY:  O(n) — single pass through string
 * SPACE COMPLEXITY: O(n) — stack can hold up to n/2 elements
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // handle closing brackets
            else {
                if (st.empty()) return false; // nothing to match with

                char top = st.top();
                st.pop();

                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return st.empty(); // valid only if all brackets matched
    }
};

// ---- Test ----
int main() {
    Solution sol;

    cout << "Test 1 '()':     " << (sol.isValid("()") ? "true" : "false") << endl;
    // Expected: true

    cout << "Test 2 '()[]{}': " << (sol.isValid("()[]{}") ? "true" : "false") << endl;
    // Expected: true

    cout << "Test 3 '(]':     " << (sol.isValid("(]") ? "true" : "false") << endl;
    // Expected: false

    cout << "Test 4 '([)]':   " << (sol.isValid("([)]") ? "true" : "false") << endl;
    // Expected: false

    cout << "Test 5 '{[]}':   " << (sol.isValid("{[]}") ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
