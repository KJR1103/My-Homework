#include "Ellipse.h"
#include "Quaternion.h"
#include <iostream>

int main() {
    // ================================
    // Test de la classe Ellipse
    // ================================
    std::cout << "=== Test de la classe Ellipse ===" << std::endl;
    // Création d'une ellipse avec centre (2,3), a = 5, b = 3, axe horizontal ('X')
    Ellipse e1(2.0, 3.0, 5.0, 3.0, 'X');
    e1.printEquationAndPoints();
    
    std::cout << "Perimetre approxime: " << e1.approximatePerimeter() << std::endl;
    std::cout << "Aire: " << e1.area() << std::endl;
    
    // Vérification de la position d'un point
    double x = 3.0, y = 3.0;
    int pos = e1.pointPosition(x, y);
    std::cout << "Le point (" << x << ", " << y << ") est ";
    if(pos == 0)
        std::cout << "sur l'ellipse." << std::endl;
    else if(pos < 0)
        std::cout << "a l'interieur de l'ellipse." << std::endl;
    else
        std::cout << "a l'exterieur de l'ellipse." << std::endl;
    
    // Calcul de la coordonnee manquante pour x donne
    double x_val = 4.0;
    double y_val = e1.computeOtherCoordinate(x_val, true);
    std::cout << "Pour x = " << x_val << ", la coordonnee y correspondante sur l'ellipse est: " << y_val << std::endl;
    
    std::cout << std::endl;
    
    // ================================
    // Test de la classe Quaternion
    // ================================
    std::cout << "=== Test de la classe Quaternion ===" << std::endl;
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(0.5, -1, 2, 1);
    
    std::cout << "q1 = "; q1.print();
    std::cout << "q2 = "; q2.print();
    
    Quaternion q_sum = q1 + q2;
    std::cout << "q1 + q2 = "; q_sum.print();
    
    Quaternion q_diff = q1 - q2;
    std::cout << "q1 - q2 = "; q_diff.print();
    
    Quaternion q_prod = q1 * q2;
    std::cout << "q1 * q2 = "; q_prod.print();
    
    Quaternion q_div = q1 / q2;
    std::cout << "q1 / q2 = "; q_div.print();
    
    std::cout << "Norme de q1: " << q1.norm() << std::endl;
    std::cout << "Conjugue de q1: "; q1.conjugate().print();
    std::cout << "q1 normalise: "; q1.normalize().print();
    
    std::cout << "Distance euclidienne entre q1 et q2: " << euclideanDistance(q1, q2) << std::endl;
    std::cout << "Norme de Chebyshev entre q1 et q2: " << chebyshevNorm(q1, q2) << std::endl;
    
    return 0;
}
