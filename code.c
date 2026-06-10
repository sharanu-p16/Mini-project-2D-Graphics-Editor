#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 20
#define COLS 50
#define MAX_SHAPES 50

typedef struct {
    int id;
    int type;
    int active;
    int x, y;
    int val1, val2;
} Shape;

char canvas[ROWS][COLS];
Shape memory[MAX_SHAPES];
int totalShapes = 0;
int nextId = 1;

void clearCanvas() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("\n=== 2D TEXT GRAPHICS EDITOR ===\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
    printf("\n===============================\n");
}

void plot(int x, int y) {
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        canvas[y][x] = '*';
    }
}

void drawRectangle(int startX, int startY, int width, int height) {
    for (int y = startY; y < startY + height; y++) {
        for (int x = startX; x < startX + width; x++) {
            plot(x, y);
        }
    }
}

void drawLine(int startX, int startY, int length) {
    for (int i = 0; i < length; i++) {
        plot(startX + i, startY);
    }
}

void drawTriangle(int startX, int startY, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x <= y; x++) {
            plot(startX + x, startY + y);
        }
    }
}

void drawCircle(int cx, int cy, int r) {
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            double dx = (x - cx) * 0.55;
            double dy = (y - cy);
            if ((dx * dx) + (dy * dy) <= (r * r)) {
                plot(x, y);
            }
        }
    }
}

void repaintAllShapes() {
    clearCanvas();
    for (int i = 0; i < totalShapes; i++) {
        if (memory[i].active == 1) {
            if (memory[i].type == 1) drawRectangle(memory[i].x, memory[i].y, memory[i].val1, memory[i].val2);
            if (memory[i].type == 2) drawLine(memory[i].x, memory[i].y, memory[i].val1);
            if (memory[i].type == 3) drawTriangle(memory[i].x, memory[i].y, memory[i].val1);
            if (memory[i].type == 4) drawCircle(memory[i].x, memory[i].y, memory[i].val1);
        }
    }
}

int main() {
    int choice;
    while (1) {
        repaintAllShapes();
        displayCanvas();

        printf("1. Draw Rectangle | 2. Draw Line | 3. Draw Triangle | 4. Draw Circle | 5. Delete | 6. Exit\n");
        printf("Enter Choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice >= 1 && choice <= 4) {
            Shape s;
            s.id = nextId++;
            s.type = choice;
            s.active = 1;
            
            if (choice == 1) printf("Enter X, Y, Width, Height: "), scanf("%d %d %d %d", &s.x, &s.y, &s.val1, &s.val2);
            else if (choice == 2) printf("Enter Start X, Y, Length: "), scanf("%d %d %d", &s.x, &s.y, &s.val1);
            else if (choice == 3) printf("Enter Top X, Y, Height: "), scanf("%d %d %d", &s.x, &s.y, &s.val1);
            else if (choice == 4) printf("Enter Center X, Y, Radius: "), scanf("%d %d %d", &s.x, &s.y, &s.val1);
            
            memory[totalShapes++] = s;
        } else if (choice == 5) {
            printf("\n--- ACTIVE SHAPES ---\n");
            for(int i = 0; i < totalShapes; i++) {
                if(memory[i].active == 1) printf("ID %d: Type %d\n", memory[i].id, memory[i].type);
            }
            int targetId;
            printf("Enter ID to delete: ");
            scanf("%d", &targetId);
            for(int i = 0; i < totalShapes; i++) {
                if(memory[i].id == targetId) memory[i].active = 0;
            }
        } else if (choice == 6) {
            break;
        }
    }
    return 0;
}