// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Job {
// public:
//     int id, deadline, profit;
//     // Constructor
//     Job(int id = 0, int deadline = 0, int profit = 0)
//         : id(id), deadline(deadline), profit(profit) {}
// };

// class JobScheduling {
// public:
//     // Function to schedule jobs and maximize profit
//     void scheduleJobs(Job jobs[], int n) {
//         // Step 1: Sort jobs by profit in descending order
//         sort(jobs, jobs + n, [](Job a, Job b) {
//             return a.profit > b.profit;
//         });
        
//         // Find the maximum deadline to determine the number of slots needed
//         int maxDeadline = 0;
//         for (int i = 0; i < n; i++) {
//             maxDeadline = max(maxDeadline, jobs[i].deadline);
//         }

//         // Step 2: Initialize an array to keep track of free time slots
//         vector<int> result(maxDeadline, -1); // To store job ids in selected time slots
//         vector<bool> slot(maxDeadline, false); // Track occupied slots
//         int totalProfit = 0;

//         // Step 3: Iterate through all jobs
//         for (int i = 0; i < n; i++) {
//             // Find a free slot for this job (starting from the last possible slot)
//             for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
//                 if (!slot[j]) { // If the slot is free
//                     result[j] = jobs[i].id; // Assign the job id to the slot
//                     slot[j] = true; // Mark the slot as occupied
//                     totalProfit += jobs[i].profit; // Add the profit
//                     break;
//                 }
//             }
//         }

//         // Print selected jobs and total profit
//         cout << "Jobs scheduled: ";
//         for (int i = 0; i < maxDeadline; i++) {
//             if (slot[i]) {
//                 cout << "Job " << result[i] << " ";
//             }
//         }
//         cout << "\nTotal Profit: " << totalProfit << endl;
//     }
// };

// int main() {
//     // Array of jobs (id, deadline, profit) entered by user
//     int n;
//     cout << "Enter the number of jobs: ";
//     cin >> n;
//     Job jobs[n];
//     cout << "Enter the job id, deadline, and profit for each job:" << endl;
//     for (int i = 0; i < n; i++) {
//         int id, deadline, profit;
//         cin >> id >> deadline >> profit;
//         jobs[i] = Job(id, deadline, profit);
//     }

//     // Create an instance of JobScheduling and schedule jobs
//     JobScheduling scheduler;
//     scheduler.scheduleJobs(jobs, n);

//     return 0;
// }


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Activity class to represent an activity with start and finish times
class Activity {
public:
    int start, finish;

    // Constructor
    Activity(int start=0, int finish=0) : start(start), finish(finish) {}
};

// Comparator function to sort activities by their finish times
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// ActivitySelection class that contains methods to perform activity selection
class ActivitySelection {
public:
    // Method to print the maximum set of activities
    void printMaxActivities(vector<Activity>& activities) {
        int n = activities.size();
        // Sort activities based on finish time
        sort(activities.begin(), activities.end(), compare);
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
    // Initialize the array of activities with start and finish times entered manually by the user using cin
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    // Use vector to store activities
    vector<Activity> activities;

    cout << "Enter the start and finish times of each activity:" << endl;
    for (int i = 0; i < n; i++) {
        int start, finish;
        cin >> start >> finish;
        activities.push_back(Activity(start, finish));
    }

    ActivitySelection activitySelection;
    activitySelection.printMaxActivities(activities);
    
    return 0;
}
