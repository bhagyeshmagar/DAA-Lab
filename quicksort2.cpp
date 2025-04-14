#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    int pivotIndex = i + 1;
    
    quicksort(arr, left, pivotIndex - 1);
    quicksort(arr, pivotIndex + 1, right);
}

int main() {
    srand(time(0));
    vector<int> sizes = {100, 500, 1000, 5000, 10000};
    
    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000 + 1;
        }
        
        clock_t start_time = clock();
        quicksort(arr, 0, n - 1);
        clock_t end_time = clock();
        
        cout << "Time taken to sort " << n << " elements: " 
             << (double)(end_time - start_time) / CLOCKS_PER_SEC 
             << " seconds" << endl;
    }
    
    return 0;
}