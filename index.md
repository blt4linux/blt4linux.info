---
layout: default
---

# About
BLT4Linux is a Linux port of the popular Better Lua injecTor (BLT)
modding framework for the First-Person co-op shooter PAYDAY 2.

While it is a rewrite of the C++ part of BLT, it uses the same Lua
code and is compatible with the majority of the PAYDAY 2 lua mods that can be found online.
The only exception to this is Beardlib, which is compatible with lua mods on Linux, but does not
like loading Custom Assets, such as Custom Heists or the use of the Beardlib Music Module, as
the Linux version of PAYDAY 2 does not have SysFS to load said assets in-game.

## Credits
 - [Roman Hargrave](https://github.com/RomanHargrave) - Initial work, code, translations from BLT4WIN
 - [Leonard König](https://github.com/LeonardKoenig) - C++ cleanup, linker work
 - [Ozymandias117](https://github.com/Ozymandias117) - Fixed subhook on 64-bit platforms
 - [James Wilkinson](https://github.com/JamesWilko) - BLT LUA (and BLT)
 - [ZNixian](https://znix.xyz) - Hosting this website
 - [Dribbleondo](http://twitter.com/dribbleondo) - Writing some of this websites information.

## Source Code
The source code for this project is available on [GitHub](https://github.com/blt4linux/blt4l),
under the terms of the GNU GPLv3 License.

The source code for the platform-independent Lua code is
also on [GitHub](https://github.com/JamesWilko/Payday-2-BLT-Lua), under the MIT License.

The source code for this website is available on both [GitLab](https://gitlab.com/znixian/blt4linux.info)
and [GitHub](https://github.com/blt4linux/blt4linux.info), under the GNU GPLv3 License.

# Installation

---

## Installing with binary packages (Debian)
This is easiest way to go about installing BLT4Linux, as the releases are already compiled,
ready for use. Go to the [GitHub release page](https://github.com/blt4linux/blt4l/releases/latest)
and download the archive appropriate for your distro. If you are unsure, select "Debian-Stretch".

Next, extract the archive and move 'mods' and 'libblt_loader.so' to your PAYDAY 2 folder.
This can be found in "~/.steam/steam/steamapps/common/PAYDAY 2/"

You should find the hook in your build folder, named libblt_loader.so.
You will need to set LD_PRELOAD for the PAYDAY2 process to find the loader. By default,
the path should be:

       env LD_PRELOAD="$LD_PRELOAD ./libblt_loader.so" %command% -skip_intro

(The -skip_intro command is optional, but useful for somewhat obvious reasons =P)

If you have set everything up correctly, you should be up and running with the BLT Mod API in PAYDAY 2.

---

## Installing with the installer script (Debian/Arch)
First, download a copy of BLT4L and switch to it's directory:

	$ git clone https://github.com/blt4linux/blt4l.git
	Cloning into 'blt4l'...
	remote: Counting objects: 571, done.
	remote: Total 571 (delta 0), reused 0 (delta 0), pack-reused 571
	Receiving objects: 100% (571/571), 318.37 KiB | 167.00 KiB/s, done.
	Resolving deltas: 100% (310/310), done.
	$ cd blt4l

Now, run the installer script:

	$ ./install.sh
	TODO: Can someone please get some sample output?

---

## Manual Build
First, install the packages we need to compile everything. How you
do that will vary depending on your distribution and package manager.
 - openssl
 - curl4-openssl
 - zlib
 - cmake

Download a copy of BLT4L:

	$ git clone https://github.com/blt4linux/blt4l.git
	Cloning into 'blt4l'...
	remote: Counting objects: 571, done.
	remote: Total 571 (delta 0), reused 0 (delta 0), pack-reused 571
	Receiving objects: 100% (571/571), 318.37 KiB | 167.00 KiB/s, done.
	Resolving deltas: 100% (310/310), done.
	$ cd blt4l

Download all the required submodules:

	$ git submodule init
	Submodule 'lua/Payday-2-BLT-Lua' (https://github.com/Luffyyy/Payday-2-BLT-Lua)
	registered for path 'lua/Payday-2-BLT-Lua' 
	Submodule 'subhook' (https://github.com/Zeex/subhook.git) registered for path 'subhook' 
	$ git submodule update
	Cloning into 'blt4l/lua/Payday-2-BLT-Lua'...
	Cloning into 'blt4l/subhook'...
	Submodule path 'lua/Payday-2-BLT-Lua': checked out '2a8f8a0767817bbe12fa7f0244718a308db40a34'
	Submodule path 'subhook': checked out '9551217ba4fadbf729e810ab94b4ab7f67b4cfbe'

Configure, ready for building:

	$ mkdir build
	$ cd build
	$ cmake ..a
	-- The C compiler identification is GNU 6.3.1
	-- The CXX compiler identification is GNU 6.3.1
	-- Check for working C compiler: /usr/bin/cc
	-- Check for working C compiler: /usr/bin/cc -- works
	-- Detecting C compiler ABI info
	-- Detecting C compiler ABI info - done
	-- Detecting C compile features
	-- Detecting C compile features - done
	-- Check for working CXX compiler: /usr/bin/c++
	-- Check for working CXX compiler: /usr/bin/c++ -- works
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Detecting CXX compile features
	-- Detecting CXX compile features - done
	-- Found CURL: /usr/lib64/libcurl.so (found version "7.52.1")
	-- Found OpenSSL: /usr/lib64/libssl.so;/usr/lib64/libcrypto.so (found version "1.0.2k")
	-- Found ZLIB: /usr/lib64/libz.so (found version "1.2.11")
	-- Configuring done
	-- Generating done
	-- Build files have been written to: blt4l/build

Compile it:

	$ make
	Scanning dependencies of target blt_loader
	[  9%] Building C object CMakeFiles/blt_loader.dir/subhook/subhook.c.o
	[ 18%] Building CXX object CMakeFiles/blt_loader.dir/src/event.cc.o
	[ 27%] Building CXX object CMakeFiles/blt_loader.dir/src/zip.cc.o
	[ 36%] Building CXX object CMakeFiles/blt_loader.dir/src/fs.cc.o
	[ 45%] Building CXX object CMakeFiles/blt_loader.dir/src/http.cc.o
	[ 54%] Building CXX object CMakeFiles/blt_loader.dir/src/log.cc.o
	[ 63%] Building CXX object CMakeFiles/blt_loader.dir/src/hook.cc.o
	[ 72%] Building CXX object CMakeFiles/blt_loader.dir/src/lapi.cc.o
	[ 81%] Building CXX object CMakeFiles/blt_loader.dir/src/lapi_http.cc.o
	[ 90%] Building CXX object CMakeFiles/blt_loader.dir/src/blt_main.cc.o
	[100%] Linking CXX shared library libblt_loader.so
	[100%] Built target blt_loader

You should find the hook in your build folder, named libblt_loader.so.

### Setting LD_PRELOAD
As with the prebuilt, releases, you need to make sure that PAYDAY 2 can find the Lua hook.
Go into steam, and set the launch command to:

	env LD_PRELOAD="$LD_PRELOAD ./libblt_loader.so" %command% -skip_intro

### Copy across the mods folder
Next, you will need to copy a LUA mod base to your PAYDAY 2 folder (or
whatever working directory you intend to run PAYDAY 2 in). There
is a symlink to the BLT LUA mod base (from the BLT4WIN submodule) under lua/mods.

If you set everything up correctly, you should be up and running with the BLT mod API in PAYDAY 2.
