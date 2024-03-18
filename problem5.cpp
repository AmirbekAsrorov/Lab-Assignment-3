#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxVal = arr[n - 1];
    arr[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = maxVal;
        maxVal = max(maxVal, temp);
    }

    cout << "Resulting array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
