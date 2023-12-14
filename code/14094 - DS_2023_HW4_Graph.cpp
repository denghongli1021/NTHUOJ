#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2147483647;
const int MAX_AIRLINES = 55;

struct Flight {
    int destination;
    int cost;
    int airline;
};

struct State {
    int city;
    int cost;
    int changes;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

class Graph {
public:
    explicit Graph(int numCities) : adjList(numCities) {}

//    void addFlight(int from, int to, int cost, int airline) {
//        Flight newFlight;
//        newFlight.destination = to;
//        newFlight.cost = cost;
//        newFlight.airline = airline;
//        adjList[from].push_back(newFlight);
//    }
    void addFlight(int from, int to, int cost, int airline) {
        auto& flights = adjList[from];
        FlightMatcher matcher(to, airline);

        for (auto& existingFlight : flights) {
            if (matcher(existingFlight)) {
                // Flight with the same destination and airline exists, update cost
                existingFlight.cost = cost;
                return; // Exit the function after updating the cost
            }
        }

        // If no existing flight found, add a new one
        Flight newFlight;
        newFlight.destination = to;
        newFlight.cost = cost;
        newFlight.airline = airline;
        adjList[from].push_back(newFlight);
    }
    void deleteFlight(int from, int to, int airline) {
        auto& flights = adjList[from];
        FlightMatcher matcher(to, airline);

        for (auto it = flights.begin(); it != flights.end();) {
            if (matcher(*it)) {
                it = flights.erase(it);
            } else {
                ++it;
            }
        }
    }

    int findCheapestPath(int src, int dst, int maxCost) {
        vector<vector<int>> dp(adjList.size(), vector<int>(MAX_AIRLINES, INF));

        priority_queue<State, vector<State>, greater<State>> pq;
        State initial_state = {src, 0, -1};
        pq.push(initial_state);
        dp[src][0] = 0;

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.city == dst) {
                return current.cost;
            }

            if (current.cost > dp[current.city][current.changes]) {
                continue;
            }

            for (const Flight& flight : adjList[current.city]) {
                int newCost = current.cost + flight.cost + ((flight.airline != current.changes && current.changes != -1) ? 5 : 0);
                int newChanges = flight.airline;

                if (newCost <= maxCost && newCost < dp[flight.destination][newChanges]) {
                    dp[flight.destination][newChanges] = newCost;

                    // Update cost for all possible airline changes if newChanges is -1
                    if (newChanges == -1) {
    for (int i = 0; i < MAX_AIRLINES; ++i) {
        int additionalCost = newCost + ((i != flight.airline) ? 5 : 0);
        if (additionalCost <= maxCost && additionalCost < dp[flight.destination][i]) {
            State newState = {flight.destination, additionalCost, i};
            pq.push(newState);
            dp[flight.destination][i] = additionalCost;
        }
    }
} else {
    State newState = {flight.destination, newCost, newChanges};
    pq.push(newState);
}
                }
            }
        }

        return -1;
    }

private:
    vector<vector<Flight>> adjList;

    struct FlightMatcher {
        int destination;
        int airline;

        FlightMatcher(int dest, int air) : destination(dest), airline(air) {}

        bool operator()(const Flight& flight) const {
            return flight.destination == destination && flight.airline == airline;
        }
    };
};

int main() {
    int c, n;
    int u, v, p, a, w;
    cin >> c >> n;

    Graph graph(c);

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "Add") {
            cin >> u >> v >> p >> a;
            graph.addFlight(u, v, p, a);
        } else if (command == "Delete") {
            cin >> u >> v >> a;
            graph.deleteFlight(u, v, a);
        } else if (command == "Request") {
            cin >> u >> v >> w;
            cout << graph.findCheapestPath(u, v, w) << endl;
        }
    }

    return 0;
}
