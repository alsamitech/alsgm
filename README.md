# _AlsGM_ Game Engine

This is a game engine that I am working on as one of my projects. (TLDR: this is meant to be a simple game engine that still does a good job of abstracting away most of the complexity involved in low-level graphics!)

NOTE BEFORE READING:
  This engine is likely to go through a ton of rewrites. I'm learning with every line of C++ and C I write. This engine will probably not be stable for a few months (or longer!).
  Also, while I plan to work on this as often as possible, for the first month or so, I would probably spend most of the time reading about how to pull off a project as large as this.

Premable:
  Game Engines are not supposed to be one-size-fits-all engines. While this can be done efficiently with a lot of effort, I don't see the point in trying to use one engine for a ton of use cases.
  Game Engines are supposed to assist with game rendering, but not abstract the APIs away. You should still be to use OpenGL functions.
  Game Engines are also supposed to be open source. Why would you make a game on a engine which has source code that you dont even know or cant even modify to your needs?
  Game Engines are supposed to be written as low-level as possible. While this isin't too much of a problem with engines like Unity or Unreal, smaller game engine projects are sometimes wirrtin in excessive C++. While Class-Based game engines make life easier, they are often slower and harder to port to C.
  
  ALSGM intends to fix all that.
  
## Dependencies
*AlsGM (Codename Yin) Relies on mulitple dependencies for redenring and API implementation*
* Vulkan Must be linked (if vulkan selected in config.h file)
* OpenGL Must be linked (if opengl selected in config.h file)
* GLFW (if vulkan) 
* Xlib Header Files (This makes alsgm practically gnu/(linux or hurd) exclusive)
* GLFW Headers (if vulkan selected in config.h file)
* GLU To interact with both OpenGL and X11. (if opengl selected in config.h file) 
* Pthread and `sys/` files (This makes alsgm POSIX-Exclusive)
* While not a dependency, It is importnat to note that ALSGM uses a fork of ALSGM, Version 1.4 for networking



**What is it?**
	ALSGM is a module-based game engine, Moduels can be both written in C or C++. Unlike most game engines, it's actually compiled with the game itself. This helps because the game studio can easily make new modules and extend the engine's functionality.  

**What Does it do?**
  _alsgm_ does the low-level implementation work that would normally be have to be done on it's own if you were do design a game without a game engine. AlsGM also intends to standardize logging (both to console and to files). AlsGM is also responsible for utilizing multiple threads using pthreads. The game can spin off more threads from it's one thread. However, AlsGM does not abstract away pthead.h __(thankfully)__. AlsGM also can run on either a sprite model, or a function-based model. In the sprite model, everything (depending on the configuration). is a struct or object that has functions for handling the sprite.
  Example (in C++):
  ```cpp
  gm_sprite *foo = new gm_sprite(/*intial position*/100,130,/*states that the object would not be able to be dragged by a mouse*/STATIC,/*nmv states that this object is unchanging*/NMV);
  foo->Show();
  // Shows the sprite
  ```
  The function model provides the fuctions to draw , move, and destroy objects. It also provides a comprehensive event system. However, it does take more code.

**How Does it work?**
	ALSGM has 2 types of modules, core modules and expandability modules. Core modules are things like the Event System, the Logging System, and the Interface with OpenGL. These are all considered extremly critical for the stable operation of aslgm. These are all loaded before the Application's entry point is spun off onto a new process. Also, ALSGM has a differnt kind of module called expandability modules. These modules, while also loaded before the app spins off into it's own process, are considred much less critical, have a less privliges than the core modules, but also can have more integration with things that are not strictly part of the app/engine. Early on, I recongnized that not all developers __want__ to go through the source code and edit things. So I made a config file to do that. All Options can be changed through defines, and there are explinations of each define in comments.

![](docs/processes.jpg)

The Spec for an alsgm-compatible engine is available at `docs/spec`

Vulkan SDK:
https://vulkan.lunarg.com/sdk/home#linux
=======
	ALSGM has 2 types of modules, core modules and expandability modules. Core modules are things like the Event System, the Logging System, and the Interface with OpenGL or Vulkan. These are all considered extremly critical for the stable operation of aslgm. These are all loaded before the Application's entry point is spun off onto a new process. Also, ALSGM has a differnt kind of module called expandability modules. These modules, while also loaded before the app spins off into it's own process, are considred much less critical, have a less privliges than the core modules, but also can have more integration with things that are not strictly part of the app/engine

Assumed Timeline:
	1. November - Finish the core components, and do some basic Vulkan and OpenGL implmentation, and expand documentation
	2. December - The enginerring part, take the (essentially) template for the game engine and turn it into a full engine and fully document every function, variable
	3. Early 2021 - Flush out the engine, by this time, the engine should be suitable for large game projects
	4. Mid 2021 - Bug fixes, expanding the logging system, and turn some of the code from C to platform-specific Assemby (Risc-V and x84-64(amd64))
	5. Late 2021 and after - Bug fixes, efficeincy fixes, and making a designer and IDE for alsgm.
  
I also don't think this should be the only game engine you should ever use. If you know C++ or C, try experimenting with making your own game engine!
Learning Resources:
  https://www.youtube.com/watch?v=dZr-53LAlOw&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=6
  *The Cherno's Videos did help me with this project, but if you want to develop a game engine for Linux like me, you will need other resources and a good knowledge of OpenGL or Vulkan and Xlib. If you really want, I will put some of the key components of this rendering engine in a seperate GitHub Repository

Note Before Contributing:
Please read the CONTRIBUTING file before pull-reqesting alsgm. While it is not required, it is __highly__ reccomended to do so as it will give you a ton of good advice

Official Public Mirror (GitHub):
  https://github.com/alsamitech/alsgm

__if you want a good alternative of alsgm for Windows, see https://github.com/thecherno/Hazel__

>>> NOTE: Don't ask why there are so many  mentions of the word "Yin", it's a long story that I don't feel like explaining.
