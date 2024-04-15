#include <iostream>
#include <omp.h>

int main()
{
    omp_lock_t writelock;
    omp_init_lock(&writelock);

    int size_threads;
    std::cin >> size_threads;
    int rank;

#pragma omp parallel shared(size_threads) private(rank)
    {
#pragma omp for nowait
        for (int i = 0; i < size_threads; i++) {
            omp_set_lock(&writelock);
            rank = omp_get_thread_num();
            std::cout << "I am thread " << rank << std::endl;
            omp_unset_lock(&writelock);
        }
    }

    return 0;
}