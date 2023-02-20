#define CRT_SECURE_NO_WARNING
#define M_PI 3.14159265358979323846
#define SIZE 100000000

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

oyoh5Bef5p

int main() {

    float* sinus_array_f = malloc(SIZE * sizeof(float));
    double* sinus_array_d = malloc(SIZE * sizeof(double));

    float w_f = (2 * M_PI) / SIZE;
    double w_d = (2 * M_PI) / SIZE;

    float corners_together_f = 0;
    double corners_together_d = 0;

#pragma acc data create(sinus_array_f[:SIZE]) copy(corners_together_f) copy(corners_together_d) copyin(w_f) copyin(w_d){
#pragma acc kernel{
            for (int i = 0; i < SIZE; i++) {
                sinus_array_f[i] = (sin(i * w_f));
                sinus_array_d[i] = (sin(i * w_d));
            }
        }

#pragma acc kernel{
            for (int i = 0; i < SIZE; i++) {
                corners_together_f += sinus_array_f[i];
                corners_together_d += sinus_array_d[i];
            }
        }
    }

    return 0;
}