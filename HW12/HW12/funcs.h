#pragma once

void bubbleSort(int arr[], int size);

const int ROWS = 3;
const int COLUMNS = 4;

enum class SortingDirection { ByRows, ByColumns };

int partition(int arr[], int start, int end);

void quickSort(int arr[], int start, int end);

void sort(int arr[ROWS][COLUMNS], SortingDirection direction);

void printArray(int arr[ROWS][COLUMNS]);