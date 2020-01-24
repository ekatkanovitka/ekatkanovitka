#include<stdio.h>
#include<stdlib.h>


void Taskw(double*,double*,int,int);
void TaskOut(double*,double*,int,int);
void qs(double*,int,int);
void swap(double*,double*);
int minim(int*,int*);
int main(void)
{
    int i,n=0,m=0;
    double *a,*b,t;
    FILE *In,*Out1;

    if(!(In=fopen("1.txt","r")))
        return(-1);

     while(1) {
        if(fscanf(In,"%lf",&t)<=0)
            break;
        n++;
        }
       fclose(In);
    if (n==0)
        return(-1);
    if (!(a=(double*)malloc(n*sizeof(double))))
        return(-1);
    In=fopen("1.txt","r");
    for (i=0;i<n;++i)
        fscanf(In,"%lf",a+i);
        fclose(In);


       if(!(In=fopen("2.txt","r")))
        return(-1);

     while(1) {
        if(fscanf(In,"%lf",&t)<=0)
            break;
        m++;
        }
       fclose(In);
    if (m==0)
        return(-1);
    if (!(b=(double*)malloc(m*sizeof(double))))
        return(-1);
    In=fopen("2.txt","r");
    for (i=0;i<m;++i)
        fscanf(In,"%lf",b+i);
        fclose(In);


    if(!(Out1=fopen("output.txt","w"))) {
        free(a);
    free(b);
    return(-1);
    }

    printf("\n\nSee result in output file\n\n");
    TaskOut(a,b,n,m);
    return(0);

}
  void    Taskw(double *a,double *b,int n,int m)
      {
          qs(a,0,n-1);
          qs(b,0,m-1);
          return;
      }
    void  TaskOut(double *a,double *b,int n,int m)
      {
          int i=0,j=0,count=0,mint;
          FILE *Out;
          Taskw(a,b,n,m);
          mint=minim(&n,&m);
          Out=fopen("output.txt","w");
         for (i=0;i<mint;++i) {
            if (a[i]<b[i])
            ++count;
          }
           if (count>(mint-count))
           {
               fprintf(Out,"YES");
           }
           else{
            fprintf(Out,"NO");
           }
          fclose(Out);
          free(a);
          free(b);
          return;
      }
      void qs(double *arr,int first,int last)
      {
          int i=first,j=last,x=arr[(first+last)/2];

          do{
            while(arr[i]>x) i++;
            while(arr[j]<x) j--;
            if (i<=j){
                if (arr[i]<arr[j])
                    swap(&arr[i],&arr[j]);
                i++;
                j--;
            }
          }while(i<=j);

          if (i<last)
            qs(arr,i,last);
          if(first<j)
            qs(arr,first,j);
      }
      void swap(double *k,double *l)
      {
          int t=*k;
          *k=*l;
          *l=t;
      }
      int minim(int *k,int *l)
      {
          int min;
          if (*k<=*l){
             min=*k;
          }
           else {
                min=*l;
           }
           return(min);
      }
