#include <iostream>
#include <queue>
#include <vector>
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
vector<Process> getProcesses(int numProcesses) {
    vector<Process> processes(numProcesses);
    for (int i = 0; i < numProcesses; i++) {
        int burstTime;
        cout << "Enter CPU burst time for process " << (i + 1) << ": ";
        cin >> burstTime;
        processes[i].id = i + 1;
        processes[i].burstTime = burstTime;
    }
    return processes;
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
void multilevelQueueScheduling(vector<Process>& processes, int quantum1, int quantum2, int quantum3) {
    queue<Process> queue1, queue2, queue3;

    for (const Process& process : processes)
        queue1.push(process);

    int time = 0;
    while (!queue1.empty() || !queue2.empty() || !queue3.empty()) {
        if (!queue1.empty()) {
            Process currentProcess = queue1.front();
            queue1.pop();
            if (currentProcess.burstTime > quantum1) {
                currentProcess.burstTime -= quantum1;
                time += quantum1;
                queue2.push(currentProcess);
            } else {
                time += currentProcess.burstTime;
            }
        } else if (!queue2.empty()) {
            Process currentProcess = queue2.front();
            queue2.pop();
            if (currentProcess.burstTime > quantum2) {
                currentProcess.burstTime -= quantum2;
                time += quantum2;
                queue3.push(currentProcess);
            } else {
                time += currentProcess.burstTime;
            }
        } else if (!queue3.empty()) {
            Process currentProcess = queue3.front();
            queue3.pop();
            time += currentProcess.burstTime;
        }
    }

    // Step 6: Calculate which process has the highest completion time
    int highestCompletionTime = time;

    // Step 7: Calculate the highest completion time of the process
    cout << "Highest completion time: " << highestCompletionTime << endl;
}

int main() {
    // Step 2: Input the number of processes in the ready Queue
    int numProcesses = getNumProcesses();

    // Step 3: For each process in the ready Q, assign the process id and input the CPU burst time
    vector<Process> processes = getProcesses(numProcesses);

    // Step 4: Input the time quantum for Queue 1, Queue 2, Queue 3
    int quantum1, quantum2, quantum3;
    getTimeQuantums(quantum1, quantum2, quantum3);

    // Step 5: Implement Queue 1 and Queue 2 using Round Robin Scheduling Algorithm
    //         and Queue 3 using First Come First Serve.
    multilevelQueueScheduling(processes, quantum1, quantum2, quantum3);

    // Step 8: Stop the process
    return 0;
}