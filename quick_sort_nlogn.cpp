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

    int k = 1;
    while (5 * k < in.size()) {
        for (int i = l + k / 2; i + 4 * k < r; i += 5 * k) {
            if (in[i + 4 * k] < in[i])
                std::swap(in[i + 4 * k], in[i]);
            if (in[i + 3] < in[i + 1 * k])
                std::swap(in[i + 3 * k], in[i + 1 * k]);
            if (in[i + 1 * k] < in[i]) {
                std::swap(in[i + 1 * k], in[i]);
                std::swap(in[i + 4 * k], in[i + 3 * k]);
            }
            if (in[i + 2 * k] < in[i + 1 * k]) {
                T x = in[i + 2 * k];
                in[i + 2 * k] = in[i + 1 * k];
                if (x < in[i])
                    std::swap(x, in[i]);
                in[i + 1 * k] = x;
            } else if (in[i + 3 * k] < in[i + 2 * k])
                std::swap(in[i + 3 * k], in[i + 2 * k]);
            if (in[i + 4 * k] < in[i + 2 * k]) {
                T x = in[i + 4 * k];
                in[i + 4 * k] = in[i + 3 * k];
                in[i + 3 * k] = in[i + 2 * k];
                if (x < in[i + 1 * k]) {
                    in[i + 2 * k] = in[i + 1 * k];
                    in[i + 1 * k] = x;
                } else
                    in[i + 2 * k] = x;
            } else if (in[i + 4 * k] < in[i + 3 * k])
                std::swap(in[i + 4 * k], in[i + 3 * k]);
        }
        k *= 5;
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