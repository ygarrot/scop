gcc test.c -I./glfw/include -framework OpenGL -framework CoreVideo -framework IOKit -framework Cocoa -framework Carbon -I/Users/ygarrot/.brew/Cellar/glfw/3.3/include ~/.brew/lib/libglfw3.a
gcc test.c  -lGL -lm -lXinerama -lXrandr -lXi -lXcursor -lXxf86vm `pkg-config --static --libs glfw3`
