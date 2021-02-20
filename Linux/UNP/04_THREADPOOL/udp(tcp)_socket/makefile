src = $(wildcard *.c)
obj = $(patsubst %.c, %, $(src))

ALL:$(obj)

%:%.c
	gcc  $< -o $@ -pthread

clean: 
	-rm -rf $(obj)
