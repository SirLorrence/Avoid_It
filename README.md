# Avoid it!
For this project, I wanted to apply my limited c++ knowledge and also code without a game engine or just a simple console application. Along with the course that I'm following, it introduced me to a simple library for game programming called "Raylib" (which is now one of my favorites). After I learned the basic knowledge of what I needed to start, I went ahead and programmed a simple game loop with increasing difficulty. This project also semi-introduced me to creating CMake files and learning how to compile to different platforms from Linux (with no luck). Also, I messed around with pointers & memory addresses and learned how to create some simple classes in c++. 


<p align="center">
  <img src="https://github.com/SirLorrence/ReadMeImages/blob/main/Avoid-it/AvoidIt.gif?raw=true">
</p>

Compile on Unix:
```
cmake -B build
cmake --build build
```
Windows - Sadly, I was unable to compile with project on an windows pc and through mingw32 command on linux. Will update when i find a solution

### LOGS
---
Log #1

First I struggle on how to install the library, I could of just used the zip file but I wanted to create this from starch. I followed the github wiki on installing it on linux and got stuck, but I found a video that help clearified what I was doing and managed to get an basic window to work. 

<p align="center">
  <img src="https://github.com/SirLorrence/ReadMeImages/blob/main/Avoid-it/FirstGameWindow.png?raw=true">
</p>

When in was trying to pass in an variable to my movement input, at first it did not work. Then I remember cpp as points, so instead of passing in a variable - I passed in the memory addrease and that solve my problem. Pointers are pretty cool\
Example:
`` void Input(int& x, int& y, int speed) ``

Log #2 

I wanted to reoriginze my project, but to do that I couldnt use gcc anymore, well it gave me an ‘fatal error’. Now I started to learn how to create an cmake file.

After getting more errors, I went back to gcc because the cmake method didn’t work with the why I had raylibs install(maybe). I searched around an found that I had an extra / in front of the folder I was trying to compile from. Simple mistake but I also learned that you can do /*file to compile all of them, cool.

I also ran into an issue when trying to link object files which changing to g++ to gcc turn out ti fix it. I had no reason until now to change but will be using this by default of any other project.


Log #3

Have a full day of googling, search forms and asking a question in the raylib community(still hoping for a solution) I was unable to do a cross platform build on Linux. But this lead me to start looking in on how to make a cmake file, still confused but I got something to work. I modified a example script that was in the repo and used the knowledge I learned the other day. Tested this out on my Mac and with an  std=c++11 + make —build build command I got my project up and run on Mac. 
