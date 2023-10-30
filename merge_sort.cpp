#include <vector>

template<typename T>
void merge_sort(std::vector<T>& in, int l, int r) {
    if (l + 1 == r)
        return;

    merge_sort(in, l, (l + r) / 2);
    merge_sort(in, (l + r) / 2, r);

    std::vector<T> tmp(r - l);
    int i = 0, j = 0;
    while (i + j < r - l) {
        if (l + i >= (l + r) / 2) {
            tmp[i + j] = in[(l + r) / 2 + j];
            j++;
            continue;
        }
        if ((l + r) / 2 + j >= r) {
            tmp[i + j] = in[l + i];
            i++;
            continue;
        }

        if (in[l + i] < in[(l + r) / 2 + j]) {
            tmp[i + j] = in[l + i];
            i++;
        } else {
            tmp[i + j] = in[(l + r) / 2 + j];
            j++;
        }
    }

    for (int k = l; k < r; ++k) {
        in[k] = tmp[k - l];
    }
}