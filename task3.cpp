#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

  
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

   
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { 
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
  
    if (left >= right) {
        return; 
    }

    int mid = left + (right - left) / 2;

 
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void displayArray(int arr[], int n) {
    if (n <= 0) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

int main() {

    int test1[] = {45, 12, 78, 33, 20, 60};
    int n1 = sizeof(test1) / sizeof(test1[0]);
    cout << "Input: "; displayArray(test1, n1);
    mergeSort(test1, 0, n1 - 1);
    cout << "Output: "; displayArray(test1, n1);
    cout << "---" << endl;

    int test2[] = {1, 2, 3, 4};
    int n2 = sizeof(test2) / sizeof(test2[0]);
    cout << "Input: "; displayArray(test2, n2);
    mergeSort(test2, 0, n2 - 1);
    cout << "Output: "; displayArray(test2, n2);
    cout << "---" << endl;

  
    int test3[] = {9, 7, 5, 3, 1};
    int n3 = sizeof(test3) / sizeof(test3[0]);
    cout << "Input: "; displayArray(test3, n3);
    mergeSort(test3, 0, n3 - 1);
    cout << "Output: "; displayArray(test3, n3);
    cout << "---" << endl;

   
    int test4[] = {5, 2, 5, 1, 2};
    int n4 = sizeof(test4) / sizeof(test4[0]);
    cout << "Input: "; displayArray(test4, n4);
    mergeSort(test4, 0, n4 - 1);
    cout << "Output: "; displayArray(test4, n4);
    cout << "---" << endl;

  
    int test5[] = {8};
    int n5 = sizeof(test5) / sizeof(test5[0]);
    cout << "Input: "; displayArray(test5, n5);
    mergeSort(test5, 0, n5 - 1);
    cout << "Output: "; displayArray(test5, n5);
    cout << "---" << endl;

    
    int test6[] = {}; 
    int n6 = 0;
    cout << "Input: "; displayArray(test6, n6);
    mergeSort(test6, 0, n6 - 1); 
    cout << "Output: "; displayArray(test6, n6);

    return 0;
}