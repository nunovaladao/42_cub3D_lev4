# Cub3D 🎮👾

- This project was made in collaboration with [Inês Alves](https://github.com/inesalves44)!

## Introduction
This is our **Cub3D project** developed as part of the curriculum at the 42 programming school. Cub3D is a simple 3D game inspired by Wolfenstein 3D.

## Features
- 3D graphical rendering
- Player movement
- Textures and maps
- Collision detection
- ...

## Prerequisites
- [Minilibx](https://github.com/42Paris/minilibx-linux)

## GRADE PROJECT ✅
- 105/125 📋
- [**Subject**](https://github.com/nunovaladao/42_cub3D/blob/main/extras/en.subject.pdf)

## Installation
To get started with cub3d, follow the steps below:
1. Clone the repository via:
```bash
git clone https://github.com/nunovaladao/42_cub3D.git
```

2. Move into the repository directory:
```bash
cd 42_Cub3D
```

3. Build the project using the provided Makefile:
```bash
make
```

4. Run Cub3D:
```bash
./cub3D <.cub file>
```

## Usage
- W, A, S, D: Movement
- Arrow keys: Camera rotation
- Change the color of the ceiling and floor in the .cub file
- Change the map in the .cub file
- Change the textures too


## Skills and Competencies Acquired

During the development of the Cub3D project, I acquired and strengthened various skills and competencies, including:

- **C Programming:** Enhanced proficiency in the C programming language, particularly in low-level and systems programming.

- **Graphics Programming:** Gained practical experience in 3D graphics programming, including rendering techniques, texture mapping, and working with graphical libraries such as minilibx.

- **Problem Solving:** Developed problem-solving skills by addressing challenges related to game development, collision detection, and map rendering.

- **Git and Version Control:** Strengthened version control skills using Git, maintaining a clean and well-documented commit history.

- **Documentation:** Practiced documenting code, project structure, and usage to facilitate understanding for both myself and potential contributors.

These skills and competencies have not only contributed to the success of the Cub3D project but also provided a valuable foundation for future programming and software development endeavors.

## Raycasting and DDA ✍🏼

**Raycasting and the DDA (Digital Differential Analyzer)** algorithm are fundamental concepts in computer graphics and game development, particularly in the context of creating 3D environments. They are commonly used in applications like rendering a 3D scene or implementing a first-person perspective in games.

**Raycasting:**
Raycasting is a technique used to render a 3D scene on a 2D screen. It simulates the behavior of rays cast from the viewer's perspective, determining which objects in the scene the rays intersect with. This technique is computationally less intensive compared to true 3D rendering techniques and is often used in older games with limited computing power.

Here's a simplified overview of how raycasting works:

- ```Initialize Camera:``` Define a camera position, direction, and field of view.

- ```Cast Rays:``` Cast rays from the camera's position, covering the entire viewport. Typically, the number of rays corresponds to the number of pixels on the screen.

- ```Intersection Check:``` For each ray, check where it intersects with the 3D environment. This is often done by finding the intersection point with walls or other objects in the scene.

- ```Calculate Distance:``` Determine the distance from the camera to the intersection point. This information is crucial for rendering perspective correctly.

- ```Draw on Screen:``` Use the distance information to draw vertical columns on the screen, representing the 3D scene. Closer objects are wider, while farther objects are narrower.

Raycasting is the foundation of many classic first-person shooter games, including Wolfenstein 3D.

**DDA (Digital Differential Analyzer) Algorithm:**
The DDA algorithm is used for drawing lines on a computer screen. In the context of raycasting, it's often employed to determine which grid cells in the 2D map the ray intersects.

The DDA algorithm is crucial for drawing lines efficiently on a digital grid and is often utilized in the process of rendering the raycasted scene onto the screen, helping to determine which grid cells the rays intersect and should be shaded or textured.

## Conclusion
The Cub3D project has been an exhilarating and educational journey, providing a meaningful hands-on experience in 3D game development and C programming. 

While the Cub3D project presented its share of challenges, the journey facilitated significant growth in my skills as a developer. I am excited to apply these newfound insights to future projects and continue exploring the vast realm of game development and low-level programming.

## Useful links

- https://harm-smits.github.io/42docs/libs/minilibx.html
- https://harm-smits.github.io/42docs/projects/cub3d


## Note:

- [**Coding Norm**](https://github.com/nunovaladao/42_cub3D/blob/main/extras/en_norm.pdf) - All students must follow the 42 code writing standards. This standard is applied to many projects in the course.
- 42's projects are made and designed to work on the school's computers, so it is possible that when testing it, it may give an unexpected error.
##
Nuno Valadão | nsoares-@student.42porto.com
