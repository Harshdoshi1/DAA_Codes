#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
    int id, deadline, profit;

    // Constructor
    Job(int id = 0, int deadline = 0, int profit = 0)
        : id(id), deadline(deadline), profit(profit) {}
};

class JobScheduling {
public:
    void scheduleJobs(Job jobs[], int n) {
        sort(jobs, jobs + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });

        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (jobs[i].deadline > maxDeadline) {
                maxDeadline = jobs[i].deadline;
            }
        }

        int* result = new int[maxDeadline];
        bool* slot = new bool[maxDeadline];
        fill(slot, slot + maxDeadline, false);

        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = min(maxDeadline, jobs[i].deadline) - 1; j >= 0; j--) {
                if (!slot[j]) { // If the slot is free
                    result[j] = jobs[i].id; // Assign the job id to the slot
                    slot[j] = true; // Mark the slot as occupied
                    totalProfit += jobs[i].profit; // Add the profit
                    break;
                }
            }
        }

        cout << "Jobs scheduled: ";
        for (int i = 0; i < maxDeadline; i++) {
            if (slot[i]) {
                cout << "Job " << result[i] << " ";
            }
        }
        cout << "\nTotal Profit: " << totalProfit << endl;

        delete[] result;
        delete[] slot;
    }
};

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job* jobs = new Job[n];

    cout << "Enter job details (id, deadline, profit):" << endl;
    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cout << "Job " << i + 1 << ": ";
        cin >> id >> deadline >> profit;
        jobs[i] = Job(id, deadline, profit);
    }

    JobScheduling scheduler;
    scheduler.scheduleJobs(jobs, n);

    delete[] jobs;
    return 0;
}

