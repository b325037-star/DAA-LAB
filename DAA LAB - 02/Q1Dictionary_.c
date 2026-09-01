
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SAMPLES 10
#define WIDTH 900
#define HEIGHT 600

typedef struct Node {
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

// Time measurements storage
double time_unsorted_array[MAX_SAMPLES];
double time_sorted_array[MAX_SAMPLES];
double time_unsorted_dll[MAX_SAMPLES];
double time_sorted_dll[MAX_SAMPLES];
int sizes[MAX_SAMPLES];

void benchmark(int idx, int n) {
    sizes[idx] = n;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = rand() % (n * 10);

    // 1. Unsorted Array Search
    double start = GetTime();
    for (int k = 0; k < 1000; k++) {
        int target = rand() % (n * 10);
        for (int i = 0; i < n; i++) {
            if (arr[i] == target) break;
        }
    }
    time_unsorted_array[idx] = (GetTime() - start) * 1000.0;

    // 2. Sorted Array Binary Search
    int *sarr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) sarr[i] = i * 2;
    start = GetTime();
    for (int k = 0; k < 1000; k++) {
        int target = rand() % (n * 10);
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sarr[mid] == target) break;
            if (sarr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }
    time_sorted_array[idx] = (GetTime() - start) * 1000.0;

    free(arr);
    free(sarr);
}

int main(void) {
    srand(42);
    for (int i = 0; i < MAX_SAMPLES; i++) {
        benchmark(i, (i + 1) * 2000);
    }

    InitWindow(WIDTH, HEIGHT, "Dictionary Search Operations - Order of Growth");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Search Operation Execution Time vs N", 220, 20, 20, DARKGRAY);
        
        // Draw Axes
        DrawLine(80, 500, 820, 500, BLACK); // X axis
        DrawLine(80, 100, 80, 500, BLACK); // Y axis

        DrawText("Input Size (N)", 420, 530, 16, BLACK);
        DrawText("Time (ms)", 15, 280, 16, BLACK);

        // Legend
        DrawRectangle(650, 80, 15, 15, RED);
        DrawText("Unsorted Array O(N)", 675, 80, 14, BLACK);
        DrawRectangle(650, 105, 15, 15, BLUE);
        DrawText("Sorted Array O(log N)", 675, 105, 14, BLACK);

        // Plot Points and Lines
        for (int i = 0; i < MAX_SAMPLES - 1; i++) {
            float x1 = 80 + (i * 70);
            float x2 = 80 + ((i + 1) * 70);

            // Scale Y values
            float y1_unsorted = 500 - (float)(time_unsorted_array[i] * 10.0);
            float y2_unsorted = 500 - (float)(time_unsorted_array[i + 1] * 10.0);
            
            float y1_sorted = 500 - (float)(time_sorted_array[i] * 10.0);
            float y2_sorted = 500 - (float)(time_sorted_array[i + 1] * 10.0);

            DrawLineEx((Vector2){x1, y1_unsorted}, (Vector2){x2, y2_unsorted}, 2.5f, RED);
            DrawLineEx((Vector2){x1, y1_sorted}, (Vector2){x2, y2_sorted}, 2.5f, BLUE);

            DrawCircle(x1, y1_unsorted, 4, RED);
            DrawCircle(x1, y1_sorted, 4, BLUE);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}