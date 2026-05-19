/*
 * PROBLEM: Contains Duplicate
 * PLATFORM: LeetCode #217
 * LINK: https://leetcode.com/problems/contains-duplicate/
 *
 * PROBLEM STATEMENT:
 * Given an integer array nums, return true if any value appears
 * at least twice, and false if every element is distinct.
 *
 * APPROACH: HashSet
 * - Insert each element into an unordered_set
 * - If element already exists in set → duplicate found → return true
 * - If we finish loop without finding duplicate → return false
 *
 * TIME COMPLEXITY:  O(n) — single pass
 * SPACE COMPLEXITY: O(n) — storing elements in set
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true; // duplicate found
            }
            seen.insert(num);
        }

        return false; // no duplicates
    }
};

// ---- Test ----
int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Test 1: " << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;
    // Expected: true

    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test 2: " << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;
    // Expected: false

    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Test 3: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;
    // Expected: true

    return 0;
}
