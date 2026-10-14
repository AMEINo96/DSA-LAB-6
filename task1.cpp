#include <iostream>
using namespace std;
void inputIDs(int arr[], int n) {
    if (n <= 0) return;
    
    cout << "Enter " << n << " student IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
int linearSearch(int arr[], int n, int target) {
    if (n == 0) return -1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
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
int main() {
    int array[30];
    int n, target;
    
    cout << "Enter the number of students (max 30): ";
    cin >> n;
    
    if (n > 30) {
        cout << "Error: Array capacity is 30." << endl;
        return 1;
    }
    inputIDs(array, n);
    cout << "Enter the target ID to search: ";
    cin >> target;
    int result = linearSearch(array, n, target);
    displayResult(result);
    return 0;
}