TESTS = $(wildcard ./*.in)

all:
	@g++ main.cpp
	@for file in $(TESTS); do \
		echo $$file; \
		./a.out < $$file; \
	done
