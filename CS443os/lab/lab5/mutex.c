#include <stdio.h>

// simple spinlock-based mutex
volatile int lock = 0;

void mutex_lock() {
    while (__sync_lock_test_and_set(&lock, 1)) {
        
    }
}

void mutex_unlock() {
    __sync_lock_release(&lock);
}

int shared = 0;

void work() {
    mutex_lock();  

    int temp = shared;
    temp++;
    shared = temp;

    mutex_unlock(); 
}

int main() { 
    work();
    work();

    printf("Final value: %d\n", shared);
    return 0;
}
