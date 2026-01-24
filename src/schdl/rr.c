#include <stdio.h>
#include "process.h"

#define QUANTUM 2

int main() {
    int n;
    printf("Número de procesos: ");
    scanf("%d", &n);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    int time = 0;
    int completed = 0;

    /* Inicializar remaining_time */
    for (int i = 0; i < n; i++) {
        p[i].remaining_time = p[i].burst_time;
    }

    /* Round Robin */
    while (completed < n) {
        int executed = 0;

        for (int i = 0; i < n; i++) {

            if (p[i].arrival_time <= time &&
                p[i].remaining_time > 0) {

                executed = 1;

                int exec_time =
                    (p[i].remaining_time > QUANTUM)
                    ? QUANTUM
                    : p[i].remaining_time;

                p[i].remaining_time -= exec_time;
                time += exec_time;

                if (p[i].remaining_time == 0) {
                    completed++;
                    p[i].turnaround_time =
                        time - p[i].arrival_time;
                    p[i].waiting_time =
                        p[i].turnaround_time - p[i].burst_time;
                }
            }
        }

        /* CPU ocioso */
        if (!executed) {
            time++;
        }
    }

    print_results(p, n, "RR Scheduling");
    return 0;
}
