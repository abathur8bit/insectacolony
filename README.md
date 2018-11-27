# Insecta Colony
A simulated insect civilization. 


# License
Copyright 2018 Lee Patterson

You may use and modify at will. Please credit me in the source.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


# Objective 
Create a simulated insect civilization, making use of Finite State Machine (FSM) that runs on a Raspberry PI, or VPS. 
The ultimate goal is to learn some new technologies, and be able to ramp up the simulation to max out the RPi. Each 
insect will have a script based AI to, and an AI can be tailored to different personalities.

Each insect can be a different type, and can has it's own stats.

    World
        |
        +---Colony
        |   |
        |   +---Insect 1
        |   |
        |   +---Insect n
        |
        +---Colony
            |
            +---Insect 1
            |
            +---Insect n

The sim server can be stopped at any time and the colony should pick up where it left off. World state will always be 
persisted to the database.


# Technologies 
A major part of this excersize is to learn new technologies. To understand their stregnths and weaknesses. To that end, 
the following technologies will be employed:

**Java** - programming language of choice, since I mostly program in Java, and the IDE's and debugging experience on Mac 
is better.

**SQLite DB** - A fast, single file, single app database. Ideal to swap in instead of writing to a flat file using 
fopen(). Allows you to use the full suit of SQL commands. 

**NCurses** - A console based package for positioning the cursor, and setting colors. Also will likely be using panels 
and possibly menus, which complement ncurses.

**PHP** - For building a simple CGI script to allow for a simple view into the state of the simulation.

**Web Based** will make use of streaming jpg to show a bitmap of the world. 

**Console** will use ncurses to manage and view the world. This will be the primary interface into the colony. The 
reason for this is I want to experiment with console based technologies.


# Notes 

EMACS
https://www.cs.rutgers.edu/LCSR-Computing/some-docs/emacs-chart.html

My quick list

General
C-_      Undo

File
C-x C-f  Open file
C-x C-s  save-buffer
C-x C-w  write-file (save as)
C-x k    Close file
C-x b    Switch buffer

Window
C-x 3    Split vert
C-x 2    Split horz
C-x 1    One window
C-x 0    Close window
C-x o    Next window

Search
C-s      isearch-forward
C-r      isearch-backward

Navigate
C-x [    backward-page
C-x ]    forward-page
C-l      recenter
C-v      scroll-up (page down)
ESC v    scroll-down (page up)


Selecting
C-sp     set-mark-command (set select)
C-w      kill-region
C-y      yank (paste)

Help
C-h k    describe-key




# Insect name generation
Created a simple name generator to create insect names, since there will be a lot of insects.

## Building and running generator
```
$ mkdir -p target
$ g++ -o target/generate src/main/cpp/namegeneratortest.cpp
$ target/generate 
Name Generator 1.0
syllables 3 name = Wonkrayfay
```

## Sample insect names 
Just a few generated names.

Shimon      
Izenwonkwonk
Fayfay      
Zagrash     
Gnokray     
Rayzag      
Wonkwonk    
Blargraygnok
Monizenrash 
Rayshiblarg 
Izenmonrash 
Monfay      
Izenblarg   
Shiblargrash
Zagmon      
Fayrashzag  
Gnokfay     


