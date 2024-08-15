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
int absValue(int x) {
    return x < 0 ? -x : x;
}
int closestThreeSum(int arr[], int n, int X) {
    bubbleSort(arr, n);
    int closestSum = arr[0] + arr[1] + arr[2];

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = arr[i] + arr[left] + arr[right];
            if (absValue(currentSum - X) < absValue(closestSum - X)) {
                closestSum = currentSum;
            }

            if (currentSum < X) {
                ++left;
            } else if (currentSum > X) {
                --right;
            } else {
                return closestSum;
            }
        }
    }
    return closestSum;
}
int main() {
    int arr[10],n,x;
    cout<<"Enter the no of elements of the array:";
    cin>>n;
    cout<<"Enter the elements of the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the sum to closest:";
    cin>>x;
    cout << "Closest sum to " << x << " is " << closestThreeSum(arr, n, x) << endl;
    return 0;
}
