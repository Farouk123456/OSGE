sudo g++ -pthread -g Dependencies/*.cpp main.cpp -Wno-narrowing -o Out -lglfw -lGLEW -lGLU -lglut -lGL -lXrandr -lXi -lXinerama -lX11 -lrt -ldl -lSDL2 -lSOIL
sudo mv /home/$USER/Documents/OpenGL/SourceCode/LinuxBuild/Out /home/$USER/Documents/OpenGL/Executables/Linux/
sudo cp -r /home/$USER/Documents/OpenGL/SourceCode/LinuxBuild/shaders /home/$USER/Documents/OpenGL/Executables/Linux/
sudo cp -r /home/$USER/Documents/OpenGL/SourceCode/LinuxBuild/data /home/$USER/Documents/OpenGL/Executables/Linux/
cd /home/$USER/Documents/OpenGL/Executables/Linux
#clear
sudo ./Out
#clear