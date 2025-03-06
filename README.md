# Ellipse and Quaternion Project

This project implements two C++ classes: **Ellipse** and **Quaternion**. The implementation covers various functionalities including constructors, getters/setters, and mathematical operations, as well as detailed UML diagrams representing the structure of each class.

## Project Structure

- **Ellipse.h**  
  Header file containing the declaration of the `Ellipse` class.

- **Ellipse.cpp**  
  Implementation of the methods declared in `Ellipse.h`.

- **Quaternion.h**  
  Header file containing the declaration of the `Quaternion` class and the global functions (operator overloads, dot product, etc.).

- **Quaternion.cpp**  
  Implementation of the methods declared in `Quaternion.h`.

- **main.cpp**  
  A test file that creates instances of both classes and demonstrates their functionality.

- **UML_Diagrams.pdf**  
  A PDF file that includes the UML diagrams for both the `Ellipse` and `Quaternion` classes. The diagrams detail the class name, attributes (with access modifiers), and methods along with their signatures.

## Features

### Ellipse Class

- **Definition:**  
  Represents an ellipse defined by its center `(h, k)`, semi-major axis `a`, and semi-minor axis `b`. An additional attribute, `orientation`, indicates whether the major axis lies along the X-axis (`'X'`) or Y-axis (`'Y'`).

- **Key Functionalities:**
  - **Constructors:**  
    - Default constructor: Initializes the ellipse with center `(0, 0)`, `a = 1`, and `b = 0.5`.
    - Parameterized constructor: Accepts center coordinates, axis lengths, and orientation.
    - Copy constructor.
  - **Methods:**  
    - Compute the focal distance (`c = sqrt(a^2 - b^2)`).
    - Retrieve vertices and foci based on orientation.
    - Calculate the focal chord length (`L_R = 2b²/a`) and eccentricity (`e = c/a`).
    - Print the ellipse’s equation and its characteristic points.
    - Check if a point is inside, on, or outside the ellipse.
    - Compute an approximate perimeter (using Ramanujan's formula) and the area.
    - Calculate the other coordinate when one coordinate is given.

### Quaternion Class

- **Definition:**  
  Represents a quaternion in the form `q = a + b*i + c*j + d*k`, where `a` is the scalar part and `b`, `c`, `d` are the imaginary components.

- **Key Functionalities:**
  - **Constructors:**  
    - Default constructor: Initializes the quaternion to `1 + 0*i + 0*j + 0*k`.
    - Parameterized constructor.
    - Copy constructor.
  - **Methods:**  
    - Set and get the values of the quaternion.
    - Print the quaternion in standard format.
    - Calculate the norm, conjugate, normalization, and inverse.
  - **Global Functions:**  
    - Operator overloads for addition, subtraction, multiplication, and division.
    - Functions to compute the dot product, Euclidean distance, and Chebyshev norm between two quaternions.

## UML Diagrams

The UML diagrams for the project are included in the file **UML_Diagrams.pdf**. They provide a visual representation of the structure for:
- **Ellipse Class:**  
  - **Name Section:** "Ellipse"
  - **Attributes Section:**  
    - `- h : double`  
    - `- k : double`  
    - `- a : double`  
    - `- b : double`  
    - `- orientation : char`
  - **Methods Section:**  
    - `+ Ellipse()`
    - `+ Ellipse(double, double, double, double, char)`
    - `+ Ellipse(const Ellipse &)`
    - `+ setCenter(double, double) : void`
    - `+ getCenter() : pair<double, double>`
    - ... (and the rest of the methods as detailed in the code)
- **Quaternion Class:**  
  - **Name Section:** "Quaternion"
  - **Attributes Section:**  
    - `- a : double`
    - `- b : double`
    - `- c : double`
    - `- d : double`
  - **Methods Section:**  
    - `+ Quaternion()`
    - `+ Quaternion(double, double, double, double)`
    - `+ Quaternion(const Quaternion &)`
    - `+ setValues(double, double, double, double) : void`
    - `+ getA() : double`
    - `+ getB() : double`
    - ... (and the remaining methods)
  - **Global Functions:** Listed separately for operator overloads and other operations.

## Compilation

To compile the project, run the following command (assuming you are using a Linux terminal or similar environment):

```bash
g++ -o project Ellipse.cpp Quaternion.cpp main.cpp -lm
