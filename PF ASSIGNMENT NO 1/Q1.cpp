#include <iostream>

using namespace std;

bool same(int* arr1, int* arr2, int size1, int size2) {
    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}

int main() {
    int size1, size2;

    cout << "Enter size of first array: ";
    cin >> size1;
    cout << "Enter size of second array: ";
    cin >> size2;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    cout << "Enter elements of first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    if (same(arr1, arr2, size1, size2)) {
        cout << "Arrays are identical!" << endl;
    } else {
        cout << "Arrays are not identical!" << endl;
    }

    delete[] arr1;
    delete[] arr2;

    return 0;
}
