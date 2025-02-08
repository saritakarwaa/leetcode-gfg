// Fibonacci search divides the array into two parts that have sizes that are consecutive Fibonacci numbers. On average, this leads to about 4% more comparisons to be executed,[2] but it has the advantage that one only needs addition and subtraction to calculate the indices of the accessed array elements, while classical binary search needs bit-shift, division or multiplication,[1] operations that were less common at the time Fibonacci search was first published. Fibonacci search has an average- and worst-case complexity of O(log n)

// The Fibonacci sequence has the property that a number is the sum of its two predecessors. Therefore the sequence can be computed by repeated addition. The ratio of two consecutive numbers approaches the Golden ratio, 1.618... Binary search works by dividing the seek area in equal parts (1:1). Fibonacci search can divide it into parts approaching 1:1.618 while using the simpler operations.

#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(vector<int> arr, int x) {
    int n = arr.size();
    
    // Initialize Fibonacci numbers
    int fibM2 = 0;  // (m-2)th Fibonacci number
    int fibM1 = 1;  // (m-1)th Fibonacci number
    int fibM = fibM2 + fibM1;  // mth Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to be inspected
    while (fibM > 1) {
        int i = min(offset + fibM2, n - 1);  // Check valid index

        // If x is greater, move right
        if (arr[i] < x) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        }
        // If x is smaller, move left
        else if (arr[i] > x) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        }
        // Element found
        else {
            return i;
        }
    }

    // If last element is the target
    if (fibM1 && arr[offset + 1] == x)
        return offset + 1;

    return -1; // Element not found
}

int main() {
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int x = 85;
    
    int index = fibonacciSearch(arr, x);
    
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
