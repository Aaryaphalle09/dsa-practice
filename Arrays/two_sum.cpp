/*
 * PROBLEM: Two Sum
 * PLATFORM: LeetCode #1
 * LINK: https://leetcode.com/problems/two-sum/
 *
 * PROBLEM STATEMENT:
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers that add up to target.
 *
 * APPROACH: HashMap (Unordered Map)
 * - For each element, check if (target - element) already exists in map
 * - If yes, we found our pair → return indices
 * - If no, store the element and its index in map
 *
 * TIME COMPLEXITY:  O(n) — single pass through the array
 * SPACE COMPLEXITY: O(n) — storing elements in hashmap
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (seen.count(complement)) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }

        return {}; // no solution found
    }
};

// ---- Test ----
int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test 1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    // Expected: [0, 1]

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test 2: [" << result2[0] << ", " << result2[1] << "]" << endl;
    // Expected: [1, 2]

    return 0;
}
