#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum task_status {
    ready,
    blocked,
    running,
};

struct task {
    int id;
    int prior;
    int arrive_time;
    int need_time;
    int used_time;
    task_status status;

    task(int id, int prior, int arrive_time, int need_time)
        : id(id)
        , prior(prior)
        , arrive_time(arrive_time)
        , need_time(need_time)
        , used_time(0)
        , status(ready){};
};

bool operator<(task a, task b) { return a.arrive_time > b.arrive_time; }

const int task_num = 20;

int main(int argc, char const* argv[])
{
    priority_queue<task> q[4];
    vector<task> readyline;
    vector<task> futureline;
    int sum = 0;

    // for (int i = 0; i < task_num; i++) {
    //     int prior = rand() % 4;
    //     int arrive_time = rand() % 21;
    //     int need_time = rand() % 100 + 1;
    //     task a(i, prior, arrive_time, need_time);
    //     futureline.push_back(a);
    // }
    futureline.push_back(task(0, 0, 1, 20));
    futureline.push_back(task(1, 1, 3, 20));
    futureline.push_back(task(2, 3, 6, 20));
    futureline.push_back(task(3, 3, 9, 20));

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < futureline.size(); j++) {
            if (futureline[j].arrive_time == i) {
                int ind = futureline[j].prior;
                q[ind].push(futureline[j]);
            }
        }

        for (int j = 3; j > -1; j--) {
            if (q[j].size()) {
                task a(q[j].top().id, q[j].top().prior, q[j].top().arrive_time, q[j].top().need_time);
                a.used_time = q[j].top().used_time;
                q[j].pop();
                a.status = running;

                cout << "Time " << i << ":"
                     << "task " << a.id << endl;

                a.used_time++;
                a.status = ready;
                if (a.used_time < a.need_time) {
                    q[j].push(a);
                } else {
                    sum++;
                }
                break;
            }
        }

        if (sum == task_num) {
            break;
        }
    }

    system("pause");
    return 0;
}
