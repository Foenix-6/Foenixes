brog:main.o map.o entity.o
	gcc main.o map.o entity.o -o brog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o:main.c 
	gcc -c main.c -g

entity.o:entity.c
	gcc -c entity.c -g
map.o:map.c
	gcc -c map.c -g
