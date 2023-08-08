#include <iostream>

using namespace std;

struct Process {
    int pid;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void sortProcessesByPriority(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void calculateWaitingTurnaroundTimes(Process* processes, int num_processes) {
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void printProcessDetails(Process* processes, int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        cout << "Process ID: " << processes[i].pid << endl;
        cout << "Waiting Time: " << processes[i].waiting_time << endl;
        cout << "Turnaround Time: " << processes[i].turnaround_time << endl;
        cout << endl;
    }

    double avg_waiting_time = static_cast<double>(total_waiting_time) / num_processes;
    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / num_processes;

    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
}

int main() {
    int num_processes;
    cout << "Enter the number of processes in the ready queue: ";
    cin >> num_processes;

    Process* processes = new Process[num_processes];

    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1; 
        cout << "Enter the priority for process " << i + 1 << ": ";
        cin >> processes[i].priority;

        cout << "Enter the burst time for process " << i + 1 << ": ";
        cin >> processes[i].burst_time;

        cout << endl;
    }
    sortProcessesByPriority(processes, num_processes);
    calculateWaitingTurnaroundTimes(processes, num_processes);
    printProcessDetails(processes, num_processes);

    return 0;
}
