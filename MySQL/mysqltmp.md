

23章 使用存储过程

需要mysql5以后的版本

执行存储过程

```sql
call productpricing(@pricelow, @pricehigh, @priceaverage);


```



创建存储过程

以下语法在客户机会出错，因为默认的sql语句分隔符为; mysql命令行实用程序也使用;作为分隔符。如果命令行实用程序要解释存储过程自身内的;字符，则他们最终不会成为存储过程的成分，这会使存储过程中的sql语句出现语法错误。

```sql
create procedure productpricing()
begin
	select avg(prod_price) as priceaverage
	from products;
end;
```



解决方法：

```sql
delimiter //
create procedure productpricing()
begin
	select avg(prod_price) as priceaverage
	from products;
end //

delimiter ;
```

其中，delimter是告诉命令行实用程序使用//作为新的语句分隔符。





调用上述存储过程

```sql
call productpricing();

```

删除上述存储过程, 仅当存在时删除，如果不存在会报错，想要不报错需要执行 drop procedure if exists

```sql
drop procedure productpricing;
```



向存储过程传递参数：

mysql 支持IN，OUT和INOUT类型的参数。存储过程的代码位于begin和end语句内，如前所见，它们是一系列select语句，用来检索值，然后保存到相应的变量，通过指定into关键字。

```sql
create procedure productpricing(
	out pl decimal(8,2),
	out pa decimal(8,2),
	out ph decimal(8,2)
)
begin
	select min(prod_price)
	into pl
	from products;
	select max(prod_price)
	into ph
	from products;
	from avg(prod_price)
	into pa
	from products;
end;
```

mysql 变量都必须以@开始



```sql
delimiter //
create procedure productpricing(
	out pl decimal(8,2),
	out pa decimal(8,2),
	out ph decimal(8,2)
)
begin
	select min(prod_price)
	into pl
	from products;
	select avg(prod_price)
	into pa
	from products;
	select max(prod_price)
	into ph
	from products;

end //

delimiter ;
```

使用变量：

```sql
select @pricelow


```



存储过程， 通过--加注释。

完整的存储过程参考172页的例子



第24章 使用游标

游标只能用于存储过程

创建游标：

create procedure processorders()

begin

​	declare ordernumbers cursor

​	for

​	select order_num from orders;

end;

declare语句用来定义和命名游标，这里为ordernums。

定义游标后可以打开它。

2.打开和关闭游标：

open ordernums;

close ordernumbers;

close 释放游标使用的所有内存和资源，因此在每个游标不再需要时都应该关闭。



3.使用游标

```sql
create procedure processorders()
begin
	-- declare local variables
	declare o int 
	
	-- 定义游标
	declare ordernumbers CURSOR
	for 
	select order_num from orders;
	
	--open the cursor
	open ordernumbers;
	
	-- get order number
	fetch ordernumbers into o;
	
	--close the cursor
	close ordernumbers;
end;
	
```



其中fetch用来检索当前行的order_num列(将自动从第一行开始)到一个名为o的局部声明的变量中。

sqlstate '02000'是一个未找到的条件， 当repeat由于没有更多的行供循环而不能继续时出现这个条件。



**declare语句的次序： 局部变量必须定义在游标和句柄之前， 而句柄必须定义在游标之后。 不遵循此关系将产生错误信息。**



循环语句：

```sql


declare continue handler for sqlstate '02000' set done = 1;

repeat



until done end repeat;
```





第25章 使用触发器

1.触发器

触发器是mysql响应以下任意语句而自动执行的一条mysql语句 位于begin 和 end 之间的

delete;

insert;

update;

其他的mysql语句不支持触发器

创建触发器需要给出四个信息：

唯一的触发器名

触发器关联的表

触发器应该响应的活动

触发器何时执行



例如：

```sql
--crashcourse 会报错

create trigger newproduct after insert on products for each row select 'Product added'

--解决方法：加上 into @ee，因为从MySQL5以后不支持触发器返回结果集

create trigger newproduct after insert on products for each row select 'Product added' into @ee
```

只有表支持触发器，试图不支持

触发器失败 P183

根据错误提示，不允许返回结果。查找相关资料，显示MYSQL5以后，不允许触发器返回任何结果。

因此使用into @变量名，将结果赋值到变量中，用select调用。

删除触发器：

```sql
drop trigger newproduct;
```





第26章 管理事物处理

1.事物 transaction  指一组sql语句

2.回退 rollback 指撤销指定 的sql语句的过程

3.提交 commit 指将为存储的sql语句结果写入数据库表;

4.保留点 savepoint 指事物处理中设置的占位符 placeholder， 可以对他发布回退





第27章 全球化和本地化

1.字符集和校对顺序

2.使用字符集和校对顺序

mysql支持众多字符集。为查看所支持的字符集完整列表，使用一下语句

```sql
show character set;
```



查看所有支持校对的完整列表：

```sql
show collation;
```



确定所用的字符集和校对：

```sql
mysql> show variables like 'character%' ;
+--------------------------+----------------------------+
| Variable_name            | Value                      |
+--------------------------+----------------------------+
| character_set_client     | utf8mb4                    |
| character_set_connection | utf8mb4                    |
| character_set_database   | utf8mb4                    |
| character_set_filesystem | binary                     |
| character_set_results    | utf8mb4                    |
| character_set_server     | utf8mb4                    |
| character_set_system     | utf8                       |
| character_sets_dir       | /usr/share/mysql/charsets/ |
+--------------------------+----------------------------+
8 rows in set (0.01 sec)

mysql> show variables like 'collation%' ;
+----------------------+--------------------+
| Variable_name        | Value              |
+----------------------+--------------------+
| collation_connection | utf8mb4_0900_ai_ci |
| collation_database   | utf8mb4_0900_ai_ci |
| collation_server     | utf8mb4_0900_ai_ci |
+----------------------+--------------------+

```



给表指定字符集和校对

```sql
create table mytable(columnn1 INT, columnn2 varchar(10)) default character set hebrew collate hebrew_general_ci;

```

mysql 还能指定对每个列设置字符集和校对



28 安全管理

1,访问控制

root 用户账户对整个mysql服务具有完全的控制

不要使用root 应该严肃对待root登录的使用。

use mysql;

select user from user;



create user kwong identified by '123456';

identified by 指定的口令为纯文本， mysql将在保存到user表前对口令加密

重命名user 

rename user kwong to kwong77

删除用户

drop user kwong77;



2.设置访问控制权限



```sql
show grants for kwong;
+-----------------------------------+
| Grants for kwong@%                |
+-----------------------------------+
| GRANT USAGE ON *.* TO `kwong`@`%` |
+-----------------------------------+

```

表示根本没要权限



grant select on crashcourse.* to kwong;



revoke select on crashcourse.* to kwong;

grant 和 revoke 可以控制几个层次的访问权限

整个服务器， 使用grant all 和 revoke all;

整个数据库， 使用on database.*

t特定的表， 使用 on database.table

特定的列

特定的存储过程。



更改用户口令



首先说明我这里的情况是，开启了mysql服务之后，我以root用户登录mysql数据库的时候始终不需要密码，想要为msql的root用户设置一个登录密码，试过好几种类办法，都没有成功，最后发现是系统版本的问题。新版本的密码字段换成了authentication_string

set password for kwong  = password('654321');

给当前用户

set password = Password('123456');

update mysql.user set authentication_string=password('654321') where user='kwong' ;

ALTER USER 'kwong'@'localhost' IDENTIFIED BY '123456';

ALTER USER 'kwong' IDENTIFIED BY '123456';

alter 改变



29. 备份数据
30. 首先刷新未写数据

```sql
analyze table orders;

check table orders, ordertimes;
+------------------------+-------+----------+----------------------------------------------+
| Table                  | Op    | Msg_type | Msg_text                                     |
+------------------------+-------+----------+----------------------------------------------+
| crashcourse.orders     | check | status   | OK                                           |
| crashcourse.ordertimes | check | Error    | Table 'crashcourse.ordertimes' doesn't exist |
| crashcourse.ordertimes | check | status   | Operation failed                             |
+------------------------+-------+----------+----------------------------------------------+
```





redis 和mysql

https://blog.csdn.net/D_R_L_T/article/details/81676999