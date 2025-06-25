#include <iostream>
#include <vector>

// Function to find the search insert position
// This is equivalent to finding the lower bound of the target value.
// It returns the index where the target would be if it were inserted in order.
// If the target is already present, it returns the index of its first occurrence.
// Time Complexity: O(log n)
// Space Complexity: O(1)
int searchInsert(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size(); // Default answer: insert at the end if target is greater than all elements

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
            ans = mid;      // Potential position, try to find an earlier one
            high = mid - 1;
        } else { // nums[mid] < target
            low = mid + 1;  // Target must be in the right half
        }
    }
    return ans;
}

int main() {
    // Example Usage
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    // Expected: 2 (index of 5)
    std::cout << "Search insert position for " << target1 << " in {1,3,5,6} is " << searchInsert(nums1, target1) << std::endl;

    std::vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    // Expected: 1 (index where 2 would be inserted)
    std::cout << "Search insert position for " << target2 << " in {1,3,5,6} is " << searchInsert(nums2, target2) << std::endl;

    std::vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    // Expected: 4 (insert at the end)
    std::cout << "Search insert position for " << target3 << " in {1,3,5,6} is " << searchInsert(nums3, target3) << std::endl;

    std::vector<int> nums4 = {1, 3, 5, 6};
    int target4 = 0;
    // Expected: 0 (insert at the beginning)
    std::cout << "Search insert position for " << target4 << " in {1,3,5,6} is " << searchInsert(nums4, target4) << std::endl;

    std::vector<int> nums5 = {1};
    int target5 = 0;
    // Expected: 0
    std::cout << "Search insert position for " << target5 << " in {1} is " << searchInsert(nums5, target5) << std::endl;

    return 0;
}
