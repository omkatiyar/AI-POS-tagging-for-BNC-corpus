#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element and std::distance (for testing/verification)

// Function to find how many times a sorted array has been rotated
// This is equivalent to finding the index of the minimum element.
// Assumes unique elements and counter-clockwise rotation.
// Time Complexity: O(log n)
// Space Complexity: O(1)
int countRotations(const std::vector<int>& arr) {
    if (arr.empty()) {
        return 0; // Or handle as an error
    }
    if (arr.size() == 1) {
        return 0;
    }

    int low = 0;
    int high = arr.size() - 1;

    // If the array is not rotated (or rotated n times)
    if (arr[low] <= arr[high]) {
        return 0; // 0 rotations
    }

    int n = arr.size();
    int minIndex = 0; // Stores the index of the minimum element

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the minimum element
        // Condition: arr[mid] <= arr[(mid + n - 1) % n] (previous element)
        // AND arr[mid] <= arr[(mid + 1) % n] (next element)
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            minIndex = mid;
            break;
        }

        // If the left half is sorted, the pivot (minimum) must be in the right half
        if (arr[low] <= arr[mid]) {
            // If arr[low] is the overall minimum so far, consider it.
            // But since we are looking for the actual pivot point,
            // we move to the unsorted part.
            low = mid + 1;
        }
        // If the right half is sorted, the pivot must be in the left half (or mid itself)
        else { // arr[mid] < arr[high] (or arr[mid] < arr[low])
            high = mid - 1;
            // minIndex = mid; // If arr[mid] could be the minimum, store it.
                           // This assignment is better placed within the condition check above.
        }
    }

    // A slightly different and often more robust way to find the index of the minimum element:
    low = 0;
    high = n - 1;
    minIndex = 0; // Default to 0 if not rotated

    if (arr[low] <= arr[high]) return 0; // Not rotated or rotated n times

    while(low <= high){
        int mid = low + (high-low)/2;

        // Check if mid is the minimum
        // The minimum element is the only element smaller than its previous (circularly)
        // and also smaller than or equal to the last element of the original sorted array (which is arr[n-1] before rotation)
        // A simpler check: if arr[mid] < arr[high], it means the right part is sorted and mid *could* be the minimum or something to its left is.
        // If arr[mid] > arr[high], it means the minimum is in the right part.

        if (arr[mid] < arr[n-1]) { // Mid could be the minimum or something to its left
             minIndex = mid;
             high = mid - 1;
        } else if (arr[mid] > arr[0] && arr[mid] > arr[n-1]) { // Minimum is definitely in the right part
            low = mid + 1;
        } else { // arr[mid] < arr[0] but arr[mid] > arr[n-1] is not possible in standard rotation
                 // This part needs refinement. Let's use the standard min element finding logic.
            // If arr[mid] is less than its 'right' neighbor (arr[high] as boundary of current search space)
            // it means the inflection point is to its left or it is the inflection point.
            if (arr[mid] <= arr[high]) { // Right part is sorted, or mid is the smallest in current view
                minIndex = mid; // Potential minimum
                high = mid - 1; // Try to find even smaller on left
            } else { // arr[mid] > arr[high] means left part is sorted, min is on right
                low = mid + 1;
            }
        }
    }

    // Final refined approach for finding the index of the minimum element:
    low = 0;
    high = n - 1;
    // If array is already sorted (0 rotations)
    if (arr[low] <= arr[high]) return 0;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int prev = (mid - 1 + n) % n; // Previous element
        int next = (mid + 1) % n;     // Next element

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
            return mid; // arr[mid] is the minimum element
        }
        // If left part is sorted, minimum is in the right part
        if (arr[low] <= arr[mid]) {
            low = mid + 1;
        }
        // If right part is sorted (or mid is in the right part which is unsorted relative to start)
        // minimum is in the left part (including mid)
        else { // arr[mid] < arr[low]
            high = mid - 1;
        }
    }
    return 0; // Should be unreachable if array has at least 1 element and is rotated
}


int main() {
    // Example Usage
    std::vector<int> arr1 = {15, 18, 2, 3, 6, 12};
    // Minimum is 2 at index 2. So, rotated 2 times.
    // Expected: 2
    std::cout << "Array: {15,18,2,3,6,12}. Rotations: " << countRotations(arr1) << std::endl;

    std::vector<int> arr2 = {7, 9, 11, 12, 5};
    // Minimum is 5 at index 4. Rotated 4 times.
    // Expected: 4
    std::cout << "Array: {7,9,11,12,5}. Rotations: " << countRotations(arr2) << std::endl;

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    // Not rotated (or rotated 0 or 5 times). Index of min is 0.
    // Expected: 0
    std::cout << "Array: {1,2,3,4,5}. Rotations: " << countRotations(arr3) << std::endl;

    std::vector<int> arr4 = {5, 1, 2, 3, 4};
    // Minimum is 1 at index 1. Rotated 1 time.
    // Expected: 1
    std::cout << "Array: {5,1,2,3,4}. Rotations: " << countRotations(arr4) << std::endl;

    std::vector<int> arr5 = {2,1};
    // Minimum is 1 at index 1. Rotated 1 time.
    // Expected: 1
    std::cout << "Array: {2,1}. Rotations: " << countRotations(arr5) << std::endl;

    std::vector<int> arr6 = {1};
    // Expected: 0
    std::cout << "Array: {1}. Rotations: " << countRotations(arr6) << std::endl;

    std::vector<int> arr7 = {3,4,5,1,2};
    // Expected: 3
    std::cout << "Array: {3,4,5,1,2}. Rotations: " << countRotations(arr7) << std::endl;


    // For verification using std::min_element:
    // auto minIt = std::min_element(arr1.begin(), arr1.end());
    // std::cout << "Verification: Index of min element for arr1: " << std::distance(arr1.begin(), minIt) << std::endl;
    // minIt = std::min_element(arr2.begin(), arr2.end());
    // std::cout << "Verification: Index of min element for arr2: " << std::distance(arr2.begin(), minIt) << std::endl;
    // minIt = std::min_element(arr3.begin(), arr3.end());
    // std::cout << "Verification: Index of min element for arr3: " << std::distance(arr3.begin(), minIt) << std::endl;

    return 0;
}
