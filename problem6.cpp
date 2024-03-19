#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int findMinimumDistance(const vector<int>& arr, int x, int y) {
    int minDistance = INT_MAX;
    int prevIndex = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x || arr[i] == y) {
            if (prevIndex != -1 && arr[i] != arr[prevIndex]) {
                minDistance = min(minDistance, abs(i - prevIndex));
            }
            prevIndex = i;
        }
    }

    return minDistance;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integer numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int minDistance = findMinimumDistance(arr, x, y);

    cout <</* "Minimum distance between " << x << " and " << y << ": " <<*/ minDistance << endl;

    return 0;
}
