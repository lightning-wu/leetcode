#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char** argv) {
    int ch = 0;

    while (1) {
        pid_t pid = fork();
        if (pid < 0) {
            sleep(10);
            continue;
        }

        if (pid == 0) {
            printf("i am child  begin to sleep\n");
            sleep(10);
			printf("child exit");
            return 0;
        } else {
            printf("i am parent\n");
        }
		printf("occur once?\n");
        int status = 0;
        while (waitpid(pid, &status, 0) == -1) {
        }
        printf("parent exit\n");
        sleep(1);
        break;
    }
    return 0;
}
