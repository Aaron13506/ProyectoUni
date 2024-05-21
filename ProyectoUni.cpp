//
// Created by Aaron on 07/05/2024.
//
#include "iostream"
#include "cmath"
#include "cstdlib"

using namespace std;

int main() {
    const double PI = M_PI; //Constante PI
    const double GRAVITY = -9.81; //Constante gravedad
    const char character164 = static_cast<char>(164); //Permite colocar la letra
    string char164(1, character164);
    string finalResult;
    int initialPositionX, initialPositionY, initialSpeed, actualAngle, objectiveQty, actualTargetX, actualTargetY, cannonQty;
    double timeInAir; //Luego se calcula cuanto tarda en caer el suelo según la altura inicial(Funcionando)
    cin >> cannonQty;
    int canonID = 65;
    for (int i = 0; i < cannonQty; ++i) {
        char canonLetter = static_cast<char>(canonID);
        string canonString(1, canonLetter);
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
        for (int j = 0; j < objectiveQty; ++j) {
            cin >> actualTargetX >> actualTargetY;
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
            if (initialPositionY > 50 || initialSpeed > 500 || cannonQty > 26 || actualAngle > 180) {
                cout << "Datos de entrada invalidos";

                return 0;

            }
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
                .append( char164)
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
                for (int k = 0; k <= 1800; ++k) {
                    auto doubleK = static_cast<double>(k);
                    double allTheAngles = doubleK / 10;
                    double cosNewAngle = cos
                            (allTheAngles * PI / 180);
                    double senoNewAngle = sin(allTheAngles * PI / 180);
                    double senoNewAngleSquare = pow(senoNewAngle, 2); //Cuadrado del seno(Funcionando)
                    double newTimeY = (-initialSpeed * senoNewAngle + sqrt(
                            (pow(initialSpeed, 2) * senoNewAngleSquare +
                             2 * GRAVITY * (actualTargetY - initialPositionY)))) /
                                      GRAVITY;//(Funcionando)
                    double newTimeY2 = -(
                            (initialSpeedY +
                             sqrt(pow(initialSpeedY, 2) + 2 * GRAVITY * (actualTargetY - initialPositionY))) /
                            GRAVITY);
                    double xWhenNewY1 = round((initialSpeed * (newTimeY) * cosNewAngle) +
                                              initialPositionX); //Indica donde se encuentra el proyectil en el eje X cuando pasa por el eje Y indicado
                    double xWhenNewY2 = round((initialSpeed * (newTimeY2) * cosNewAngle) +
                                              initialPositionX);
                    if (xWhenNewY1 == actualTargetX || xWhenNewY2 == actualTargetX) {
                        int movedGrades = round(abs(actualAngle - allTheAngles));
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
        canonID++;
    }

    cout << finalResult;
    cout << endl << endl;
    return 0;
}