#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>

class Quaternion {
private:
    double a, b, c, d; // Représente : a + b*i + c*j + d*k
public:
    // Constructeurs
    Quaternion();
    Quaternion(double a, double b, double c, double d);
    Quaternion(const Quaternion &q);
    
    // Setters et Getters
    void setValues(double a, double b, double c, double d);
    double getA() const;
    double getB() const;
    double getC() const;
    double getD() const;
    
    // Méthodes
    void print() const;
    double norm() const;
    Quaternion conjugate() const;
    Quaternion normalize() const;
    Quaternion inverse() const;
};

// Opérations globales sur deux quaternions
Quaternion operator+(const Quaternion &q1, const Quaternion &q2);
Quaternion operator-(const Quaternion &q1, const Quaternion &q2);
Quaternion operator*(const Quaternion &q1, const Quaternion &q2);
Quaternion operator/(const Quaternion &q1, const Quaternion &q2);
double dotProduct(const Quaternion &q1, const Quaternion &q2);
double euclideanDistance(const Quaternion &q1, const Quaternion &q2);
double chebyshevNorm(const Quaternion &q1, const Quaternion &q2);

#endif // QUATERNION_H
