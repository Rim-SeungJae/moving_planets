<img src="https://img.shields.io/badge/C-A8B9CC?style=flat&logo=C&logoColor=white"/> <img src="https://img.shields.io/badge/C++-00599C?style=flat&logo=C++&logoColor=white"/> <img src="https://img.shields.io/badge/OpenGL-5586A4?style=flat&logo=OpenGL&logoColor=white"/>
# moving_planets
This repository is about the third assignment of SKKU's 2021 Introduction to Computer Graphics. This project further developed the [planet_in_space](https://github.com/dipreez/planet_in_space) to implement a solar system simulation program in which several spheres revolve around the sphere at the center.
![cg3](https://github.com/dipreez/moving_planets/assets/50349104/4633503c-d321-4aeb-b087-6eba28c922cc)

# Algorithms and data structures
## Sphere initialization
The sphere was implemented in the same way as in the previous
assignment(A2). Color switching and wireframe mode switching functions
are still available with 'D' and 'W' buttons. Every planet initially has its
own center coordinates, and radius. Accordingly, the initial location and
form are determined by the application of scaling matrix and translation
matrix.
## Sphere revolution&self-rotation
Spheres begin their revolution and self-rotation right after they are
generated. Every time update() function is called, it calls glfwGetTIme()
function and saves its value. update() function compares current
glfwGetTime() and previously saved glfwGetTime() value to calculate the
time interval between the current and previous frame. According to this
time interval, spheres are revolved and self-rotated per each frame by
applying rotation matrix. Sphere revolution and self-rotation can be
stopped/resumed by pressing ‘PAUSE’.
## Camera zooming&panning
Right button and shift+left button of a mouse along the Y-axis in the
screen will zoom the camera in/out. This function is implemented by
mapping the mouse displacement to translation along n axis. Middle
button and ctrl+left button of a mouse along the screen will activate
camera panning. This function is implemented by mapping the mouse
displacement to translation along uv plane. The amount of panning is
scaled based on distance to the scene center.
# Discussions
When using the camera zoom function, if you zoom in excessively,
the eye position of the camera goes over the other side of the at
position and the view is reversed. There was no mention of the
assignment evaluation criteria, so I did not modify this problem in my
submission. However, the sample provided on the course website
seems to have limited zooming in so that problem doesn't happen.
However, I found that if I zoom in excessively after panning the
camera in the sample program, program will start malfunctioning and
the camera will not pan and zoom normally after that. I think we need
a better solution.
