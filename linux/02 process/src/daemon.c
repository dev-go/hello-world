// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char const *argv[])
{
    int ret = umask(0000);
    if (ret < 0)
    {
        fprintf(stderr, "umask failed: %s\n", strerror(errno));
        return errno;
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return errno;
    }
    else if (pid > 0)
    {
        // parent process
        fprintf(stdout, "[P] exit\n");
        return EXIT_SUCCESS;
    }

    // child process to daemon process
    ret = setsid();
    if (ret < 0)
    {
        fprintf(stderr, "setsid failed: %s\n", strerror(errno));
        return errno;
    }
    ret = chdir("/");
    if (ret < 0)
    {
        fprintf(stderr, "chdir failed: %s\n", strerror(errno));
        return errno;
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    openlog(argv[0], LOG_PID, LOG_SYSLOG);
    char const *msg = "Hello, Linux C!";
    for (;;)
    {
        syslog(LOG_DEBUG, "%s", msg);
        sleep(2);
    }
    syslog(LOG_INFO, "[%d] %s finished!", getpid(), argv[0]);
    closelog();

    return EXIT_SUCCESS;
}