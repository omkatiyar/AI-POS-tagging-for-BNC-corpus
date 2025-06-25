#include <iostream>
#include <vector>
#include <algorithm>

// Function to search for a target in a rotated sorted array (with duplicates)
// Time Complexity: O(log n) in the average case, O(n) in the worst case (e.g., all elements are the same)
// Space Complexity: O(1)
bool searchInRotatedSortedArrayII(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return true; // Target found
        }

        // Handle the case where nums[low] == nums[mid] == nums[high]
        // This is the tricky part due to duplicates. We can't determine which half is sorted.
        // So, we shrink the search space from both ends.
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
            continue; // Continue to the next iteration with the reduced range
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
    return false; // Target not found
}

int main() {
    // Example Usage
    std::vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1_1 = 0; // Expected: true
    int target1_2 = 3; // Expected: false
    std::cout << "Array: {2,5,6,0,0,1,2}, Target: 0. Found: " << (searchInRotatedSortedArrayII(nums1, target1_1) ? "true" : "false") << std::endl;
    std::cout << "Array: {2,5,6,0,0,1,2}, Target: 3. Found: " << (searchInRotatedSortedArrayII(nums1, target1_2) ? "true" : "false") << std::endl;

    std::vector<int> nums2 = {1, 0, 1, 1, 1};
    int target2_1 = 0; // Expected: true
    std::cout << "Array: {1,0,1,1,1}, Target: 0. Found: " << (searchInRotatedSortedArrayII(nums2, target2_1) ? "true" : "false") << std::endl;

    std::vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1};
    int target3_1 = 2; // Expected: true
    std::cout << "Array: {lots of 1s, one 2}, Target: 2. Found: " << (searchInRotatedSortedArrayII(nums3, target3_1) ? "true" : "false") << std::endl;

    std::vector<int> nums4 = {3,1,1};
    int target4_1 = 3; // Expected: true
    std::cout << "Array: {3,1,1}, Target: 3. Found: " << (searchInRotatedSortedArrayII(nums4, target4_1) ? "true" : "false") << std::endl;

    std::vector<int> nums5 = {1,1,3,1};
    int target5_1 = 3; // Expected: true
    std::cout << "Array: {1,1,3,1}, Target: 3. Found: " << (searchInRotatedSortedArrayII(nums5, target5_1) ? "true" : "false") << std::endl;

    std::vector<int> nums6 = {1,3};
    int target6_1 = 3; // Expected: true
    std::cout << "Array: {1,3}, Target: 3. Found: " << (searchInRotatedSortedArrayII(nums6, target6_1) ? "true" : "false") << std::endl;

    std::vector<int> nums7 = {0,0,0,0,0};
    int target7_1 = 0; // Expected: true
    int target7_2 = 1; // Expected: false
    std::cout << "Array: {0,0,0,0,0}, Target: 0. Found: " << (searchInRotatedSortedArrayII(nums7, target7_1) ? "true" : "false") << std::endl;
    std::cout << "Array: {0,0,0,0,0}, Target: 1. Found: " << (searchInRotatedSortedArrayII(nums7, target7_2) ? "true" : "false") << std::endl;


    return 0;
}
