#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename RAI>
RAI partition(RAI first, RAI pivot, RAI last) {
    swap(*pivot, *(last - 1));
    RAI store = first;
    RAI curr = first;
    RAI currpivot = last - 1;
    while (curr < currpivot) {
        if (*curr < *currpivot) {
            swap(*store++, *curr);
        }
        ++curr;
    }
    swap(*store, *currpivot);
    return store;
}

template <typename RAI>
RAI random_partition(RAI first, RAI last) {
    if (first == last) return first;
    srand(time(NULL));
    RAI pivot = first + rand() % (last - first);
    return partition(first, pivot, last);
}

// expected linear time reimplementation of nth_element
template <typename RAI>
void quickselect(RAI first, RAI nth, RAI last) {
    RAI pivot;
    do {
        pivot = random_partition(first, last);
        if (nth < pivot)
            last = pivot;
        else if (nth > pivot)
            first = pivot + 1;
    } while (pivot != nth);
}

int main() {
    srand(time(NULL));

    int n = 5 + rand() % 20;
    int *r = new int[n];
    for (int i = 0; i < n; ++i) r[i] = rand() % 50;
    copy(r, r + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    
    int i = rand() % n;
    cout << i << endl;
    quickselect(r, r + i, r + n);
    copy(r, r + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << r[i] << endl;

    return 0;
}
