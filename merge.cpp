#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

void merge(vector<int>& arr, int left,  int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++) {
                L[i] = arr[left + i];
        }
        for (int j = 0; j <n2; j++) {
                R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;

        while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                        arr[k] = L[i];
                        i++;
                }
                else {
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
}

void printArray(vector<int> arr) {
        for (int i=0; i < arr.size(); i++) {
                cout << arr[i] << " ";
        }
        cout << endl;
}

void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
                return;
        }

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
}

int main(int argc, char* argv[]) {
        int arraySize = atoi(argv[1]);
        std::vector<int> arr(arraySize);
        srand(time(0));
        for (int i = 0; i < arraySize; i++) {
                arr[i] = rand() % 100;
        }
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arraySize - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << elapsed.count() << std::endl;
        std::cout << arraySize << std::endl;
        return 0;
}