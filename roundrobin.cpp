#include <iostream>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimeslices(Process* processes, int numProcesses, int timeSlice) {
    for (int i = 0; i < numProcesses; i++) {
        int numTimeslices = processes[i].burstTime / timeSlice;
        if (processes[i].burstTime % timeSlice != 0) {
            numTimeslices++;
        }
        processes[i].turnaroundTime = numTimeslices * timeSlice;
    }
}

void calculateWaitingTimes(Process* processes, int numProcesses) {
    processes[0].waitingTime = 0;

    for (int i = 1; i < numProcesses; i++) {
        int timeDifference = processes[i - 1].turnaroundTime;
        processes[i].waitingTime = processes[i - 1].waitingTime +
                                   processes[i - 1].burstTime + timeDifference;
    }
}

void calculateAverages(Process* processes, int numProcesses, double& avgWaitingTime, double& avgTurnaroundTime) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < numProcesses; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime = static_cast<double>(totalWaitingTime) / numProcesses;
    avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / numProcesses;
}

int main() {
    int numProcesses, timeSlice;
    cout << "Enter the number of processes in the ready queue: ";
    cin >> numProcesses;
    cout << "Enter the time quantum (time slice): ";
    cin >> timeSlice;

    Process* processes = new Process[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    calculateTimeslices(processes, numProcesses, timeSlice);
    calculateWaitingTimes(processes, numProcesses);

    double avgWaitingTime, avgTurnaroundTime;
    calculateAverages(processes, numProcesses, avgWaitingTime, avgTurnaroundTime);

    cout<< "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t\t"<< processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << "\n";
    }

    cout << "\nAverage Waiting Time: " << avgWaitingTime << "\n";
    cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";
    
    return 0;
}
