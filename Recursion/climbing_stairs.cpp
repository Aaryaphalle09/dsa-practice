/*
 * PROBLEM: Climbing Stairs
 * PLATFORM: LeetCode #70
 * LINK: https://leetcode.com/problems/climbing-stairs/
 *
 * PROBLEM STATEMENT:
 * You are climbing a staircase with n steps.
 * Each time you can climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * APPROACH: Dynamic Programming (Fibonacci pattern)
 * - To reach step i, you can come from step (i-1) or step (i-2)
 * - So ways[i] = ways[i-1] + ways[i-2]  ← exactly like Fibonacci!
 * - Base cases: ways[1] = 1, ways[2] = 2
 * - Optimized: use only two variables instead of full array
 *
 * TIME COMPLEXITY:  O(n) — single loop
 * SPACE COMPLEXITY: O(1) — only two variables used
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

// ---- Test ----
int main() {
    Solution sol;

    cout << "Test 1 (n=2): " << sol.climbStairs(2) << endl;
    // Expected: 2  → [1+1, 2]

    cout << "Test 2 (n=3): " << sol.climbStairs(3) << endl;
    // Expected: 3  → [1+1+1, 1+2, 2+1]

    cout << "Test 3 (n=5): " << sol.climbStairs(5) << endl;
    // Expected: 8

    cout << "Test 4 (n=10): " << sol.climbStairs(10) << endl;
    // Expected: 89

    return 0;
}
