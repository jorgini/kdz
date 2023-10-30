#include <iostream>
#include <vector>

template<typename T>
void insert_sort_bin(std::vector<T>& in) {
    for (int i = 1; i < in.size(); ++i) {
        if (in[i] < in[i - 1]) {
            T target = std::move(in[i]);

            int l = 0, r = i - 1;

            while (l <= r) {
                int aver = (l + r) / 2;

                if (in[aver] < target)
                    l = aver + 1;
                else
                    r = aver - 1;
            }
            for (int j = i; j > l; --j)
                in[j] = std::move(in[j - 1]);
            in[l] = std::move(target);
        }
    }
}