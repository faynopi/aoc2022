#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUF_CAP 10

void part1(char *file_path) {
    FILE *f = NULL;
    char buf[BUF_CAP];
    int sum = 0;
    int p2, p2s;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fgets(buf, BUF_CAP, f);

        p2 = buf[2];
        p2s = 0;

        if (!feof(f)) {
            switch (buf[0]) {
                case 'A': // rock
                    p2s += (p2 == 'X' ? 3 : (p2 == 'Z' ? 0 : 6 ));
                    break;
                case 'B': // paper
                    p2s += (p2 == 'Y' ? 3 : (p2 == 'X' ? 0 : 6 ));
                    break;
                case 'C': // scissor
                    p2s += (p2 == 'Z' ? 3 : (p2 == 'Y' ? 0 : 6 ));
                    break;
            }
            p2s += (p2 == 'X' ? 1 : (p2 == 'Y' ? 2 : 3));
            sum += p2s;
        }
    }

    printf("[p1] %s: %d\n", file_path, sum);

end:
    fclose(f);
} 

void part2(char *file_path) {
    FILE *f = NULL;
    char buf[BUF_CAP];
    int sum = 0;
    int p2, p2s;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fgets(buf, BUF_CAP, f);

        p2 = buf[2];
        p2s = 0;

        if (!feof(f)) {
            p2s = (p2 == 'X' ? 0 : (p2 == 'Y' ? 3 : 6 ));

            switch (buf[0]) {
                case 'A': // rock
                    p2 = (p2 == 'X' ? 'Z' : (p2 == 'Y' ? 'X' : 'Y' ));
                    break;
                case 'B': // paper
                    p2 = (p2 == 'X' ? 'X' : (p2 == 'Y' ? 'Y' : 'Z' ));
                    break;
                case 'C': // scissor
                    p2 = (p2 == 'X' ? 'Y' : (p2 == 'Y' ? 'Z' : 'X' ));
                    break;
            }

            p2s += (p2 == 'X' ? 1 : (p2 == 'Y' ? 2 : 3));
            sum += p2s;
        }
    }

    printf("[p2] %s: %d\n", file_path, sum);

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
