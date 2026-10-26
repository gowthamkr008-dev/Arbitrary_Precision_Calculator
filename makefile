#  get all c source files
src := $(wildcard *.c) 

obj := $(patsubst %.c,%.o,$(src))

a.exe: $(obj)
	gcc -o $@ $^

%.o: %.c
	gcc -c $< -o $@

clean:
	rm -f $(obj) a.out

.PHONY:clean
