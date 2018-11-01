#define MAINH
#include <functions.h>
#include <ctype.h>

void getstate(char *initstate);

int main(int argc, char **argv)
{
    printf("Пожалуйста введите начальное состояние в виде\n\
            N N N\n\
            0 N N\n\
            N N N\n\n\
            Где 'N' - цифра от 1 до 8, '0' должен соответствовать\n\
            положению пустой клетки\n\n");

    char state[9];
    getstate(state);
    stptr index, hit;
    goeptr root = buildss(state, &index);
    printf("Пожалуйста введите конечное состояние:\n");
    getstate(state);
    if (attach(index, get_s_code(state), &hit))
        solve (hit->adr, root);
    else
        printf("Данное состояние не достижимо из начального!!!");
    treedelete(index);
    return 0;
}

void getstate(char *initstate)
{
    char t = 0, i = 0;
//    while(t = getchar())
//        if (isdigit(t)) {
//            putc(t, stdin);
//            break;
//        }
    while ((t = getc(stdin)) && (i < 9)) {
        if ((' ' != t) && ('\n' != t))
            initstate[i++] = t - '0';
    }
}
            
