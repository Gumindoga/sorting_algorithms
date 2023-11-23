CFLAGS = -Wall -pedantic -Werror -Wextra -std=gnu89
FUTILS = print_array.c print_list.c
F0 = 0-bubble_sort.c
F1 = 1-insertion_sort_list.c
F2 = 2-selection_sort.c
F3 = 3-quick_sort.c

betty-all:
	betty sort.h $(F0) $(F1) $(F2) $(F3)

clean:
	rm bubble insertion select quick

bubble_sort:
	gcc $(CFLAGS) 0-main.c $(FUTILS) $(F0) -o bubble -g
	./bubble

insertion_sort:
	gcc $(CFLAGS) 1-main.c $(FUTILS) $(F1) -o insertion -g
	./insertion

select_sort:
	gcc $(CFLAGS) 2-main.c $(FUTILS) $(F2) -o select -g
	./select

quick_sort:
	gcc $(CFLAGS) 3-main.c $(FUTILS) $(F3) -o quick -g
	./quick