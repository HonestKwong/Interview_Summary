# MySQL基础指令学习

# 1.基本命令

sudo mysql -u root -p 进入mysql? 使用的root用户?

mysql命令行参数说明:

https://www.jianshu.com/p/c604f04b9db5

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



Order by  排序

desc

选择多个列



where :

Is NULL

S





SQL 像绝大数语言一样优先处理AND 再处理OR 可以使用圆括号解决这种优先级问题



第8章 用通配符进行过滤

1.like 操作符



2.%通配符



3.下划线_







第 9章 正则表达式

和like的区别

REGEXP 不区分大小写

BINARY 可以使其区分大小写

例如 select prod_name from products where prod_name REGEXP BINARY 'JetPack .000'

进行or 匹配使用 '|'

```
SELECT prod_name from products where prod_name  REGEXP '1000|2000' order by prod_name;
```

[123]  '[]' 定义了一组字符.它的意思是匹配1或2或3 意思相当与[1|2|3] 没有[] 会有问题

[^123] 匹配除了 123 以外的数字

通过括号匹配范围[1-3], [a-z]



匹配特殊字符通过使用 '\\\\'+符号 这种方式就是所谓的转义

```
select * from vendors where vend_name REGEXP '\\.';
```



^ 文本的开始

$ 文本的结束 使用开始和结束可以让regexp的效果和like一样

[[:<:]] 词的开始 [[:>:]] 词的结束



第十章 创建计算字段

1.拼接字段 

```sql
select concat(vend_name,'(',vend_country, ')') from vendors order by vend_name;
```



2.删除右侧空格RTrim 以及使用别名 as 

```sql
select concat(rtrim(vend_name),'(',rtrim(vend_country), ')') as vend_title from vendors order by vend_name;
```



3.执行算术运算

```sql
select prod_id, quantity, item_price, quantity*item_price as expanded_price from orderitems where order_num = 20005
```



4.select通常用来从表中检索数据,但可以省略From子句以便简单地访问和处理表达式.

```sql
select 3*6;
select Trim('abc');

select now();
```



第十一章 使用数据处理函数

1.upper() 将文本转换为大写

```sql
select vend_name , upper(vend_name) as vend_name_upcase from vendors order by vend_name;

```



2.soundex 是一个将任何文本串转换为描述其语表示的字母数字模式的算法. 

```sql
select cust_name, cust_contact from customers where cust_contact = 'Y.Lie';
empty set
select cust_name, cust_contact from customers where soundex(cust_contact) = soundex('Y.Lie');
+-------------+--------------+
| cust_name   | cust_contact |
+-------------+--------------+
| Coyote Inc. | Y Lee        |
+-------------+--------------+




```



3.日期和时间处理函数

```sql
select cust_id, order_num from orders where order_date = '2005-09-01';
#截选处日期部分,更加可靠
select cust_id, order_num from orders where date(order_date) = '2005-09-01';
#范围
select cust_id, order_num from orders where date(order_date) between '2005-09-01' and  '2005-09-30';
select cust_id, order_num from orders where year(order_date)='2005' and month(order_date)= '09';
```



我

第十二章 汇总数据

1.聚集函数;

avg() 平均

```sql
select avg(prod_price) as avg_price from products;

```

count() 返回某列的行数

```sql
select count(cust_email) as num_cust from customers;

```

count(*) 对所有行计数, count(column) 对特定列不为null的行计数

max() 返回某列的最大值

```sql
select max(prod_price) as max_price from products;
```

min() 返回某列的最小值

min和max也可以返回文本数据中的最大最小,实际上是通过排列以后最前的是min 最后的是max

sum() 返回某列值之和

```sql
select sum(quantity) as items_ordered from orderitems where order_num = 20005;
#也可以组合计算值
select sum(quantity*item_price) as total_price from orderitems where order_num = 20005;

```



**所有聚集函数都可用来执行多个列上的计算**



2.聚集不同的值

```sql
select avg(distinct prod_price) as avg_price from products where vend_id = 1003
```



3.组合聚集函数

```sql
select count(*) as num_items, min(prod_price) as price_min, max(prod_price) as price_max, avg(prod_price) as price_avg from products;
```



第13章.数据分组

1.数据分组

```sql
mysql> select vend_id , count(*) as num_prods from products group by vend_id;
+---------+-----------+
| vend_id | num_prods |
+---------+-----------+
|    1001 |         3 |
|    1002 |         2 |
|    1003 |         7 |
|    1005 |         2 |
+---------+-----------+


```



2.过滤分组

Where 过滤行 Having 过滤分组

```sql
select cust_id , count(*) as orders from orders group by cust_id having count(*) >=2;
```



```sql
select vend_id , count(*) as num_prods from products where prod_price >=10 group by vend_id having count(*) >=2
```



3.分组与排序

不要忘记order by 一般在使用group by子句时, 应该也给出orderby子句. 这是保证数据正确排序的唯一方法.千万不要仅依赖groupby的排序.



第14章 使用子查询

1.子查询

查询(query)任何sql语句都是查询. 但此术语一般指select

允许子查询 subquery



在select语句中,子查询总是从内向外处理. 在处理上面select语句时,mysql实际上执行了两个操作.

```sql
select cust_id from orders where order_num in (select order_num from orderitems where prod_id = 'TNT2');
```





2.作为计算字段使用子查询

相关子查询 设计外部查询的子查询. 任何时候只要列名可能有多义性的时候,就必须使用这种语法(表名和列名由一个句点分隔)

```sql
select cust_name, cust_state, (select count(*) from orders where orders.cust_id = customers.cust_id) as orders from customers order by cust_name;
+----------------+------------+--------+
| cust_name      | cust_state | orders |
+----------------+------------+--------+
| Coyote Inc.    | MI         |      2 |
| E Fudd         | IL         |      1 |
| Mouse House    | OH         |      0 |
| Wascals        | IN         |      1 |
| Yosemite Place | AZ         |      1 |
+----------------+------------+--------+
5 rows in set (0.00 sec)

mysql> select * from orders;
+-----------+---------------------+---------+
| order_num | order_date          | cust_id |
+-----------+---------------------+---------+
|     20005 | 2005-09-01 00:00:00 |   10001 |
|     20006 | 2005-09-12 00:00:00 |   10003 |
|     20007 | 2005-09-30 00:00:00 |   10004 |
|     20008 | 2005-10-03 00:00:00 |   10005 |
|     20009 | 2005-10-08 00:00:00 |   10001 |
+-----------+---------------------+---------+
5 rows in set (0.00 sec)

mysql> select * from customers;
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+
| cust_id | cust_name      | cust_address        | cust_city | cust_state | cust_zip | cust_country | cust_contact | cust_email          |
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+
|   10001 | Coyote Inc.    | 200 Maple Lane      | Detroit   | MI         | 44444    | USA          | Y Lee        | ylee@coyote.com     |
|   10002 | Mouse House    | 333 Fromage Lane    | Columbus  | OH         | 43333    | USA          | Jerry Mouse  | NULL                |
|   10003 | Wascals        | 1 Sunny Place       | Muncie    | IN         | 42222    | USA          | Jim Jones    | rabbit@wascally.com |
|   10004 | Yosemite Place | 829 Riverside Drive | Phoenix   | AZ         | 88888    | USA          | Y Sam        | sam@yosemite.com    |
|   10005 | E Fudd         | 4545 53rd Street    | Chicago   | IL         | 54545    | USA          | E Fudd       | NULL                |
+---------+----------------+---------------------+-----------+------------+----------+--------------+--------------+---------------------+
5 rows in set (0.00 sec)

```



子查询最常见的使用是在where 子句的IN操作符中.



第15章 联结表

联结

1.关系表

外键

外键为某个表中的一个列,它包含另一个表的主键值

分解数据为多个表能更有效地存储



2.创建联结

```sql
select vend_name, prod_name, prod_price from vendors, products where vendors.vend_id = products.vend_id order by vend_name, prod_name;
```

3.内部联结

所有联结都为等值联结

基于两个表, 可以使用不同表

```sql
 select vend_name , prod_name, prod_price from vendors inner join products on vendors.vend_id = products.vend_id;
```



第16章 创建高级联结

1,使用表别名

除了用于列名和计算字段外, SQL还允许给表名. 这样可以 缩短sql语句；允许在单条select语句中多次使用相同的表.

2.使用不同类型的联结

3.自联结

```sql
select p1.prod_id, p1.prod_name from products as p1, products as p2 where p1.vend_id = p2.vend_id and p2.prod_id = 'DTNTR';
```



4.自然联结



使用联结和联结条件 Mysql crash course P112



第17章. 组合查询

多数SQL查询都只包含从一个或多个表中返回数据的单条色了传统语句Mysql也允许执行多个查询，并将结果作为单个查询结果并返回。



1.创建组合查询， 使用union操作符来组合sql

```sql


select vend_id , prod_id, prod_price from products where prod_price <=5 union select vend_id, prod_id, prod_price from products where vend_id in (1001,1002);
上下等同
select vend_id , prod_id, prod_price from products where prod_price<=5 or vend_id in (1001,1002)
```



union 从查询结果中自动去除了重复的行。UNION的默认行为是合并重复行，可以通过UNION ALL 而不合并重复行。

在组合查询union中，只使用一条order by 子句， 它必须出现在最后一条select语句之后。例如：

```sql


select vend_id , prod_id, prod_price from products where prod_price <=5 union select vend_id, prod_id, prod_price from products where vend_id in (1001,1002) order by vend_id, prod_price;
```

order by 将排序所有子句。



第18章 全文本搜索

1.启用全文本搜索支持

不要在导入数据时使用FULLTEXT ， 应该首先导入所有数据，然后在修改表，定义fulltext。 这样有助于更快的导入数据且使索数据的总时间小于导入每行时分别进行索引所需的总时间。

```sql
CREATE TABLE productnotes
(
  note_id    int           NOT NULL AUTO_INCREMENT,
  prod_id    char(10)      NOT NULL,
  note_date datetime       NOT NULL,
  note_text  text          NULL ,
  PRIMARY KEY(note_id),
  FULLTEXT(note_text) #fulltext
) ENGINE=MyISAM;

```

```sql
select note_text from productnotes where match(note_text) against('rabbit');

```

Match(note_text) 指示Mysql针对指定的列进行搜索， against('rabbit') 指定次rabbit作为搜索文本。由于有两行包含此rabbit，这两个行被返回。



Match() 和 against()用来建立一个计算列，此列包含全文本搜索计算出的等级值。这是like语句不具有的功能，而且由于数据是索引，全文本还相当快。

2.使用查询搜索

​	查询搜索试图放宽所返回的全文本搜索结果的范围。

```sql
select note_text from productnotes where match(note_text) against('anvils');
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| Multiple customer returns, anvils failing to drop fast enough or falling backwards on purchaser. Recommend that customer considers using heavier anvils. |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+

select note_text from productnotes where match(note_text) against('anvils' with query expansion);
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| note_text                                                                                                                                                |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+
| Multiple customer returns, anvils failing to drop fast enough or falling backwards on purchaser. Recommend that customer considers using heavier anvils. |
| Customer complaint:
Sticks not individually wrapped, too easy to mistakenly detonate all at once.
Recommend individual wrapping.                         |
| Customer complaint:
Not heavy enough to generate flying stars around head of victim. If being purchased for dropping, recommend ANV02 or ANV03 instead.  |
| Please note that no returns will be accepted if safe opened using explosives.                                                                            |
| Customer complaint: rabbit has been able to detect trap, food apparently less effective now.                                                             |
| Customer complaint:
Circular hole in safe floor can apparently be easily cut with handsaw.                                                               |
| Matches not included, recommend purchase of matches or detonator (item DTNTR).                                                                           |
+----------------------------------------------------------------------------------------------------------------------------------------------------------+

```

这样做增加了搜索的结果，也增加了很多无用的信息。



3.布尔文本搜索(可以不用fulltext索引)

要匹配的词，要排斥的词

排列提示

表达式分组

另外一些内容

 仅在Myisam数据库引擎中支持全文本搜索。



第19章 插入数据 

1.插入完整的行

```sql
insert into customers values(NULL, 'Pep E. LaPew', '100 Main Street', 'Los Angeles', 'CA', '90046', 'USA', NULL, NULL);

```

对每一列必须提供一个值。

虽然这种语法简单，但并不安全， 应尽量避免使用。上面的sql高度依赖于表中列的定义次序，并且还依赖于其次序。



有一种更繁琐的方法、也更安全的方法：

```sql
 insert into customers(cust_name, cust_address, cust_city, cust_state, cust_zip, cust_country, cust_contact, cust_email) values('Pep E. LaPew', '100 Main Street', 'Los Angeles', 'CA', '90046', 'USA', NULL, NULL);

```

不一定按照实际表中的次序。即使表的结构改，insert依然可用。

不管使用那种insert语法，都必须给出values的正确数目。



省略列， 如果表定义允许，则可省略， 允许NULL值， 默认值。



2.一次插入多个行：

P135



3.插入检索出的数据：

P138



第20章 更新和删除数据

1.更新数据

为了更新表中的数据,可使用update语句. 可采用两种方式使用update:



更新表中特定行;

更新表中所有行.



update customers set cust_email = 'elmer@fudd.com' where cust_id = 10005;

where 筛选



更新多个列使,只需要使用一个set.

为了**删除某个列**的值可以使用 update 将某个值设置为 NULL,(假定表定义允许NULL值)



如果update更新多个行,并且在更新这些行中的一行或多行时出现一个错误时,整个update操作被取消.即使是发生错误也要继续的话需要使用ignore关键字, 如下所示:

update ignore customers...



2.删除数据

使用delete语句;

从表中删除特定行. 

从表中删除所有行

delete from customers where cust_id = 10006;

delete 语句不需要通配符..delete删除的整行而不是一个列.为了删除指定的列需要使用update语句.

delete不善处表本身.



mysql没有撤回按钮, 使用强制实时引用完整性数据库,这样mysql不允许删除具有与其他表相关联的数据的行.



第21章 创建和操作表



1.创建表

书中创建customer表的语句;

```sql
CREATE TABLE customers
(
  cust_id      int       NOT NULL AUTO_INCREMENT,
  cust_name    char(50)  NOT NULL ,
  cust_address char(50)  NULL ,
  cust_city    char(50)  NULL ,
  cust_state   char(5)   NULL ,
  cust_zip     char(10)  NULL ,
  cust_country char(50)  NULL ,
  cust_contact char(50)  NULL ,
  cust_email   char(255) NULL ,
  PRIMARY KEY (cust_id)
) ENGINE=InnoDB;
```



primary key关键字指定主键.

创建表时,指定的表明必须不存在.

如果不存在则创建, 加上 if not exists.



2.使用NULL值

注意区分NULL和空串的区别' '



3.主键

主键值必须唯一.



4.使用auto_increment

在使用auto_increment时如何获得这个值呢?可使用last_insert_id()函数获得这个值,如下所示

select last_insert_id()

此语句返回最后一个auto_increment值,然后可以将它用于后续的mysql语句.





5.使用默认值

使用默认而不是null

例如 quantity int not null  default 1,



6.引擎类型

mysql和其他dbms不一样

为什么要发行多种引擎呢? 因为他们具有各自不同的功能和特性,为不同的任务选择正确的引擎能获得良好的功能和灵活性.

如果省略enginr = 语句,则使用默认引擎 很可能是myism.



需要知道的引擎 InnoDB (可靠的事物处理引擎)

memory(数据存储在内存,而不是磁盘,速度很快)

myisam(性能极高的引擎,支持全文本搜索)



引擎类型可以混用

混用引擎的缺陷: 外键不能跨引擎, 即使一个引擎的表不能引用具有使用不同引擎的外键.



7更新表

为更新表,可以使用alter table语句. 但是理想状态中, 当表存储了数据后,表就不应该被更新了.

```
添加列

alter table vendors add vend_phone char(20);

删除表项

alter tavle vendors drop column vend_phone;
```

8.删除表

drop table customers2;

9.重命名表

rename table customer2 to customers



第 22 章 使用视图

更新视图

视图是可以更新的.更新一个视图将更新其基表



```sql
create view vendorlocations as vend_title select concat(rtrim(vend_name), '(', RTrim(vend_country), ')') from vendors order by vend_name;
```



```sql
select * from vendorlocations;
+------------------------+
| vend_name              |
+------------------------+
| ACME(USA)              |
| Anvils R Us(USA)       |
| Furball Inc.(USA)      |
| Jet Set(England)       |
| Jouets Et Ours(France) |
| LT Supplies(USA)       |
+------------------------+
```





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



















































































