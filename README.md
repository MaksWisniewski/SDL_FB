# SDL_FB

* link do dokumentacji:
    * [Dokumentacja](https://hackmd.io/@Oem6_SikRyyd7TnX_kPlOA/SDL_FB)
* Implementacja poplarnej gry flappy bird w jezyku c
 
 Aby uruchomić grę: 
 ```bash
 make all
 ./game
 ```
 Aby rozpocząć grę wciśnij enter, następnie spację.

##### Arch install
```bash
sudo pacman -S sdl2 sdl2_image sdl2_mixer sdl2_gfx sdl2_net sdl2_ttf
```

#####  Debian install
```bash
    sudo apt install libsdl2-image-dev libsdl2-ttf-dev libsdl2-ttf-2.0.0-0 
    make cmake autoconf automake 
    libtool pkg-config libasound2-dev libpulse-dev libaudio-dev libjack-dev 
    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev 
    libxinerama-dev libxxf86vm-dev libxss-dev libgl1-mesa-dev libdbus-1-dev 
    libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev 
    fcitx-libs-dev libsamplerate0-dev libsndio-dev libwayland-dev 
    libxkbcommon-dev libdrm-dev libgbm-dev 
```

```bash
git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
../configure
make
sudo make install
```

#####  Create documentation
```bash
doxygen dconfig
```
