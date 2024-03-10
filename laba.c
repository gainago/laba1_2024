#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "laba_sourseComplex.c"
#include "laba_sourseInt.c"
#include "test_Complex.c"
void User()
{
    int work=1;
    massive* mas1,* mas2;
        mas1=(massive*)malloc(sizeof(massive));
        mas2=(massive*)malloc(sizeof(massive));
        mas1->FI=CreateIntFieldInfo();
        mas2->FI=CreateIntFieldInfo();
        mas1->size=0;
        mas2->size=0;
    while(work)
    {
        printf(" выберите один из двух массивов. введите число(0 если выбираете первый, !0 если второй)\n");

        int n=0;
        int flag=0;
        flag=scanfint(&n);
        fflush(stdin);
        if(flag==-1)
        {
            printf("некорестный ввод\n");
            break;
        }
        int action=0;
        
        printf("выберите действие \n1:заполнить массив с клавиатуры \n2:отсортировать массив\n3:вывести массив на экран\n4:использовать фукцию where(изменит выбранный массив и проверит чсила на четность)\n5:использовать функцию map (изменит выбранный массив и домножит числа на два)\n6:сложить выбранный массив с другим\n");
        flag=scanfint(&action);
        fflush(stdin);
        if(flag==-1)
        {
            printf("некорестный ввод\n");
            break;
        }
        
        if(n)
        {
            massive* mas3;
            switch (action)
            {
            case 1:
                setInt((void*)mas1);
                break;
            case 2:
                sortInt((void*)mas1,compareInt);
                break;
            case 3:
                showInt((void*)mas1);
                break;
            case 4:
            
                 mas3=whereInt((void*)mas1,fooBoolInt);
                 if(mas3==0)
                {
                    break;
                }
                mas1=mas3;
                mas3=0;
                break;
            case 5:
           
                mas3=mapInt((void*)mas1,fooInt);
                if(mas3==0)
                {
                    break;
                }
                mas1=mas3;
                mas3=0;
                break;
            case 6:
            
                mas3=concatinationInt(mas1,mas2);
                if(mas3==0)
                {
                    break;
                }
                mas1=mas3;
                mas3=0;
                break;
            default:
            printf("неправильный ввод\n");
                break;
            }
        }
        else{
             massive* mas3;
            switch (action)
            {
            case 1:
                setInt((void*)mas2);
                break;
            case 2:
                sortInt((void*)mas2,compareInt);
                break;
            case 3:
                showInt((void*)mas2);
                break;
            case 4:
            
                 mas3=whereInt((void*)mas2,fooBoolInt);
                 if(mas3==0)
                {
                    break;
                }
                mas2=mas3;
                mas3=0;
                break;
            case 5:
            
                mas3=mapInt((void*)mas2,fooInt);
                if(mas3==0)
                {
                    break;
                }
                mas2=mas3;
                mas3=0;
                break;
            case 6:
            
                mas3=concatinationInt(mas2,mas1);
                if(mas3==0)
                {
                    break;
                }
                mas2=mas3;
                mas3=0;
                break;
            default:
            printf("неправильный ввод\n");
            work=0;
                break;
            }
        }
        printf("продолжить использование?введите число (0 если нет !0 если да)\n");
        flag=scanfint(&work);
        fflush(stdin);
        if(flag==-1)
        {
            printf("некорестный ввод\n");
            break;
        }
        fflush(stdin);



    }
}
int main(){
   User();
   
   //scanf("%d",&n);
    //test_Complex();
   /*int arr[5]={1,2,3,4,5};
    int arr2[5]={5,4,3,2,1};
    massive mas1,mas2;
    mas1.FI=CreateIntFieldInfo();
    mas2.FI=CreateIntFieldInfo();
    set_int_massive(&mas1,5,arr);
    set_int_massive(&mas2,5,arr2);
    massive *mas;
    mas=concatinationInt(&mas1,&mas2);
    printf("%d",mas->size);
    showInt((void*)mas);*/


}