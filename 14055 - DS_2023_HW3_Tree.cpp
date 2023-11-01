// C++ code to implement the approach
// https://www.geeksforgeeks.org/minimum-swaps-to-sort-the-leaf-nodes-in-a-perfect-binary-tree/
#include <bits/stdc++.h>
using namespace std;
vector<int> A(100000+5, -1);
// Function to perform swap in the left
// and right parts if required
bool mergeSubTrees(vector<int>& a, int low, int mid,
                   int high)
{
    // If the leaf nodes are already sorted
    if (a[mid] < a[mid + 1])
        return 0;

    // Swapping the left leaf nodes
    // with right leafnodes
    for (int i = low; i <= mid; i++)
        swap(a[i], a[i + (high - low + 1) / 2]);
    return 1;
}

// Recursive function to count the
// operations required in left and right
// subtree to make leaf nodes sorted
void minSwapsRequired(vector<int>& a, int low, int high,
                      int& result)
{
    if (low < high) {
        // Calculating middle point for
        // partitioning the tree into
        // left and right subtrees
        int mid = low + (high - low) / 2;
        // Recursive call for left subtree
        minSwapsRequired(a, low, mid, result);
        // Recursive call for right subtree
        minSwapsRequired(a, mid + 1, high, result);
        // If swap was made in left
        // and right part of subtrees
        // then increase the result
        if (mergeSubTrees(a, low, mid, high))
            result++;
    }
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//TreeNode* constructTree(vector<int>& A) {
//    if (A.empty()) return nullptr;
//    TreeNode* root = new TreeNode(A[0]);
//    TreeNode* curr = root;
////    queue<TreeNode*> q;
////    q.push(root);
//    for (int i = 1; i < A.size(); i += 2) {
//        // TreeNode* curr = q.front();
//        // q.pop();
//        if (A[i] != -1) {
//            curr->left = new TreeNode(A[i]);
//            // q.push(curr->left);
//        }
//        if (i + 1 < A.size() && A[i + 1] != -1) {
//            curr->right = new TreeNode(A[i + 1]);
//            // q.push(curr->right);
//        }
//        curr = curr->
//    }
//    return root;
//}
int maximumRootToLeafPath(vector<int>& A , int id , int max_num) {
    if (A.empty()) return 0;
    else if (A[id] == -1) return max_num;
    //cout << id;
    max_num = max_num + A[id];
    int leftPath = maximumRootToLeafPath(A , (id) * 2 , max_num);
    int rightPath = maximumRootToLeafPath(A , (id) * 2 + 1, max_num);
    return max(leftPath, rightPath);
}
// Driver code
int main()
{
    int L;
    cin >> L;
      // Initialize with -1 values
    for (int i = 1; i < (1 << L); i++) {
        cin >> A[i];
        //cout << i;
    }
    // TreeNode* root = constructTree(A);
    int maxPathValue = maximumRootToLeafPath(A , 1 , 0);
    int N = L-1;
    L = (1<<L)-1;
    N = (1 << N);
    // cout << N << " " << L << "\n";
    vector<int> a;
    //int tmp;
    for (int i = 1; i<=L ;i++) {
        //cin >> tmp;
        if (i >= N) {
            //cout << A[i-1] ;
            a.push_back(A[i]);
        }
    }
    // Perfect tree with N height
    // has 2^N leaf nodes
    // vector<int> a = { 2,1,4,3};
    int result = 0;
    minSwapsRequired(a, 0, N - 1, result);

    // Check if the leaf nodes are
    // now in increasing order or not
    if (is_sorted(a.begin(), a.end()))
        cout << result << "\n";
    else
        cout << -1<<"\n";
    cout << maxPathValue;
    return 0;
}
