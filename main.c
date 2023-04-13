#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16
#define MIN_SCORE 60.0

#define TOOSHORT "TOOSHORT "
#define TOOLONG "TOOLONG "
#define NOALNUM "NOALNUM "
#define NOUPPER "NOUPPER "
#define NOPUNCT "NOPUNCT "
#define INVALID "INVALID "
#define STRONG "STRONG "
#define WEAK "WEAK "

int main() {
    int score = 0, count = 0;
    char password[50];
    for (count = 1; count <= 3 && fgets(password, sizeof(password), stdin); count++) {
        if (*password == '\n' || *password == '\r' || *password == ' ') {
            continue;
        }
        int sifre_uzunluk = 0, buyukharf = 0, gecerli = 0, ozelkarakter = 0, valid = 1, cokuzun = 0;
        char* p = password;
        while (*p && *p != '\n') {
            if (!isalnum(*p) && !isspace(*p) && !ispunct(*p)) {
                printf(INVALID);
                valid = 0;
            }
            if (isupper(*p)) {
                buyukharf = 1;
            }
            if (isalnum(*p)) {
                gecerli = 1;
            }
            if (ispunct(*p)) {
                ozelkarakter = 1;
            }
            ++sifre_uzunluk;
            ++p;
        }
        if (sifre_uzunluk > MAX_LENGTH && !buyukharf && !ozelkarakter && valid) {
            printf("%s%s%s", TOOLONG, NOUPPER, NOPUNCT);
            valid = 0;
        }
        else {
            if (cokuzun != 0 && valid) {
                printf(TOOLONG);
                valid = 0;
            }
            if (sifre_uzunluk < MIN_LENGTH && valid) {
                printf(TOOSHORT);
                valid = 0;
            }
            if (!gecerli && valid) {
                printf(NOALNUM);
                valid = 0;
            }
            if (!buyukharf && valid) {
                printf(NOUPPER);
                valid = 0;
            }
            if (!ozelkarakter && valid) {
                printf(NOPUNCT);
                valid = 0;
            }
            if (valid) {
                score += (int)(6.55 * sifre_uzunluk);
                if (score >= MIN_SCORE) {
                    printf(STRONG);
                }
                else {
                    printf(WEAK);
                }
            }
        }

        if (count != 3) {
            printf("\r\n");
        }
        //printf("sayac -> %d", count);
    }
    if (score >= MIN_SCORE) {
        return EXIT_SUCCESS;
    }
  return EXIT_FAILURE;
}
