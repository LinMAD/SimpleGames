#### SimpleTetris with SDL2

![](assets/v02.png)

### Development
To prepare project use script: `conan.sh` to setup remote and install dependencies.
Fresh example:
```text
    ./conan.sh add_remote
    ./conan.sh debug
    // Or if you want
    ./conan.sh release 
```
And then you can build project:
```text
├── main
│   └── src
│       ├── GameHandler  // Contains game loop (input, update, draw)
│       ├── Model        // Contains drawable game object
│       ├── Component    // Game components  
│       └── Setting      // General game enums settings
└────────── Util         // Utilities, like random generator
```

#### Inspiration and ideas
 - [Tetris on wiki](https://en.wikipedia.org/wiki/Tetris)
 - [Text guide for SDL 1](http://javilop.com/gamedev/tetris-tutorial-in-c-platform-independent-focused-in-game-logic-for-beginners/)
 - [Video guide](https://www.youtube.com/watch?v=htfB7D2ruXw)
 
