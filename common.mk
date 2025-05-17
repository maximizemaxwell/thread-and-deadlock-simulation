CC      := gcc
CFLAGS  := -Wall -Wextra -pedantic -std=c11 -g
LDFLAGS := 
PREFIX  := $(CURDIR)/bin
SDLFLAGS:= $(shell sdl2-config --cflags --libs)

$(shell mkdir -p $(PREFIX))
