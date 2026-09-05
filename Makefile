CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2

exp01:
	$(CC) $(CFLAGS) src/01-finite-difference-first-kind/main.c -o exp01

exp02:
	$(CC) $(CFLAGS) src/02-finite-difference-second-kind/main.c -o exp02

exp03:
	$(CC) $(CFLAGS) src/03-finite-difference-third-kind/main.c -o exp03

exp04:
	$(CC) $(CFLAGS) src/04-numerov-method/main.c -o exp04

exp05:
	$(CC) $(CFLAGS) src/05-euler-method/main.c -o exp05

exp06:
	$(CC) $(CFLAGS) src/06-euler-cauchy-method/main.c -o exp06

exp07:
	$(CC) $(CFLAGS) src/07-runge-kutta-fourth-order/main.c -o exp07

exp08:
	$(CC) $(CFLAGS) src/08-runge-kutta-nystrom/main.c -o exp08

exp09:
	$(CC) $(CFLAGS) src/09-shooting-euler/main.c -o exp09

exp10:
	$(CC) $(CFLAGS) src/10-shooting-euler-cauchy/main.c -o exp10

exp11:
	$(CC) $(CFLAGS) src/11-shooting-runge-kutta/main.c -o exp11

all: exp01 exp02 exp03 exp04 exp05 exp06 exp07 exp08 exp09 exp10 exp11

clean:
	rm -f exp01 exp02 exp03 exp04 exp05 exp06 exp07 exp08 exp09 exp10 exp11

.PHONY: all clean exp01 exp02 exp03 exp04 exp05 exp06 exp07 exp08 exp09 exp10 exp11
