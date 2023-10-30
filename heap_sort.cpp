#include <vector>


template<typename T>
void heapify(std::vector<T>& in, int n, int i) {
    int largest = i;

    int l = 2 * i;
    int r = 2 * i + 1;

    if (l < n && in[l] > in[largest])
        largest = l;

    if (r < n && in[r] > in[largest])
        largest = r;

    if (largest != i) {
        std::swap(in[i], in[largest]);

        heapify(in, n, largest);
    }
}

template<typename T>
void heap_sort(std::vector<T>& in) {
    in.push_back(in[0]);
    for (int i = in.size() / 2; i > 0 ; --i)
        heapify(in, in.size(), i);

    for (int i = in.size() - 1; i > 1; --i)
    {
        std::swap(in[1], in[i]);

        heapify(in, i, 1);
    }
    in.erase(in.begin());
}
