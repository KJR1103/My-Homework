#include "Ellipse.h"

// Constructeur par défaut : Centre à (0,0), a = 1 et b = 0.5 par défaut.
Ellipse::Ellipse() : h(0), k(0), a(1), b(0.5), orientation('X') {
    if (a <= b) {
        std::swap(a, b);
    }
}

Ellipse::Ellipse(double h, double k, double a, double b, char orientation)
    : h(h), k(k), a(a), b(b), orientation(orientation) {
    if (a <= b) {
        std::cerr << "Erreur : a doit etre superieur a b. Les valeurs sont echangées." << std::endl;
        std::swap(this->a, this->b);
    }
}

Ellipse::Ellipse(const Ellipse &other)
    : h(other.h), k(other.k), a(other.a), b(other.b), orientation(other.orientation) {}

void Ellipse::setCenter(double h, double k) {
    this->h = h;
    this->k = k;
}

std::pair<double, double> Ellipse::getCenter() const {
    return {h, k};
}

void Ellipse::setAxes(double a, double b) {
    if (a > b) {
        this->a = a;
        this->b = b;
    } else {
        std::cerr << "Erreur : a doit etre superieur a b." << std::endl;
    }
}

std::pair<double, double> Ellipse::getAxes() const {
    return {a, b};
}

void Ellipse::setOrientation(char orientation) {
    if (orientation == 'X' || orientation == 'Y')
        this->orientation = orientation;
}

char Ellipse::getOrientation() const {
    return orientation;
}

double Ellipse::computeC() const {
    return sqrt(a * a - b * b);
}

std::vector<std::pair<double, double>> Ellipse::getVertices() const {
    std::vector<std::pair<double, double>> vertices;
    if (orientation == 'X') {
        vertices.push_back({h - a, k});
        vertices.push_back({h + a, k});
    } else {
        vertices.push_back({h, k - a});
        vertices.push_back({h, k + a});
    }
    return vertices;
}

std::vector<std::pair<double, double>> Ellipse::getFoci() const {
    double c = computeC();
    std::vector<std::pair<double, double>> foci;
    if (orientation == 'X') {
        foci.push_back({h - c, k});
        foci.push_back({h + c, k});
    } else {
        foci.push_back({h, k - c});
        foci.push_back({h, k + c});
    }
    return foci;
}

double Ellipse::getFocalChordLength() const {
    return (2 * b * b) / a;
}

double Ellipse::getEccentricity() const {
    return computeC() / a;
}

void Ellipse::printEquationAndPoints() const {
    if (orientation == 'X')
        std::cout << "Equation: ((x - " << h << ")^2)/" << (a * a)
                  << " + ((y - " << k << ")^2)/" << (b * b) << " = 1" << std::endl;
    else
        std::cout << "Equation: ((x - " << h << ")^2)/" << (b * b)
                  << " + ((y - " << k << ")^2)/" << (a * a) << " = 1" << std::endl;
    
    std::cout << "Centre: (" << h << ", " << k << ")" << std::endl;
    
    auto vertices = getVertices();
    std::cout << "Vertices: ";
    for (auto &v : vertices)
        std::cout << "(" << v.first << ", " << v.second << ") ";
    std::cout << std::endl;
    
    auto foci = getFoci();
    std::cout << "Foyers: ";
    for (auto &f : foci)
        std::cout << "(" << f.first << ", " << f.second << ") ";
    std::cout << std::endl;
}

int Ellipse::pointPosition(double x, double y) const {
    double value;
    if (orientation == 'X')
        value = ((x - h) * (x - h)) / (a * a) + ((y - k) * (y - k)) / (b * b);
    else
        value = ((x - h) * (x - h)) / (b * b) + ((y - k) * (y - k)) / (a * a);
    
    if (fabs(value - 1.0) < 1e-6)
        return 0;   // Sur l'ellipse
    else if (value < 1)
        return -1;  // A l'interieur
    else
        return 1;   // A l'exterieur
}

double Ellipse::approximatePerimeter() const {
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

double Ellipse::area() const {
    return M_PI * a * b;
}

double Ellipse::computeOtherCoordinate(double givenValue, bool isXGiven) const {
    double result = 0, term;
    if (isXGiven) { // x donné, calcul de y
        if (orientation == 'X')
            term = 1 - ((givenValue - h) * (givenValue - h)) / (a * a);
        else
            term = 1 - ((givenValue - h) * (givenValue - h)) / (b * b);
        
        if (term < 0) {
            std::cerr << "La coordonnee x=" << givenValue << " n'appartient pas a l'ellipse." << std::endl;
            return NAN;
        }
        result = (orientation == 'X') ? k + b * sqrt(term) : k + a * sqrt(term);
    } else { // y donné, calcul de x
        if (orientation == 'X')
            term = 1 - ((givenValue - k) * (givenValue - k)) / (b * b);
        else
            term = 1 - ((givenValue - k) * (givenValue - k)) / (a * a);
        
        if (term < 0) {
            std::cerr << "La coordonnee y=" << givenValue << " n'appartient pas a l'ellipse." << std::endl;
            return NAN;
        }
        result = (orientation == 'X') ? h + a * sqrt(term) : h + b * sqrt(term);
    }
    return result;
}
