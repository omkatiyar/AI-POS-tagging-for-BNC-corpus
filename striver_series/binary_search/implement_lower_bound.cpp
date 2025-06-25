#include <iostream>
#include <vector>
#include <algorithm> // For std::lower_bound (for comparison/testing if needed)

// Function to implement lower bound
// Lower bound is the first index at which an element >= x can be inserted
// while maintaining the sorted order of the array.
// If all elements are smaller than x, it returns n (size of the array).
// If x is present, it returns the index of the first occurrence of x.
// Time Complexity: O(log n)
// Space Complexity: O(1)
int lowerBound(std::vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default answer if no element is >= x

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;      // Potential answer, try to find a smaller index
            high = mid - 1;
        } else {
            low = mid + 1;  // arr[mid] < x, so x must be in the right half
        }
    }
    return ans;
}

int main() {
    // Example Usage
    std::vector<int> arr1 = {1, 2, 2, 3, 3, 5, 6};
    int x1 = 3;
    int result1 = lowerBound(arr1, x1);
    std::cout << "Lower bound of " << x1 << " is at index " << result1 << std::endl; // Expected: 3 (index of first 3)

    std::vector<int> arr2 = {1, 2, 3, 4, 6};
    int x2 = 5;
    int result2 = lowerBound(arr2, x2);
    std::cout << "Lower bound of " << x2 << " is at index " << result2 << std::endl; // Expected: 4 (index where 5 would be inserted, which is index of 6)

    std::vector<int> arr3 = {10, 20, 30, 40, 50};
    int x3 = 5;
    int result3 = lowerBound(arr3, x3);
    std::cout << "Lower bound of " << x3 << " is at index " << result3 << std::endl; // Expected: 0

    std::vector<int> arr4 = {10, 20, 30, 40, 50};
    int x4 = 55;
    int result4 = lowerBound(arr4, x4);
    std::cout << "Lower bound of " << x4 << " is at index " << result4 << std::endl; // Expected: 5 (arr4.size())

    std::vector<int> arr5 = {10, 20, 20, 20, 30, 40};
    int x5 = 20;
    int result5 = lowerBound(arr5, x5);
    std::cout << "Lower bound of " << x5 << " is at index " << result5 << std::endl; // Expected: 1

    // Using std::lower_bound for verification
    // auto it = std::lower_bound(arr1.begin(), arr1.end(), x1);
    // std::cout << "std::lower_bound result: " << (it - arr1.begin()) << std::endl;

    return 0;
}
