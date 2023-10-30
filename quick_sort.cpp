#include <vector>
#include <random>

template<typename T>
void quick_sort(std::vector<T>& in, int l, int r, std::mt19937& gen) {
    if (l + 1 >= r)
        return;

    std::uniform_int_distribution distr(l, r - 1);
    size_t ind = distr(gen);
    int pivot = in[ind];

    int i = l, j = r - 1;

    while (i <= j) {

        while (in[i] < pivot) {
            i++;
        }

        while (in[j] > pivot) {
            j--;
        }

        if (i >= j)
            break;

        std::swap(in[i++], in[j--]);
    }
    if (r - l > 2) {
        quick_sort(in, l, j + 1, gen);
        quick_sort(in, j + 1, r, gen);
    }
}
