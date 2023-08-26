#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

#include <stdbool.h>

enum Type {
    Type_SCALAR=10,
    Type_PTR=11,
};

/************************************************************
Int
************************************************************/

typedef struct {
    union {
        int scalar;
        const int* ptr;
    };
    enum Type type;
} Int;

static Int Int_from_scalar(int scalar)
{
    return (Int){ .scalar=scalar, Type_SCALAR };
}

static Int Int_from_ptr(const int* ptr)
{
    return (Int){ .ptr=ptr, Type_PTR };
}

#define Int_from(X) _Generic((X), \
    int: Int_from_scalar, \
    int*: Int_from_ptr, \
    default: Int_from_scalar \
    )(X)

/************************************************************
Float
************************************************************/

typedef struct {
    union {
        float scalar;
        const float* ptr;
    };
    enum Type type;
} Float;

Float Float_from_scalar(float scalar)
{
    return (Float){ .scalar=scalar, Type_SCALAR }; 
}

Float Float_from_ptr(const float* ptr)
{
    return (Float){ .ptr=ptr, Type_PTR };
}

#define Float_from(X) _Generic((X), \
    float: Float_from_scalar, \
    float*: Float_from_ptr, \
    default: Float_from_scalar \
    )(X)

/************************************************************
Char
************************************************************/

typedef struct {
    union {
        char scalar;
        const char* ptr;
    };
    enum Type type;
} Char;

static Char Char_from_scalar(char scalar)
{
    return (Char){ .scalar=scalar, Type_SCALAR };
}

static Char Char_from_ptr(const char* ptr)
{
    return (Char){ .ptr=ptr, Type_PTR };
}

#define Char_from(X) _Generic((X), \
    char: Char_from_scalar, \
    char*: Char_from_ptr, \
    default: Char_from_scalar \
    )(X)

/************************************************************
Bool
************************************************************/

typedef struct {
    union {
        bool scalar;
        const bool* ptr;
    };
    enum Type type;
} Bool;

static Bool Bool_from_scalar(bool scalar)
{
    return (Bool){ .scalar=scalar, Type_SCALAR };
}

static Bool Bool_from_ptr(const bool* ptr)
{
    return (Bool){ .ptr=ptr, Type_PTR };
}

#define Bool_from(X) _Generic((X), \
    bool: Bool_from_scalar, \
    bool*: Bool_from_ptr, \
    default: Bool_from_scalar \
    )(X)

/************************************************************
Ptr_from
************************************************************/

static int* Ptr_from_int(int scalar)
{
    int* ptr = malloc(sizeof(int));
    *ptr = scalar;
    return ptr;
}

static float* Ptr_from_float(float scalar)
{
    float* ptr = malloc(sizeof(float));
    *ptr = scalar;
    return ptr;
}

static char* Ptr_from_char(char scalar)
{
    char* ptr = malloc(sizeof(char));
    *ptr = scalar;
    return ptr;
}

static bool* Ptr_from_bool(bool scalar)
{
    bool* ptr = malloc(sizeof(bool));
    *ptr = scalar;
    return ptr;
}

static void* Ptr_from_ptr(void* ptr)
{
    return ptr;
}

#define Ptr_from(X) _Generic((X), \
    int: Ptr_from_int, \
    float: Ptr_from_float, \
    char: Ptr_from_char, \
    bool: Ptr_from_bool, \
    int*: Ptr_from_ptr, \
    float*: Ptr_from_ptr, \
    char*: Ptr_from_ptr, \
    bool*: Ptr_from_ptr \
    )(X)

#endif
