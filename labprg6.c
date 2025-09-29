#include <stdio.h>
#include <mpi.h>
#define SIZE 200000000
int main(int argc, char *argv[]) {
    int rank, data_send, data_recv;
    static int data_send[0];
    static int data_recv[1];


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    data_send = rank;

    if (rank == 0) {
        MPI_Send(&data_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&data_recv, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    } else if (rank == 1) {
        MPI_Send(&data_send, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        MPI_Recv(&data_recv, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    printf("Process %d received %d\n", rank, data_recv);
    MPI_Finalize();
    return 0;
}
