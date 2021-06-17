/*********
 * 作者 吳庭華
 * 日期 2021/6/17
 * 題目 走迷宮
 * 班級 資一乙
*********/


#include <iostream>
#include <time.h>
#include <conio.h>

class Maze {
private:
    int playerX = 1;
    int playerY = 1;
    int max = 0;
    int maxXY[2];
    std::string map[11][11];
    int list[4][2] = {{2,0},{0,2},{-2,0},{0,-2}};
    void generate(int x, int y, int index) {
        map[x][y] = "1";
        if (max < index) {
            max = index;
            maxXY[0] = x;
            maxXY[1] = y;
        }
        int number = 0;
        int data;
        int ok[4];
        while (true) {
            bool inside = false;
            data = rand() % 4;

            for (int i = 0; i < 4; i++) {
                if (data == ok[i]) {
                    inside = true;
                    break;
                }
            }
            if (!inside) {
                number++;
                ok[number] = data;
                go(list[data], x, y, index);
            }
            if (number == 3) break;
        }
    }
    void go(int data[2], int x, int y, int index) {
        if (
                x + data[0] > 0 &&
                x + data[0] < 10 &&
                y + data[1] > 0 &&
                y + data[1] < 10
        ) {
            if (map[x + data[0]][y + data[1]] == "0") {
                map[x+data[0]/2][y+data[1]/2] = "1";
                x += data[0];
                y += data[1];
                generate(x, y, index + 1);
            }
        }
    }
public:
    bool clearance = false;

    Maze() {
        srand( time(NULL) );
        for (int x = 0; x < 11; x++) {
            for (int y = 0; y < 11; y++) {
                map[x][y] = "0";
            }
        }
        generate(1, 1, 1);
        map[maxXY[0]][maxXY[1]] = "3";
        print();
    }

    void print() {
        system("cls");
        std::cout << "q quit w top s bottom a left d right" << std::endl;
        std::cout << "1 road 2 player 3 end 0 wall" << std::endl;
        for (int x = 0; x < 11; x++) {
            for (int y = 0; y < 11; y++) {
                if (x == playerX && y == playerY) std::cout << "2";
                else std::cout << map[x][y];
            }
            std::cout << '\n';
        }
    }

    void play(int x, int y) {
        if (map[playerX + x][playerY + y] == "1") {
            playerY += y;
            playerX += x;
            print();
        } else if (map[playerX + x][playerY + y] == "0") {
            std::cout << "Hit the wall" << '\n';
        } else if (map[playerX + x][playerY + y] == "3") {
            clearance = true;
        }
    }
};

int main() {
    Maze maze = Maze();
    while (true) {
        int userInput = getch();
        if (userInput == 113) break;
        if (userInput == 119) {
            maze.play(-1, 0);
        } else if (userInput == 100) {
            maze.play(0, 1);
        } else if (userInput == 97) {
            maze.play(0, -1);
        } else if (userInput == 115) {
            maze.play(1, 0);
        }
        if (maze.clearance) {
            std::cout << "Clearance" << std::endl;
            break;
        }
    }
    return 0;
}
