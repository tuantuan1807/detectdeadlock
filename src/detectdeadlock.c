#include <stdio.h>
#include <stdlib.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() {
    printf("===== Deadlock Detection =====\n");
    input();
    show();
    cal();
    return 0;
}

void input() {
    int i, j;
    printf("Nhap so tien trinh (Process): ");
    scanf("%d", &n);
    printf("Nhap so luong tai nguyen (Resource): ");
    scanf("%d", &r);
    printf("Nhap ma tran Max:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Nhap ma tran Allocation:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Nhap Available Resources:\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("Process\t Allocation\t Max\t Available\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t ", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0) {
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void cal() {
    int finish[100], temp, flag = 1, k, c1 = 0;
    int dead[100];
    int i, j;

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    // Tính ma trận Need
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            int can_be_processed = 1;
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        can_be_processed = 0;
                        break;
                    }
                }
                if (can_be_processed) {
                    for (j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
    }

    int deadlock = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            dead[deadlock++] = i;
        }
    }

    if (deadlock > 0) {
        printf("\n\nHe thong co Deadlock va cac tien trinh Deadlock la:\n");
        for (i = 0; i < deadlock; i++) {
            printf("P%d\t", dead[i] + 1);
        }
    } else {
        printf("\nKhong co Deadlock");
    }
}
