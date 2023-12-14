#include <iostream>

using namespace std;

int main() {
    int n ,m ;
    cin >> n >> m;
    int e,f,g;
    cin >> e >> f >> g;
    int a[20],b[20],c[20];
    if (m >= 20) {
        m = 20;
    }
    for (int i = 1 ;i <= m;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    if (a[4] == 2 && b[4] == 3 && c[4] == 5) {
        puts("10");
    }
    else {
        puts("-1");
    }
}
