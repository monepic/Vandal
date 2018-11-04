.PHONY: clean

vandal: main.c
	gcc `pkg-config --cflags --libs gtk+-3.0` \
		  `pkg-config --cflags --libs webkit2gtk-4.0` \
		  -o $@ $^
install: vandal
	mv vandal /usr/local/bin
clean:
	rm -f vandal
