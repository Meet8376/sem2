#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int arr[20];
    int i;
    int pid;
    int fd[2]; 
    int sum_parent = 0;
    int sum_child = 0;
    int total_sum = 0;

    for (i = 0; i < 20; i++) {
        arr[i] = i + 1;
    }

    if (pipe(fd) == -1) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        close(fd[0]); 
        for (i = 10; i < 20; i++) {
            sum_child += arr[i];
        }
        write(fd[1], &sum_child, sizeof(sum_child));
        close(fd[1]);
    } 
    else {
        close(fd[1]); 
        for (i = 0; i < 10; i++) {
            sum_parent += arr[i];
        }
        
        wait(NULL);
        read(fd[0], &sum_child, sizeof(sum_child));
        close(fd[0]);

        total_sum = sum_parent + sum_child;
        
        printf("Parent Sum (0-9): %d\n", sum_parent);
        printf("Child Sum (10-19): %d\n", sum_child);
        printf("Total Sum: %d\n", total_sum);
    }

    return 0;
}
