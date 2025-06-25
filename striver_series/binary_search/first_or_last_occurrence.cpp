#include <iostream>
#include <vector>
#include <algorithm> // For std::vector operations if needed

// Function to find the first occurrence of k in a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findFirstOccurrence(const std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            first = mid;     // Potential first occurrence
            high = mid - 1;  // Try to find an earlier one in the left half
        } else if (arr[mid] < k) {
            low = mid + 1;   // k must be in the right half
        } else {
            high = mid - 1;  // k must be in the left half
        }
    }
    return first;
}

// Function to find the last occurrence of k in a sorted array
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findLastOccurrence(const std::vector<int>& arr, int k) {
    int low = 0;
    int high = arr.size() - 1;
    int last = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) {
            last = mid;      // Potential last occurrence
            low = mid + 1;   // Try to find a later one in the right half
        } else if (arr[mid] < k) {
            low = mid + 1;   // k must be in the right half
        } else {
            high = mid - 1;  // k must be in the left half
        }
    }
    return last;
}

// Function to find both first and last occurrence (often asked this way)
// Returns a pair: {first_occurrence, last_occurrence}. {-1, -1} if not found.
std::pair<int, int> findFirstAndLastOccurrence(const std::vector<int>& arr, int k) {
    int first = findFirstOccurrence(arr, k);
    if (first == -1) { // If first occurrence is not found, k is not in the array
        return {-1, -1};
    }
    int last = findLastOccurrence(arr, k);
    return {first, last};
}


int main() {
    std::vector<int> arr1 = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int k1 = 5;
    std::cout << "Array: {1, 3, 5, 5, 5, 5, 67, 123, 125}, k = 5" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr1, k1) << std::endl; // Expected: 2
    std::cout << "Last Occurrence: " << findLastOccurrence(arr1, k1) << std::endl;   // Expected: 5
    auto p1 = findFirstAndLastOccurrence(arr1, k1);
    std::cout << "First and Last: {" << p1.first << ", " << p1.second << "}" << std::endl; // Expected: {2, 5}
    std::cout << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    int k2 = 6;
    std::cout << "Array: {1, 2, 3, 4, 5}, k = 6" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr2, k2) << std::endl; // Expected: -1
    std::cout << "Last Occurrence: " << findLastOccurrence(arr2, k2) << std::endl;   // Expected: -1
    auto p2 = findFirstAndLastOccurrence(arr2, k2);
    std::cout << "First and Last: {" << p2.first << ", " << p2.second << "}" << std::endl; // Expected: {-1, -1}
    std::cout << std::endl;

    std::vector<int> arr3 = {5, 5, 5, 5, 5};
    int k3 = 5;
    std::cout << "Array: {5, 5, 5, 5, 5}, k = 5" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr3, k3) << std::endl; // Expected: 0
    std::cout << "Last Occurrence: " << findLastOccurrence(arr3, k3) << std::endl;   // Expected: 4
    auto p3 = findFirstAndLastOccurrence(arr3, k3);
    std::cout << "First and Last: {" << p3.first << ", " << p3.second << "}" << std::endl; // Expected: {0, 4}
    std::cout << std::endl;

    std::vector<int> arr4 = {1, 2, 3, 5, 5};
    int k4 = 5;
    std::cout << "Array: {1, 2, 3, 5, 5}, k = 5" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr4, k4) << std::endl; // Expected: 3
    std::cout << "Last Occurrence: " << findLastOccurrence(arr4, k4) << std::endl;   // Expected: 4
    auto p4 = findFirstAndLastOccurrence(arr4, k4);
    std::cout << "First and Last: {" << p4.first << ", " << p4.second << "}" << std::endl; // Expected: {3, 4}
    std::cout << std::endl;

    std::vector<int> arr5 = {5, 5, 1, 2, 3}; // Note: Unsorted, but functions assume sorted for correctness
                                          // For demonstration of logic, if it were sorted {1,2,3,5,5}
                                          // then first=3, last=4 for k=5
    // Example with a single element
    std::vector<int> arr6 = {7};
    int k6_present = 7;
    int k6_absent = 8;
    std::cout << "Array: {7}, k = 7" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr6, k6_present) << std::endl; // Expected: 0
    std::cout << "Last Occurrence: " << findLastOccurrence(arr6, k6_present) << std::endl;   // Expected: 0
    auto p6 = findFirstAndLastOccurrence(arr6, k6_present);
    std::cout << "First and Last: {" << p6.first << ", " << p6.second << "}" << std::endl; // Expected: {0, 0}
    std::cout << "Array: {7}, k = 8" << std::endl;
    std::cout << "First Occurrence: " << findFirstOccurrence(arr6, k6_absent) << std::endl; // Expected: -1
    std::cout << "Last Occurrence: " << findLastOccurrence(arr6, k6_absent) << std::endl;   // Expected: -1
    auto p7 = findFirstAndLastOccurrence(arr6, k6_absent);
    std::cout << "First and Last: {" << p7.first << ", " << p7.second << "}" << std::endl; // Expected: {-1, -1}


    return 0;
}
