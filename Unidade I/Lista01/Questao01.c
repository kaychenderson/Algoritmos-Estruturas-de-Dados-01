// Questão 01: Quais serão os valores de x, y e p ao final do trecho de código abaixo:

int main (void) {
    int x, y, *p;
    y = 0;
    p = &y;
    x = &p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
}

// Resposta: x = 3, y = 4, p = &y 