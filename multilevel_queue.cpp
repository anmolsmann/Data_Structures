#include <iostream>
using namespace std;

// Step 1: Start the process
struct Process {
    int id;
    int burstTime;
};

// Step 2: Input the number of processes in the ready Queue
int getNumProcesses() {
    int num;
    cout << "Enter the number of processes in the ready queue: ";
    cin >> num;
    return num;
}

// Step 3: For each process in the ready Q, assign the process id and input the CPU burst time
void getProcesses(int numProcesses, Process processes[]) {
    for (int i = 0; i < numProcesses; i++) {
        int burstTime;
        cout << "Enter CPU burst time for process " << (i + 1) << ": ";
        cin >> burstTime;
        processes[i].id = i + 1;
        processes[i].burstTime = burstTime;
    }
}

// Step 4: Input the time quantum for Queue 1, Queue 2, Queue 3
void getTimeQuantums(int& quantum1, int& quantum2, int& quantum3) {
    cout << "Enter time quantum for Queue 1: ";
    cin >> quantum1;
    cout << "Enter time quantum for Queue 2: ";
    cin >> quantum2;
    cout << "Enter time quantum for Queue 3: ";
    cin >> quantum3;
}

// Step 5: Implement Queue 1 and Queue 2 using Round Robin Scheduling Algorithm
//         and Queue 3 using First Come First Serve.
void multilevelQueueScheduling(Process processes[], int numProcesses, int quantum1, int quantum2, int quantum3) {
    const int maxProcesses = numProcesses;
    const int maxQueueSize = maxProcesses;

    Process queue1[maxQueueSize];
    Process queue2[maxQueueSize];
    Process queue3[maxQueueSize];

    int queue1Front = 0, queue1Rear = 0, queue2Front = 0, queue2Rear = 0, queue3Front = 0, queue3Rear = 0;
    int completedProcesses = 0;
    int currentTime = 0;

    for (int i = 0; i < numProcesses; i++)
        queue1[queue1Rear++] = processes[i];

    while (completedProcesses < maxProcesses) {
        if (queue1Front != queue1Rear) {
            Process currentProcess = queue1[queue1Front++];
            if (currentProcess.burstTime > quantum1) {
                currentProcess.burstTime -= quantum1;
                currentTime += quantum1;
                queue2[queue2Rear++] = currentProcess;
            } else {
                currentTime += currentProcess.burstTime;
                completedProcesses++;
            }
        } else if (queue2Front != queue2Rear) {
            Process currentProcess = queue2[queue2Front++];
            if (currentProcess.burstTime > quantum2) {
                currentProcess.burstTime -= quantum2;
                currentTime += quantum2;
                queue3[queue3Rear++] = currentProcess;
            } else {
                currentTime += currentProcess.burstTime;
                completedProcesses++;
            }
        } else if (queue3Front != queue3Rear) {
            Process currentProcess = queue3[queue3Front++];
            currentTime += currentProcess.burstTime;
            completedProcesses++;
        }
    }

    // Step 6: Calculate which process has the highest completion time
    int highestCompletionTime = currentTime;

    // Step 7: Calculate the highest completion time of the process
    cout << "Highest completion time: " << highestCompletionTime << endl;
}

int main() {
    // Step 2: Input the number of processes in the ready Queue
    int numProcesses = getNumProcesses();
    Process* processes = new Process[numProcesses];

    // Step 3: For each process in the ready Q, assign the process id and input the CPU burst time
    getProcesses(numProcesses, processes);

    // Step 4: Input the time quantum for Queue 1, Queue 2, Queue 3
    int quantum1, quantum2, quantum3;
    getTimeQuantums(quantum1, quantum2, quantum3);

    // Step 5: Implement Queue 1 and Queue 2 using Round Robin Scheduling Algorithm
    //         and Queue 3 using First Come First Serve.
    multilevelQueueScheduling(processes, numProcesses, quantum1, quantum2, quantum3);

    // Step 8: Stop the process
    delete[] processes;
    return 0;
}