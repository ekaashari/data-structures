#include <iostream>
using namespace std;
void countFrequencies(int arr[], int n, int freq[]) {
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
}
int minSetSize(int arr[], int n) {
    int maxVal = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    int maxFreq = 0;
    int* freq = new int[maxVal + 1]();
    countFrequencies(arr, n, freq);
    int removed = 0, setSize = 0;
    for (int i = 0; i <= maxVal; ++i) {
        if (freq[i] > 0) {
            removed += freq[i];
            setSize++;
            if (removed >= n / 2) {
                break;
            }
        }
    }
    return setSize;
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
    int minSize = minSetSize(arr, n);
    cout << "Minimum size of the array after removal: " << minSize << endl;
    return 0;
}
