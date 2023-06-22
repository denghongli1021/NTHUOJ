#include <iostream>
#include <set>

void point(std::set<int> &m, int pt);
void segment(std::set<int> &m, int pt);

int main() {
    int op, pt, T;
    std::set<int> m;
    std::cin >> T;
    while (T--) {
        std::cin >> op >> pt;
        if (op == 1) point(m, pt);
        else segment(m, pt);
    }
}

void point(std::set<int> &m, int pt) {
    auto it = m.find(pt);
    if (it != m.end()) m.erase(pt);
    else m.insert(pt);
}

void segment(std::set<int> &m, int pt) {
    auto it = m.find(pt);
    if (it == m.end()) {
//        最后一个元素之后的位置
        // 插值搜尋
        m.insert(pt);
        it = m.find(pt);
        if (it == m.begin()) std::cout << -1 << '\n';
        else {
            auto left = it, right = it;
            left--, right++;
            if (right == m.end()) std::cout << -1 << '\n';
            else std::cout << *right - *left << '\n';
        }
        m.erase(pt);
    }
    else {
        auto left = it, right = it;
        right++;
        if (right == m.end()) std::cout << -1 << '\n';
        else std::cout << *right - *left << '\n';
    }
}

// By Utin
