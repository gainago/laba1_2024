#include "laba.h"
void test_Complex()
{   int n=10;
    complex arr[5]={11,22,33,444,55,66,77,8888,9,10};
    complex arr2[2]={12,-4,7,-10};
    massive mas1;
    mas1.FI=CreateComplexFieldInfo();
    massive mas2,mas3;

    mas2.FI=CreateComplexFieldInfo();
    mas3.FI=CreateComplexFieldInfo();
    set_Complex_massive(&mas2,5,arr);
    set_Complex_massive(&mas3,2,arr2);

    
    set_Complex_massive(&mas1,n/2,arr);
    showComplex((void*)(&mas1));
    {
         massive *mas2;
         sortComplex((void*)&mas1,compareComplex);
         showComplex((void*)(&mas1));
         mas2=mapComplex((void*)(&mas1),fooComplex);
         showComplex((void*)mas2);
         mas2=whereComplex((void*)&mas1,fooBoolComplex);
         showComplex(((void*)mas2));
         mas2=concatinationComplex(mas2,&mas3);
         showComplex(((void*)mas2));
         
    }
    void* ptr=0;
      {
         massive *mas2;
         sortComplex(ptr,compareComplex);
         showComplex(ptr);
         mas2=mapComplex(ptr,fooComplex);
         showComplex(ptr);
         mas2=whereComplex(ptr,fooBoolComplex);
         showComplex(ptr);
         mas2=concatinationComplex(mas2,&mas3);
         showComplex(((void*)mas2));
         
    }
    n=1;
   complex arr3[1]={566,0};
   set_Complex_massive(&mas1,n,arr3);
    showComplex((void*)(&mas1));
    {
         massive *mas2;
         sortComplex((void*)&mas1,compareComplex);
         showComplex((void*)(&mas1));
         mas2=mapComplex((void*)(&mas1),fooComplex);
         showComplex((void*)mas2);
         mas2=whereComplex((void*)&mas1,fooBoolComplex);
         showComplex(((void*)mas2));
         mas2=concatinationComplex(mas2,&mas3);
         showComplex(((void*)mas2));
         
    }


    
}