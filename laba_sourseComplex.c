#include "laba.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void* fooComplex(void* ptr)
{   
    complex c=(*(complex*)ptr);
     c.imaginary*=2;
     c.real*=2;
    void *p2=malloc(sizeof(complex));
    memcpy(p2,(void*)(&c),sizeof(complex));
    return p2;
}
void sortComplex(void *p1,int (*compare)(void* p1,void* p2))
 {
    if(p1==0)
    {
        printf("sortcomplex\tp1==0\n");
        return;
    }
    for(int i=0;i<((struct massive*)p1)->size;i++)
    {
        for(int j=0;j<((struct massive*)p1)->size-1;j++)
            if(compareComplex((void*)((complex*)(((massive*)p1)->elements)+j),(void*)((complex*)(((massive*)p1)->elements)+j+1)))
            {   void *p=malloc(sizeof(complex));
               memcpy(p,(void*)((complex*)(((struct massive*)p1)->elements)+j),sizeof(complex));
               memcpy((void*)((complex*)(((struct massive*)p1)->elements)+j),(void*)((complex*)(((struct massive*)p1)->elements)+j+1),sizeof(complex));
               memcpy((void*)((complex*)(((struct massive*)p1)->elements)+j+1),p,sizeof(complex));
            }
            
    }
 }



FieldInfo* CreateComplexFieldInfo()
{
    FieldInfo *fi=(FieldInfo*)malloc(sizeof(FieldInfo));
    fi->element_size=sizeof(complex);
    fi->sort=sortComplex;
    fi->set=setComplex;
    fi->show=showComplex;
    fi->map=mapComplex;
    return fi;
}
void setComplex(void* p1)
{   
    if(p1==0)
    {
        printf("setcomplex\tp1==0\n");
        return;
    }
    printf("enter count of complex numbers\n");
    int n=0;
    scanf("%d",&n);
    ((struct massive*)p1)->elements=calloc(n,sizeof(complex));
    printf("enter real and imaginary parths %d times\n",n);
    for(int i=0;i<n;i++)
    {
        int real=0;
        int imaginary=0;
        scanf("%d%d",&real,&imaginary);
        memcpy((void*)(&((complex*)(((struct massive*)p1)->elements)+i)->real),(void*)(&real),sizeof(complex));
        memcpy((void*)(&((complex*)(((struct massive*)p1)->elements)+i)->imaginary),(void*)(&imaginary),sizeof(complex));
    }
    ((struct massive *)p1)->size=n;

}
void showComplex(void *p1)
{
    if(p1==0)
    {
        printf("showcomplex\tp1==0\n");
        return;
    }
    struct massive *p2=(struct massive*)p1;
    for(int i=0;i<p2->size;i++)
    printf("%d\t",i);
    printf("\n");
    for(int i=0;i<p2->size;i++)
    printf("%d,%d \t",(*((complex*)p2->elements+i)).real,(*((complex*)p2->elements+i)).imaginary);
    printf("\n\n");

}
massive* mapComplex(void *mas,void* (*foo)(void*) )
{
    if(mas==0)
    {
        printf("mapcomplex\tmas==0\n");
        return 0;
    }
    void *ptr=malloc(((struct massive*)mas)->size*((struct massive*)mas)->FI->element_size);
    
    for(int i=0;i<((struct massive*)mas)->size;i++)
    {
        void* p2=foo((void*)((complex*)((struct massive*)mas)->elements+i));

        memcpy((void*)((complex*)(ptr)+i),p2,((struct massive*)mas)->FI->element_size);
        free (p2);
    }
    massive* mas2=(massive*)malloc(sizeof(massive));
    mas2->FI=CreateComplexFieldInfo();
    mas2->size=((struct massive*)mas)->size;
    mas2->elements=ptr;
    return mas2;
}
void set_Complex_massive(massive *mas,int size,complex arr[])
{   if(arr==0)
{
    printf("set_complex_massive\tarr=0\n");
    return;
}
    mas->size=size;
    mas->elements=malloc(sizeof(complex)*size);
    for(int i=0;i<size;i++)
    {
        memcpy((void*)((complex*)mas->elements+i),(void*)(arr+i),sizeof(complex));
    }
}
int compareComplex(void* p1,void* p2)
{
    if((*(complex*)p1).real>(*(complex*)p2).real)
        return 1;
        return 0;
}
massive* whereComplex(void* mas,int (*foo)(void*))
{   if(mas==NULL)
    {
    printf("wherecomplex\tmas=0\n");
    return 0;
    }
    if(foo==NULL)
    {
    printf("wherecomplex\tfoo=0\n");
    return 0;
    }
    int count=0;
    for(int i=0;i<((massive*)mas)->size;i++)
    {
        if(foo((void*)(((complex*)(((massive*)mas)->elements))+i)))
            count++;
    }
    void *p2=calloc(count,((massive*)mas)->FI->element_size);
   int j=0;
   for(int i=0;i<((massive*)mas)->size;i++)
    {
        if(foo((void*)(((complex*)(((massive*)mas)->elements))+i)))
        {
            memcpy((void*)((complex*)p2+j),(void*)(((complex*)(((massive*)mas)->elements))+i),((massive*)mas)->FI->element_size);
            j++;
        }
            
    }
    massive* mas2= (massive*)malloc(sizeof(massive));
    mas2->FI=CreateComplexFieldInfo();
    mas2->size=count;
    mas2->elements=p2;
    return mas2;
   
}
int fooBoolComplex(void* p)
{
    complex c=*(complex*)p;
    if(c.real%2==0)
        return 1;
    return 0;

}
massive * concatinationComplex(massive* mas1,massive* mas2)
{
    if(mas1==0)
    {
        printf("concationComplex\tmas1==0\n");
        return 0;
    }
    if(mas2==0)
    {
        printf("concationComplex\tmas2==0\n");
        return 0;
    }
    massive* mas=(massive*)malloc(sizeof(massive));
    mas->FI=CreateIntFieldInfo();
    mas->size=mas1->size+mas2->size;
    mas->elements=malloc(mas->size*sizeof(complex));
    for(int i=0;i<mas1->size;i++)
    {
        memcpy((void*)((complex*)mas->elements+i),(void*)((complex*)mas1->elements+i),sizeof(complex));
    }
    for(int i=0;i<mas2->size;i++)
    {
        memcpy((void*)((complex*)mas->elements+i+mas1->size),(void*)((complex*)mas2->elements+i),sizeof(complex));
        
    }
    return mas;
}