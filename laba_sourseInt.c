
#include "laba.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void* fooInt(void* ptr)
{   
    int c=(*(int*)ptr);
    if(__INT_MAX__/2<c)
    {
        printf(" переполнение типа integer \n");
        c=0;
    }
    c*=2;
    void *p2=malloc(sizeof(int));
    memcpy(p2,(void*)(&c),sizeof(int));
    return p2;
}
void sortInt(void *p1,int (*compare)(void* p1,void* p2))
 {
    if(p1==0)
    {
        printf("sortInt\tp1==0\n");
        return;
    }
    for(int i=0;i<((struct massive*)p1)->size;i++)
    {
        for(int j=0;j<((struct massive*)p1)->size-1;j++)
            if(compareInt((void*)((int*)(((massive*)p1)->elements)+j),(void*)((int*)(((massive*)p1)->elements)+j+1)))
            {   void *p=malloc(sizeof(int));
               memcpy(p,(void*)((int*)(((struct massive*)p1)->elements)+j),sizeof(int));
               memcpy((void*)((int*)(((struct massive*)p1)->elements)+j),(void*)((int*)(((struct massive*)p1)->elements)+j+1),sizeof(int));
               memcpy((void*)((int*)(((struct massive*)p1)->elements)+j+1),p,sizeof(int));
            }
            
    }
 }



FieldInfo* CreateIntFieldInfo()
{
    FieldInfo *fi=(FieldInfo*)malloc(sizeof(FieldInfo));
    fi->element_size=sizeof(int);
    fi->sort=sortInt;
    fi->set=setInt;
    fi->show=showInt;
    fi->map=mapInt;
    return fi;
}
void setInt(void* p1)
{
    if(p1==0)
    {
        printf("setInt\tp1==0\n");
        return;
    }
    printf("введите количество элементов\n");
    int n=0;
    int flag=0;
    flag=scanfint(&n);
    fflush(stdin);
        if(flag==-1)
        {
            printf("некорестный ввод\n");
            return;
        }
    ((struct massive*)p1)->elements=calloc(n,sizeof(int));
    if(p1==0)
    {
        printf("setInt \tcan not highlight memory\n");
        return ;
    }
    
    if(n<0)
    {
        printf("длина должна быть больше нуля\n");
        return;
    }

    if(n>2000000)
    {
        printf("слишком большой размер массива\n");
        return;
    }
    printf("введите %d элемент(а/oв)\n ",n);
    for(int i=0;i<n;i++)
    {
        int curr=0;
        int flag=0;
        flag=scanfint(&curr);
        fflush(stdin);
        if(flag==-1)
        {
            printf("некорестный ввод\n");
            return;
        }
        memcpy((void*)((int*)(((struct massive*)p1)->elements)+i),(void*)(&curr),sizeof(int));
    }
    ((struct massive *)p1)->size=n;
    printf("вы успешно создали массив\n");

}
void showInt(void *p1)
{
    if(p1==0)
    {
        printf("showInt\tp1==0\n");
        return;
    }
    struct massive *p2=(struct massive*)p1;
    for(int i=0;i<p2->size;i++)
    printf("%d\t",i);
    printf("\n");
    for(int i=0;i<p2->size;i++)
    printf("%d\t",*((int*)p2->elements+i));
    printf("\n\n");

}
massive* mapInt(void *mas,void* (*foo)(void*) )
{
    if(mas==0)
    {
        printf("mapInt\tmas==0\n");
        return 0;
    }
    void *ptr=malloc(((struct massive*)mas)->size*((struct massive*)mas)->FI->element_size);
    if(ptr==0)
    {
        printf("mapInt \tcan not highlight memory\n");
        return 0;
    }
    
    for(int i=0;i<((struct massive*)mas)->size;i++)
    {
        void* p2=foo((void*)((int*)((struct massive*)mas)->elements+i));

        memcpy((void*)((int*)(ptr)+i),p2,((struct massive*)mas)->FI->element_size);
        free (p2);
    }
    massive* mas2=(massive*)malloc(sizeof(massive));
   
    mas2->FI=CreateIntFieldInfo();
    mas2->size=((struct massive*)mas)->size;
    mas2->elements=ptr;
    return mas2;
}
void set_int_massive(massive *mas,int size,int arr[])
{   if(arr==0)
{
    printf("set_int_massive\tarr=0\n");
    return;
}
    mas->size=size;
    mas->elements=malloc(sizeof(int)*size);
    if(mas->elements==0)
    {
        printf("set_int_massive \tcan not highlight memory\n");
        return;
    }
    for(int i=0;i<size;i++)
    {
        memcpy((void*)((int*)mas->elements+i),(void*)(arr+i),sizeof(int));
    }
}
int compareInt(void* p1,void* p2)
{
    if(*(int*)p1>*(int*)p2)
        return 1;
        return 0;
}
massive* whereInt(void* mas,int (*foo)(void*))
{   if(mas==NULL)
    {
    printf("whereInt\tmas=0\n");
    return 0;
    }
    if(foo==NULL)
    {
    printf("foo=0\n");
    return 0;
    }
    int count=0;
    for(int i=0;i<((massive*)mas)->size;i++)
    {
        if(foo((void*)(((int*)(((massive*)mas)->elements))+i)))
            count++;
    }
    void *p2=calloc(count,((massive*)mas)->FI->element_size);
    if(p2==0)
    {
        printf("whereInt \tcan not highlight memory\n");
        return 0;
    }
   int j=0;
   for(int i=0;i<((massive*)mas)->size;i++)
    {
        if(foo((void*)(((int*)(((massive*)mas)->elements))+i)))
        {
            memcpy((void*)((int*)p2+j),(void*)(((int*)(((massive*)mas)->elements))+i),((massive*)mas)->FI->element_size);
            j++;
        }
            
    }
    massive* mas2= (massive*)malloc(sizeof(massive));
    mas2->FI=CreateIntFieldInfo();
    mas2->size=count;
    mas2->elements=p2;
    return mas2;
   
}
int fooBoolInt(void* p)
{
    int c=*(int*)p;
    if(c%2==0)
        return 1;
    return 0;

}
massive * concatinationInt(massive* mas1,massive* mas2)
{
    if(mas1==0)
    {
        printf("mas1==0\n");
        return 0;
    }
    if(mas2==0)
    {
        printf("mas2==0\n");
        return 0;
    }
    massive* mas=(massive*)malloc(sizeof(massive));
    mas->FI=CreateIntFieldInfo();
    if(__INT_MAX__-mas2->size<mas1->size)
    {
        printf("суммарный массив слишком большой длины\n");
        return 0;
    }
    mas->size=mas1->size+mas2->size;
    mas->elements=malloc(mas->size*sizeof(int));
    if(mas->size==0)
    {
        printf("concatinationInt \tcan not highlight memory\n");
        return 0;
    }
    for(int i=0;i<mas1->size;i++)
    {
        memcpy((void*)((int*)mas->elements+i),(void*)((int*)mas1->elements+i),sizeof(int));
    }
    for(int i=0;i<mas2->size;i++)
    {
        memcpy((void*)((int*)mas->elements+i+mas1->size),(void*)((int*)mas2->elements+i),sizeof(int));
        
    }
    return mas;
}
int scanfint(int *integer)
{ int flag=-1;
int minusflag=0;
    char c;
   *integer=0;
    while(c=getchar())
     { if(c==' '||c==EOF||c=='\n')
        {
            if(flag==1){
                if(minusflag%2!=0)
                    *integer=*integer*(-1);
                return 1;
            }
        }
        if(c=='-')
            minusflag++;
        if((int)c>='0'&&(int)c<='9')
        {   flag=1;
            (*integer)*=10;
            (*integer)+=(int)c-48;
        }
        if(*integer>2000000)
            return -1;



    }
}