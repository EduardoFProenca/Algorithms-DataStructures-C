#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct {int num, den;} TRac;
/* Prototipos das funcoes */
TRac SomaRac(TRac, TRac);
TRac SubtraiRac(TRac, TRac);
TRac MultRac(TRac, TRac);
TRac DivRac(TRac, TRac);
TRac SimplRac(TRac);
int mdc(int, int);
int main(void)
{    TRac X, Y, R, b;
    int QuatTest , i;
    char sinal;

    scanf(" %d", &QuatTest);

    TRac Resultado[QuatTest];
    TRac ResultadoSimpl[QuatTest];

    if (1 <= QuatTest && 10000 >= QuatTest)
    for ( i = 0; i < QuatTest; i++ ){
        scanf("%d / %d %c %d / %d", &X.num, &X.den, &sinal, &Y.num, &Y.den);

        switch(sinal){
            case '+':
                R = SomaRac(X, Y);    
            break;

            case '-':
                R = SubtraiRac(X, Y);    
            break;

            case '*':
                R = MultRac(X, Y);        
            break;

            case '/':
                R = DivRac(X, Y);
            break;

            default: 
            return 1;
        }
        b = R;
        Resultado [i] = R ;
        ResultadoSimpl [i] = SimplRac(b);        

        }
    for (int i = 0;i < QuatTest; i++  ){
        printf("%d/%d = %d/%d\n", Resultado[i].num, Resultado[i].den, 
               ResultadoSimpl[i].num, ResultadoSimpl[i].den);            
    }

    return 0;
}
TRac SomaRac(TRac n1, TRac n2)
{    TRac res;
    res.num = n1.num * n2.den + n2.num * n1.den;
    res.den = n1.den * n2.den;

    return res;
}
TRac SubtraiRac(TRac n1, TRac n2)
{    TRac res;
    res.num = n1.num * n2.den - n2.num * n1.den;
    res.den = n1.den * n2.den;

    return res;
}
TRac MultRac(TRac n1, TRac n2)
{    TRac res;
    res.num = n1.num * n2.num;
    res.den = n1.den * n2.den;

    return res;
}
TRac DivRac(TRac n1, TRac n2)
{    TRac res;
    res.num = n1.num * n2.den;
    res.den = n2.num * n1.den;

    return res;
}
TRac SimplRac(TRac n1)
{    TRac res;
    res.num = n1.num / mdc(n1.num, n1.den);
    res.den = n1.den / mdc(n1.num, n1.den);

    return res;
}
int mdc(int m, int n)
{    if (m < 0) m = -m;
    if (n < 0) n = -n;
    if (m % n == 0)
        return n;
    else
        return mdc(n, m % n);
}