#include <iostream>
#include <vector>
#include <algorithm> // For std::lower_bound and std::upper_bound for alternative approach

// Helper function to find the first occurrence of k in a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findFirstOccurrence(const std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1; // Try to find an earlier one
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

// Helper function to find the last occurrence of k in a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findLastOccurrence(const std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1; // Try to find a later one
        } else if (arr[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

// Function to count occurrences of k in a sorted array
// It uses findFirstOccurrence and findLastOccurrence
// Count = (Last Occurrence - First Occurrence) + 1
// Time Complexity: O(log n) due to two binary searches
// Space Complexity: O(1)
int countOccurrences(const std::vector<int>& arr, int k) {
    if (arr.empty()) {
        return 0;
    }
    int first = findFirstOccurrence(arr, k);
    if (first == -1) {
        return 0; // Element not found
    }
    int last = findLastOccurrence(arr, k); // Element is present, so last will also be found
    return (last - first + 1);
}

// Alternative approach using lower_bound and upper_bound from C++ STL
// (or custom implementations of lower_bound and upper_bound)
// lower_bound returns an iterator to the first element not less than k (i.e., >= k)
// upper_bound returns an iterator to the first element greater than k
// The count of k is the distance between these two iterators.
// int countOccurrencesSTL(const std::vector<int>& arr, int k) {
//     auto first_it = std::lower_bound(arr.begin(), arr.end(), k);
//     if (first_it == arr.end() || *first_it != k) {
//         return 0; // k is not present in the array
//     }
//     auto last_it = std::upper_bound(arr.begin(), arr.end(), k);
//     return std::distance(first_it, last_it);
// }


int main() {
    std::vector<int> arr1 = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int k1 = 5;
    // Expected: 4
    std::cout << "Array: {1,3,5,5,5,5,67,123,125}, k = 5. Occurrences: " << countOccurrences(arr1, k1) << std::endl;
    // std::cout << "STL Occurrences: " << countOccurrencesSTL(arr1, k1) << std::endl;


    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 6;
    // Expected: 0
    std::cout << "Array: {1,2,3,4,5}, k = 6. Occurrences: " << countOccurrences(arr2, k2) << std::endl;
    // std::cout << "STL Occurrences: " << countOccurrencesSTL(arr2, k2) << std::endl;

    std::vector<int> arr3 = {5, 5, 5, 5, 5};
    int k3 = 5;
    // Expected: 5
    std::cout << "Array: {5,5,5,5,5}, k = 5. Occurrences: " << countOccurrences(arr3, k3) << std::endl;
    // std::cout << "STL Occurrences: " << countOccurrencesSTL(arr3, k3) << std::endl;

    std::vector<int> arr4 = {1, 1, 1, 1, 1};
    int k4 = 1;
     // Expected: 5
    std::cout << "Array: {1,1,1,1,1}, k = 1. Occurrences: " << countOccurrences(arr4, k4) << std::endl;
    // std::cout << "STL Occurrences: " << countOccurrencesSTL(arr4, k4) << std::endl;

    std::vector<int> arr5 = {};
    int k5 = 5;
    // Expected: 0
    std::cout << "Array: {}, k = 5. Occurrences: " << countOccurrences(arr5, k5) << std::endl;
    // std::cout << "STL Occurrences: " << countOccurrencesSTL(arr5, k5) << std::endl;

    std::vector<int> arr6 = {1,2,2,2,3,3,4,5,5};
    int k6 = 2;
    // Expected: 3
    std::cout << "Array: {1,2,2,2,3,3,4,5,5}, k = 2. Occurrences: " << countOccurrences(arr6, k6) << std::endl;
    int k7 = 3;
    // Expected: 2
    std::cout << "Array: {1,2,2,2,3,3,4,5,5}, k = 3. Occurrences: " << countOccurrences(arr6, k7) << std::endl;
    int k8 = 7;
    // Expected: 0
    std::cout << "Array: {1,2,2,2,3,3,4,5,5}, k = 7. Occurrences: " << countOccurrences(arr6, k8) << std::endl;


    return 0;
}
