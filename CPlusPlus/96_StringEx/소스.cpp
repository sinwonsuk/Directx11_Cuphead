//#include <iostream>
//#include <math.h>
//
//using namespace std;

//int main() {
//	// 타원의 중심점을 설정합니다.
//	double x = -1;
//	double y = 1;
//
//	// 타원의 축을 설정합니다.
//	double a = 5;
//	double b = 1;
//
//	// 타원을 회전할 각도를 설정합니다.
//	double angle = 2;
//
//	// 타원을 회전합니다.
//	double x_new = x * cos(angle) - y * sin(angle);
//	double y_new = x * sin(angle) + y * cos(angle);
//
//	// 타원의 새로운 중심점을 출력합니다.
//	cout << "The new center of the ellipse is (" << x_new << ", " << y_new << ")." << endl;
//
//	return 0;
//
//
//
//
//}

#include <iostream>
#include <vector>

using namespace std;

// 테트리스 블록의 모양
#include <iostream>
#include <vector>

using namespace std;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

int board[BOARD_WIDTH][BOARD_HEIGHT];

vector<int> blocks;

void init() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            board[i][j] = 0;
        }
    }

    blocks.push_back(0);
    blocks.push_back(1);
    blocks.push_back(2);
    blocks.push_back(3);
    blocks.push_back(4);
    blocks.push_back(5);
    blocks.push_back(6);
    blocks.push_back(7);
    blocks.push_back(8);
    blocks.push_back(9);
}

void draw() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            cout << board[j][i];
        }
        cout << endl;
    }
}

void move(int dx, int dy) {
    for (int i = 0; i < blocks.size(); i++) {
        blocks[i] += dx;
    }
}

void rotate() {
    vector<int> new_blocks;
    for (int i = 0; i < blocks.size(); i++) {
        new_blocks.push_back(blocks[blocks.size() - 1 - i]);
    }
    blocks = new_blocks;
}

bool check_collision() {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i] < 0 || blocks[i] >= BOARD_WIDTH) {
            return true;
        }
        if (board[blocks[i]][blocks[i + blocks.size() - 1]] != 0) {
            return true;
        }
    }

    return false;
}

void drop() {
    while (!check_collision()) {
        for (int i = 0; i < blocks.size(); i++) {
            blocks[i]++;
        }
    }
}

int main() {
    init();

    while (true) {
        draw();

        int key = getchar();

        if (key == 'a') {
            move(-1, 0);
        }
        else if (key == 'd') {
            move(1, 0);
        }
        else if (key == 's') {
            drop();
        }
        else if (key == 'w') {
            rotate();
        }

        if (check_collision()) {
            break;
        }
    }

    return 0;
}