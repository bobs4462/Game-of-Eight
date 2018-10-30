#define MAINH
#include <eight.h>

void get_init_state(char *initstate);

int main(int argc, char **argv)
{
    printf("Пожалуйста введите начальное состояние в виде\n""\
            N N N\n\
            * N N\n\
            N N N\n\n\
            Где 'N' - цифра от 1 до 8, '*' должен соответствовать\n\
            положению пустой клетки\n\n");

    char initstate[9];
    get_init_state(initstate);
    goeptr root = buildss(initstate);
}

void get_init_state(char *initstate)
{
    char t = 0, i = 0;
    while ((t = getc(stdin)) && (i < 9)) {
        if ('*' == t)
            initstate[i++] = '\0';
        else if ((' ' != t) && ('\n' != t))
            initstate[i++] = t - '0';
    }
}
            
