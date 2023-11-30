#include <bits/stdc++.h>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
TreeNode* head;

// 简单队列的实现
template <typename T>
class MyQueue {
public:
    MyQueue(int capacity) : front(0), rear(-1), size(0) {
        this->capacity = capacity;
        data = new T[capacity];
    }

    ~MyQueue() {
        delete[] data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    void push(T item) {
        if (!isFull()) {
            rear = (rear + 1) % capacity;
            data[rear] = item;
            size++;
        }
    }

    T pop() {
        if (!isEmpty()) {
            T item = data[front];
            front = (front + 1) % capacity;
            size--;
            return item;
        }
        return T(); // 返回默认值，这里假设 T 可以被默认构造
    }

private:
    T* data;
    int front, rear, size, capacity;
};

TreeNode* buildCompleteBinaryTree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    head = root;
    MyQueue<TreeNode*> nodeQueue(values.size());
    nodeQueue.push(root);

    int i = 1;
    while (i < values.size()) {
        TreeNode* current = nodeQueue.pop();
        if (i < values.size()) {
            int leftValue = values[i++];
        // if (leftValue != -1) {
            current->left = new TreeNode(leftValue);
            nodeQueue.push(current->left);
        //}
        }
        if (i < values.size()) {
            int rightValue = values[i++];
            // if (rightValue != -1) {
                current->right = new TreeNode(rightValue);
                nodeQueue.push(current->right);
            // }
        }
    }

    return root;
}

int maxLevel(TreeNode* node) {
    if (node == nullptr || node->value == -1) {
        return 0;
    }

    int leftLevel = maxLevel(node->left);
    int rightLevel = maxLevel(node->right);

    return 1 + std::max(leftLevel, rightLevel);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    // 仅当节点值不为 -1 时才输出
     if (root->value != -1) {
        if (root != head) {
            std::cout << root->value << " ";
        } else {
            std::cout << root->value;
        }
     }
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> values(N);
    for (int i = 0; i < N; i++) {
        std::cin >> values[i];
    }

    TreeNode* root = buildCompleteBinaryTree(values);

    int leftSubtreeLevel = maxLevel(root->left);
    int rightSubtreeLevel = maxLevel(root->right);
    leftSubtreeLevel = leftSubtreeLevel + rightSubtreeLevel;
    std::cout << leftSubtreeLevel << "\n";
    postOrderTraversal(root);

    return 0;
}
