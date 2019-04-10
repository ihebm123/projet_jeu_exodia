

jeux:main.o menu.o
	gcc main.o menu.o -o jeux  -lSDL -lSDL_image -lSDL_mixer -g

main.o:main.c
	gcc main.c -c  -lSDL -lSDL_image -lSDL_mixer -g 


menu.o:menu.c
	gcc menu.c -c -lSDL -lSDL_image -lSDL_mixer -g
