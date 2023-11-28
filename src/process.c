/*
 * thread.c - simple example demonstrating the creation of threads
 */

#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/* global value */
int g_value = 0;

void* child_func() {
    g_value = 1;
    return NULL;
}

int main() {
    size_t pid = fork();
    if (pid == -1) {
        return -1;
    }

    if (pid) {
        g_value = 2;

        if (waitpid(pid, NULL, 0) == -1) {
            return -1;
        }
    }

    else {
        child_func();
    }

    printf("value = %d\n", g_value);
    return 0;
}