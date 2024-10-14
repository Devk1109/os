#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
};

bool compare(Process a, Process b) {
    return a.priority < b.priority;
}

void nonPreemptivePriority(vector<Process> &processes) {
    int time = 0;
    sort(processes.begin(), processes.end(), compare);

    for (auto &p : processes) {
        time += p.burstTime;
        cout << "Process " << p.id << " completed at time " << time << endl;
    }
}

int main() {
    vector<Process> processes = {{1, 10, 2}, {2, 5, 1}, {3, 8, 3}};

    nonPreemptivePriority(processes);
    return 0;
}
