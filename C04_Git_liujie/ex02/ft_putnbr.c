
#include <unistd.h>

// Calculate the number of digits in an integer (handle negative numbers)
int calc_digits(int nb) {
    int digits = 0;
    if (nb == 0) return 1;  // Special case for zero
    if (nb < 0) nb = -nb;   // Handle negative numbers
    while (nb > 0) {
        nb /= 10;
        digits++;
    }
    return digits;
}

// Convert an integer to a string
void itos(int nb, char *str) {
    int is_negative = 0;
    int len;

    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    if (nb < 0) {
        is_negative = 1;
        nb = -nb;
    }

    len = calc_digits(nb);
    str[len + is_negative] = '\0';

    while (nb > 0) {
        str[--len + is_negative] = (nb % 10) + '0';
        nb /= 10;
    }

    if (is_negative) {
        str[0] = '-';
    }
}

// Print an integer using write
void ft_putnbr(int nb) {
    char str[12];  // Enough to hold an integer string including negative sign

    // Convert integer to string
    itos(nb, str);

    // Write the string to standard output
    for (int i = 0; str[i] != '\0'; i++) {
        write(1, &str[i], 1);
    }
}

int main() {
    int number = -12345;
    ft_putnbr(number);
    write(1, "\n", 1);  // Newline for readability

    return 0;
}
