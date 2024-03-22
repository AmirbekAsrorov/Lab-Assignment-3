#include<iostream>
using namespace std;

int minimumDistance(int arr[], int n, int x, int y) {
    int minDist = INT_MAX;
    int prevIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x || arr[i] == y) {
            if (prevIndex != -1 && arr[i] != arr[prevIndex]) {
                minDist = min(minDist, i - prevIndex);
            }
            prevIndex = i;
        }
    }

    return minDist;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x, y;
    cout << "Enter two numbers (x and y): ";
    cin >> x >> y;

    int minDistance = minimumDistance(arr, n, x, y);

    if (minDistance == INT_MAX) {
        cout << "No occurrence of x or y in the array." << endl;
    } else {
        cout << "Minimum distance between " << x << " and " << y << " is: " << minDistance << endl;
    }

    return 0;
}





