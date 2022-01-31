# SDL_FB
---

### Install SDL2
```bash
git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
../configure
make
sudo make install
```


### Compile program
```bash
gcc -o myprogram myprogram.c `sdl2-config --cflags --libs`
```


### Importante
```bash
sudo apt install libsdl2-image-dev
```

### Eventually, install
*(Ubuntu 20.04, all available features enabled:)*

    sudo apt-get install build-essential git make cmake autoconf automake \
    libtool pkg-config libasound2-dev libpulse-dev libaudio-dev libjack-dev \
    libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxfixes-dev libxi-dev \
    libxinerama-dev libxxf86vm-dev libxss-dev libgl1-mesa-dev libdbus-1-dev \
    libudev-dev libgles2-mesa-dev libegl1-mesa-dev libibus-1.0-dev \
    fcitx-libs-dev libsamplerate0-dev libsndio-dev libwayland-dev \
    libxkbcommon-dev libdrm-dev libgbm-dev
