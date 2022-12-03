#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_CAP 127

int in(char a, char *b) {
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == a) {
            return 1;
        }
    }
    return 0;
}

void part1(char *file_path) {
    FILE *f = NULL;
    char buf[BUF_CAP];
    char r1[BUF_CAP / 2], r2[BUF_CAP / 2];
    int i, sum = 0;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    while (!feof(f)) {
        fgets(buf, BUF_CAP, f);

        if (!feof(f)) {
            buf[strcspn(buf, "\n")] = 0;

            memset(r1, 0, BUF_CAP / 2);
            memset(r2, 0, BUF_CAP / 2);

            for (i = 0; i < strlen(buf) / 2; ++i) {
                r1[i] = buf[i];
                r2[i] = buf[i + strlen(buf) / 2];
            }

            for (i = 0; i < strlen(r1); ++i) {
                if (in(r1[i], r2)) {
                    sum += ('Z' >= r1[i]   ? r1[i] - ('A' - 1) + 26
                            : 'a' <= r1[i] ? r1[i] - ('a' - 1)
                            : 0);
                    break;
                }
            }
        }
    }

    printf("[p1] %s: %d\n", file_path, sum);

end:
    fclose(f);
}

void part2(char *file_path) {
    FILE *f = NULL;
    char g[3][BUF_CAP];
    int c, i, j, sum = 0;

    f = fopen(file_path, "r");
    if (f == NULL) {
        fprintf(stderr, "[!] Error opening file: %s\n", strerror(errno));
        goto end;
    }

    i = 0;
    while (!feof(f)) {
        fgets(g[i], BUF_CAP, f);
        g[i][strcspn(g[i], "\n")] = 0;

        if (!feof(f)) {
            if (i == 2) {
                i = 0;

                for (j = 0; j < strlen(g[0]); j++) {
                    c = g[0][j];
                    if (in(c, g[1]) && in(c, g[2])) {
                        break;
                    }
                }

                sum += ('Z' >= c ? c - ('A' - 1) + 26 : 'a' <= c ? c - ('a' - 1) : 0);
            } else {
                i++;
            }
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
