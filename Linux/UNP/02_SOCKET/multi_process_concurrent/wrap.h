/***********************************************************
  > File Name: wrap.h
  > Author: Kwong
  > Mail: khheng0@gmail.com
  > Created Time: 2021年02月06日 星期六 16时24分55秒
  > Modified Time:2021年02月06日 星期六 16时24分55秒
 *******************************************************/
#ifndef __WRAP_H_
#define __WRAP_H_

void perr_exit(const char* s);
int Accept(int fd, struct sockaddr* sa, socklen_t* salenptr);
int Bind(int fd, const struct sockaddr* sa, socklen_t salen);
int Listen(int fd, int backlog);
ssize_t Read(int fd, void* ptr, size_t nbytes);
ssize_t Write(int fd, const void* ptr, size_t nbytes);
int Close(int fd);
ssize_t Readn(int fd, void* vptr, size_t n);
ssize_t Writen(int fd, const void* vptr, size_t n);
ssize_t my_read(int fd, char* ptr);
ssize_t Readline(int fd, void* vptr, size_t maxlen);


#endif
