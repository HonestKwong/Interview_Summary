# 04_FIFO

# 系统编程阶段说在前面的话

系统调用  内核提供的函数
库调用 程序库中的函数


open 函数

manpage 第二卷,open 函数如下,有两个版本的

![image-20210123201530231](04_FILEIO.assets/image-20210123201530231.png)

返回一个文件描述符,理解为整数,出错返回-1

pathname 文件路径

flags 权限控制,只读,只写,读写。  O_RDONLY, O_WRONLY, O_RDWR

第二个 open

多了一个 mode 参数,用来指定文件的权限,数字设定法

文件权限 = mode & ~umask

open 常见错误:

1.打开文件不存在

2.以写方式打开只读文件(权限问题)

3.以只写方式打开目录

4.当 open 出错时,程序会自动设置 errno,可以通过 strerror(errno)来查看报错数字的含义
以打开不存在文件为例:

![image-20210123201734193](04_FILEIO.assets/image-20210123201734193.png)

执行该代码,结果如下:

![image-20210123201752416](04_FILEIO.assets/image-20210123201752416.png)

open 函数:

int open(char *pathname, int flags)  #include <unistd.h>

参数:

​	pathname: 欲打开的文件路径名

​	flags:文件打开方式:  #include <fcntl.h>

O_RDONLY|O_WRONLY|O_RDWR O_CREAT|O_APPEND|O_TRUNC|O_EXCL|O_NONBLOCK



返回值:

​	成功: 打开文件所得到对应的 文件描述符(整数)

​	失败: -1, 设置 errno



int open(char *pathname, int flags, mode_t mode) 123 775

参数:
pathname: 欲打开的文件路径名

flags:文件打开方式:O_RDONLY|O_WRONLY|O_RDWR
O_CREAT|O_APPEND|O_TRUNC|O_EXCL|O_NONBLOCK ....

mode: 参数 3 使用的前提, 参 2 指定了 O_CREAT。 取值 8 进制数,用来描述文件的 访问权限。 rwx 0664
创建文件最终权限 = mode & ~umask
返回值:
成功: 打开文件所得到对应的 文件描述符(整数)
失败: -1, 设置 errno

close 函数:

int close(int fd);



















