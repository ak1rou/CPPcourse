?#include <iostream>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

const int ROWS = 3;
const int COLUMNS = 4;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void sort(int arr[ROWS][COLUMNS], SortingDirection direction) {
    if (direction == SortingDirection::ByRows) {
        for (int i = 0; i < ROWS; ++i) {
            quickSort(arr[i], 0, COLUMNS - 1);
        }
    }
    else if (direction == SortingDirection::ByColumns) {
        for (int i = 0; i < COLUMNS; ++i) {
            int column[ROWS];
            for (int j = 0; j < ROWS; ++j) {
                column[j] = arr[j][i];
            }

            quickSort(column, 0, ROWS - 1);

            for (int j = 0; j < ROWS; ++j) {
                arr[j][i] = column[j];
            }
        }
    }
}

void printArray(int arr[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}