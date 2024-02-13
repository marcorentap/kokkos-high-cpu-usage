#include <Kokkos_Core.hpp>
#include <cstdio>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
    Kokkos::ScopeGuard guard(argc, argv);
    while(1) {
        sleep(2);
        printf("wakeup!\n");
    }
    return EXIT_SUCCESS;
}
