// Copyright (c) 2020, devgo.club
// All rights reserved.

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>

// void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
// (1) 参数:
//      @addr
//          指向欲映射的内存起始地址，通常设为 NULL，代表让系统自动选定地址，映射成功后返回该地址
//      @length
//          代表将文件中多大的部分映射到内存
//      @prot
//          映射区域的保护方式。可以为以下几种方式的组合：
//          PROT_EXEC 映射区域可被执行
//          PROT_READ 映射区域可被读取
//          PROT_WRITE 映射区域可被写入
//          PROT_NONE 映射区域不能存取
//      @flags
//          影响映射区域的各种特性。在调用mmap()时必须要指定MAP_SHARED 或MAP_PRIVATE。
//          MAP_FIXED 如果参数start所指的地址无法成功建立映射时，则放弃映射，不对地址做修正。通常不鼓励用此。
//          MAP_SHARED对映射区域的写入数据会复制回文件内，而且允许其他映射该文件的进程共享。
//          MAP_PRIVATE 对映射区域的写入操作会产生一个映射文件的复制，即私人的“写入时复制”（copy on write）对此区域作的任何修改都不会写回原来的文件内容。
//          MAP_ANONYMOUS建立匿名映射。此时会忽略参数fd，不涉及文件，而且映射区域无法和其他进程共享。
//          MAP_DENYWRITE只允许对映射区域的写入操作，其他对文件直接写入的操作将会被拒绝。
//          MAP_LOCKED 将映射区域锁定住，这表示该区域不会被置换（swap）
//      @fd
//          要映射到内存中的文件描述符。如果使用匿名内存映射时，即flags中设置了MAP_ANONYMOUS，fd设为-1
//      @offset
//          文件映射的偏移量，通常设置为0，代表从文件最前方开始对应，offset必须是分页大小的整数倍
// (2) 返回值:
//          成功执行时，mmap()返回被映射区的指针
//          失败时，mmap()返回MAP_FAILED[其值为(void *)-1]

int main(int argc, char const *argv[])
{
    char *file = "map.txt";
    int fd = open(file, O_RDWR);
    if (fd < 0)
    {
        fprintf(stderr, "open failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: close(fd);

    char *buffer = (char *)mmap(NULL, 1 << 12, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED)
    {
        fprintf(stderr, "mmap failed: %s\n", strerror(errno));
        return errno;
    }
    // TODO: munmap(buffer, 1 << 12);

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        write(STDOUT_FILENO, &buffer[i], 1);
    }

    munmap(buffer, 1 << 12);
    close(fd);
    return EXIT_SUCCESS;
}