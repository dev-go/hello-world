// Copyright (c) 2020, devgo.club
// All rights reserved.

#ifndef FILE_IO_H
#define FILE_IO_H

int copy(int fd_src, int fd_des);

int get_size(int fd);

int set_flag(int fd, int flag);

int add_flag(int fd, int flag);

int rm_flag(int fd, int flag);

int lock_file(int fd, int cmd, int type, int whence, int start, int len);

// 共享读锁(非阻塞)
#define READ_LOCK(fd, whence, start, len) lock_file(fd, F_SETLK, F_RDLCK, whence, start, len)

// 共享读锁(阻塞)
#define READ_LOCKW(fd, whence, start, len) lock_file(fd, F_SETLKW, F_RDLCK, whence, start, len)

// 独占写锁(非阻塞)
#define WRITE_LOCK(fd, whence, start, len) lock_file(fd, F_SETLK, F_WRLCK, whence, start, len)

// 独占写锁(阻塞)
#define WRITE_LOCKW(fd, whence, start, len) lock_file(fd, F_SETLKW, F_WRLCK, whence, start, len)

// 解锁
#define UN_LOCK(fd, whence, start, len) lock_file(fd, F_SETLKW, F_UNLCK, whence, start, len)

#endif