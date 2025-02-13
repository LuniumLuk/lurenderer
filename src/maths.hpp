#ifndef __MATHS_HPP__
#define __MATHS_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <utility>
#include "global.hpp"

namespace LuGL
{

#define FTOD(a) (floor(a))
#define DTOF(a) ((a)+0.5f)

typedef class Vector2 vec2;
typedef class Vector3 vec3;
typedef class Vector3 rgb;
typedef class Vector4 vec4;
typedef class Vector4 rgba;
typedef class Quaternion quat;
typedef class Matrix3 mat3;
typedef class Matrix4 mat4;

/**
 * Vector2
 */
class Vector2
{
public:
    union { float x, u, theta; };
    union { float y, v, phi; };
#if 0
    float x, y;
#endif
    Vector2(): x(0), y(0) {}
    Vector2(float x, float y): x(x), y(y) {}
    Vector2(const Vector2 & vec): x(vec.x), y(vec.y) {}
    Vector2(const Vector4 & vec);
    Vector2(float * array):
        x(*(array + 0)),
        y(*(array + 1)) {}

    /* Static Members */
    static Vector2 UNIT_X;
    static Vector2 UNIT_Y;
    static Vector2 ZERO;

    /* Operator Overload Functions */
    void operator= (const Vector2 & other);
    Vector2 operator+ (const Vector2 & other) const;
    Vector2 operator- () const;
    Vector2 operator- (const Vector2 & other) const;
    Vector2 operator* (const float & multiplicand) const;
    Vector2 operator/ (const float divisor) const;
    bool operator== (const Vector2 & other) const;
    bool operator!= (const Vector2 & other) const;
    void operator+= (const Vector2 & other);

    /* Member Functions */
    float dot(const Vector2 & other) const;
    float cross(const Vector2 & other) const;
    Vector2 multiply(const Vector2 & other) const;
    float length() const;
    Vector2 normalized() const;
    void normalize();
    void print() const;

    /* Static Functions */
    static Vector2 lerp(const Vector2 & from, const Vector2 & to, float alpha);
};

Vector2 operator* (float multiplier, const Vector2 & multiplicand);

/**
 * Vector3
 */
class Vector3
{
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };
#if 0
    float x, y, z;
#endif
    Vector3(): x(0), y(0), z(0) {}
    Vector3(float x, float y, float z): x(x), y(y), z(z) {}
    Vector3(const Vector3 & vec): x(vec.x), y(vec.y), z(vec.z) {}
    Vector3(const Vector4 & vec);
    Vector3(float * array):
        x(*(array + 0)),
        y(*(array + 1)),
        z(*(array + 2)) {}

    /* Static Members */
    static Vector3 UNIT_X;
    static Vector3 UNIT_Y;
    static Vector3 UNIT_Z;
    static Vector3 ZERO;

    /* Operator Overload Functions */
    void operator= (const Vector3 & other);
    Vector3 operator+ (const Vector3 & other) const;
    Vector3 operator- () const;
    Vector3 operator- (const Vector3 & other) const;
    Vector3 operator* (const float & multiplicand) const;
    Vector3 operator/ (const float divisor) const;
    bool operator== (const Vector3 & other) const;
    bool operator!= (const Vector3 & other) const;
    void operator+= (const Vector3 & other);

    /* Member Functions */
    float dot(const Vector3 & other) const;
    Vector3 cross(const Vector3 & other) const;
    Vector3 multiply(const Vector3 & other) const;
    float length() const;
    Vector3 normalized() const;
    void normalize();
    void print() const;
    Vector3 rotated(const Quaternion & quat) const;
    void rotate(const Quaternion & quat);
    Vector3 rotatedFromAxisAngle(const Vector3 & axis, const float angle);

    /* Static Functions */
    static Vector3 lerp(const Vector3 & from, const Vector3 & to, float alpha);
    static Vector3 reflect(const Vector3 & vec, const Vector3 & normal);
};

Vector3 operator* (float multiplier, const Vector3 & multiplicand);
void swap(Vector3 & a, Vector3 & b);

/**
 * Vector4
 */
class Vector4
{
public:
    union { float x, r; };
    union { float y, g; };
    union { float z, b; };
    union { float w, a; };
#if 0
    float x, y, z, w;
#endif
    Vector4(): x(0), y(0), z(0), w(0) {}
    Vector4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}
    Vector4(const Vector4 & vec): x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}
    Vector4(const Vector3 & vec, float w): x(vec.x), y(vec.y), z(vec.z), w(w) {}
    Vector4(float * array):
        x(*(array + 0)),
        y(*(array + 1)),
        z(*(array + 2)),
        w(*(array + 3)) {}

    /* Static Members */
    static Vector4 UNIT_X;
    static Vector4 UNIT_Y;
    static Vector4 UNIT_Z;
    static Vector4 UNIT_W;
    static Vector4 ZERO;

    /* Operator Overload Functions */
    void operator= (const Vector4 & other);
    Vector4 operator+ (const Vector4 & other) const;
    Vector4 operator- () const;
    Vector4 operator- (const Vector4 & other) const;
    Vector4 operator* (const float & multiplicand) const;
    Vector4 operator/ (const float divisor) const;
    bool operator== (const Vector4 & other) const;
    bool operator!= (const Vector4 & other) const;
    void operator+= (const Vector4 & other);

    /* Member Functions */
    float dot(const Vector4 & other) const;
    Vector4 multiply(const Vector4 & other) const;
    float length() const;
    Vector4 normalized() const;
    void normalize();
    void print() const;

    /* Static Functions */
    static Vector4 lerp(const Vector4 & from, const Vector4 & to, float alpha);
};

Vector4 operator* (float multiplier, const Vector4 & multiplicand);
/**
 * Quaternion
 */
class Quaternion
{
public:
    float x, y, z, w;
    Quaternion(): x(0), y(0), z(0), w(1) {}
    Quaternion(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}
    Quaternion(const Quaternion & quat): x(quat.x), y(quat.y), z(quat.z), w(quat.w) {}
    Quaternion(float * array):
        x(*(array + 0)),
        y(*(array + 1)),
        z(*(array + 2)),
        w(*(array + 3)) {}
        
    /* Static Members */
    static Quaternion IDENTITY;

    /* Operator Overload Functions */
    void operator= (const Quaternion & other);
    Quaternion operator* (const Quaternion & other) const;
    bool operator== (const Quaternion & other) const;
    bool operator!= (const Quaternion & other) const;

    /* Member Functions */
    float dot(const Quaternion & other) const;
    Quaternion normalized() const;
    void normalize();
    Vector3 toEulerAngles() const;
    Quaternion inversed() const;
    void print() const;

    /* Static Functions */
    static Quaternion lerp(const Quaternion & from, const Quaternion & to, float alpha);
    static Quaternion slerp(const Quaternion & from, const Quaternion & to, float alpha);
    static Quaternion fromEulerAngles(const Vector3 & vec);
    static Quaternion fromToRotation(const Vector3 & from, const Vector3 to);
    static Quaternion fromAxisAngle(const Vector3 & axis, float angle);
};

/**
 * Matrix3
 */
class Matrix3
{
public:
    float m[9];

    Matrix3();
    Matrix3(
        const float & m1, const float & m2, const float & m3,
        const float & m4, const float & m5, const float & m6,
        const float & m7, const float & m8, const float & m9 );
    Matrix3(const Matrix3 & other);
    Matrix3(const Matrix4 & other);
    
    /* Static Members */
    static Matrix3 IDENTITY;
    
    /* Operator Overload Functions */
    void operator= (const Matrix3 & other);
    float& operator() (const size_t & row, const size_t & col);
    Matrix3 operator+ (const Matrix3 & other) const;
    Matrix3 operator- (const Matrix3 & other) const;
    Matrix3 operator* (const Matrix3 & other) const;
    Vector3 operator* (const Vector3 & other) const;
    Matrix3 operator/ (const float & divisor) const;
    bool operator== (const Matrix3 & other) const;
    bool operator!= (const Matrix3 & other) const;

    /* Member Functions */
    Matrix3 hadamard(const Matrix3 & other) const;
    Matrix3 inversed() const;
    float det() const;
    Matrix3 transposed() const;
    void print() const;
};

/**
 * Matrix4
 */
class Matrix4
{
public:
    float m[16];

    Matrix4();
    Matrix4(
        const float & m1,  const float & m2,  const float & m3,  const float & m4,
        const float & m5,  const float & m6,  const float & m7,  const float & m8,
        const float & m9,  const float & m10, const float & m11, const float & m12,
        const float & m13, const float & m14, const float & m15, const float & m16 );
    Matrix4(const Matrix4 & other);
    
    /* Static Members */
    static Matrix4 IDENTITY;
    
    /* Operator Overload Functions */
    void operator= (const Matrix4 & other);
    float& operator() (const size_t & row, const size_t & col);
    Matrix4 operator+ (const Matrix4 & other) const;
    Matrix4 operator- (const Matrix4 & other) const;
    Matrix4 operator* (const Matrix4 & other) const;
    Vector4 operator* (const Vector4 & other) const;
    Matrix4 operator/ (const float & divisor) const;
    bool operator== (const Matrix4 & other) const;
    bool operator!= (const Matrix4 & other) const;

    /* Member Functions */
    Matrix4 hadamard(const Matrix4 & other) const;
    void multiply(const Matrix4 & other);
    Matrix4 inversed() const;
    float det() const;
    Matrix4 transposed() const;
    void print() const;

    static Matrix4 fromQuaternion(const Quaternion & quat);
    static Matrix4 fromTRS(const Vector3 & translation, const Quaternion & rotation, const Vector3 & scale);
    static Matrix4 fromAxisAngle(const Vector3 & axis, const float & angle);
    static Matrix4 fromLookAt(const Vector3 & eye, const Vector3 & target, const Vector3 & up);
    static Matrix4 getProjection(const float & fov, const float & aspect, const float & near, const float & far);

    Matrix4 translated(const Vector3 & translation) const;
    Matrix4 scaled(const Vector3 & scale) const;
    Matrix4 rotated(const Vector3 & axis, const float & angle) const;
    Matrix4 rotated(const Quaternion & rotation) const;

    void translate(const Vector3 & translation);
    void scale(const Vector3 & scale);
    void rotate(const Vector3 & axis, const float & angle);
    void rotate(const Quaternion & rotation);
};

/**
 * Quick Sort Function
 * reference : https://www.geeksforgeeks.org/cpp-program-for-quicksort/
 */
template<typename T>
size_t qsortPartition(T* array, long low, long high, bool (*cmp)(const T &, const T &))
{
    T &pivot = array[high];
    long i = low;
    long j = high - 1;
    while (1)
    {
        while (cmp(array[i], pivot) && i < high)
        {
            i++;
        }
        while (!cmp(array[j], pivot) && j > low)
        {
            j--;
        }

        if (i >= j)
        {
            std::swap(array[i], array[high]);
            return i;
        }

        std::swap(array[i], array[j]);
    }
}

template<typename T>
void qsort(T* array, long low, long high, bool (*cmp)(const T &, const T &))
{
    if (low < high)
    {
        long pivot = qsortPartition(array, low, high, cmp);
        
        qsort(array, low, pivot - 1, cmp);
        qsort(array, pivot + 1, high, cmp);
    }
}

}



#endif