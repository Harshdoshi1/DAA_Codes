#include <iostream>
#include <algorithm>
using namespace std;

// Activity class to represent an activity with start and finish times
class Activity {
public:
    int start, finish;

    // Constructor
    Activity(int start = 0, int finish = 0) : start(start), finish(finish) {}
};

// Comparator function to sort activities by their finish times
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// ActivitySelection class that contains methods to perform activity selection
class ActivitySelection {
public:
    // Method to print the maximum set of activities
    void printMaxActivities(Activity activities[], int n) {
        // Sort activities based on finish time
        sort(activities, activities + n, compare);
        cout << "Following activities are selected:" << endl;

        // The first activity is always selected
        int i = 0;
        cout << "(" << activities[i].start << ", " << activities[i].finish << ")";

        // Consider the rest of the activities
        for (int j = 1; j < n; j++) {
            // If the start time of this activity is greater or equal to the finish time of the previously selected activity
            if (activities[j].start >= activities[i].finish) {
                cout << ", (" << activities[j].start << ", " << activities[j].finish << ")";
                i = j;
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity* activities = new Activity[n];

    cout << "Enter start and finish times for each activity:" << endl;
    for (int i = 0; i < n; i++) {
        int start, finish;
        cout << "Activity " << i + 1 << ": ";
        cin >> start >> finish;
        activities[i] = Activity(start, finish);
    }

    ActivitySelection selector;
    selector.printMaxActivities(activities, n);

    delete[] activities;
    return 0;
}
