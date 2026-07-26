===========================================
ZxLethal Engine
Complete File Connection Architecture
(Foundation Version)
===========================================

PROJECT STRUCTURE

ZxLethal/
│
├── main.cpp
├── Engine.h
├── Engine.cpp
│
├── Core/
│   ├── Window.h
│   ├── Window.cpp
│   ├── Input.h
│   ├── Input.cpp
│   ├── Time.h
│   └── Time.cpp
│
├── Graphics/
│   ├── Renderer.h
│   ├── Renderer.cpp
│   ├── Shader.h
│   ├── Shader.cpp
│   ├── Mesh.h
│   └── Mesh.cpp
│
├── Game/
│   ├── Game.h
│   └── Game.cpp
│
├── Math/
│   ├── Vector2.h
│   ├── Vector3.h
│   └── Matrix4.h
│
└── CMakeLists.txt


===========================================================
LEVEL 1 : PROGRAM STARTUP
===========================================================

Operating System
        │
        ▼
./ZxLethal
        │
        ▼
main.cpp
        │
        ▼
Engine object create
        │
        ▼
Engine::Run()
        │
        ▼
Engine controls entire application


===========================================================
LEVEL 2 : MAIN DEPENDENCY GRAPH
===========================================================

                    +----------------+
                    |    main.cpp    |
                    +--------+-------+
                             |
                             |
                             ▼
                    +----------------+
                    | Engine.cpp/.h  |
                    +--------+-------+
                             |
          +------------------+------------------+
          |                  |                  |
          |                  |                  |
          ▼                  ▼                  ▼
 +----------------+  +----------------+  +----------------+
 | Core::Window   |  | Graphics       |  | Game           |
 +----------------+  | Renderer       |  +----------------+
          |          +--------+-------+          |
          |                   |                  |
          |                   |                  |
          ▼                   ▼                  ▼
     SDL2 Window         Shader + Mesh      Game Logic
          |                   |
          |                   |
          ▼                   ▼
     OpenGL Context      GPU Rendering


===========================================================
LEVEL 3 : COMPLETE MODULE DEPENDENCIES
===========================================================

main.cpp
│
└────────────► Engine
                 │
                 ├────────► Window
                 │              │
                 │              ├────► SDL2
                 │              │
                 │              └────► OpenGL ES Context
                 │
                 ├────────► Renderer
                 │              │
                 │              ├────► Shader
                 │              │           │
                 │              │           └────► GPU Program
                 │              │
                 │              └────► Mesh
                 │                          │
                 │                          └────► Vertex Data
                 │
                 ├────────► Input
                 │              │
                 │              └────► SDL Events
                 │
                 ├────────► Time
                 │              │
                 │              └────► Delta Time
                 │
                 └────────► Game
                                │
                                └────► Game Logic


===========================================================
LEVEL 4 : FILE CONNECTIONS
===========================================================

main.cpp
│
├── includes Engine.h
│
└── creates Engine object


Engine.cpp
│
├── includes Engine.h
├── includes Window.h
├── includes Renderer.h
├── includes Input.h
├── includes Time.h
└── includes Game.h


Window.cpp
│
├── includes Window.h
├── includes SDL2
└── includes GLES3/gl3.h


Renderer.cpp
│
├── includes Renderer.h
├── includes Shader.h
└── includes Mesh.h


Shader.cpp
│
├── includes Shader.h
└── includes GLES3/gl3.h


Mesh.cpp
│
├── includes Mesh.h
└── includes GLES3/gl3.h


Input.cpp
│
├── includes Input.h
└── includes SDL2


Time.cpp
│
├── includes Time.h
└── uses SDL timing


Game.cpp
│
└── includes Game.h


===========================================================
LEVEL 5 : RUNTIME EXECUTION FLOW
===========================================================

main()

↓

Engine Constructor

↓

Window.Create()

↓

SDL_Init()

↓

SDL_CreateWindow()

↓

SDL_GL_CreateContext()

↓

Renderer.Init()

↓

Shader.Create()

↓

Mesh.Create()

↓

Engine Loop Starts

        │
        ▼

Input.Update()

↓

Time.Update()

↓

Game.Update()

↓

Window.Clear()

↓

Renderer.Draw()

↓

Shader.Use()

↓

Mesh.Bind()

↓

glDrawArrays()

↓

Window.Present()

↓

SDL_GL_SwapWindow()

↓

Next Frame

↓

(repeat until exit)

↓

Renderer.Destroy()

↓

Mesh.Destroy()

↓

Shader.Destroy()

↓

Window.Destroy()

↓

SDL_GL_DeleteContext()

↓

SDL_DestroyWindow()

↓

SDL_Quit()

↓

return 0


===========================================================
LEVEL 6 : CPU TO GPU FLOW
===========================================================

CPU
│
├── main.cpp
│
├── Engine
│
├── Renderer
│
├── Shader
│
├── Mesh
│
└────────────┐
             │
             ▼
      OpenGL Driver
             │
             ▼
      Graphics Driver
             │
             ▼
            GPU
             │
             ▼
      Vertex Shader
             │
             ▼
      Rasterizer
             │
             ▼
      Fragment Shader
             │
             ▼
        Framebuffer
             │
             ▼
          Display


===========================================================
LEVEL 7 : HEADER DEPENDENCY TREE
===========================================================

main.cpp
│
└── Engine.h
     │
     ├── Window.h
     ├── Renderer.h
     ├── Input.h
     ├── Time.h
     └── Game.h

Renderer.h
│
├── Shader.h
└── Mesh.h

Shader.h
│
└── OpenGL ES

Mesh.h
│
└── OpenGL ES

Window.h
│
├── SDL2
└── OpenGL ES

Input.h
│
└── SDL2

Time.h
│
└── SDL Timer


===========================================================
LEVEL 8 : OVERALL ARCHITECTURE
===========================================================

                     USER
                       │
                       ▼
                 Keyboard/Mouse
                       │
                       ▼
                  SDL2 Events
                       │
                       ▼
                 Input System
                       │
                       ▼
                    Engine
       ┌───────────────┼────────────────┐
       │               │                │
       ▼               ▼                ▼
   Time System    Game Logic      Renderer
                                          │
                                          ▼
                                   Shader + Mesh
                                          │
                                          ▼
                                   OpenGL ES API
                                          │
                                          ▼
                                 Graphics Driver
                                          │
                                          ▼
                                         GPU
                                          │
                                          ▼
                                       Screen

===========================================================
FOUNDATION STATUS
===========================================================

✓ Entry Point Created
✓ Engine Layer
✓ Window Layer
✓ Input Layer
✓ Time Layer
✓ Renderer Layer
✓ Shader Layer
✓ Mesh Layer
✓ Game Layer
✓ SDL2 Integrated
✓ OpenGL ES 3.0 Integrated
✓ CMake Build System
✓ Git Repository
✓ GitHub Repository
✓ Blue Triangle Successfully Rendered

Current Engine Stage:
"Minimal Modular Rendering Engine"

Next Stage:
Texture → Sprite → Camera → TileMap → Collision → ECS → Editor
===========================================================
END
===========================================================
