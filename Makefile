CC = g++
CCFLAGS = -std=c++11
INC = ./third_party
BIN = ./bin
CCFLAGS += -I$(INC)

ifeq ($(PREFIX),)
    PREFIX := /usr
endif

default: main

main:
	mkdir -p $(BIN)
	$(CC) src/jf.cc $(CCFLAGS) -o $(BIN)/jf
	chmod +x $(BIN)/jf

install: main
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 664 $(BIN)/jf $(DESTDIR)$(PREFIX)/bin/

clean:
	if [ -d "${BIN}" ]; then \
		rm -r ${BIN}; \
	fi \
