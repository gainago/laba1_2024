#include "laba.h"
void test_int()
{   int n=10;
    int arr[10]={11,22,33,444,55,66,77,8888,9,10};
    massive mas1;
    mas1.FI=CreateIntFieldInfo();
    set_int_massive(&mas1,n,arr);
    massive mas4;
    mas4.FI=CreateIntFieldInfo();
    set_int_massive(&mas4,n,arr);
    showInt((void*)(&mas1));
    {
         massive *mas2;
         sortInt((void*)&mas1,compareInt);
         showInt((void*)(&mas1));
         mas2=mapInt((void*)(&mas1),fooInt);
         showInt((void*)mas2);
         mas2=whereInt((void*)&mas1,fooBoolInt);
         showInt(((void*)mas2));
         massive* mas3=concatinationInt(&mas1,&mas4);
         showInt((void*)mas3);
         
    }
    void* ptr=0;
      {
         massive *mas2;
         sortInt(ptr,compareInt);
         showInt(ptr);
         mas2=mapInt(ptr,fooInt);
         showInt(ptr);
         mas2=whereInt(ptr,fooBoolInt);
         showInt(ptr);
         massive* mas3=concatinationInt(ptr,&mas4);
         showInt((void*)mas3);
         
    }
    n=1;
   int arr2[1]={566};
   massive* mas7;
   set_int_massive(&mas1,n,arr2);
    showInt((void*)(&mas1));
    {
         massive *mas2;
         sortInt((void*)&mas1,compareInt);
         showInt((void*)(&mas1));
         mas2=mapInt((void*)(&mas1),fooInt);
         showInt((void*)mas2);
         mas2=whereInt((void*)&mas1,fooBoolInt);
         showInt(((void*)mas2));
         mas7=concatinationInt(mas2,&mas4);
         showInt((void*)mas7);
         
    }


    
}