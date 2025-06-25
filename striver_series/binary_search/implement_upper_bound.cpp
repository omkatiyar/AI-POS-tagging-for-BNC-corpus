#include <iostream>
#include <vector>
#include <algorithm> // For std::upper_bound (for comparison/testing if needed)

// Function to implement upper bound
// Upper bound is the first index at which an element > x can be inserted
// while maintaining the sorted order of the array.
// It returns the smallest index `ind` such that arr[ind] > x.
// If all elements are smaller than or equal to x, it returns n (size of the array).
// Time Complexity: O(log n)
// Space Complexity: O(1)
int upperBound(std::vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // Default answer if no element is > x

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;      // Potential answer, try to find a smaller index
            high = mid - 1;
        } else { // arr[mid] <= x
            low = mid + 1;  // We need an element strictly greater than x
        }
    }
    return ans;
}

int main() {
    // Example Usage
    std::vector<int> arr1 = {1, 2, 2, 3, 3, 5, 6};
    int x1 = 3;
    int result1 = upperBound(arr1, x1);
    // Expected: index of 5, which is 5. (arr[5] = 5, which is > 3. arr[4]=3 is not > 3)
    std::cout << "Upper bound of " << x1 << " is at index " << result1 << std::endl;


    std::vector<int> arr2 = {1, 2, 3, 4, 6};
    int x2 = 5;
    int result2 = upperBound(arr2, x2);
    // Expected: index of 6, which is 4. (arr[4]=6, which is > 5)
    std::cout << "Upper bound of " << x2 << " is at index " << result2 << std::endl;

    std::vector<int> arr3 = {10, 20, 30, 40, 50};
    int x3 = 5;
    int result3 = upperBound(arr3, x3);
    // Expected: index of 10, which is 0. (arr[0]=10, which is > 5)
    std::cout << "Upper bound of " << x3 << " is at index " << result3 << std::endl;

    std::vector<int> arr4 = {10, 20, 30, 40, 50};
    int x4 = 55;
    int result4 = upperBound(arr4, x4);
    // Expected: arr4.size(), which is 5. (No element > 55)
    std::cout << "Upper bound of " << x4 << " is at index " << result4 << std::endl;

    std::vector<int> arr5 = {10, 20, 20, 20, 30, 40};
    int x5 = 20;
    int result5 = upperBound(arr5, x5);
    // Expected: index of 30, which is 4. (arr[4]=30 > 20. arr[3]=20 is not > 20)
    std::cout << "Upper bound of " << x5 << " is at index " << result5 << std::endl;

    std::vector<int> arr6 = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int x6 = 6;
    int result6 = upperBound(arr6, x6);
    // Expected: index of 7, which is 3
    std::cout << "Upper bound of " << x6 << " is at index " << result6 << std::endl;


    // Using std::upper_bound for verification
    // auto it = std::upper_bound(arr1.begin(), arr1.end(), x1);
    // std::cout << "std::upper_bound result for arr1, x1: " << (it - arr1.begin()) << std::endl;
    // auto it6 = std::upper_bound(arr6.begin(), arr6.end(), x6);
    // std::cout << "std::upper_bound result for arr6, x6: " << (it6 - arr6.begin()) << std::endl;


    return 0;
}
