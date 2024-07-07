#include <stdio.h>

#define MAX_R 31

int count_numbers_with_restrictions(int r) {
    if (r == 0) {
        return 0;
    }

    int dp[MAX_R][4] = {0};


    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    for (int i = 2; i <= r; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][3];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][0];
        dp[i][3] = dp[i - 1][1];
    }


    int result = dp[r][0] + dp[r][1] + dp[r][2] + dp[r][3];
    return result;
}

int main() {
    int r;
    printf("������ �������� �: ");
    scanf("%d", &r);

    if (r <= 0 || r > 30) {
        printf("�������� � ������� ���� �� 1 �� 30.\n");
        return 1;
    }

    int result = count_numbers_with_restrictions(r);
    printf("ʳ������ ����� �� %d �������: %d\n", r, result);
    return 0;
}

