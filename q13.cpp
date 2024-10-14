#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int priority;
};
void preemptivePriority(vector<Process> &processes) {
    int time = 0;
    vector<Process> queue = processes;
    bool completed[queue.size()] = {false};
    int completedCount = 0;

    while (completedCount < queue.size()) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < queue.size(); ++i) {
            if (!completed[i] && queue[i].remainingTime > 0 && queue[i].priority < highestPriority) {
                highestPriority = queue[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            queue[idx].remainingTime--;
            if (queue[idx].remainingTime == 0) {
                completed[idx] = true;
                completedCount++;
                time++;
                cout << "Process " << queue[idx].id << " completed at time " << time << endl;
            } else {
                time++;
            }
        } else {
            time++;
        }
    }
}
int main() {
    vector<Process> processes = {{1, 10, 10, 2}, {2, 5, 5, 1}, {3, 8, 8, 3}};
    
    for (auto &p : processes) {
        p.remainingTime = p.burstTime;
    }
    preemptivePriority(processes);
    return 0;
}
