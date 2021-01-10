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







