#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding random number generator

using namespace std;

void fisherYatesShuffle(vector<int>& arr) {
    int n = arr.size();
    srand(time(0));  // Seed the random number generator

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Pick a random index from 0 to i
        swap(arr[i], arr[j]);  // Swap arr[i] with arr[j]
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    fisherYatesShuffle(arr);

    cout << "Shuffled array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
