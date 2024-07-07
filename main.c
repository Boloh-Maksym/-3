#include <stdio.h>

int count_equal_divisors(int n) {
    int count = 0;
    
    for (int m = 1; m < n; m++) {
        if (n / m == n % m) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n;
    printf("Введіть натуральне число n: ");
    scanf("%d", &n);
    
    if (n <= 1 || n >= 150) {
        printf("Значення n повинно бути від 2 до 149.\n");
        return 1;
    }
    
    int result = count_equal_divisors(n);
    printf("Кількість рівних дільників числа %d: %d\n", n, result);
    
    return 0;
}
