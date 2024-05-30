//
// Created by Aaron on 07/05/2024.
//
#include "iostream"
#include "cmath"
#include "cstdlib"
using namespace std;


double calcularYcuandoX(double PI, double GRAVITY, int initialSpeed, int initialPositionX, int initialPositionY,
                        int actualTargetX, double newActualAngle) {
    double newSenoAngle = sin(
            newActualAngle * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
    double newCosAngle = cos(
            newActualAngle * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
    double newInitialSpeedY =
            initialSpeed * newSenoAngle; //Velocidad inicial Y  Vo*Sen(a) (Funcionando)
    double newInitialSpeedX = initialSpeed * newCosAngle;
    double newTimeX = (actualTargetX - initialPositionX) / newInitialSpeedX;//(Funcionando)
    double newYwhenX = round(initialPositionY + newInitialSpeedY * newTimeX - 0.5 * -GRAVITY *
                                                                              pow(newTimeX,
                                                                                  2));
    return newYwhenX;
}


int main() {
    string char164;
    string resultadoFinal;
#ifdef __linux__
    setlocale(LC_ALL, "spanish");
     char164 = "ñ"; //Permite colocar la letra
#elif _WIN32
    const char character164 = static_cast<char>(164); //Permite colocar la letra
    char164= string(1, character164);
#endif
    const double PI = M_PI; //Constante PI
    const double GRAVEDAD = -9.81; //Constante gravedad
    int posicionInicialX, posicionInicialY, velocidadInicial, anguloRecibido, nroObjetivos, xDeObjetivo, yDeObjetivo, nroCanones;
    bool invalidData = false;
    int canonNumberID = 65;
    double tiempoEnAire; //Luego se calcula cuanto tarda en caer el suelo según la altura inicial(Funcionando)
    cin >> nroCanones;
    for (int i = 0; i < nroCanones; i++) {
        char canonLetterID = static_cast<char>(canonNumberID);
        string canonStringID(1, canonLetterID);
        canonNumberID++;
        cin >> posicionInicialX >> posicionInicialY;
        cin >> velocidadInicial >> anguloRecibido;
        double senoAngulo = sin(
                anguloRecibido * PI / 180); //Numero convertido a radianes para calcular seno(Funcionando)
        double cosenoAngulo = cos(
                anguloRecibido * PI / 180); //Numero convertido a radianes para calcular coseno(Funcionando)
        double cuadradoSenoAngulo = pow(senoAngulo, 2); //Cuadrado del seno(Funcionando)
        double velocidadInicialX = velocidadInicial * cosenoAngulo; // Velocidad inicial X Vo*Cos(a) (Funcionando)
        double alturaMaxima = -(pow(velocidadInicial, 2) * (cuadradoSenoAngulo) / (2 * GRAVEDAD)) +
                              posicionInicialY; //Altura maxima Vo²*Sen²(a)/2*g + Altura inicial (Funcionando)
        int alturaRedondeada = static_cast<int>(round(alturaMaxima));
        string stringAltura = to_string(alturaRedondeada);
        if (posicionInicialY == 0) { //Las fórmulas difieren si la posición inicial de Y es 0 o no
            tiempoEnAire = ((2 * velocidadInicial) * senoAngulo /
                            -GRAVEDAD); //Tiempo de vuelo si la altura es 0  Vo*Sen(a)/g (Funcionando)

        } else {
            tiempoEnAire = (velocidadInicial * senoAngulo +
                            sqrt((pow(velocidadInicial, 2) * cuadradoSenoAngulo + 2 * -GRAVEDAD * posicionInicialY))) /
                           -GRAVEDAD; //  (Funcionando)
        }
        int tiempoEnAireRedondeado = static_cast<int>(round(tiempoEnAire));
        string stringTiempoEnAire = to_string(tiempoEnAireRedondeado);
        resultadoFinal.append("\nLos proyectiles del ca")
                .append(char164)
                .append("on ")
                .append(canonStringID)
                .append(" subiran hasta ")
                .append(stringAltura)
                .append(" metros antes de comenzar a caer.\n")
                .append("Estos impactaran contra el suelo pasados ")
                .append(stringTiempoEnAire)
                .append(" segundos luego de ser disparados.\n");
        cin >> nroObjetivos;
        if (posicionInicialY > 50 || posicionInicialY < 0
            || velocidadInicial > 500 || velocidadInicial < 1
            || anguloRecibido > 180 || anguloRecibido < 0 ||
            nroCanones > 26) {
            invalidData = true;
        }
        for (int j = 0; j < nroObjetivos; ++j) {
            cin >> xDeObjetivo >> yDeObjetivo;
            if (yDeObjetivo < 0) {
                invalidData = true;
            }
            double tiempoX = (xDeObjetivo - posicionInicialX) / velocidadInicialX;//(Funcionando)
            int tiempoXRedondeado = static_cast<int>(round(tiempoX));
            string stringTiempoX = to_string(tiempoXRedondeado);


            double yCuandoX = calcularYcuandoX(PI, GRAVEDAD, velocidadInicial, posicionInicialX, posicionInicialY,
                                               xDeObjetivo, anguloRecibido);
            int yCuandoXRedondeado = static_cast<int>(yCuandoX);
            string stringYCuandoX = to_string(yCuandoXRedondeado);

            if (xDeObjetivo == posicionInicialX && yDeObjetivo == posicionInicialY) {
                resultadoFinal.append("\nCa")
                        .append(char164)
                        .append("on destruido\n");
                for (int a = j + 1; a < nroObjetivos; ++a) {
                    cin >> xDeObjetivo >> yDeObjetivo;
                }


                break;
            } else if (xDeObjetivo == posicionInicialX && yDeObjetivo < posicionInicialY) {
                resultadoFinal.append("\nEnemigos en las murallas\n");


            } else if ((xDeObjetivo > posicionInicialX && anguloRecibido > 90) ||
                       (xDeObjetivo < posicionInicialX && anguloRecibido < 90)) {
                resultadoFinal.append("\nPosicion comprometida\n");
            } else if (yCuandoX == yDeObjetivo) {
                resultadoFinal.append("\nObjetivo ")
                        .append(to_string(j + 1))
                        .append(" destruido por el ca")
                        .append(char164)
                        .append("on ")
                        .append(canonStringID)
                        .append(" en ")
                        .append(stringTiempoX)
                        .append(" segundos.\n");
            } else {
                double anguloInicial = 0;
                if (anguloRecibido > 90) { anguloInicial = 180; }
                double anguloFinal;
                double rangoDeComparacion = 10;
                double anguloFuncional = 0;
                for (int k = 0; k < 80; ++k) {
                    if (anguloRecibido > 90) { anguloFinal = anguloInicial - rangoDeComparacion; }
                    else { anguloFinal = anguloInicial + rangoDeComparacion; }
                    double calculoConAnguloInicial = calcularYcuandoX(PI, GRAVEDAD, velocidadInicial, posicionInicialX,
                                                                      posicionInicialY,
                                                                      xDeObjetivo, anguloInicial);
                    double calculoConAnguloFinal = calcularYcuandoX(PI, GRAVEDAD, velocidadInicial, posicionInicialX,
                                                                    posicionInicialY, xDeObjetivo, anguloFinal);
                    if (calculoConAnguloInicial == yDeObjetivo) { anguloFuncional = round(anguloInicial); }
                    else if (calculoConAnguloFinal == yDeObjetivo) { anguloFuncional = round(anguloFinal); }
                    if (calculoConAnguloInicial == yDeObjetivo || calculoConAnguloFinal == yDeObjetivo) {
                        int movedGrades = static_cast<int>(round(abs(anguloRecibido - anguloFuncional)));
                        string stringGrades = to_string(movedGrades);
                        resultadoFinal.append("\nReajuste de ")
                                .append(stringGrades)
                                .append(" grados requerido en el ca")
                                .append(char164)
                                .append("on ")
                                .append(canonStringID)
                                .append("\n");
                        break;
                    } else if (calculoConAnguloInicial < yDeObjetivo && yDeObjetivo < calculoConAnguloFinal) {
                        rangoDeComparacion/=10;
                    } else {
                        if (anguloRecibido > 90) { anguloInicial -= rangoDeComparacion; }
                        else { anguloInicial += rangoDeComparacion; }
                    }
                }
            }
        }
    }
    if (invalidData) { cout << "\nDatos de entrada invalidos\n"; }
    else { cout << resultadoFinal; }
    return 0;
}