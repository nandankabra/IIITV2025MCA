#include <bits/stdc++.h>
using namespace std;

struct Process {
    int pid, arrival, burst;
    int completion, waiting, turnaround;
};

int main() {
    int n, cst;
    cin >> n;
    cin >> cst;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }

    // Sort by arrival time, then by PID for tie-breaking
    sort(processes.begin(), processes.end(), [](Process &a, Process &b) {
        if (a.arrival == b.arrival) return a.pid < b.pid;
        return a.arrival < b.arrival;
    });

    int currentTime = 0;
    double totalWait = 0, totalTAT = 0, totalBurst = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrival) {
            currentTime = processes[i].arrival; // CPU idle till arrival
        }

        int start = currentTime;
        processes[i].waiting = start - processes[i].arrival;
        currentTime += processes[i].burst;
        currentTime += cst; // context switch after each process
        processes[i].completion = currentTime;
        processes[i].turnaround = processes[i].completion - processes[i].arrival;

        totalWait += processes[i].waiting;
        totalTAT += processes[i].turnaround;
        totalBurst += processes[i].burst;
    }

    double avgWait = totalWait / n;
    double avgTAT = totalTAT / n;
    int finalCT = processes.back().completion;
    double efficiency = (totalBurst / finalCT) * 100.0;
    double inefficiency = 100.0 - efficiency;

    // Output
    cout << "Process Arrival Time Burst Time Completion Time Waiting Time Turnaround Time\n";
    for (auto &p : processes) {
        cout << p.pid << "       "
             << p.arrival << "            "
             << p.burst << "          "
             << p.completion << "                "
             << p.waiting << "             "
             << p.turnaround << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << avgWait << "\n";
    cout << "Average Turnaround Time: " << avgTAT << "\n";
    cout << "Efficiency: " << efficiency << "\n";
    cout << "Inefficiency: " << inefficiency << "\n";

    return 0;
}
