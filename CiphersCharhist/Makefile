#
# Makefile for cipher
# Supports Caesar cipher and Vigenere cipher
#

CC = gcc
CFLAGS	= -g -Wall

default: cipher

cipher: cipher.c vigenere.h caesar.h vigenere.o caesar.o
	$(CC) $(CFLAGS) cipher.c vigenere.o caesar.o -o cipher

caesar.o: caesar.h caesar.c
	$(CC) $(CFLAGS) caesar.c -c -o caesar.o

vigenere.o: vigenere.h vigenere.c
	$(CC) $(CFLAGS) vigenere.c -c -o vigenere.o

clean:
	$(RM) cipher
	$(RM) *.o	
