#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job {
    int id;     // Job ID
    int deadline;  // Deadline of the job
    int profit;    // Profit for completing the job
};

// Function to compare jobs based on profit (in descending order)
bool jobComparison(Job a, Job b) {
    return a.profit > b.profit; // Sort by profit in decreasing order
}

// Function to find the maximum profit by scheduling jobs
int jobScheduling(vector<Job>& jobs, int n) {
    // Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), jobComparison);
    
    // To keep track of free time slots
    vector<bool> slots(n, false);

    // Result to store the maximum profit
    int totalProfit = 0;

    // Process each job
    for (int i = 0; i < n; i++) {
        // Find a slot for this job
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // If the slot is available
            if (!slots[j]) {
                // Schedule this job
                slots[j] = true;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    return totalProfit;
}

int main() {
    int n;

    // Ask user for the number of jobs
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    // Ask user to input the jobs' details
    cout << "Enter job details (ID, Deadline, Profit) for each job:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Call jobScheduling function to get the maximum profit
    int result = jobScheduling(jobs, n);
    
    cout << "Maximum profit: " << result << endl;

    return 0;
}

