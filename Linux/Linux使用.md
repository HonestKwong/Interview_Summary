# Linux的基本使用

[TOC]





## 1.常用快捷键

### 1.1 常见终端快捷键

- Ctrl + Alt + T：打开终端
- Tab：命令或文件名自动补全
- Ctrl + Shift + C：复制
- Ctrl + Shift + V：粘贴
- Ctrl + Shift + T：在同一个窗口新建终端标签页
- Ctrl + Shift + W：关闭标签页
- Ctrl + Shift + N：新建终端窗口
- Ctrl + Shift + Q：关闭终端窗口
- Ctrl + Shift + PageUp：标签页左移
- Ctrl + Shift + PageDown：标签页右移
- Ctrl + D：关闭标签页
- Ctrl + L：清除屏幕
- Ctrl + C：终止当前任务
- Ctrl + P：显示上一条历史命令
- Ctrl + N：显示下一条历史命令
- Ctrl + R：反向搜索历史命令
- Ctrl + J/M：回车（同enter键功能）
- Ctrl + A：光标移动到行首
- Ctrl + E：光标移动到行尾
- Ctrl + B：关闭想后移动一个位置（backward）
- Ctrl + Z：把当前任务放到后台运行



### 1.2 桌面常用快捷键

- Alt + F1：聚焦到桌面左侧任务导航栏，可按上下键进行导航
- Alt + F2：运行命令
- Alt + F4：关闭当前窗口
- Alt + Tab：切换程序窗口
- Alt + 空格：打开窗口菜单
- PrtSc：桌面截图
- Win + A：搜索/浏览程序
- Win + F：搜索/浏览文件
- Win + M：搜索/浏览音乐文件
- Win：搜索/浏览程序、文件、音乐文件等
- Pirnt Screen 为截屏键 
- ＃保存到文件夹，主目录（home）下的图片文件夹中 
- Print Screen  #截取整个桌面
-  Alt + Print Screen #截取选中的窗口 
- Shift + Print Screen #自由选区 
- ＃剪贴板 
- Ctrl + Print Screen  #整个桌面 
- Ctrl + Alt + Print Screen #选中的窗口
-  Shift + Ctrl + Print Screen #自由选区



## 2.常用Shell命令

### 2.1 man手册

linux编程肯定用的到,非常好用.

第2章是系统调用

第3章是库函数

第7章是查看linux的一些机制



### 2.2 ps



### 2.3 chmod



### 2.4 dpkg

​		deb文件是linux发行版debian系统的安装包格式，还有像基于debian系统的发型版ubuntu等系统就是使用的deb格式安装包，我们可以使用dpkg命令进行安装管理这些deb安装包文件。

​		**sudo dpkg -i deb文件名**

### 2.5 apt-get

​		**apt-get**命令是Debian Linux发行版中的APT软件包管理工具。所有基于Debian的发行都使用这个包管理系统。deb包可以把一个应用的文件包在一起，大体就如同Windows上的安装文件。

```shell
apt-get install packagename
apt-get remove packagename
```

### 2.6 stat



### 2.7 git



### 2.8 netstat

sudo netstat -tap | grep mysql

### 2.9 ln



### 2.10 gcc/gdb



### 2.11 snap

Snappy是一个软件部署和软件包管理系统，最早由Canonical公司为了Ubuntu移动电话操作系统而设计和构建。

https://m.linuxidc.com/Linux/2018-05/152385.htm







## 3.常用软件

- **PDF**

  okular和Ubuntu自带的都勉强能用

- **Typora**

  可以方便在Ubuntu下记录笔记

- **坚果云&Zotero**

  可以与我的Windows共享论文,都提供了官方的Linux发行版

  Zotero 安装https://www.zotero.org/support/installation

- **BaiduDisk**

  良心发现的Linux发行版

- **wireshark**

  抓包工具

- **火焰截图**

  暂时还没找到可以直接复制到剪切板的比较好用的软件

- **Chrome**

  不用多说

- **QV2ray**

  无需多言

- **ifcitx**

  ibus真不行

- mysql 数据库软件 安装:

  (1)sudo apt update

  (2)sudo apt install mysql-server

  (3)sudo mysql_secure_installation //在安装完 MySQL 之后，应该运行一下包含的安全脚本：

  具体步骤:

  https://blog.csdn.net/liang19890820/article/details/105071479

  https://cloud.tencent.com/developer/article/1592103

- 

- 

  

