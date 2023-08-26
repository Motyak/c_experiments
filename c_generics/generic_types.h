#ifndef GENERIC_TYPES_H
#define GENERIC_TYPES_H

#include <stdbool.h>

enum Type {
    Type_SCALAR=10,
    Type_PTR=11,
};

/************************************************************
int
************************************************************/

typedef struct {
    union {
        int scalar;
        const int* ptr;
    };
    enum Type type;
} Int;

Int Int_from_scalar(int scalar)
{
    return (Int){ .scalar=scalar, Type_SCALAR };
}

Int Int_from_ptr(const int* ptr)
{
    return (Int){ .ptr=ptr, Type_PTR };
}

#define Int_from(X) _Generic((X), \
    int: Int_from_scalar, \
    int*: Int_from_ptr, \
    default: Int_from_scalar \
    )(X)

/************************************************************
float
************************************************************/

float float_from_scalar(float scalar)
{
    return scalar;
}

float float_from_ptr(const float* ptr)
{
    return *ptr;
}

#define float_from(X) _Generic((X), \
    float: float_from_scalar, \
    float*: float_from_ptr, \
    default: float_from_scalar \
    )(X)

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
char
************************************************************/

typedef struct {
    union {
        char scalar;
        const char* ptr;
    };
    enum Type type;
} Char;

Char Char_from_scalar(char scalar)
{
    return (Char){ .scalar=scalar, Type_SCALAR };
}

Char Char_from_ptr(const char* ptr)
{
    return (Char){ .ptr=ptr, Type_PTR };
}

#define Char_from(X) _Generic((X), \
    char: Char_from_scalar, \
    char*: Char_from_ptr, \
    default: Char_from_scalar \
    )(X)

/************************************************************
bool
************************************************************/

typedef struct {
    union {
        bool scalar;
        const bool* ptr;
    };
    enum Type type;
} Bool;

Bool Bool_from_scalar(bool scalar)
{
    return (Bool){ .scalar=scalar, Type_SCALAR };
}

Bool Bool_from_ptr(const bool* ptr)
{
    return (Bool){ .ptr=ptr, Type_PTR };
}

#define Bool_from(X) _Generic((X), \
    bool: Bool_from_scalar, \
    bool*: Bool_from_ptr, \
    default: Bool_from_scalar \
    )(X)

#endif
