#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int PAGE_SIZE = 1024;
const int PAGE_TABLE_SIZE = 4;
const int MEMORY_SIZE = 16;

void displayMemory(const vector<int>& memory)
{
    for (int i = 0; i < memory.size(); ++i)
    {
        cout << "Frame " << i << ": ";
        if (memory[i] == -1)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << "Page " << memory[i] << endl;
        }
    }
}

int main()
{
    vector<int> pageTable(PAGE_TABLE_SIZE, -1);
    vector<int> memory(MEMORY_SIZE, -1);

    int logicalAddress, page, offset;

    while (true)
    {
        cout << "\nEnter logical address (-1 to exit): ";
        cin >> logicalAddress;

        if (logicalAddress == -1)
        {
            break;
        }

        // Calculate page number and offset
        page = logicalAddress / PAGE_SIZE;
        offset = logicalAddress % PAGE_SIZE;

        // Check if the page is valid
        if (page >= PAGE_TABLE_SIZE)
        {
            cout << "Invalid page number!" << endl;
            continue;
        }

        // Check if the page is in memory
        if (pageTable[page] != -1)
        {
            int frame = pageTable[page];
            int physicalAddress = (frame * PAGE_SIZE) + offset;

            cout << "Page number: " << page << endl;
            cout << "Offset: " << offset << endl;
            cout << "Physical address: " << physicalAddress << endl;
        }
        else
        {
            cout << "Page fault occurred. Page is not in memory." << endl;

            // Find an empty frame in memory
            int emptyFrame = -1;
            for (int i = 0; i < memory.size(); ++i)
            {
                if (memory[i] == -1)
                {
                    emptyFrame = i;
                    break;
                }
            }

            if (emptyFrame == -1)
            {
                cout << "No empty frame available. Page replacement required." << endl;
                // Perform page replacement algorithm here
                // Example: FIFO or LRU
                // Update the page table and memory accordingly
            }
            else
            {
                cout << "Assigning an empty frame to the page." << endl;
                memory[emptyFrame] = page;
                pageTable[page] = emptyFrame;
            }
        }

        cout << "\nMemory State:\n";
        displayMemory(memory);
    }

    return 0;
}