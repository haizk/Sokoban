# Sokoban Game

This is a command-line implementation of the classic Sokoban puzzle game, written in the C programming language.

## Gameplay

The objective of Sokoban is to push all the boxes ('X') onto the designated target locations ('$'). The player ('O') can only push one box at a time and cannot pull boxes. Walls ('#') obstruct movement.

Default game elements are represented by the following characters:
- Wall: `#`
- Target: `$`
- Box: `X`
- Box on Target: `Y`
- Player: `O`
- Player on Target: `@`
- Empty Space: ` ` (a space character)

## How to Play

Use the following keys to control the player and interact with the game:

- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right

Other commands:
- **R**: Restart the current level.
- **Z**: Undo the last move.
- **X**: Exit the current level and return to the level selector.

## Game Features

- **Levels:** The game includes 20 standard levels and 3 special, more challenging levels.
- **Hatoken System:** Earn "Hatoken" (in-game currency) by successfully completing levels. The amount of Hatoken earned depends on the level difficulty and your performance (number of moves).
- **Shop:** Use your Hatoken in the in-game shop to customize the appearance of various game elements, such as walls, targets, boxes, and the player character. This allows you to personalize your gaming experience.
- **Undo Functionality:** Made a wrong move? No problem! You can undo your last move using the 'Z' key.
- **Move Counter:** Keep track of your moves. The game displays the current number of moves for each level.
- **Secret Cheat Code:** There's a hidden cheat code (`0x0521030` in the main menu) to get extra Hatoken!

## Compilation and Execution

To compile and run the game, you'll need a C compiler (like GCC).

1.  **Compile the code:**
    Open your terminal or command prompt, navigate to the directory containing `Sokoban.c`, and run the following command:
    ```bash
    gcc Sokoban.c -o Sokoban
    ```
2.  **Run the game:**
    After successful compilation, an executable file named `Sokoban` (or `Sokoban.exe` on Windows) will be created. Run it with:
    ```bash
    ./Sokoban
    ```
    On Windows, you might run it as:
    ```bash
    Sokoban.exe
    ```

## Language

The in-game menus, prompts, and messages are primarily in **Indonesian**.
