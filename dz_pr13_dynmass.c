#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

double* full_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
int copy_skip4(double* src, int n, double* dst, int k);

int main(void)
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(NULL));

    double* a, * b, * c, * d;
    int n, m, l, h;

    printf("Размер массива a > ");
    scanf_s("%d", &n);
    printf("Размер массива b > ");
    scanf_s("%d", &m);
    printf("Размер массива c > ");
    scanf_s("%d", &l);

    a = (double*)malloc(n * sizeof(double));
    b = (double*)malloc(m * sizeof(double));
    c = (double*)malloc(l * sizeof(double));
    d = (double*)malloc((n + m + l) * sizeof(double));
    if (a == NULL || b == NULL || c == NULL || d == NULL)
    {
        puts("error");
        return -1;
    }

    full_elements(a, n);
    full_elements(b, m);
    full_elements(c, l);

    printf("\nМассив a:\n");
    put_elements(a, n);
    printf("Массив b:\n");
    put_elements(b, m);
    printf("Массив c:\n");
    put_elements(c, l);

    h = 0;
    h = copy_skip4(a, n, d, h);
    h = copy_skip4(b, m, d, h);
    h = copy_skip4(c, l, d, h);

    printf("\nМассив d (без каждого 4-го элемента массивов):\n");
    put_elements(d, h);

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}


double* full_elements(double* ptr_array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        ptr_array[i] = -1 + 2.0 * rand() / RAND_MAX;
    return ptr_array;
}

int put_elements(double* ptr_array, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%8.2f", ptr_array[i]);
    printf("\n");
    return size;
}


int copy_skip4(double* src, int n, double* dst, int k)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if ((i + 1) % 4 != 0)
        {
            dst[k] = src[i];
            k++;
        }
    }
    return k;
}