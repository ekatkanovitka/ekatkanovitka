#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void prog (double*a,int n,int m);
void print_matrix(double*a,int n,int m);
void change (double*a,int n,int m,int i,int j);
double sum (double*a,int n,int m,int i);

double sum (double*a,int n,int m,int j)
{
    double s = 0;
    int i;
    for (i = 0;i<n;i++)
    {
        s+=a[i*m+j];
    }

    return s;
}

void change (double*a,int n,int m,int i,int j)
{
    int k;
    double t;
    for (k =0;k<m;k++)
    {
        t = a[i*m+k];
        a[i*m+k] = a[j*m+k];
        a[j*m+k] = t;
    }
    n = n;
}

void print_matrix(double*a,int n,int m)
{
    int i,j;
    for (i = 0;i<n;i++)
    {
        for (j = 0;j<m;j++)
        {
            printf ("%lf   ",a[i*m+j]);
        }
        printf ("\n");
    }
}

void prog (double*a,int n,int m)
{
    int j;
    int flag = 1;
    while (flag==1)
    {
        flag = 0;
        for (j = 0;j<m-1;j++)
        {
            if (sum(a,n,m,j)>sum(a,n,m,j+1))
            {
                change (a,n,m,j,j+1);
                flag = 1;
            }
        }
    }
}

int main(void)
{
    double*a;
    int n,m,i,j;
    FILE*f;
    f = fopen ("file.txt","r");
    if (f == NULL)
    {
        return -1;
    }

    if (fscanf(f,"%d",&n)!=1)
    {
        fclose(f);
        return -1;
    }
    if (fscanf(f,"%d",&m)!=1)
    {
        fclose(f);
        return -1;
    }

    if (n<=0)
    {
        fclose(f);
        return -1;
    }
    if (m<=0)
    {
        fclose(f);
        return -1;
    }

    printf ("n = %d, m = %d\n",n,m);

    printf ("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrz");

    a = (double*)malloc(n*m*sizeof(double));

    printf ("rhhfjhjddsz");

    if (a == NULL)
    {
        fclose (f);
        return -1;

    }

    printf ("tttttttttthz");

    for (i = 0;i<n;i++)
    {
        for (j = 0;j<m;j++)
        {
            if (fscanf(f,"%lf",&(a[i*m+j]))!=1)
            {
                fclose(f);
                free(a);
                return -1;
            }
        }
    }
    printf ("rhz");
    prog(a,n,m);
    printf ("rozzzzz");
    print_matrix(a,n,m);
    fclose(f);
    free(a);
    return 0;

}
