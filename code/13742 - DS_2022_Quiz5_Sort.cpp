//#include <iostream>
//
//using namespace std;
//
//int A[1000000+5];
//
//int main() {
//    int N;
//    cin >> N;
//    for (int i=1;i<=N;i++) {
//        cin >> A[i];
//    }
//    int num = 0;
//    for (int i=1;i<=N;i++) {
//        for (int j = i + 1; j<=N;j++) {
//            if (A[i] > A[j]) {
//                num ++;
//            }
//        }
//    }
//    cout << num << endl;
//}
#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& A, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    long long inversions = 0;

    int i = left;       // Index for the left subarray
    int j = mid + 1;    // Index for the right subarray
    int k = 0;          // Index for the temporary merged array

    while (i <= mid && j <= right) {
        if (A[i] > A[j]) {
            // A[i] > A[j] is an inversion
            inversions += (mid - i + 1);
            temp[k++] = A[j++];
        } else {
            temp[k++] = A[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = A[i++];
    }

    while (j <= right) {
        temp[k++] = A[j++];
    }

    for (int x = left, y = 0; x <= right; ++x, ++y) {
        A[x] = temp[y];
    }

    return inversions;
}

long long mergeSortAndCount(vector<int>& A, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversions += mergeSortAndCount(A, left, mid);
        inversions += mergeSortAndCount(A, mid + 1, right);
        inversions += mergeAndCount(A, left, mid, right);
    }
    return inversions;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long inversions = mergeSortAndCount(A, 0, N - 1);

    cout << inversions << endl;

    return 0;
}
