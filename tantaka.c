#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 状態を管理する識別子 */
enum state {
        STATE_START,    /* 始状態 */
        STATE_TA,       /* タ */
        STATE_XN,       /* ン */
        STATE_KA,       /* カ */
        STATE_ME,       /* メ */
        STATE_END,      /* 終状態 */
        STATE_MAX       /* 状態の数 */
};

/** 推移行列 */
static const double
stab[STATE_MAX][STATE_MAX] = {
        /* 始    タ    ン    カ    メ    終 */
        { 0/1., 1/1., 0/1., 0/1., 0/1., 0/1. }, /* 始状態 */
        { 0/1., 0/1., 5/6., 1/6., 0/1., 0/1. }, /* タ */
        { 0/1., 2/3., 0/1., 0/1., 1/6., 1/6. }, /* ン */
        { 0/1., 1/1., 0/1., 0/1., 0/1., 0/1. }, /* カ */
        { 0/1., 0/1., 1/1., 0/1., 0/1., 0/1. }, /* メ */
        { 0/1., 0/1., 0/1., 0/1., 0/1., 1/1. }, /* 終状態 */
};

/** 状態に対応する文字の表 */
static const char *
ctab[STATE_MAX] = {
        "", "タ", "ン", "カ", "メ", "",
};

/** 手っ取り早く [0, 1) の一様分布の乱数を生成する関数 */
static double
urand(void)
{
        return rand() / (RAND_MAX + 1.0);
}

int
main(void)
{
        /** 現在の状態、次の状態 */
        enum state current, next;
        /** 遷移先を決めるための変数 */
        double tmp;

        srand((unsigned)time(NULL));
        current = STATE_START;
        do {
                (void)printf("%s", ctab[current]);
                tmp = urand();
                for (next = STATE_START; tmp > stab[current][next]; next++)
                        tmp -= stab[current][next];
                current = next;
        } while (current != STATE_END);
        (void)printf("\n");

        return 0;
}
