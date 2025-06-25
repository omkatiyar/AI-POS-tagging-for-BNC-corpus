#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element (for testing/verification)

// Function to find the minimum element in a rotated sorted array (unique elements)
// The array is sorted and then rotated k times. The minimum element is the pivot point.
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findMin(const std::vector<int>& nums) {
    if (nums.empty()) {
        // Or throw an exception, depending on problem constraints
        return -1; // Should not happen based on constraints (1 <= nums.length)
    }

    int low = 0;
    int high = nums.size() - 1;
    int minVal = nums[0]; // Initialize with first element, or use INT_MAX

    // If the array is not rotated at all (or rotated n times)
    if (nums[low] <= nums[high]) {
        return nums[low];
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // The minimum element will be the one that is smaller than its previous element
        // (if mid > 0, to handle array start) OR it's the only element left.
        // Also, if nums[mid] > nums[mid+1], then nums[mid+1] is the minimum.

        // If mid element is greater than its next element, then mid+1 element is the minimum
        if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        // If mid element is smaller than its previous element, then mid is the minimum
        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            return nums[mid];
        }

        // Decide which half to search
        // If nums[low] <= nums[mid], the left part is sorted.
        // The pivot (minimum) must be in the right part.
        if (nums[low] <= nums[mid]) {
            low = mid + 1;
        }
        // If nums[mid] <= nums[high], the right part is sorted.
        // The pivot (minimum) could be nums[mid] or in the left part.
        else { // nums[mid] < nums[low] implies pivot is in left half including mid
            high = mid - 1;
        }
    }
    // Fallback, though the logic above should find it.
    // For an array like {1}, low becomes > high quickly.
    // A more robust approach for finding minimum in rotated array:
    low = 0;
    high = nums.size() -1;
    minVal = nums[0];

    if (nums[low] <= nums[high]) return nums[low]; // Already sorted or single element

    while(low <= high){
        int mid = low + (high - low) / 2;
        minVal = std::min(minVal, nums[mid]);

        // If left part is sorted
        if(nums[low] <= nums[mid]){
            minVal = std::min(minVal, nums[low]); // Smallest in sorted left part is nums[low]
            low = mid + 1; // Search in right unsorted part
        }
        // If right part is sorted
        else { // nums[mid] < nums[low] means pivot is in left half (including mid)
            minVal = std::min(minVal, nums[mid]); // nums[mid] could be the minimum
            high = mid - 1; // Search in left part
        }
    }
    return minVal;
}


int main() {
    // Example Usage
    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    // Expected: 1
    std::cout << "Array: {3,4,5,1,2}. Min: " << findMin(nums1) << std::endl;
    // std::cout << "Actual min using std::min_element: " << *std::min_element(nums1.begin(), nums1.end()) << std::endl;


    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    // Expected: 0
    std::cout << "Array: {4,5,6,7,0,1,2}. Min: " << findMin(nums2) << std::endl;
    // std::cout << "Actual min using std::min_element: " << *std::min_element(nums2.begin(), nums2.end()) << std::endl;

    std::vector<int> nums3 = {11, 13, 15, 17};
    // Expected: 11 (array is sorted, not rotated, or rotated n times)
    std::cout << "Array: {11,13,15,17}. Min: " << findMin(nums3) << std::endl;
    // std::cout << "Actual min using std::min_element: " << *std::min_element(nums3.begin(), nums3.end()) << std::endl;

    std::vector<int> nums4 = {1};
    // Expected: 1
    std::cout << "Array: {1}. Min: " << findMin(nums4) << std::endl;
    // std::cout << "Actual min using std::min_element: " << *std::min_element(nums4.begin(), nums4.end()) << std::endl;

    std::vector<int> nums5 = {2, 1};
    // Expected: 1
    std::cout << "Array: {2,1}. Min: " << findMin(nums5) << std::endl;
    // std::cout << "Actual min using std::min_element: " << *std::min_element(nums5.begin(), nums5.end()) << std::endl;

    std::vector<int> nums6 = {5,1,2,3,4};
    // Expected: 1
    std::cout << "Array: {5,1,2,3,4}. Min: " << findMin(nums6) << std::endl;

    return 0;
}
