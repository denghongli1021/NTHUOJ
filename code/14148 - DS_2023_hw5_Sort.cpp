#include <iostream>
#include <vector>

int main() {
    // Read input values
    int N, K;
    std::cin >> N >> K;

    // Read scores into a vector
    std::vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> scores[i];
    }

    // Find the k-th highest score
    int kthHighestScore = -1;
    int left = 0, right = N - 1;

    while (left <= right) {
        int pivotIndex = left;
        int pivotValue = scores[pivotIndex];

        // Partition the array
        for (int i = left + 1; i <= right; ++i) {
            if (scores[i] > pivotValue) {
                std::swap(scores[i], scores[++pivotIndex]);
            }
        }

        std::swap(scores[left], scores[pivotIndex]);

        // Check the position of the pivot
        if (pivotIndex == K - 1) {
            kthHighestScore = pivotValue;
            break;
        } else if (pivotIndex < K - 1) {
            left = pivotIndex + 1;
        } else {
            right = pivotIndex - 1;
        }
    }

    // Output the result
    std::cout << kthHighestScore << '\n';

    return 0;
}
