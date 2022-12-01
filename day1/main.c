#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define BUF_CAP 30

void part1(char *file_path) {
    FILE *f = NULL;
    char buf[BUF_CAP];
    int sum = 0, max = 0;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fgets(buf, BUF_CAP, f);

        if (buf[0] == '\n' || feof(f)) {
            sum = 0;
        } else {
            sum += atoi(buf);
            max = sum > max ? sum : max;
        }
    }

    printf("[p1] %s: %d\n", file_path, max);

end:
    fclose(f);
} 


void part2(char *file_path) {
    FILE *f = NULL;
    char buf[BUF_CAP];
    int sum = 0, t1 = 0, t2 = 0, t3 = 0;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fgets(buf, BUF_CAP, f);

        if (buf[0] == '\n' || feof(f)) {
            t3 = (sum > t2) ? t2 : ((sum > t3) ? sum : t3);
            t2 = (sum > t1) ? t1 : ((sum > t2) ? sum : t2);
            t1 = (sum > t1) ? sum : t1;
            sum = 0;

        } else {
            sum += atoi(buf);
        }
    }

    printf("[p2] %s: %d\n", file_path, t1+t2+t3);

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
