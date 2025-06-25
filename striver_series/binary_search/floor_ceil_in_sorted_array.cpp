#include <iostream>
#include <vector>
#include <utility> // For std::pair

// Function to find the floor of x in a sorted array
// Floor: largest element in the array <= x
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findFloor(const std::vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int floorVal = -1; // Initialize with a value indicating not found or handle as per problem constraints

    if (arr.empty()) return -1; // Or throw exception

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return arr[mid]; // Exact match is the floor
        } else if (arr[mid] < x) {
            floorVal = arr[mid]; // Potential floor, try to find a larger one in the right half
            low = mid + 1;
        } else { // arr[mid] > x
            high = mid - 1; // Floor must be in the left half
        }
    }
    return floorVal;
}

// Function to find the ceiling of x in a sorted array
// Ceiling: smallest element in the array >= x
// Time Complexity: O(log n)
// Space Complexity: O(1)
int findCeil(const std::vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    int ceilVal = -1; // Initialize with a value indicating not found or handle as per problem constraints

    if (arr.empty()) return -1; // Or throw exception

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return arr[mid]; // Exact match is the ceil
        } else if (arr[mid] < x) {
            low = mid + 1; // Ceil must be in the right half
        } else { // arr[mid] > x
            ceilVal = arr[mid]; // Potential ceil, try to find a smaller one in the left half
            high = mid - 1;
        }
    }
    return ceilVal;
}

// Function to get both floor and ceil
std::pair<int, int> getFloorAndCeil(const std::vector<int>& arr, int x) {
    // This is essentially what the problem asks for on platforms like GFG
    // They might expect a pair {floor, ceil}
    // Floor is the largest number in the array that is smaller than or equal to x
    // Ceil is the smallest number in the array that is greater than or equal to x

    int n = arr.size();
    int floorVal = -1;
    int ceilVal = -1;

    int low = 0, high = n - 1;

    // Find Floor
    low = 0; high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] <= x){
            floorVal = arr[mid];
            low = mid + 1; // look for a larger value that is still <= x
        } else {
            high = mid - 1;
        }
    }

    // Find Ceil
    low = 0, high = n - 1;
     while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            ceilVal = arr[mid];
            high = mid - 1; // look for a smaller value that is still >= x
        } else {
            low = mid + 1;
        }
    }
    return {floorVal, ceilVal};
}


int main() {
    std::vector<int> arr = {1, 2, 8, 10, 10, 12, 19};

    // Test findFloor
    std::cout << "Testing findFloor:" << std::endl;
    std::cout << "Floor of 0: " << findFloor(arr, 0) << std::endl; // Expected: -1 (or as per problem for not found)
    std::cout << "Floor of 1: " << findFloor(arr, 1) << std::endl; // Expected: 1
    std::cout << "Floor of 5: " << findFloor(arr, 5) << std::endl; // Expected: 2
    std::cout << "Floor of 8: " << findFloor(arr, 8) << std::endl; // Expected: 8
    std::cout << "Floor of 20: " << findFloor(arr, 20) << std::endl; // Expected: 19

    // Test findCeil
    std::cout << "\nTesting findCeil:" << std::endl;
    std::cout << "Ceil of 0: " << findCeil(arr, 0) << std::endl;   // Expected: 1
    std::cout << "Ceil of 1: " << findCeil(arr, 1) << std::endl;   // Expected: 1
    std::cout << "Ceil of 5: " << findCeil(arr, 5) << std::endl;   // Expected: 8
    std::cout << "Ceil of 8: " << findCeil(arr, 8) << std::endl;   // Expected: 8
    std::cout << "Ceil of 20: " << findCeil(arr, 20) << std::endl; // Expected: -1 (or as per problem for not found)
    std::cout << "Ceil of 11: " << findCeil(arr, 11) << std::endl; // Expected: 12
    std::cout << "Ceil of 19: " << findCeil(arr, 19) << std::endl; // Expected: 19

    // Test getFloorAndCeil
    std::cout << "\nTesting getFloorAndCeil:" << std::endl;
    auto p1 = getFloorAndCeil(arr, 5);
    std::cout << "For x = 5, Floor: " << p1.first << ", Ceil: " << p1.second << std::endl; // Exp: F:2, C:8

    auto p2 = getFloorAndCeil(arr, 8);
    std::cout << "For x = 8, Floor: " << p2.first << ", Ceil: " << p2.second << std::endl; // Exp: F:8, C:8

    auto p3 = getFloorAndCeil(arr, 0);
    std::cout << "For x = 0, Floor: " << p3.first << ", Ceil: " << p3.second << std::endl; // Exp: F:-1, C:1

    auto p4 = getFloorAndCeil(arr, 20);
    std::cout << "For x = 20, Floor: " << p4.first << ", Ceil: " << p4.second << std::endl; // Exp: F:19, C:-1

    std::vector<int> arr_empty = {};
    auto p5 = getFloorAndCeil(arr_empty, 5);
    std::cout << "For empty array, x = 5, Floor: " << p5.first << ", Ceil: " << p5.second << std::endl; // Exp: F:-1, C:-1


    std::vector<int> arr_single = {10};
    auto p6 = getFloorAndCeil(arr_single, 5);
    std::cout << "For arr={10}, x = 5, Floor: " << p6.first << ", Ceil: " << p6.second << std::endl; // Exp: F:-1, C:10
    auto p7 = getFloorAndCeil(arr_single, 10);
    std::cout << "For arr={10}, x = 10, Floor: " << p7.first << ", Ceil: " << p7.second << std::endl; // Exp: F:10, C:10
    auto p8 = getFloorAndCeil(arr_single, 15);
    std::cout << "For arr={10}, x = 15, Floor: " << p8.first << ", Ceil: " << p8.second << std::endl; // Exp: F:10, C:-1


    return 0;
}
