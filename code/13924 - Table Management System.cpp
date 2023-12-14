#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

struct Guest {
    int id;
    int arrival;
    int group;
    int duration;
} arr[N];

// sort by arrival time
auto cmp_arrival = [](Guest a, Guest b) { return a.arrival < b.arrival; };
set<Guest, decltype(cmp_arrival)> waiting_arrival(cmp_arrival);

// sort by group size (small to large) -> arrival time (late -> early)
auto cmp_group = [](Guest a, Guest b) {
    return a.group == b.group ? a.arrival > b.arrival : a.group < b.group;
};
set<Guest, decltype(cmp_group)> waiting_group(cmp_group);

// available tables -> {table size: number of tables}
map<int, int> table_avl;

// tables in use -> {release time, table size}
multiset<pair<int, int>> table_use; // {release time, table size}

int ans[N];

bool assignTable(int time) {
    // no table or no one is waiting
    if (table_avl.empty() || waiting_arrival.empty()) return false;

    // table (iterator) and guest are about to be assigned
    Guest guest = *waiting_arrival.begin();
    auto table = table_avl.lower_bound(guest.group); // to find the smallest table that can accommodate the guest

    if (table == table_avl.end()) { // no such table

        int largest_size = (*table_avl.rbegin()).first; // largest table size

        // to find the largest-sized guest that can be accommodated
        auto it = waiting_group.upper_bound(Guest{0, 0, largest_size, 0});
        if (it == waiting_group.begin()) return false;
        guest = *(--it);

        // to find the smallest table that can accommodate the guest
        table = table_avl.lower_bound(guest.group);
    }
    // handle table availability
    int table_size = table->first;
    table_avl[table_size]--;
    if (!table_avl[table_size]) table_avl.erase(table_size);
    table_use.insert({time+guest.duration, table_size});

    // record the answer and remove guest from the list
    ans[guest.id] = time;
    waiting_arrival.erase(guest); waiting_group.erase(guest);
    return true;
}

void releaseTable(int time) {
    while (table_use.size() && (*table_use.begin()).first <= time) {
        int release_time = (*table_use.begin()).first;
        table_avl[(*table_use.begin()).second]++;
        table_use.erase(table_use.begin());

        // table release simultaneously
        if (table_use.size() && ((*table_use.begin()).first) == release_time) continue;
        // table release simultaneously

        // attempt to assign table
        while (assignTable(release_time));
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i].arrival >> arr[i].group >> arr[i].duration;
        arr[i].id = i;
    }
    int x, y;
    for (int i=0; i<m; i++) {
        cin >> x >> y;
        table_avl[x] = y;
    }
    for (int i=0; i<n; i++) {
        // clear and assign table before i-th arrival
        releaseTable(arr[i].arrival-1);

        // add to waiting list
        waiting_arrival.insert(arr[i]);
        waiting_group.insert(arr[i]);

        // clear all the table and try to assign table on i-th arrival
        releaseTable(arr[i].arrival);
        assignTable(arr[i].arrival);
    }

    // clear all the remaining table
    if (waiting_arrival.size()) releaseTable(1e9);

    for (int i=0; i<n; i++) cout << ans[i] << endl;
}
