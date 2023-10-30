#include <vector>

template<typename T>
std::vector<T>& insert_sort(std::vector<T>& in) {
    for (int i = 1; i < in.size(); ++i) {
        if (in[i] < in[i - 1]) {
            T tmp = std::move(in[i]);
            int j;

            for (j = i - 1; j >= 0 && in[j] > tmp; --j) {
                in[j + 1] = std::move(in[j]);
            }
            in[j + 1] = std::move(tmp);
        }
    }
    return in;
}