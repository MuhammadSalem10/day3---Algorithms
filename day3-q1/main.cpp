#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSearch(int arr[], int size, int target) {
    vector<int> indices;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            indices.push_back(i);
        }
    }
    return indices;
}

int main() {
    int arr[] = {1, 5, 7, 5, 9, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target element: ";
    cin >> target;

    vector<int> result = linearSearch(arr, size, target);

    if (result.empty()) {
        cout << "Target element " << target << " not found in the array." << endl;
    } else {
        cout << "Target element " << target << " found at indices: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
