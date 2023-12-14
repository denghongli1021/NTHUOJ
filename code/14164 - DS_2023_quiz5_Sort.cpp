#include <random>
#include <iostream>
using namespace std;

mt19937 rng;
void quick_sort(int a[], int n) {
	if (n < 2) return;
	int idx = rng() % n, val = a[idx];
	swap(a[idx], a[n - 1]);
	int len = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] < val) swap(a[i], a[len++]);
	swap(a[len], a[n - 1]);
	int len2 = len + 1;
	for (int i = len + 1; i < n - 1; i++)
		if (a[i] == val) swap(a[i], a[len2++]);
	quick_sort(a, len), quick_sort(a + len2, n - len2);
}
//void merge_sort(int a[], int n) {
//	if (n < 2) return;
//	int len1 = n / 2, len2 = n - len1;
//	int *a1 = a, *a2 = a + len1;
//	merge_sort(a1, len1), merge_sort(a2, len2);
//	int tmp[n], len = 0, p1 = 0, p2 = 0;
//	while (len < n) {
//		if (p2 == len2 || (p1 < len1 && a1[p1] <= a2[p2])) tmp[len++] = a1[p1++];
//		else tmp[len++] = a2[p2++];
//	}
//	for (int i = 0; i < n; i++) a[i] = tmp[i];
//}

//void radix_sort(int a[], int n) {
//	int e = 4, b = 1 << e;
//	vector<int> bucket[b];
//	for (int k = 0; k <= 7; k++) {
//		for (auto& i : bucket) i.clear();
//		int radix = k * e;
//		for (int i = 0; i < n; i++) {
//			int d = (a[i] >> radix) & (b - 1);
//			bucket[d].push_back(a[i]);
//		}
//		int len = 0;
//		for (const auto& i : bucket)
//			for (const auto& j : i) a[len++] = j;
//	}
//}

int A[10000000+5];

int main() {
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }
    quick_sort(A, N);
    if (N%2 ==1) {
        int mid = (N+1)/2;
        cout << A[mid-1] << "\n";
    }
    else {
        int mid1 = N/2-1;
        int mid2 = N/2;
        cout << (A[mid1] + A[mid2]) /2 << "\n";
    }
}
