WebPhonon
=========
[![Splash Screen](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/WebPhonon-Master-text2.png)](https://youtu.be/xsereIusvYk)

Phonon based Video Player written in Qt
-----------------------------------------------
http://zakhrov.github.io/WebPhonon/
## Features:
* OpenGL Visualization
[![Visualizer](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/visualizer.png)](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/visualizer.png)
* MySQL powered Media Library
[![database](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/db_manager.png)](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/db_manager.png)
* 10 band Equalizer (Linux Gstreamer backend Only)
[![Equalizer](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/equalizer.png)](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/equalizer.png)
* Volume amplifier (can blow your speakers out!)
[![interface](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/full_interface.png)](https://raw.githubusercontent.com/Zakhrov/WebPhonon/master/screens/full_interface.png)

## Runtime Dependencies:
Qt5, Phonon, kdelibs5 (linux only)
## Build Dependencies:
cmake, Qt5-dev, Phonon4Qt5-dev, kdebase5-dev
## Ubuntu build dependencies command:
apt-get install cmake libqt5-dev libphonon4-dev kdelibs5-dev
## OpenSUSE build dependencies command:
zypper in cmake libqt5-devel phonon4qt5-devel libkde4-devel

## OpenSUSE Repo
http://software.opensuse.org/package/WebPhonon-Qt5
* The OBS repository contains packages for all supported OpenSUSE versions along with Arch Linux packages

## Generic Binary Packages (RPM, DEB and win32 EXE)
http://sourceforge.net/projects/webphonon/
* The Windows version requires K-lite codec pack

## Build from Source:
* git clone https://www.github.com/Zakhrov/WebPhonon-Qt5.git
* Build Instructions:
* cd to the directory you cloned WebPhonon to
* mkdir build
* cd build
* cmake -DCMAKE_INSTALL_PREFIX=/usr ..
* make
* execute using ./WebPhonon-Qt5 or run sudo make install for systemwide install
