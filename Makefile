all: anagram.pdf angle-between-clock-hands.pdf time-slot-booking.pdf

anagram.pdf: prepare
	make -C challenges/anagram
	mv -f challenges/anagram/README.pdf .build/anagram.pdf

angle-between-clock-hands.pdf: prepare
	make -C challenges/angle-between-clock-hands
	mv -f challenges/angle-between-clock-hands/README.pdf .build/angle-between-clock-hands.pdf

time-slot-booking.pdf: prepare
	make -C challenges/time-slot-booking
	mv -f challenges/time-slot-booking/README.pdf .build/time-slot-booking.pdf

prepare:
	mkdir -p .build

.PHONY: all prepare
