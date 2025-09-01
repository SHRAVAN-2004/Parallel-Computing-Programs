//Write an OpenMP program that divides the iterations into chunks containing 2 iterations, respectively
//(OMP_SCHEDULE=static,2). Its input should be the number of iterations, and its output should be which iterations of a 
//para/llelized for loop are executed by which thread.
#include <stdio.h>
#include <omp.h>
int main() {
    int num_iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);
    #pragma omp parallel
    {
        #pragma omp for schedule(static,2)
        for (int i = 0; i < num_iterations; i++) {
            printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
        }
    }
    return 0;
}
