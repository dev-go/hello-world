// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/*
int mkdir(const char *pathname,mode_t mode);
    其中参数pathname是新创建目录的目录名，mode指定该目录的访问权限，这些位将受到文件创建方式屏蔽（umask）的修正。
    该函数创建一个名为pathname的空目录，此目录自动含有“.”和“..”2个登记项。这个新创建目录的用户ID被设置为调用进程的有效用户ID，其组则为父目录的组ID或者进程的有效组ID。
    若调用成功，mkdir将更新该目录的st_atime、st_ctime和st_mtime，同时更新其父目录的st_ctime和st_mtime，然后返回0。若调用失败，mkdir将返回-1.
    由pathname指定的新目录的父目录必须存在，并且调用进程必须具有该父目录的写权限以及pathname涉及的各个分路径目录的搜寻权限。

int rmdir(const char *pathname);
    使用rmdir函数时，目录必须为空，否则调用失败，函数返回-1.成功时，函数返回0.

int remove(char * filename);
    [参数] filename为要删除的文件名，可以为一目录。如果参数filename 为一文件，则调用unlink()处理；若参数filename 为一目录，则调用rmdir()来处理。
    [返回值] 成功则返回0，失败则返回-1，错误原因存于errno。

int rename(char * oldname, char * newname);
    [参数] oldname为旧文件名，newname为新文件名。
    [返回值] 修改文件名成功则返回0，否则返回-1。
    重命名文件
        如果newname指定的文件存在，则会被删除。
        如果newname与oldname不在一个目录下，则相当于移动文件。
    重命名目录：
        如果oldname和oldname都为目录，则重命名目录。
        如果newname指定的目录存在且为空目录，则先将newname删除。
        对于newname和oldname两个目录，调用进程必须有写权限。
        重命名目录时，newname不能包含oldname作为其路径前缀。例如，不能将/usr更名为/usr/foo/testdir，因为老名字（ /usr/foo）是新名字的路径前缀，因而不能将其删除。
*/

// int main(int argc, char const *argv[])
// {
//     if (argc != 3)
//     {
//         fprintf(stderr, "Usage: %s <cmd> <path>\n"
//                         "<cmd>: 'mkdir', 'rmdir', 'remove'\n",
//                 argv[0]);
//         return EXIT_FAILURE;
//     }
//     if (strcmp(argv[1], "mkdir") == 0)
//     {
//         if (mkdir(argv[2], S_IRUSR | S_IWUSR | S_IRGRP) != 0)
//         {
//             fprintf(stderr, "mkdir failed: %s, path = %s\n", strerror(errno), argv[2]);
//             return errno;
//         }
//         fprintf(stdout, "mkdir: ok, path = %s\n", argv[2]);
//     }
//     else if (strcmp(argv[1], "rmdir") == 0)
//     {
//         if (rmdir(argv[2]) != 0)
//         {
//             fprintf(stderr, "rmdir failed: %s, path = %s\n", strerror(errno), argv[2]);
//             return errno;
//         }
//         fprintf(stdout, "rmdir: ok, path = %s\n", argv[2]);
//     }
//     else if (strcmp(argv[1], "remove") == 0)
//     {
//         if (remove(argv[2]) != 0)
//         {
//             fprintf(stderr, "remove failed: %s, path = %s\n", strerror(errno), argv[2]);
//             return errno;
//         }
//         fprintf(stdout, "remove: ok, path = %s\n", argv[2]);
//     }
//     else
//     {
//         fprintf(stderr, "unknown cmd: %s\n", argv[1]);
//         fprintf(stderr, "Usage: %s <cmd> <path>\n"
//                         "\tcmd: 'mkdir', 'rmdir', 'remove'\n",
//                 argv[0]);
//         return EXIT_FAILURE;
//     }
//     return EXIT_SUCCESS;
// }

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <oldname> <newname>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (rename(argv[1], argv[2]) != 0)
    {
        fprintf(stderr, "rename failed: %s, oldname = %s, newname = %s\n", strerror(errno), argv[1], argv[2]);
        return errno;
    }
    fprintf(stdout, "rename: ok, oldname = %s, newname = %s\n", argv[1], argv[2]);
    return EXIT_SUCCESS;
}

/*
opendir()和 fdopendir() 都是打开一个目录返回DIR 类型指针(目录的句柄)
closedir() 关闭打开的目录句柄
readdir() 从一个目录流读取连续的条目,返回时并未对文件名进行排序，按照文件在目录中出现的天然次序，也就是文件系统向目录中添加文件的次序 "ls -f" 查看的一样 
rewinddir() 可将目录流回到起点，类型C语言库函数中的 rewind()将打开的文件指向文件开头。
seekdir()和 telldir() 允许随机访问目录流，telldir()返回当前目录流的位置，seekdir()设置目录流的位置
dirfd() 有一个目录流，就有一个文件描述符与之关联， dirfd根据目录流返回对应的文件描述符
*/

/*
void show_dir(char const *path);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat _stat;
    if (stat(argv[1], &_stat) < 0)
    {
        fprintf(stderr, "stat failed: %s, path = %s\n", strerror(errno), argv[1]);
        return errno;
    }

    if (S_ISDIR(_stat.st_mode))
    {
        show_dir(argv[1]);
    }
    else
    {
        fprintf(stdout, "%s is not a dir\n", argv[1]);
    }

    return EXIT_SUCCESS;
}

void show_dir(char const *path)
{
    DIR *dir = opendir(path);
    // TODO: closedir(dir);
    struct dirent *de;
    while ((de = readdir(dir)) != NULL)
    {
        fprintf(stdout, "inode = %lu, name = %s\n", de->d_ino, de->d_name);
    }
    closedir(dir);
}
*/

/*
getcwd()    获取进程的当前工作目录，得到的是绝对路径名
            getcwd()会将当前工作目录的绝对路径复制到参数buffer所指的内存空间中,参数size为buf的空间大小。
            这时会将工作目录的绝对路径复制到buf所指向的空间中,但如果路径长度大于size,则会返回NULL
            令 buf 为 NULL并使 size 为零来使 getcwd 调用 malloc 动态给 buf 分配,但是这种情况要特别注意使用后释放缓冲以防止内存泄漏。
chdir()     改变进程当前工作目录
            返回值执行成功则返回0，失败返回-1，errno为错误代码
*/

/*
int main(int argc, char const *argv[])
{
    char *cwd;
    if ((cwd = getcwd(NULL, 0)) == NULL)
    {
        fprintf(stderr, "getcwd failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: free(cwd);
    fprintf(stdout, "cwd = %s\n", cwd);
    free(cwd);

    if (chdir("/") != 0)
    {
        fprintf(stderr, "chdir failed: %s\n", strerror(errno));
        return errno;
    }

    if ((cwd = getcwd(NULL, 0)) == NULL)
    {
        fprintf(stderr, "getcwd failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: free(cwd);
    fprintf(stdout, "cwd = %s\n", cwd);
    free(cwd);

    return EXIT_SUCCESS;
}
*/