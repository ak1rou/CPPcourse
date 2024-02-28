#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <future>

void quickSortParallel(std::vector<int>& arr, int left, int right, int num_threads);
