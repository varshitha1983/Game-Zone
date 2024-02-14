#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int mazeSize = 10; // Adjust the maze size as needed

enum CellType {
    Empty,
    Wall,
    Start,
    Exit,
    Player
};

struct Position {
    int x;
    int y;
};

class MazeSolverGame {
private:
    vector<vector<CellType>> maze;
    Position playerPosition;

public:
    MazeSolverGame() {
        initializeMaze();
        placePlayer();
    }

    void initializeMaze() {
        maze.assign(mazeSize, vector<CellType>(mazeSize, Empty));

        // Set random walls
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < mazeSize * mazeSize / 4; ++i) {
            int x = rand() % mazeSize;
            int y = rand() % mazeSize;
            maze[y][x] = Wall;
        }

        // Set start and exit points
        maze[0][0] = Start;
        maze[mazeSize - 1][mazeSize - 1] = Exit;
    }

    void placePlayer() {
        playerPosition.x = 0;
        playerPosition.y = 0;
        maze[playerPosition.y][playerPosition.x] = Player;
    }

    void displayMaze() {
        for (int y = 0; y < mazeSize; ++y) {
            for (int x = 0; x < mazeSize; ++x) {
                switch (maze[y][x]) {
                    case Empty:
                        cout << ". ";
                        break;
                    case Wall:
                        cout << "# ";
                        break;
                    case Start:
                        cout << "S ";
                        break;
                    case Exit:
                        cout << "E ";
                        break;
                    case Player:
                        cout << "P ";
                        break;
                }
            }
            cout << endl;
        }
    }

    bool movePlayer(char direction) {
        int newX = playerPosition.x;
        int newY = playerPosition.y;

        switch (direction) {
            case 'U':
                newY--;
                break;
            case 'D':
                newY++;
                break;
            case 'L':
                newX--;
                break;
            case 'R':
                newX++;
                break;
            default:
                return false; // Invalid direction
        }

        if (newX >= 0 && newX < mazeSize && newY >= 0 && newY < mazeSize && maze[newY][newX] != Wall) {
            // Valid move
            maze[playerPosition.y][playerPosition.x] = Empty;
            playerPosition.x = newX;
            playerPosition.y = newY;
            maze[playerPosition.y][playerPosition.x] = Player;
            return true;
        } else {
            return false; // Invalid move
        }
    }

    bool isGameComplete() const {
        return playerPosition.x == mazeSize - 1 && playerPosition.y == mazeSize - 1;
    }
};

int main() {
    MazeSolverGame game;

    while (!game.isGameComplete()) {
        system("cls"); // Clear console (for Windows)
        game.displayMaze();

        cout << "Enter direction (U/D/L/R): ";
        char direction;
        cin >> direction;

        if (game.movePlayer(direction)) {
            if (game.isGameComplete()) {
                cout << "Congratulations! You reached the exit." << endl;
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}

