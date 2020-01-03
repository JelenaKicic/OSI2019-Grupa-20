<p align="center" style="margin:0px">
    <img src="https://res.cloudinary.com/codejard/image/upload/v1577780828/adventurist_logo_part_1_trl4eh.png" width="150">
</p>
<p align="center" style="font-size:28px; margin:0px;"> Adventurist </p>
<p align="center">
    <img src="https://res.cloudinary.com/codejard/image/upload/v1577780842/adventurist_logo_part_2_wlnnmh.png" width="125">
</p>

# Project setup

- First clone the repository

  ```sh
  git clone https://github.com/JelenaKicic/OSI2019-Grupa-20.git
  ```

## Windows

- Download and install MinGW https://osdn.net/projects/mingw/releases/
- In command promt enter  

    ```sh
    copy C:\MinGW\bin\mingw32-make.exe C:\MinGW\bin\make.exe
    ```

- To build and run the application from project root in command promt enter  
  
    ```sh
    make
    ```

## Linux

- Download and install MinGW  
  - Debian, Ubuntu, Mint, ...

    ```sh
    sudo apt install g++-mingw-w64-x86-64
    ```

  - Arch, Manjaro, ...  

    ```sh
    yay -S mingw-w64-g++
    ```

- For running the .exe download and install wine
  - Deian, Ubuntu, Mint, ...
  
    ```sh
    sudo apt install wine64
    ```

  - Arch, Manjaro, ...
  
    ```sh
    sudo pacman -S wine
    ```

- To build and run the application from the project root in terminal enter
  
  ```sh
  make
  ```

  (Note that for the application to start project has to be cloned in a directory accessible by wine)
