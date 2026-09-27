#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Group
{
    int index;                // Original input order
    int people;               // Number of people in the group
    vector<int> milk_amounts; // Amount of milk each person brings
    long long total_milk;     // Total milk from the group
    int max_milk_person;      // Maximum milk from a single person
};

bool compare_groups(const Group &a, const Group &b)
{
    if (a.total_milk != b.total_milk)
        return a.total_milk > b.total_milk; // Sort by total milk (descending)

    if (a.max_milk_person != b.max_milk_person)
        return a.max_milk_person > b.max_milk_person; // Sort by max milk (descending)

    if (a.people != b.people)
        return a.people > b.people; // Sort by number of people (descending)

    return a.index < b.index; // Sort by input order (ascending)
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<Group> groups(N);

        for (int i = 0; i < N; i++)
        {
            groups[i].index = i;
            cin >> groups[i].people;

            groups[i].milk_amounts.resize(groups[i].people);
            groups[i].total_milk = 0;
            groups[i].max_milk_person = 0;

            for (int j = 0; j < groups[i].people; j++)
            {
                cin >> groups[i].milk_amounts[j];
                groups[i].total_milk += groups[i].milk_amounts[j];
                groups[i].max_milk_person = max(groups[i].max_milk_person, groups[i].milk_amounts[j]);
            }
        }

        // Sort the groups according to the criteria
        sort(groups.begin(), groups.end(), compare_groups);

        // Output each group's information in the sorted order
        for (const auto &group : groups)
        {
            for (int i = 0; i < group.milk_amounts.size() ; i++)
            {
                cout << group.milk_amounts[i] << (i == group.milk_amounts.size()-1 ? "\n" : " ");
            }
        }
    }

    return 0;
}