/*
 * PROBLEM: Maximum Subarray
 * PLATFORM: LeetCode #53
 * LINK: https://leetcode.com/problems/maximum-subarray/
 *
 * PROBLEM STATEMENT:
 * Given an integer array nums, find the subarray with the largest sum,
 * and return its sum.
 *
 * APPROACH: Kadane's Algorithm
 * - Keep track of current running sum
 * - If current sum goes negative, reset it to 0 (start fresh)
 * - Track the maximum sum seen so far
 *
 * TIME COMPLEXITY:  O(n) — single pass
 * SPACE COMPLEXITY: O(1) — no extra space used
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0; // reset — no point carrying negative sum
            }
        }

        return maxSum;
    }
};

// ---- Test ----
int main() {
    Solution sol;

    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1: " << sol.maxSubArray(nums1) << endl;
    // Expected: 6 (subarray [4,-1,2,1])

    vector<int> nums2 = {1};
    cout << "Test 2: " << sol.maxSubArray(nums2) << endl;
    // Expected: 1

    vector<int> nums3 = {5, 4, -1, 7, 8};
    cout << "Test 3: " << sol.maxSubArray(nums3) << endl;
    // Expected: 23

    return 0;
}
