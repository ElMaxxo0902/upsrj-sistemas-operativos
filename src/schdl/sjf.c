#include "process.h"

void sjf_schedule(Process p[], int n)
{
    int current_time = 0;
    int completed = 0;

    /* Inicializar estado */
    for (int i = 0; i < n; i++) {
        p[i].completed = 0;
    }

    /* Mientras existan procesos sin terminar */
    while (completed < n) {

        int idx = -1;
        int min_burst = 1e9;

        /* Seleccionar el proceso más corto disponible */
        for (int i = 0; i < n; i++) {
            if (!p[i].completed &&
                p[i].arrival_time <= current_time) {

                if (p[i].burst_time < min_burst ||
                   (p[i].burst_time == min_burst &&
                    p[i].arrival_time < p[idx].arrival_time) ||
                   (p[i].burst_time == min_burst &&
                    p[i].arrival_time == p[idx].arrival_time &&
                    p[i].id < p[idx].id)) {

                    min_burst = p[i].burst_time;
                    idx = i;
                }
            }
        }

        /* Si no hay proceso disponible, avanzar tiempo */
        if (idx == -1) {
            current_time++;
            continue;
        }

        /* Calcular tiempos */
        p[idx].waiting_time =
            current_time - p[idx].arrival_time;

        current_time += p[idx].burst_time;

        p[idx].turnaround_time =
            p[idx].waiting_time + p[idx].burst_time;

        p[idx].completed = 1;
        completed++;
    }
}
