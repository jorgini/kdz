#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <climits>
#include <chrono>
#include "insert_sort_bin.cpp"
#include "insert_sort.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "heap_sort.cpp"
#include "quick_sort_nlogn.cpp"

void first_task(std::mt19937& gen) {
    std::uniform_int_distribution distr(INT_MIN, INT_MAX);
    std::vector<int> sizes = {10, 50, 100, 200, 300, 400, 500};
    std::cout << "\tInsertSort\t\tMergeSort\n";
    for (auto size : sizes) {
        int64_t avg_insert = 0;
        int64_t avg_merge = 0;

        for (int k = 0; k < 100; ++k) {
            std::vector<int> a(size), b(size);
            for (int i = 0; i < size; ++i) {
                int t = distr(gen);
                a[i] = t;
                b[i] = t;
            }

            auto t1 = std::chrono::high_resolution_clock::now();
            insert_sort(a);
            auto t2 = std::chrono::high_resolution_clock::now();
            avg_insert += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 100;

            t1 = std::chrono::high_resolution_clock::now();
            merge_sort(b, 0, size);
            t2 = std::chrono::high_resolution_clock::now();
            avg_merge += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 100;
        }

        std::cout << "n=" << size << "\t|"
        << avg_insert / 1e3 << "mcs\t\t|" << avg_merge / 1e3 << "mcs" << std::endl;
    }
}

void dop_task(std::mt19937& gen) {
    std::uniform_int_distribution distr(INT_MIN, INT_MAX);
    std::vector<int> sizes = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    std::cout << "\t\tQSort\t\tQSortMeridians\tHeapSort\n";
    for (auto size : sizes) {
        int64_t avg_qsort = 0;
        int64_t avg_qsort_meridians = 0;
        int64_t avg_heapsort = 0;
        for (int k = 0; k < 10; ++k) {
            std::vector<int> a(size), b(size), c(size);
            for (int i = 0; i < size; ++i) {
                int t = distr(gen);
                a[i] = t;
                b[i] = t;
                c[i] = t;
            }

            auto t1 = std::chrono::high_resolution_clock::now();
            quick_sort(a, 0, size, gen);
            auto t2 = std::chrono::high_resolution_clock::now();
            avg_qsort += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;

            t1 = std::chrono::high_resolution_clock::now();
            quick_sort_nlogn(b, 0, size);
            t2 = std::chrono::high_resolution_clock::now();
            avg_qsort_meridians += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;

            t1 = std::chrono::high_resolution_clock::now();
            heap_sort(c);
            t2 = std::chrono::high_resolution_clock::now();
            avg_heapsort += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() / 10;
        }

        std::cout << "n=" << size << (size >= 1e5 ? "\t" : "\t\t")<< "|"
                  << avg_qsort / 1e3 << "mcs\t|" << avg_qsort_meridians / 1e3 << "mcs\t|"
                  << avg_heapsort / 1e3 << "mcs" << std::endl;
    }
}

void str_task(std::mt19937& gen) {
    std::uniform_int_distribution distr(0, 25);
    std::cout << "\tInsert sort with bin search / Insert sort\n";
    std::cout << "\t\t20\t\t50\t\t100\t\t300\n";
    std::vector<int> sizes = {50, 100, 500, 1000, 5000, 10000};
    std::vector<int> lens = {20, 50, 100, 300};

    for (auto n : sizes) {
        std::cout << "n=" << n;
        for (auto m : lens) {
            int64_t avg_bin = 0;
            int64_t avg_bas = 0;

            int count = 50;
            for (int k = 0; k < count; ++k) {
                std::vector<std::string> a(n), b(n);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        a[i].push_back(char('a' + distr(gen)));
                        b[i].push_back(a[i][j]);
                    }
                }

                auto t1 = std::chrono::high_resolution_clock::now();
                insert_sort(a);
                auto t2 = std::chrono::high_resolution_clock::now();
                insert_sort_bin(b);
                auto t3 = std::chrono::high_resolution_clock::now();

                avg_bas += (std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count());
                avg_bin += (std::chrono::duration_cast<std::chrono::microseconds>(t3 - t2).count());
            }
            printf("\t\t%.5lf", static_cast<double>(avg_bin) / static_cast<double>(avg_bas));
        }
        std::cout << "\n";
    }
}

void rev_task(std::mt19937& gen) {
    std::uniform_int_distribution distr(0, INT_MAX);
    std::vector<int> sizes = {1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    std::cout << "\t\tQSort\t\tQSortMeridians\tHeapSort\n";
    for (auto size : sizes) {
        int64_t avg_qsort = 0;
        int64_t avg_qsort_meridians = 0;
        int64_t avg_heapsort = 0;
        for (int k = 0; k < 1; ++k) {
            std::vector<int> a(size), b(size), c(size);
            int t = distr(gen);
            for (int i = 0; i < size; ++i) {
                a[i] = t;
                b[i] = t;
                c[i] = t;
                --t;
            }

            auto t1 = std::chrono::high_resolution_clock::now();
            quick_sort(a, 0, size, gen);
            auto t2 = std::chrono::high_resolution_clock::now();
            avg_qsort += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1;

            t1 = std::chrono::high_resolution_clock::now();
            quick_sort_nlogn(b, 0, size);
            t2 = std::chrono::high_resolution_clock::now();
            avg_qsort_meridians += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1;

            t1 = std::chrono::high_resolution_clock::now();
            heap_sort(c);
            t2 = std::chrono::high_resolution_clock::now();
            avg_heapsort += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() / 1;
        }

        std::cout << "n=" << size << (size >= 1e5 ? "\t" : "\t\t")<< "|"
                  << avg_qsort << "mcs\t|" << avg_qsort_meridians << "mcs\t|"
                  << avg_heapsort << "mcs" << std::endl;
    }
}

int main() {
    std::mt19937 gen(time(nullptr));
    first_task(gen);
    std::cout << "\n\n";
    dop_task(gen);
    std::cout << "\n\n";
    str_task(gen);
    std::cout << "\n\n";
    //rev_task(gen);
}