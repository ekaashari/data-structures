#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int minSumProduct(int arr[], int n) {
    bubbleSort(arr, n);
    int minSum = 0;
    for (int i = 0; i < n / 2; ++i) {
        minSum += arr[i] * arr[n - i - 1];
    }
    return minSum;
}
int main() {
    int arr[10],n;
    cout<<"Enter the no of elements of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int minSum = minSumProduct(arr, n);
    cout << "Minimum sum of the product of consecutive pair elements: " << minSum << endl;
    cout << "Sorted arr[] for minimum sum: ";
    for (int i = 0; i < n / 2; ++i) {
        if (i != 0) cout << ", ";
        cout << arr[n - i - 1] << ", " << arr[i];
    }
    return 0;
}
