#define CRT_SECURE_NO_WARNING
#define M_PI 3.14159265358979323846
#define SIZE 100000000

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {

    //работа с double
    clock_t start = clock();
    double* sinus_array_d = malloc(SIZE * sizeof(double));
    double corners_together_d = 0;
    double w_d = (2 * M_PI) / SIZE;

#pragma acc kernels
#pragma omp parallel for num_threads(6){
        for (int i = 0; i < SIZE; i++) {
            corners_together_d += sin(w_d * i);
        }
        clock_t end = clock();
        printf("time %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("%.50%lf\n", corners_together_d);
    }
    
    //__________________

    //работа с float
    start = clock();
    float* sinus_array_f = malloc(SIZE * sizeof(float));
    float corners_together_f = 0;
    float w_f = (2 * M_PI) / SIZE;

#pragma acc kernels
#pragma omp parallel for num_threads(6){
        for (int i = 0; i < SIZE; i++) {
            corners_together_f += sin(w_f * i);
        }
        end = clock();
        printf("time %f\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("%.50f\n", corners_together_f);
    }
    //__________________

    return 0;
}
