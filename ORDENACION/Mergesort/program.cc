#include <vector>
using namespace std;

void merge(vector<double>& V, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors
    vector<double> L(n1), R(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; ++i)
        L[i] = V[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = V[mid + 1 + j];

    // Merge the temporary vectors back into V
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            V[k] = L[i];
            ++i;
        } else {
            V[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        V[k] = L[i];
        ++i;
        ++k;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        V[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSortHelper(vector<double>& V, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSortHelper(V, left, mid);
        mergeSortHelper(V, mid + 1, right);

        // Merge the sorted halves
        merge(V, left, mid, right);
    }
}

void mergesort(vector<double>& V) {
    if (!V.empty()) {
        mergeSortHelper(V, 0, V.size() - 1);
    }
}

