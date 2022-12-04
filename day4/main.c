#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUF_CAP 10

void part1(char *file_path) {
    FILE *f = NULL;
    int sum = 0;
    int sec[2][2] = {0};

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fscanf(f, "%d-%d,%d-%d\n", &sec[0][0], &sec[0][1], &sec[1][0], &sec[1][1]);

            // sec1 in sec0
        if ((sec[0][0] <= sec[1][0] && sec[0][1] >= sec[1][1]) || 
                // sec0 in sec1
                (sec[1][0] <= sec[0][0] && sec[1][1] >= sec[0][1])) {
            sum++;
        }
    }

    printf("[p1] %s: %d\n", file_path, sum);
end:
    fclose(f);
} 

void part2(char *file_path) {
    FILE *f = NULL;
    int sum = 0;
    int sec[2][2] = {0};

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fscanf(f, "%d-%d,%d-%d\n", &sec[0][0], &sec[0][1], &sec[1][0], &sec[1][1]);
        if (
                // Sec1 in Sec0
                ((sec[0][0] <= sec[1][0] && sec[1][0] <= sec[0][1]) ||
                 (sec[0][1] >= sec[1][1] && sec[1][1] >= sec[0][0]))||
                // Sec0 in Sec1
                ((sec[1][0] <= sec[0][0] && sec[0][0] <= sec[1][1]) ||
                 (sec[1][1] >= sec[0][1] && sec[0][1] >= sec[1][0]))) {
            sum++;
        }
    }

    printf("[p1] %s: %d\n", file_path, sum);
end:
    fclose(f);
} 

int main(int argc, char **argv) {
    if (argc < 1) {
        printf("Usage: %s [...sample_data]\n", argv[0]);
    } else {
        for (int i = 1; i < argc; ++i) {
            part1(argv[i]);
            part2(argv[i]);
        }
    }
}
