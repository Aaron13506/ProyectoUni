//
// Created by Aaron on 07/05/2024.
//
#include "iostream"
#include "cmath"
#include "cstdlib"

using namespace std;
int Objective(int a, int b){ return a + b;}
int main() {
    const double PI = M_PI; //Constante PI
    const double GRAVITY = -9.81; //Constante gravedad
    const char character164 = static_cast<char>(164);
    int initialPositionX, initialPositionY, initialSpeed, actualAngle, objectiveQty, actualTargetX, actualTargetY, cannonQty;
    double timeInAir; //Luego se calcula cuanto tarda en caer el suelo según la altura inicial(Funcionando)
    cin >> cannonQty;
    int canonID = 65;
    char canonLetter = static_cast<char>(canonID);
    for (int i = 0; i < cannonQty; ++i) {
        cin >> initialPositionX >> initialPositionY;
        cin >> initialSpeed >> actualAngle;
        double senoAngle = sin(actualAngle * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
        double cosAngle = cos(actualAngle * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
        double cosAngleSquare = pow(cosAngle, 2); //Cuadrado del coseno(Funcionando)
        double senoAngleSquare = pow(senoAngle, 2); //Cuadrado del seno(Funcionando)
        double initialSpeedY = initialSpeed * senoAngle; //Velocidad inicial Y  Vo*Sen(a) (Funcionando)
        double initialSpeedX = initialSpeed * cosAngle; // Velocidad inicial X Vo*Cos(a) (Funcionando)
        double maxHeight = -(pow(initialSpeed, 2) * (senoAngleSquare) / (2 * GRAVITY)) +
                           initialPositionY; //Altura maxima Vo²*Sen²(a)/2*g + Altura inicial (Funcionando)
        if (initialPositionY == 0) { //Las fórmulas difieren si la posición inicial de Y es 0 o no
            timeInAir = ((2 * initialSpeed) * senoAngle /
                         -GRAVITY); //Tiempo de vuelo si la altura es 0  Vo*Sen(a)/g (Funcionando)

        } else {
            timeInAir = (initialSpeed * senoAngle +
                         sqrt((pow(initialSpeed, 2) * senoAngleSquare + 2 * -GRAVITY * initialPositionY))) /
                        -GRAVITY; //  (Funcionando)
        }
        cout <<endl<< "Los proyectiles del ca" << character164 << "on " << canonLetter << " subiran hasta "
             << static_cast<int>(round(maxHeight)) << " metros antes de comenzar a caer." << std::endl;
        cout << "Estos impactaran contra el suelo pasados " << round(timeInAir) << " segundos luego de ser disparados."
             << std::endl;
        cin >> objectiveQty;
        for (int j = 0; j < objectiveQty; ++j) {
            cin>>actualTargetX>>actualTargetY;
            double timeY = (-initialSpeed * senoAngle + sqrt(
                    (pow(initialSpeed, 2) * senoAngleSquare + 2 * GRAVITY * (actualTargetY - initialPositionY)))) /
                           GRAVITY;//(Funcionando)
            double timeY2 = -(
                    (initialSpeedY + sqrt(pow(initialSpeedY, 2) + 2 * GRAVITY * (actualTargetY - initialPositionY))) /
                    GRAVITY);
            double xWhenY1 = round((initialSpeed * (timeY) * cosAngle) +
                                   initialPositionX); //Indica donde se encuentra el proyectil en el eje X cuando pasa por el eje Y indicado
            double xWhenY2 = round((initialSpeed * (timeY2) * cosAngle) +
                                   initialPositionX);
            if (xWhenY1 == actualTargetX) {
                cout<<endl << "Objetivo " << j + 1 << " destruido por el ca" << character164 << "on " << canonLetter << " en "
                     << round(timeY) << " segundos." << endl;
            } else if (xWhenY2 == actualTargetX) {
                cout<<endl << "Objetivo " << j + 1 << " destruido por el ca" << character164 << "on " << canonLetter << " en "
                     << round(timeY2) << " segundos." << endl;
            }
            if (actualTargetX == initialPositionX&&actualTargetY==initialPositionY){
                cout<<endl <<"ca"<<character164<<"on destruido";
                break;
            }
            if (xWhenY2){}

        }
        canonID++;
    }



    return 0;
}