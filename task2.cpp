#include <iostream>
using namespace std;
void inputSortedIDs(int arr[], int n) {
    cout<<"Enter student ids in ascending order !\n";
    if (n <= 0) return;
    cout << "Enter " << n << " student IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
int binarySearch(int arr[], int n, int target) {
    if (n == 0) return -1; 
    int low = 0 ;
    int high = n-1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == target )
            return mid;
        else if (target < mid){
            high = mid - 1;
        }
        else  {
            low = mid + 1;
        }
        
    }
    return -1;
}
void displayResult(int index) {
    if (index == -1) {
        cout << "The ID is not registered." << endl;
    } else {
        cout << "Element stored at index : " << index << endl;
    }
}
    bool isSorted (int arr[], int size){
        if (size <= 1)
            return true;
        for (int i = 0 ; i < size - 1 ; i ++){
            if (arr[i]>arr[i+1])
                return false ;
        }
        return true;
    }

int main() {
    int array[30];
    int n, target;
    
    cout << "Enter the number of students (max 30): ";
    cin >> n;
    
    if (n > 30) {
        cout << "Error: Array capacity is 30." << endl;
        return 1;
    }
    inputSortedIDs(array, n);
    if(isSorted(array,n)){
    cout << "Enter the target ID to search: ";
    cin >> target;
    int result = binarySearch(array, n, target);
    displayResult(result);
    return 0;
    }
    else 
        cout<<"array is not sorted in ascending order .";

}