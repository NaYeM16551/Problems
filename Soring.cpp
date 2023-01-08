#include "bits/stdc++.h"

using namespace std;


void selectionSort(int *Arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (Arr[j] < Arr[min])
                min = j;

        }
        swap(Arr[i], Arr[min]);

    }
}

void selectionSort_usingRecursion(int *arr, int size) {
    if (size == 1)
        return;
    int min = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[min] > arr[i])
            min = i;
    }
    swap(arr[0], arr[min]);
    selectionSort_usingRecursion(arr + 1, size - 1);

}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i)//surfing across the array
    {
        int flag = 1;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 0;
            }


        }
        if (flag)//best case if already sorted,complexity o(n)
            break;
    }

}

void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; ++i) {
        int value = arr[i];//picking the value of hole
        int key = i;
        while (key > 0 && arr[key - 1] > value)//checking if my hole is in first index or not
        {
            arr[key] = arr[key - 1];//putting hole with value
            key = key - 1;//shifting the hole
        }
        arr[key] = value;//replacing the hole with desired value

    }
}

void mergeArray(int *arr, int start, int end) {

    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;//length of left side array
    int len2 = end - mid;//length of right side array
    int *left = new int[len1];//creating new array
    int *right = new int[len2];
    int mainArrayIndex = start;
    for (int i = 0; i < len1; ++i)//copying array element
        left[i] = arr[mainArrayIndex++];
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; ++i)//copying array element
        right[i] = arr[mainArrayIndex++];
    int i = 0, j = 0;
    mainArrayIndex = start;
    //merging to sorted array
    while (i < len1 && j < len2) {
        if (left[i] < right[j])
            arr[mainArrayIndex++] = left[i++];
        else {

            arr[mainArrayIndex++] = right[j++];

        }

    }
    while (i < len1)
        arr[mainArrayIndex++] = left[i++];
    while (j < len2)
        arr[mainArrayIndex++] = right[j++];
    delete[] left;
    delete[] right;


}

void mergeSort(int *arr, int start, int end) {

    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    //sorting left side
    mergeSort(arr, start, mid);
    //sorting right side
    mergeSort(arr, mid + 1, end);
    //merging to sorted array
    mergeArray(arr, start, end);


}

/*this function will return the partition index and the left portion of the
partition index will be less in terms of magnitude and the right portion
wil be greater in magnitude comparing individual element*/
int partitionIndex(int *arr, int start, int end) {
    int pivot = arr[end];
    int parti_Index = start;
    for (int i = start; i < end; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[parti_Index]);
            parti_Index++;
        }
    }
    swap(arr[parti_Index], arr[end]);
    return parti_Index;
}

//in worst case T.C 0(n^2)
//in average case T.C 0(nlogn)
void quickSort(int *arr, int start, int end) {
    if (start >= end)
        return;
    int part_Index = partitionIndex(arr, start, end);
    quickSort(arr, start, part_Index - 1);
    quickSort(arr, part_Index + 1, end);

}

int main() {
    int Arr[] = {10, 9, 80, 7, 11, 4, 5, 6};
    int arr[5] = {200, 4, 1, 3, 5};
    quickSort(Arr, 0, 7);
    for (int i: Arr)
        cout << i << " ";
    cout << endl;
    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4];
    /* for(int i=0;i<size;++i)
         cout<<Arr[i]<<" ";
     cout<<endl;*/

}
