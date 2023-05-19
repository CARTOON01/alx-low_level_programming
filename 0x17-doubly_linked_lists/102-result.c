#include <stdio.h>

int isPalindrome(int number) {
    int originalNumber = number;
    int reverseNumber = 0;

    while (number != 0) {
        int remainder = number % 10;
        reverseNumber = reverseNumber * 10 + remainder;
        number /= 10;
    }

    return (originalNumber == reverseNumber);
}

int main() {
    int largestPalindrome = 0;

    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int product = i * j;
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }

    FILE *file = fopen("102-result", "w");
    if (file != NULL) {
        fprintf(file, "%d", largestPalindrome);
        fclose(file);
    }

    return 0;
}
