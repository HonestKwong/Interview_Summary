src = $(wildcard ./src/*.c)  # ./src/add.c ./src/sub.c ...
obj = $(patsubst ./src/%.c, ./obj/%.o, $(src)) # ./obj/add.o ./obj/sub.o
inc = $(wildcard ./inc)
myArgs= -Wall -g

ALL:a.out

a.out:$(obj)
	gcc $^  -o $@ $(myArgs)  

$(obj):./obj/%.o:./src/%.c
	gcc -c $< -I $(inc) -o $@ $(myArgs)
clean:
	-rm -rf $(obj) a.out

.PHONY: clean ALL
