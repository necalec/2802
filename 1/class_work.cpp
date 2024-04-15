#include <iostream>
#include <omp.h>

int main()
{
    int size_threads;
    std::cin >> size_threads;

#pragma omp parallel shared(size_threads)
    {
        int rank;

#pragma omp for nowait
        for (int i = 0; i < size_threads; i++) {
            rank = omp_get_thread_num();
            std::cout << "I am thread " << rank << std::endl;
        }
    }

    return 0;
}