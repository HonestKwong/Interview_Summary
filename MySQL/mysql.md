# MySQL基础指令学习

# 1.基本命令

创建数据源

```sql
create  database crashcourse;

use crashcourse;

show databases;

show tables;

describe XXX (show XXX from crashcourse)

select XXX from xxxcolumn
```

https://blog.csdn.net/hukangqiang/article/details/79319525



distinct 关键字:防止重复

limit 限制行数 以及选择从第几行开始

LIMIT3,4 含义是从行4开始的3行还是从行3开始的4行； Mysql 5 产生了 limit 5 offset 3 从行3 取 5 行.



完全限定的表名, 有一点像C++类;











