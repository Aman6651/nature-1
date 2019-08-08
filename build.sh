g++ graphics.cpp nature_object.cpp nature.cpp main.cpp \
    -std=c++11 \
    `sdl2-config --cflags --libs` -o main
