//
// Created by Aaron on 07/05/2024.
//
#include "iostream"
#include "cmath"
#include "cstdlib"

int main() {
    int initialPositionX, initialPositionY, initialSpeed, actualAngule, objectiveQty, actualTargetX, actualTargetY, cannonQty;
    std::cout<<"Ingrese el numero de canones: ";
    std::cin>>cannonQty;
    initialPositionX = 1;
    initialPositionY = 1;
    initialSpeed = 100;
    actualAngule = 45;
    std::cin>>objectiveQty;
    actualTargetX = 850;
    actualTargetY = 143;
    const double PI = M_PI; //Constante PI
    const double GRAVITY = -9.81; //Constante gravedad
    double timeInAir; //Luego se calcula cuanto tarda en caer el suelo según la altura inicial(Funcionando)
    double senoAngle = sin(actualAngule * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
    double cosAngle = cos(actualAngule * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
    double cosAngleSquare = pow(cosAngle, 2); //Cuadrado del coseno(Funcionando)
    double senoAngleSquare = pow(senoAngle, 2); //Cuadrado del seno(Funcionando)
    double initialSpeedY = initialSpeed * senoAngle; //Velocidad inicial Y  Vo*Sen(a) (Funcionando)
    double initialSpeedX = initialSpeed * cosAngle; // Velocidad inicial X Vo*Cos(a) (Funcionando)
    double timeY = (-initialSpeed * senoAngle + sqrt(
            (pow(initialSpeed, 2) * senoAngleSquare + 2 * GRAVITY * (actualTargetY - initialPositionY)))) /
                   GRAVITY;//(Funcionando)
    double timeY2 = -(
            (initialSpeedY + sqrt(pow(initialSpeedY, 2) + 2 * GRAVITY * (actualTargetY - initialPositionY))) /
            GRAVITY);
    double maxHeight = -(pow(initialSpeed, 2) * (senoAngleSquare) / (2 * GRAVITY)) +
                       initialPositionY; //Altura maxima Vo²*Sen²(a)/2*g + Altura inicial (Funcionando)
    double xWhenY = (initialSpeed * (timeY2) * cosAngle) +
                    initialPositionX; //Indica donde se encuentra el proyectil en el eje X cuando pasa por el eje Y indicado
    if (initialPositionY == 0) { //Las fórmulas difieren si la posición inicial de Y es 0 o no
        timeInAir = ((2 * initialSpeed) * senoAngle /
                     -GRAVITY); //Tiempo de vuelo si la altura es 0  Vo*Sen(a)/g (Funcionando)

    } else {
        timeInAir = (initialSpeed * senoAngle +
                     sqrt((pow(initialSpeed, 2) * senoAngleSquare + 2 * -GRAVITY * initialPositionY))) /
                    -GRAVITY; //  (Funcionando)
    }
std::cout<<timeY<<" "<<timeY2<<" "<<xWhenY;
    return 0;
}