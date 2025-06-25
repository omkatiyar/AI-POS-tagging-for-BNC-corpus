#include <iostream>
#include <vector>
#include <algorithm>

// Function to search for a target in a rotated sorted array (unique elements)
// Time Complexity: O(log n)
// Space Complexity: O(1)
int searchInRotatedSortedArrayI(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        }

        // Check if the left half (low to mid) is sorted
        if (nums[low] <= nums[mid]) {
            // If target is within the sorted left half
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1;  // Search in the right half
            }
        }
        // Otherwise, the right half (mid to high) must be sorted
        else {
            // If target is within the sorted right half
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }
    return -1; // Target not found
}

int main() {
    // Example Usage
    std::vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    // Expected: 4
    std::cout << "Array: {4,5,6,7,0,1,2}, Target: 0. Index: " << searchInRotatedSortedArrayI(nums1, target1) << std::endl;

    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    // Expected: -1
    std::cout << "Array: {4,5,6,7,0,1,2}, Target: 3. Index: " << searchInRotatedSortedArrayI(nums2, target2) << std::endl;

    std::vector<int> nums3 = {1};
    int target3 = 0;
    // Expected: -1
    std::cout << "Array: {1}, Target: 0. Index: " << searchInRotatedSortedArrayI(nums3, target3) << std::endl;

    std::vector<int> nums4 = {1};
    int target4 = 1;
    // Expected: 0
    std::cout << "Array: {1}, Target: 1. Index: " << searchInRotatedSortedArrayI(nums4, target4) << std::endl;

    std::vector<int> nums5 = {3, 1};
    int target5 = 1;
    // Expected: 1
    std::cout << "Array: {3,1}, Target: 1. Index: " << searchInRotatedSortedArrayI(nums5, target5) << std::endl;

    std::vector<int> nums6 = {5, 1, 3};
    int target6_1 = 5; // Expected: 0
    int target6_2 = 1; // Expected: 1
    int target6_3 = 3; // Expected: 2
    int target6_4 = 0; // Expected: -1
    std::cout << "Array: {5,1,3}, Target: 5. Index: " << searchInRotatedSortedArrayI(nums6, target6_1) << std::endl;
    std::cout << "Array: {5,1,3}, Target: 1. Index: " << searchInRotatedSortedArrayI(nums6, target6_2) << std::endl;
    std::cout << "Array: {5,1,3}, Target: 3. Index: " << searchInRotatedSortedArrayI(nums6, target6_3) << std::endl;
    std::cout << "Array: {5,1,3}, Target: 0. Index: " << searchInRotatedSortedArrayI(nums6, target6_4) << std::endl;


    return 0;
}
