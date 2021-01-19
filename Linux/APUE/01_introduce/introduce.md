# 01 linux 简介

## 1.简介

什么是终端，一切输入输出设备的总称。

linux中teminal 是一个虚拟终端

shell 家族 

```shell
cat /etc/shells
```

查看当前系统支持的shell

```shell
echo $SHELL
```

当前使用的shell

常见shell

```
/bin/sh
/bin/bash
/usr/bin/bash
/bin/rbash
/usr/bin/rbash
/bin/dash
/usr/bin/dash
```



命令和路径补齐， 直接使用tab补齐

补齐出来的一定不会错



主键盘快捷建

![image-20210119234202984](/home/kwong/.config/Typora/typora-user-images/image-20210119234202984.png)

ctrl + u 直接清除命令行



目录和文件

类unix的目录结构

![image-20210119234513072](/home/kwong/.config/Typora/typora-user-images/image-20210119234513072.png)

linux 系统中 “所见皆文件”。

设备相关的都放在dev文件目录下

/etc/ passwd

/lib 所使用的库都在之中

usr 目录 安装的第三方库就在user下面

bin: 存放二进制可执行文件

boot：存放开机启动程序

dev：存放设备文件

home：存放用户

etc：用户信息和系统配置文件

lib:库文件

root:管理员宿主目录(家目录)

user:用户资源管理目录





相对路径和绝对路径

cd -  两个路径的切换， 上一个跳转来的路径

cd .

cd /

cd 



ls -l 详细信息

ls -a 隐藏文件

ls -l 目录 会查看目录中的文件

ls -dl 会查看目录中本身

ls -R 查看目录中及子目录的文件



Linux系统文件类型：

普通文件：-

目录文件：d

字符设备文件：c

块设备 文件：b

软链接：l （硬链接是普通文件)

管道文件： p

套接字：s

未知文件

pwd 查看当前目录所在位置





