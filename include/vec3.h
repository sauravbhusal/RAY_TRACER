#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include<iostream>

class vec3 {
    public:
        double e[3];            //declares the empty vector with 3 elements or 3d vector

        vec3() : e{0,0,0} {}            //constructor to initialize the every value of the array as 0   
        vec3(double e0, double e1, double e2) : e(e0, e1, e2) {}            //constructor to manually insert the value of array 

        double x() const { return e[0]; }           //returns the corresponding value of x, y and z axis making the array-like   
        double y() const { return e[1]; }           //retrieval of array element more defined and easy to use
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }            //provides the negative value of the array without changing the actual value
        double operator[](int i) const { return e[i]; }             //gives read-only access for eg. v = vec3.e[0]     //double do not changes original value
        double& operator[](int i) { return e[i]; }              //gives write access for eg vec3.e[0] = 50      //double& directly refers to original memory

        vec3& operator+=(const vec3& v ) {              //vec3& is used instead of vec3 because it enables chaining of the multiple
            e[0] += v.e[0];                             //operators and also it doesn't create the copy so it is faster and efficient too
            e[1] += v.e[1];                             //and works as expected
            e[2] += v.e[2];
            return *this;           
        }

        vec3& operator*=(double t) {                    //performs the scalar multiplication
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const{
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        
}