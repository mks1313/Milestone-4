# Cub3D

## Description

**Cub3D** is a 3D engine project built using the **raycasting** technique, inspired by the classic "Wolfenstein 3D" game. This project aims to simulate a 3D world based on a 2D map, where the player can navigate through the environment.

The main goal of this project was to learn about **3D visualization**, **rendering**, and gain experience working with **C programming** to implement real-time graphics.

### Features:
- **Raycasting**: Implemented raycasting to generate 3D graphics from a 2D map.
- **Player Movement**: Player movement within the 3D world using `W`, `A`, `S`, `D` keys for walking and mouse control for rotation.
- **Textures**: Applied textures to walls and the ground.
- **Collision Handling**: A simple collision detection system to prevent the player from walking through walls.
- **2D to 3D Map**: The project takes a 2D map and renders a 3D world based on it.

## Installation

### Prerequisites

Make sure you have the following installed:
- **C Compiler**: Use `gcc` or any compatible C compiler.
- **SDL2**: SDL2 library for graphical rendering and user input.

### Installation Steps

1. **Clone the repository**:

    ```bash
    git clone https://github.com/your_username/Cub3D.git
    ```

2. **Install SDL2 dependencies**:

   For **Ubuntu** or **Debian** users:

    ```bash
    sudo apt-get update
    sudo apt-get install libsdl2-dev
    ```

   For **MacOS** users with **Homebrew**:

    ```bash
    brew install sdl2
    ```

3. **Navigate to the Cub3D directory**:

    ```bash
    cd Cub3D
    ```

4. **Compile the project**:

    ```bash
    make
    ```

5. **Run the project**:

    ```bash
    ./cub3d map.cub
    ```

    - Make sure the `map.cub` file is present, or use one of the example maps.

## Usage

- **Movement**: Use the `W`, `A`, `S`, `D` keys to move the player in the 3D world.
- **Rotation**: Move the mouse to rotate the player's view.
- **Exit**: Press the `Esc` key to exit the game.

## Technologies Used

- **C**: The main programming language for building the 3D engine.
- **SDL2**: Graphics library used for rendering and handling user input.
- **Raycasting**: Technique used to render 3D graphics from a 2D map.
- **Mathematics for 3D Graphics**: Used to calculate projections and interactions with walls.

## Contributing

1. Fork this project.
2. Create a new branch for your feature (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push the branch (`git push origin feature-name`).
5. Open a Pull Request.

## License

This project is licensed under the **MIT License**. See [LICENSE](./LICENSE) for more details.
