![image-20210220202451850](06_simple_webserver.assets/image-20210220202451850.png)

# 06 简单的webserver

请求协议:    --浏览器组织发送

​			GET /xxx Http/1.1

![image-20210220141102816](06_simple_webserver.assets/image-20210220141102816.png)

应答协议:

Http1.1 200 OK

<img src="06_simple_webserver.assets/image-20210220141403305.png" alt="image-20210220141403305" style="zoom:67%;" />



1.getline() 获取http协议的第一行

2.从首行中拆分 GET, 文件名, 协议版本. 获取用户请求的文件名.

3.判断文件是否存在. stat()

4.判断是文件还是目录.

5.是文件--open -- read --写回给浏览器

6.先写http应答协议头: http/1.1 200 ok

​										Content-Type: text/plain: charset=iso8859-1

7.写文件数据.



scandir(待操作的目录, &子目录项列表数组, 过滤器(通常NULL), alphasort);

unicode 码 , --- >服务器发送的时候回传编码, 浏览器接受回传的编码, ---->解码.

![image-20210220202332803](06_simple_webserver.assets/image-20210220202332803.png)







![image-20210220094612138](06_simple_webserver.assets/image-20210220094612138.png)

![image-20210220094728473](06_simple_webserver.assets/image-20210220094728473.png)

![image-20210220094813878](06_simple_webserver.assets/image-20210220094813878.png)

![image-20210220094919798](06_simple_webserver.assets/image-20210220094919798.png)

![image-20210220095013362](06_simple_webserver.assets/image-20210220095013362.png)

![image-20210220095824768](06_simple_webserver.assets/image-20210220095824768.png)

![image-20210220095843668](06_simple_webserver.assets/image-20210220095843668.png)

<img src="06_simple_webserver.assets/image-20210220100552598.png" alt="image-20210220100552598" style="zoom:67%;" />

<img src="06_simple_webserver.assets/image-20210220101053432.png" alt="image-20210220101053432" style="zoom:67%;" />

<img src="06_simple_webserver.assets/image-20210220103605074.png" alt="image-20210220103605074" style="zoom:67%;" />



<img src="06_simple_webserver.assets/image-20210220123903488.png" alt="image-20210220123903488" style="zoom:67%;" />



<img src="06_simple_webserver.assets/image-20210220124319629.png" alt="image-20210220124319629" style="zoom:67%;" />

<img src="06_simple_webserver.assets/image-20210220124330821.png" alt="image-20210220124330821" style="zoom:67%;" />

![image-20210220124344053](06_simple_webserver.assets/image-20210220124344053.png)

<img src="06_simple_webserver.assets/image-20210220124811000.png" alt="image-20210220124811000" style="zoom:67%;" />

 ![image-20210220130020722](06_simple_webserver.assets/image-20210220130020722.png)

![image-20210220130053410](06_simple_webserver.assets/image-20210220130053410.png)

![image-20210220130123458](06_simple_webserver.assets/image-20210220130123458.png)

![image-20210220131124562](06_simple_webserver.assets/image-20210220131124562.png)



![image-20210220130628189](06_simple_webserver.assets/image-20210220130628189.png)

![image-20210220130955461](06_simple_webserver.assets/image-20210220130955461.png)

![image-20210220131014384](06_simple_webserver.assets/image-20210220131014384.png)

![image-20210220192153222](06_simple_webserver.assets/image-20210220192153222.png)

![image-20210220202454416](06_simple_webserver.assets/image-20210220202454416.png)

![image-20210220202510436](06_simple_webserver.assets/image-20210220202510436.png)

![image-20210220202530508](06_simple_webserver.assets/image-20210220202530508.png)

![image-20210220201026977](06_simple_webserver.assets/image-20210220201026977.png)