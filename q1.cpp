#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void roundRobin(vector<Process> &processes, int quantum) {
    queue<Process> q;
    int time = 0;

    for (auto &p : processes) {
        p.remainingTime = p.burstTime;
        q.push(p);
    }

    while (!q.empty()) {
        Process p = q.front();
        q.pop();

        if (p.remainingTime > quantum) {
            time += quantum;
            p.remainingTime -= quantum;
            q.push(p);
        } else {
            time += p.remainingTime;
            cout << "Process " << p.id << " completed at time " << time << endl;
        }
    }
}

int main() {
    vector<Process> processes = {{1, 10}, {2, 5}, {3, 8}};
    int quantum = 3;

    roundRobin(processes, quantum);
    return 0;
}
