//
// Created by Aaron on 07/05/2024.
//
#include "iostream"
#include "cmath"
#include "cstdlib"

using namespace std;

int main() {
    cout << "ñ" << "Ñ";
    const double PI = M_PI; //Constante PI
    const double GRAVITY = -9.81; //Constante gravedad
    const char character164 = static_cast<char>(164); //Permite colocar la letra
    string char164(1, character164);
    string finalResult;
    int initialPositionX, initialPositionY, initialSpeed, actualAngle, objectiveQty, actualTargetX, actualTargetY, cannonQty;
    int canonID = 65;
    double timeInAir; //Luego se calcula cuanto tarda en caer el suelo según la altura inicial(Funcionando)
    cin >> cannonQty;
    for (int i = 0; i < cannonQty; i++) {
        char canonLetter = static_cast<char>(canonID);
        string canonString(1, canonLetter);
        canonID++;
        cin >> initialPositionX >> initialPositionY;
        cin >> initialSpeed >> actualAngle;
        double senoAngle = sin(actualAngle * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
        double cosAngle = cos(actualAngle * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
        double senoAngleSquare = pow(senoAngle, 2); //Cuadrado del seno(Funcionando)
        double initialSpeedY = initialSpeed * senoAngle; //Velocidad inicial Y  Vo*Sen(a) (Funcionando)
        double maxHeight = -(pow(initialSpeed, 2) * (senoAngleSquare) / (2 * GRAVITY)) +
                           initialPositionY; //Altura maxima Vo²*Sen²(a)/2*g + Altura inicial (Funcionando)
        int roundedHeight = static_cast<int>(round(maxHeight));
        string stringHeight = to_string(roundedHeight);
        if (initialPositionY == 0) { //Las fórmulas difieren si la posición inicial de Y es 0 o no
            timeInAir = ((2 * initialSpeed) * senoAngle /
                         -GRAVITY); //Tiempo de vuelo si la altura es 0  Vo*Sen(a)/g (Funcionando)

        } else {
            timeInAir = (initialSpeed * senoAngle +
                         sqrt((pow(initialSpeed, 2) * senoAngleSquare + 2 * -GRAVITY * initialPositionY))) /
                        -GRAVITY; //  (Funcionando)
        }
        int roundedTimeInAir = static_cast<int>(round(timeInAir));
        string stringTimeInAir = to_string(roundedTimeInAir);
        finalResult.append("\nLos proyectiles del ca")
                .append(char164)
                .append("on ")
                .append(canonString)
                .append(" subiran hasta ")
                .append(stringHeight)
                .append(" metros antes de comenzar a caer.\n")
                .append("Estos impactaran contra el suelo pasados ")
                .append(stringTimeInAir)
                .append(" segundos luego de ser disparados.\n");
        cin >> objectiveQty;
        cout << (initialPositionY > 50) << (initialSpeed > 500) << (cannonQty > 26) << (actualAngle > 180)
             << (cannonQty < 1)
             << (initialSpeed < 1) << (initialPositionY < 0) << (objectiveQty < 1);
        if (initialPositionY > 50 || initialSpeed > 500 || cannonQty > 26 || actualAngle > 180 || actualAngle < 0 ||
            cannonQty < 1 ||
            initialSpeed < 1 || initialPositionY < 0 || objectiveQty < 1) {
            cout << "Datos de entrada invalidos";
            return 0;
        }
        for (int j = 0; j < objectiveQty; ++j) {
            cin >> actualTargetX >> actualTargetY;
            if (actualTargetY < 0) {
                cout << "Datos de entrada invalidos";
                return 0;
            }
            double timeY = (-initialSpeed * senoAngle + sqrt(
                    (pow(initialSpeed, 2) * senoAngleSquare + 2 * GRAVITY * (actualTargetY - initialPositionY)))) /
                           GRAVITY;//(Funcionando)
            int roundedTimeY = static_cast<int>(round(timeY));
            string stringTimeY = to_string(roundedTimeY);
            double timeY2 = -(
                    (initialSpeedY + sqrt(pow(initialSpeedY, 2) + 2 * GRAVITY * (actualTargetY - initialPositionY))) /
                    GRAVITY);
            int roundedTimeY2 = static_cast<int>(round(timeY2));
            string stringTimeY2 = to_string(roundedTimeY2);

            double xWhenY1 = round((initialSpeed * (timeY) * cosAngle) +
                                   initialPositionX); //Indica donde se encuentra el proyectil en el eje X cuando pasa por el eje Y indicado
            double xWhenY2 = round((initialSpeed * (timeY2) * cosAngle) +
                                   initialPositionX);
            if (actualTargetX == initialPositionX && actualTargetY == initialPositionY) {
                finalResult.append("\nCa")
                        .append(char164)
                        .append("on destruido");

                break;
            }
            if (actualTargetX == initialPositionX && actualTargetY < initialPositionY) {
                finalResult.append("\nEnemigos en las murallas");

                continue;
            }
            if ((actualTargetX > initialPositionX && actualAngle > 90) ||
                (actualTargetX < initialPositionX && actualAngle < 90)) {
                finalResult.append("\nPosicion comprometida");
                continue;
            }
            if (xWhenY1 == actualTargetX) {
                finalResult.append("\nObjetivo ")
                        .append(to_string(j + 1))
                        .append(" destruido por el ca")
                        .append(char164)
                        .append("on ")
                        .append(canonString)
                        .append(" en ")
                        .append(stringTimeY)
                        .append(" segundos.\n");
                continue;
            } else if (xWhenY2 == actualTargetX) {
                finalResult.append("\nObjetivo ")
                        .append(to_string(j + 1))
                        .append(" destruido por el ca")
                        .append(char164)
                        .append("on ")
                        .append(canonString)
                        .append(" en ")
                        .append(stringTimeY2)
                        .append(" segundos.\n");
                continue;
            } else {
                for (int k = 0; k < 18000; ++k) {


                    auto k2 = static_cast<double>(k);
                    double actualAngle2 = k2 / 100;
                    double senoAngle2 = sin(
                            actualAngle2 * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
                    double cosAngle2 = cos(
                            actualAngle2 * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
                    double senoAngleSquare2 = pow(senoAngle2, 2); //Cuadrado del seno(Funcionando)
                    double initialSpeedY2 = initialSpeed * senoAngle2; //Velocidad inicial Y  Vo*Sen(a) (Funcionando)
                    double timeY12 = (-initialSpeed * senoAngle2 + sqrt(
                            (pow(initialSpeed, 2) * senoAngleSquare2 +
                             2 * GRAVITY * (actualTargetY - initialPositionY)))) /
                                     GRAVITY;//(Funcionando)
                    double timeY22 = -((initialSpeedY2 + sqrt(pow(initialSpeedY2, 2) +
                                                              2 * GRAVITY * (actualTargetY - initialPositionY))) /
                                       GRAVITY);
                    double xWhenY12 = round((initialSpeed * (timeY12) * cosAngle2) +
                                            initialPositionX);
                    double xWhenY22 = round((initialSpeed * (timeY22) * cosAngle2) +
                                            initialPositionX);
                    if (abs(xWhenY12 - actualTargetX) < 0.5 || abs(xWhenY22 - actualTargetX) < 0.5) {
                        int movedGrades = round(abs(actualAngle - actualAngle2));
                        string stringGrades = to_string(movedGrades);
                        finalResult.append("\nReajuste de ")
                                .append(stringGrades)
                                .append(" grados requerido en el ca")
                                .append(char164)
                                .append("on ")
                                .append(canonString)
                                .append("\n");
                        break;
                    }
                }
            }
        }
    }
    cout << finalResult;
    cout << endl;
    return 0;

}