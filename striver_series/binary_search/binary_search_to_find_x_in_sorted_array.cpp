#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search to find X in a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int search(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow
        if (nums[mid] == target) {
            return mid; // Target found at index mid
        } else if (nums[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    // Example Usage
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = search(arr, x);
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in array" << std::endl;
    }

    std::vector<int> arr2 = {2, 3, 4, 10, 40};
    int x2 = 5;
    int result2 = search(arr2, x2);
    if (result2 != -1) {
        std::cout << "Element found at index " << result2 << std::endl;
    } else {
        std::cout << "Element not found in array" << std::endl;
    }
    return 0;
}
