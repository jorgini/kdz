#include <vector>

template<typename T>
T get_pivot(std::vector<T>& in, int l, int r) {
    if (r - l < 5) {
        for (int i = l + 1; i < r; ++i) {
            T tmp = in[i];
            int j;

            for (j = i - 1; j >= l && in[j] > tmp; --j)
                in[j + 1] = in[j];
            in[j + 1] = tmp;
        }
        return in[(l + r) / 2];
    }


    for (int i = l; i + 4 < r; i += 5) {
        if (in[i + 4] < in[i])
            std::swap(in[i + 4], in[i]);
        if (in[i + 3] < in[i + 1])
            std::swap(in[i + 3], in[i + 1]);
        if (in[i + 1] < in[i]) {
            std::swap(in[i + 1], in[i]);
            std::swap(in[i + 4], in[i + 3]);
        }
        if (in[i + 2] < in[i + 1]) {
            T x = in[i + 2];
            in[i + 2] = in[i + 1];
            if (x < in[i])
                std::swap(x, in[i]);
            in[i + 1] = x;
        } else if (in[i + 3] < in[i + 2])
            std::swap(in[i + 3], in[i + 2]);
        if (in[i + 4] < in[i + 2]) {
            T x = in[i + 4];
            in[i + 4] = in[i + 3];
            in[i + 3] = in[i + 2];
            if (x < in[i + 1]) {
                in[i + 2] = in[i + 1];
                in[i + 1] = x;
            } else
                in[i + 2] = x;
        } else if (in[i + 4] < in[i + 3])
            std::swap(in[i + 4], in[i + 3]);
    }

    return in[l + 2 + 5 * (((r - l) / 5) / 2)];
}

template<typename T>
void quick_sort_nlogn(std::vector<T>& in, int l, int r) {
    if (l + 1 >= r)
        return;

    int pivot = get_pivot(in, l, r);

    int i = l, j = r - 1;

    while (i <= j) {

        while (in[i] < pivot) {
            i++;
        }

        while (in[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(in[i++], in[j--]);
        }
    }

    quick_sort_nlogn(in, l, j + 1);
    quick_sort_nlogn(in, j + 1, r);
}
