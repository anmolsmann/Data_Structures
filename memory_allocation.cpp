#include <iostream>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

void allocateWorstFit(MemoryBlock* memory, int numBlocks, int processId, int processSize) {
    int worstFitIndex = -1;
    int maxFragmentation = -1;

    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            int fragmentation = memory[i].size - processSize;
            if (fragmentation > maxFragmentation) {
                maxFragmentation = fragmentation;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = true;
        memory[worstFitIndex].id = processId;
        cout << "Process " << processId << " allocated to block " << worstFitIndex << endl;
    } else {
        cout << "Process " << processId << " cannot be allocated (worst-fit)" << endl;
    }
}

void allocateBestFit(MemoryBlock* memory, int numBlocks, int processId, int processSize) {
    int bestFitIndex = -1;
    int minFragmentation = INT_MAX;

    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            int fragmentation = memory[i].size - processSize;
            if (fragmentation < minFragmentation) {
                minFragmentation = fragmentation;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = true;
        memory[bestFitIndex].id = processId;
        cout << "Process " << processId << " allocated to block " << bestFitIndex << endl;
    } else {
        cout << "Process " << processId << " cannot be allocated (best-fit)" << endl;
    }
}

void allocateFirstFit(MemoryBlock* memory, int numBlocks, int processId, int processSize) {
    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = true;
            memory[i].id = processId;
            cout << "Process " << processId << " allocated to block " << i << endl;
            return;
        }
    }

    cout << "Process " << processId << " cannot be allocated (first-fit)" << endl;
}

void deallocateProcess(MemoryBlock* memory, int numBlocks, int processId) {
    for (int i = 0; i < numBlocks; i++) {
        if (memory[i].allocated && memory[i].id == processId) {
            memory[i].allocated = false;
            memory[i].id = -1;
            cout << "Process " << processId << " deallocated from block " << i << endl;
            return;
        }
    }

    cout << "Process " << processId << " is not currently allocated" << endl;
}

void printMemoryLayout(const MemoryBlock* memory, int numBlocks) {
    cout << "Memory Layout:" << endl;
    for (int i = 0; i < numBlocks; i++) {
        cout << "Block " << i << " Size: " << memory[i].size << " Allocated: " << (memory[i].allocated ? "Yes" : "No") << endl;
    }
    cout << endl;
}

int main() {
    const int numBlocks = 5;
    MemoryBlock memory[numBlocks] = {
        {0, 100, false},
        {0, 50, false},
        {0, 200, false},
        {0, 75, false},
        {0, 150, false},
    };

    printMemoryLayout(memory, numBlocks);

    allocateWorstFit(memory, numBlocks, 1, 80);
    allocateBestFit(memory, numBlocks, 2, 100);
    allocateFirstFit(memory, numBlocks, 3, 120);

    printMemoryLayout(memory, numBlocks);

    deallocateProcess(memory, numBlocks, 1);
    deallocateProcess(memory, numBlocks, 2);

    printMemoryLayout(memory, numBlocks);

    allocateWorstFit(memory, numBlocks, 4, 60);
    allocateBestFit(memory, numBlocks, 5, 100);
    allocateFirstFit(memory, numBlocks, 6, 200);

    printMemoryLayout(memory, numBlocks);

    return 0;
}