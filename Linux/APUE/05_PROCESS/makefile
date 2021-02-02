src = $(wildcard *.c)
target = $(patsubst %.c, %, $(src))


ALL:$(target)


%:%.c
	gcc $^ -o $@

clean:
	rm -rf $(target)

.PHONT: clean ALL



















