#include "Quaternion.h"

// Constructeurs
Quaternion::Quaternion() : a(1), b(0), c(0), d(0) {}

Quaternion::Quaternion(double a, double b, double c, double d)
    : a(a), b(b), c(c), d(d) {}

Quaternion::Quaternion(const Quaternion &q)
    : a(q.a), b(q.b), c(q.c), d(q.d) {}

// Setters et Getters
void Quaternion::setValues(double a, double b, double c, double d) {
    this->a = a; this->b = b; this->c = c; this->d = d;
}

double Quaternion::getA() const { return a; }
double Quaternion::getB() const { return b; }
double Quaternion::getC() const { return c; }
double Quaternion::getD() const { return d; }

// Méthodes
void Quaternion::print() const {
    std::cout << a << " + " << b << "i + " << c << "j + " << d << "k" << std::endl;
}

double Quaternion::norm() const {
    return sqrt(a * a + b * b + c * c + d * d);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(a, -b, -c, -d);
}

Quaternion Quaternion::normalize() const {
    double n = norm();
    if(n == 0) {
        std::cerr << "Norme nulle, normalisation impossible." << std::endl;
        return *this;
    }
    return Quaternion(a/n, b/n, c/n, d/n);
}

Quaternion Quaternion::inverse() const {
    double n2 = a*a + b*b + c*c + d*d;
    if(n2 == 0) {
        std::cerr << "Erreur : division par zéro dans l'inversion." << std::endl;
        return *this;
    }
    Quaternion conj = conjugate();
    return Quaternion(conj.a/n2, conj.b/n2, conj.c/n2, conj.d/n2);
}

// Opérations globales

Quaternion operator+(const Quaternion &q1, const Quaternion &q2) {
    return Quaternion(q1.getA() + q2.getA(),
                      q1.getB() + q2.getB(),
                      q1.getC() + q2.getC(),
                      q1.getD() + q2.getD());
}

Quaternion operator-(const Quaternion &q1, const Quaternion &q2) {
    return Quaternion(q1.getA() - q2.getA(),
                      q1.getB() - q2.getB(),
                      q1.getC() - q2.getC(),
                      q1.getD() - q2.getD());
}

Quaternion operator*(const Quaternion &q1, const Quaternion &q2) {
    double a = q1.getA()*q2.getA() - q1.getB()*q2.getB() - q1.getC()*q2.getC() - q1.getD()*q2.getD();
    double b = q1.getA()*q2.getB() + q1.getB()*q2.getA() + q1.getC()*q2.getD() - q1.getD()*q2.getC();
    double c = q1.getA()*q2.getC() - q1.getB()*q2.getD() + q1.getC()*q2.getA() + q1.getD()*q2.getB();
    double d = q1.getA()*q2.getD() + q1.getB()*q2.getC() - q1.getC()*q2.getB() + q1.getD()*q2.getA();
    return Quaternion(a, b, c, d);
}

Quaternion operator/(const Quaternion &q1, const Quaternion &q2) {
    return q1 * q2.inverse();
}

double dotProduct(const Quaternion &q1, const Quaternion &q2) {
    return q1.getA()*q2.getA() + q1.getB()*q2.getB() + q1.getC()*q2.getC() + q1.getD()*q2.getD();
}

double euclideanDistance(const Quaternion &q1, const Quaternion &q2) {
    return sqrt(pow(q1.getA()-q2.getA(), 2) +
                pow(q1.getB()-q2.getB(), 2) +
                pow(q1.getC()-q2.getC(), 2) +
                pow(q1.getD()-q2.getD(), 2));
}

double chebyshevNorm(const Quaternion &q1, const Quaternion &q2) {
    double diffA = fabs(q1.getA() - q2.getA());
    double diffB = fabs(q1.getB() - q2.getB());
    double diffC = fabs(q1.getC() - q2.getC());
    double diffD = fabs(q1.getD() - q2.getD());
    return std::max({diffA, diffB, diffC, diffD});
}
