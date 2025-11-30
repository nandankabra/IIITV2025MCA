#include <stdio.h>

int lock = 0;
int shared = 0;

void work() { 
    while (lock == 1);  
    lock = 1;

    int temp = shared;
    temp++;
    shared = temp;

    lock = 0;
}

int main() { 
    work();
    work();

    printf("Final value: %d\n", shared);
    return 0;
}
