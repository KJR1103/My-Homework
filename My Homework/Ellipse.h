#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

class Ellipse {
private:
    double h, k;         // Coordonnées du centre C(h, k)
    double a, b;         // Semi-axes (a > b)
    char orientation;    // 'X' : grand axe horizontal, 'Y' : grand axe vertical

public:
    // Constructeurs
    Ellipse();
    Ellipse(double h, double k, double a, double b, char orientation = 'X');
    Ellipse(const Ellipse &other);
    
    // Setters et Getters
    void setCenter(double h, double k);
    std::pair<double, double> getCenter() const;
    
    void setAxes(double a, double b);
    std::pair<double, double> getAxes() const;
    
    void setOrientation(char orientation);
    char getOrientation() const;
    
    // Méthodes de calcul
    double computeC() const;
    std::vector<std::pair<double, double>> getVertices() const;
    std::vector<std::pair<double, double>> getFoci() const;
    double getFocalChordLength() const;
    double getEccentricity() const;
    void printEquationAndPoints() const;
    int pointPosition(double x, double y) const;
    double approximatePerimeter() const;
    double area() const;
    double computeOtherCoordinate(double givenValue, bool isXGiven) const;
};

#endif // ELLIPSE_H
