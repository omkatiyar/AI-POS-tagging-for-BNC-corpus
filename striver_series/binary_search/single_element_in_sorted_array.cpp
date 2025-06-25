#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate with XOR (for verification)

// Function to find the single element in a sorted array where all other elements appear twice.
// The array is sorted, and pairs are adjacent.
// Example: [1,1,2,2,3,4,4,5,5] -> single element is 3
// Example: [1,1,2,3,3,4,4] -> single element is 2
//
// Logic:
// If we are at an even index `mid`, its pair should be at `mid+1`.
//   - If `nums[mid] == nums[mid+1]`, the single element is to the right of `mid+1`.
//   - If `nums[mid] != nums[mid+1]`, then `nums[mid]` could be the single element, or the single element is to its left.
// If we are at an odd index `mid`, its pair should be at `mid-1`.
//   - If `nums[mid] == nums[mid-1]`, the single element is to the right of `mid`.
//   - If `nums[mid] != nums[mid-1]`, then `nums[mid]` could be the single element, or the single element is to its left.
//
// A simpler observation:
// Before the single element, pairs are (nums[even_idx], nums[odd_idx]).
// After the single element, pairs are (nums[odd_idx], nums[even_idx]).
//
// We want to find the first even index `i` where `nums[i] != nums[i+1]`.
// If such an index is found, `nums[i]` is the single element.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
int singleNonDuplicate(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return -1; // Or throw error, though problem constraints usually say n >= 1
    if (n == 1) return nums[0];

    int low = 0;
    int high = n - 1;

    // Handle edge cases where single element is at the beginning or end
    // This check is implicitly handled by the main binary search loop's boundary conditions
    // when high = n-2 (for even length check logic) or high = n-1 (for odd length check logic).

    // We are looking for an element nums[mid] such that it's not equal to its neighbors.
    // A more structured binary search:
    // The array structure is [p1,p1, p2,p2, ..., pk,pk, SINGLE, q1,q1, ..., qm,qm]
    // OR [SINGLE, q1,q1, ..., qm,qm]
    // OR [p1,p1, ..., pk,pk, SINGLE]
    //
    // Consider indices:
    // (0,1), (2,3), (4,5), ...
    // If nums[mid] == nums[mid^1] (mid^1 gives mid+1 if mid is even, mid-1 if mid is odd)
    // it means the pair for nums[mid] is where it's expected if no single element has occurred yet.
    // So, the single element is to the right.
    // Otherwise, the single element is to the left (or it's nums[mid]).

    low = 0;
    high = n - 1; // Search the entire array initially

    while(low < high){ // Loop until low == high, which will be the index of the single element
        int mid = low + (high - low) / 2;
        // Ensure mid is an even index to simplify pair checking (mid, mid+1)
        // If mid is odd, we can effectively look at the pair starting at mid-1.
        // Or, a common trick is to ensure mid is always the first element of a potential pair.
        if (mid % 2 == 1) {
            mid--; // Adjust mid to be an even index (start of a pair)
        }

        // Now mid is an even index. Its pair should be at mid+1.
        if (nums[mid] == nums[mid+1]) {
            // Pair is intact: (nums[mid], nums[mid+1])
            // This means the single element is in the right part: [mid+2 ... high]
            low = mid + 2;
        } else {
            // Pair is broken: (nums[mid] != nums[mid+1])
            // This means nums[mid] is the single element OR the single element is in the left part
            // ending at mid.
            // Since nums[mid] != nums[mid+1], and all elements before this point appeared in pairs,
            // nums[mid] must be the single element.
            high = mid;
        }
    }
    // When low == high, this index points to the single element.
    return nums[low];
}

// XOR sum approach for verification (O(n) time, O(1) space)
int singleNonDuplicate_XOR(const std::vector<int>& nums) {
    if (nums.empty()) return -1; // Should not happen based on typical constraints
    return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
}

int main() {
    // Example Usage
    std::vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    // Expected: 2
    std::cout << "Array: {1,1,2,3,3,4,4,8,8}. Single: " << singleNonDuplicate(nums1) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums1) << std::endl;

    std::vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    // Expected: 10
    std::cout << "Array: {3,3,7,7,10,11,11}. Single: " << singleNonDuplicate(nums2) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums2) << std::endl;

    std::vector<int> nums3 = {1};
    // Expected: 1
    std::cout << "Array: {1}. Single: " << singleNonDuplicate(nums3) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums3) << std::endl;

    std::vector<int> nums4 = {1, 1, 2};
    // Expected: 2
    std::cout << "Array: {1,1,2}. Single: " << singleNonDuplicate(nums4) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums4) << std::endl;

    std::vector<int> nums5 = {0, 1, 1, 2, 2, 3, 3};
    // Expected: 0
    std::cout << "Array: {0,1,1,2,2,3,3}. Single: " << singleNonDuplicate(nums5) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums5) << std::endl;

    std::vector<int> nums6 = {1,1,2,2,3,3,4};
    // Expected: 4
    std::cout << "Array: {1,1,2,2,3,3,4}. Single: " << singleNonDuplicate(nums6) << std::endl;
    // std::cout << "XOR verification: " << singleNonDuplicate_XOR(nums6) << std::endl;

    return 0;
}
