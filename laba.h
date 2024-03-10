#pragma once
struct massive;
typedef struct complex{
    int real;
    int imaginary;
}complex;
typedef struct FieldInfo{
         int element_size;
         massive* (*map)(void*,void* (*foo)(void*));//gosha take a look,swap  and ask question to teacher about
        void (*sort)(void*,int (*compare)(void*,void*));
        massive* (*where)(void*,void*);
        void (*set)(void*);
        void (*show)(void*);

    } FieldInfo;

typedef struct massive{
    void *elements;
    int size;
    FieldInfo *FI;

} massive;
int scanfint(int *integer);
void* fooInt(void* ptr);//for mapInt
void sortInt(void *p1,int (*compare)(void*,void*));
FieldInfo* CreateIntFieldInfo();
void setInt(void* p1);
void showInt(void *p1);
massive* mapInt(void *mas,void* (*foo)(void*) );
void set_int_massive(massive*mas,int size,int arr[]);
int compareInt(void* p1,void* p2);
massive* whereInt(void* mas,int (*foo)(void*));
int fooBoolInt(void* p);
massive * concatinationInt(massive* mas1,massive* mas2);
/// @brief /////////////
/// @param ptr 
/// @return /
void* fooComplex(void* ptr);
void sortComplex(void *p1,int (*compare)(void*,void*));
FieldInfo* CreateComplexFieldInfo();
void setComplex(void* p1);
void showComplex(void *p1);
massive* mapComplex(void *mas,void* (*foo)(void*) );
void set_Complex_massive(massive*mas,int size,complex arr[]);
int compareComplex(void* p1,void* p2);
massive* whereComplex(void* mas,int (*foo)(void*));
int fooBoolComplex(void* p);
massive * concatinationComplex(massive* mas1,massive* mas2);