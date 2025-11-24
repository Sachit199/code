#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  20
#define HEIGHT 10

// Snake head position
int sx, sy;
// Food position
int fx, fy;
// Score
int score = 0;

// Create new random food position
void new_food() {
    fx = rand() % WIDTH;
    fy = rand() % HEIGHT;
}

// Draw the game area
void draw() {
    system("cls");  // for Windows; on Linux use "clear"

    // top border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    // middle area
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            if (x == 0) printf("#");  // left border

            if (x == sx && y == sy) {
                printf("O");        // snake head
            } else if (x == fx && y == fy) {
                printf("*");        // food
            } else {
                printf(" ");
            }

            if (x == WIDTH - 1) printf("#"); // right border
        }
        printf("\n");
    }

    // bottom border
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

    printf("Score: %d\n", score);
    printf("Use W A S D to move, X to exit.\n");
}

// Handle user input and move snake
int update() {
    char c;

    printf("Move: ");
    c = getchar();
    // eat extra '\n'
    if (c == '\n') {
        return 1;
    }

    if (c == 'x' || c == 'X') {
        return 0;  // end game
    }

    if (c == 'w' || c == 'W') sy--;
    else if (c == 's' || c == 'S') sy++;
    else if (c == 'a' || c == 'A') sx--;
    else if (c == 'd' || c == 'D') sx++;

    // check wall collision
    if (sx < 0 || sx >= WIDTH || sy < 0 || sy >= HEIGHT) {
        printf("Game Over! You hit the wall.\n");
        return 0;
    }

    // check food eat
    if (sx == fx && sy == fy) {
        score += 10;
        new_food();
    }

    // clear input buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    return 1; // continue game
}

int main() {
    srand(time(NULL));

    // starting snake position (middle)
    sx = WIDTH / 2;
    sy = HEIGHT / 2;

    new_food();

    int running = 1;
    while (running) {
        draw();
        running = update();
    }

    printf("Final score = %d\n", score);
    return 0;
}
