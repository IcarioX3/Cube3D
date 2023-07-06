# Cube3D

This project, developed as part of my training at 42 School, involves creating a realistic 3D graphical representation of a maze using Ray-Casting principles. 
I utilized the miniLibX library for graphics rendering. This project is inspired by the world-famous Wolfenstein 3D game, which
was the first FPS ever

## Features

- **Realistic Display**: I implemented a 3D rendering using Ray-Casting to create a first-person perspective inside the maze.
- **Wall Textures**: I added different textures for walls based on their orientation (North, South, East, West).
- **Game Controls**: Arrow keys allow looking left and right, while W, A, S, and D keys enable movement through the maze.
- **Floor and Ceiling Colors**: I implemented the ability to customize the colors of the floor and ceiling to add visual variety to the game environment.
- **Window Management**: Smooth window handling is ensured, including actions such as window switching and minimizing.

## Scene Description File

- The program takes a scene description file (.cub) as an argument, which contains the maze map composed of specific characters
(0 for an empty space, 1 for a wall, N/S/E/W for the player's starting position and orientation).
- The scene description file also allows specifying wall textures (North, South, East, West), floor and ceiling colors, and other details.

This project provided me with an opportunity to learn and apply several key programming concepts,
including 3D graphics rendering, user control handling, configuration file processing, and working with the miniLibX library.
