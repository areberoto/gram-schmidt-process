//Alberto Alvarez González
//Proceso de Gram-Schmidt
#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#define size 3 //se define como una constante
#define size_u 5 //se define como una constante

using namespace std;
void magnitud (int n, double m[], double MAG[]); //Calcula la magnitud de un vector y determina condiciones de impresión
void imprimir (double imp[]); //imprime un vector de 3 dimensiones
void imprimir_unitario (double imp[]); //imprime un vector unitario.
void fraccion (double n);//imprime el valor de un vector como fracción si encuentra una equivalente.
void vector2_ortogonal (double V2[], double U1[], double V2_O[]);//Calcula un vector ortogonal a U1
void unitario (double U[], int n, double MAG[], double V_O[]);//Calcula un vector unitario
void vector3_ortogonal (double V3[], double U1[], double U2[], double V3_O[]);//Calcula un vector ortogonal a U1 y U2
void descomponer (int suma, int &valor_afuera, int &valor_adentro);//factoriza la magnitud dentro de la raíz cuadrada

int main()
{
    double V1[size]={}, V2[size]={}, V2_O[size]={}, V3[size]={}, V3_O[size]={}, U1[size_u] = {}, U2 [size_u]={}, U3[size_u]={}, MAG[size_u]={};
    char s;
    /*  V1, V2 y V3 son los vectores originales introducidos por el usuario.
    U1, U2 y U3 son los vectores unitarios que obtiene el programa. El arreglo consta de 5 valores, con [0] = magnitud
    dentro de la raiz y [1] = magnitud fuera de la raíz (racionalizado); [2], [3], [4] son los valores de los respectivos vectores.
    V2_O y V3_O son los vectores ortogonales que se calculan para obtener posteriormente U2 y U3.
    MAG es el arreglo que se encarga de almacenar los datos de las magnitudes, ya sean raíces exactas o no.
          [0] = raíz de magnitud de V1, sin tomar en cuenta el valor de afuera de la raíz en caso de existir.
          [1] = raíz de magnitud de V2, sin tomar en cuenta el valor de afuera de la raíz en caso de existir.
          [2] = raíz de magnitud de V3, sin tomar en cuenta el valor de afuera de la raíz en caso de existir.
          [3] = Condición para el caso de ser magnitud exacta e indicarle a la función de imprimir si imprime el escalar o no.
          [4] = En caso de racionalizar, guarda el valor fuera de la raíz.  */
    do //ciclo encargado de repetir el proceso si el usuario así lo desea
    {
    cout << "\n\t\tPROCESO DE GRAM-SCHMIDT\n\tObtencion de una base ortonormal en R^3\n" << endl;
    cout << "Ingrese los tres vectores iniciales..." << endl;
    cout << "\n\t\tV1: ";
    for (int i = 0; i < size; i++)
        cin >> V1[i]; //Se ingresan los valores del vector V1 separados por un espacio
    cout << "\t\tV2: ";
    for (int i = 0; i < size; i++)
        cin >> V2[i];//Se ingresan los valores del vector V2 separados por un espacio
    cout << "\t\tV3: ";
    for (int i = 0; i < size; i++)
        cin >> V3[i];//Se ingresan los valores del vector V3 separados por un espacio

    cout << "\n1.- SE OBTIENE EL VECTOR UNITARIO DE V1:\n\n\tU1 = V1/|V1|\n\n\t\tU1 = ";
    magnitud(1, V1, MAG);//Se llama a la función para calcular la magnitud de V1. El valor 1 hace referencia al vector V1.
    unitario (U1, 1, MAG, V1);//Se llama a la función unitario para normalizar V1
    imprimir_unitario(U1);//Imprime el vector U1

    cout << "\n\n2.- SE OBTIENE UN VECTOR V2' ORTOGONAL A U1:\n";
    cout << "\n\tV2'= V2 - (V2*U1)U1"; //Le indica al usuario la fórmula que se esta usando en este paso
    cout << "\n\tV2'= "; imprimir(V2); cout << "-["; imprimir(V2);
    cout << "*"; imprimir_unitario(U1); cout << "]["; imprimir_unitario(U1); cout << "]"; /*imprime los valores sustituídps en
                                                                                               la formula anterior*/
    vector2_ortogonal(V2, U1, V2_O); //Se llama a la función para obtener el vector ortogonal a U1
    cout << "\n\n\t\tV2' = "; imprimir (V2_O); cout << endl; //Imprime el vector ortogonal (V2_O) a U1

    cout << "\n3.- SE NORMALIZA EL VECTOR V2':\n\n\tU2 = V2'/|V2'|\n\n\t\tU2 = ";
    magnitud (2, V2_O, MAG);//Se llama a la función para calcular la magnitud de V2_O. El valor 2 hace referencia al vector V2_O.
    unitario (U2, 2, MAG, V2_O);//Se llama a la función unitario para normalizar V2_O
    imprimir_unitario(U2);//Imprime el vector unitario U2

    cout << "\n\n4.- SE OBTIENE UN VECTOR V3' ORTOGONAL A U1 Y U2:\n";
    cout << "\n\tV3' = V3 - (V3*U1)U1 - (V3*U2)U2"; //indica al usuario la fórmula que se esta usando en este paso
    cout << "\n\tV3' ="; imprimir(V3); cout << "-["; imprimir(V3); cout << "*"; imprimir_unitario(U1);
    cout << "]["; imprimir_unitario(U1); cout << "]"; cout << "-["; imprimir(V3);
    cout << "*"; imprimir_unitario(U2); cout << "]["; imprimir_unitario(U2); cout << "]"; //Sustituye los valores en la fórmula
    vector3_ortogonal(V3, U1, U2, V3_O);//Se llama a la función para obtener el vector ortogonal a U1 y U2
    cout << "\n\n\t\tV3' = "; imprimir (V3_O); cout << endl;//imprime el vector ortogonal (V3_O) a los vectores unitarios U1 y U2

    cout << "\n5.- SE NORMALIZA EL VECTOR V3':\n\n\tU3 = V3'/|V3'|\n\n\t\tU3 = ";
    magnitud (3, V3_O, MAG);//Se llama a la función para calcular la magnitud de V3_O. El valor 3 hace referencia al vector V3_O.
    unitario (U3, 3, MAG, V3_O);//Se llama a la función unitario para normalizar V3_O
    imprimir_unitario(U3);//Imprime el vector unitario U3

    //Se imprimen los tres vectores unitarios como resultado final
    cout << "\n\n\n\tLOS VECTORES U1, U2, Y U3 FORMAN UNA BASE ORTONORMAL: \n\n\t\tU1: ";
    imprimir_unitario(U1); cout << "\n\t\tU2: ";
    imprimir_unitario(U2);cout << "\n\t\tU3: ";
    imprimir_unitario(U3);

    //si el usuario desea puede repetir el proceso para la obtención de otra base ortonormal
    cout << "\n\nDesea calcular otra base ortonormal? Si es asi presione (Y),\nde lo contrario cualquier caracter...";
    cin >> s;
    s = toupper(s);//se hace mayúscula de tal forma que el programa reconoce cualquier caracter
    system("cls");//limpia la pantalla para los procesos siguientes
    }while (s == 'Y'); //condición de paro para el ciclo do while
    return 0;
}
void magnitud (int n, double m[], double MAG[]) // n es el número del vector introducido
{
    double det, det2;//variables para condiciones
    double suma = 0;//se declara flotante dado que se busca un entero
    int valor_afuera = 1, valor_adentro = 1;//variables globales, las cuales se modifican en la función descomponer.
    suma = pow(m[0], 2) + pow (m[1], 2) + pow(m[2], 2);//suma los cuadrados de los valores del vector
    if (suma != 0)
    {
        det = floor (sqrt(suma));//se quitan los decimales de la raiz de la suma

        if ((det - sqrt(suma)) == 0)//se verifica si la raiz es exacta o no. En caso de serlo se guarda el valor de la raiz
        {   MAG[n-1] = sqrt(suma);//La magnitud se guarda en el arreglo MAG. (n-1) se debe a que [0],[1],[2] se reservan para U1, U2, U3
            MAG[3] = -1;}//Indica si la función unitario va a imprimir el escalar o no (-1). [3] se reserva para la condición...
        else
        {
            det2 = floor (suma);//Elimina decimales
            if ((suma - det2) == 0) //verifica si la suma es un numero entero. En caso de serlo, se llama a la función descomponer.
            {   descomponer(suma, valor_afuera, valor_adentro);//función para racionalizar la raíz.
                MAG[n-1] = sqrt(valor_adentro);//Se guarda el resultado de la raíz de la parte interna.
                MAG[3] = 1; //Elimina el -1 si antes se había cumplido para escalar exacto
                MAG[4] = valor_afuera;}//Almacena el valor fuera de la raíz
            else //En caso de ser una suma con decimales simplemente calcula el escalar
            {   MAG [n-1] = sqrt(suma);
                MAG [3] = 1;}//Elimina el -1 si antes se había cumplido para escalar exacto.
        }
    }
    else
    {   MAG[n-1] = 1;
        MAG[3] = -1;}
}
void descomponer (int suma, int &valor_afuera, int &valor_adentro) //descompone el resultado de la suma para posteriormente racionalizar, si es posible.
{
    int descompuesto [20] = {}, j = 0, i = 2, r = 0, rc[20] = {1};
    /* descompuesto [] es el arreglo que guarda los factores de la suma
    j = subíndice para descompuesto
    i = posibles divisores de la suma
    r = subíndice para el arreglo rc[]
    rc[] = arreglo que guarda los valores racionalizados tales que tienen raíz cuadrada exacta y se extraen de la suma de los cuadrados. */
    do
    {
        if (suma % i == 0)//Verifica para qué valor la suma tiene divisores
            {   suma /= i; //Divide la suma entre su divisor exacto
                descompuesto[j] = i; //Se guardan los valores obtenidos al descomponer la suma
                j++;}
        else i++; //Aumenta el posible divisor
    } while (suma > 1);//condicion de paro para la búsqueda de divisores

    for (int n = 0; n < j; n++)//n < j dado que evalúa los valores guardados en descompuesto
    {
            for (int p = n+1; p < j-1; p++)//Racionaliza la suma dentro de la raíz
            {
                if (descompuesto[n] != 0)//condición que permite la repetición del ciclo sin volver a evaluar los valores anteriores
                {
                    if (descompuesto [n] == descompuesto[p])
                        {   rc[r] = descompuesto[n];//dado que se esta calculando raíz cuadrada de un numero al cuadrado sólo se almacena un valor
                            descompuesto[n] = descompuesto[p] = 0;//de esta forma no se toman en el ciclo la siguiente vez.
                            r++;}//Aumenta el subíndice del arreglo rc[].
                }
            }
    }
    for (int i = 0; i < r; i++) //multiplica los valores obtenidos fuera de la raíz de tal forma que se tiene un solo entero
        valor_afuera *= rc[i];//se almacena en la variable global
    for (int i = 0; i < j; i++)//Se realiza lo mismo pero con el valor de adentro de la raíz
    {   if (descompuesto[i] != 0) //se evitan los valores igualados a 0
        valor_adentro *= descompuesto[i];}
}
void unitario (double U[], int n, double MAG[], double V_O[]) //Calcula el vector unitario
{
    double det, resta;
    if (MAG[3] == -1) //Si la raíz fue exacta entra en el ciclo
    {
        for (int i = 0; i < size_u; i++)
        {
            if(i == 0)
                U[i] = -1; //El valor del escalar toma el valor de -1 y se utiliza como condición futura.
            else
            {
                if(i == 1)
                {
                    for (int j = 0; j < size; j++) // Evalúa el producto de la magnitud por el vector, evitando decimales
                    {   det = floor (V_O[j]/MAG[n-1]);
                        resta = det -(V_O[j]/MAG[n-1]);
                        if (resta != 0)
                        {   i = j = size_u; // termina con el ciclo
                            MAG[3] = 1;} // Dado que se evita tener decimales, no se multiplica por el escalar.
                    }
                }
            if (i != size_u) //En caso de que el producto sea entero se realiza la operación
                U[i+1] = V_O[i-1]/MAG[n-1]; //MAG[3] permanece como -1.
            }
        }
    }
    if (MAG[3] != -1)//Si la magnitud no es un valor entero cuando se obtiene su raíz, se guarda en el subíndice [0] del vector unitario
    {
        /*Si la magnitud es un decimal muy pequeño, se realiza todo el producto del vector. Con esto
        se evita tener valores muy pequeños dentro de la raíz, lo cual es poco legible para el usuario*/
        if(MAG[n-1] < 0.0001)
        {
            for(int i = 2; i < size_u; i++)
                U[i] = V_O[i-2] * (1/MAG[n-1]) * (1/MAG[4]);
            U[0] = -1; //dado que ya se multiplicó por su magnitud, se iguala a -1
            U[1] = 1;//el valor fuera de la raíz toma el valor de 1, dado que no afecta el vector cuando se multiplica por la unidad
        }
        else //en caso de no ser un número tan pequeño se almacena por separado cada elemento
        {
            for (int i = 0; i < size_u; i++)
            {   if (i == 0)
                U[i] = MAG[n-1]; //Se almacena la magnitud dentro de la raíz en U[0]
                else if (i == 1)
                U[i] = MAG[4]; //Se almacena el valor que esta afuera de la raíz en U[1]
                else U[i] = V_O[i-2];} //Copia los elementos del vector ortogonal al vector unitario
        }
    }
}
void imprimir_unitario (double imp[]) //Imprime el vector unitario n.
{
    double det = 0;
    for (int i = 0; i < size_u; i++)
    {
        if (i == 0)
        {
            if (imp[0] != -1)//En caso de no tener una codición igual a -1, imprime la magnitud como escalar
            {
                cout << "1/";
                if (imp[1] != 1)//Imprime la magnitud. Si es igual a 1 el valor de afuera de la raíz no lo imprime
                    cout << imp[1] << "(" << pow(imp [i], 2) << ")^1/2 ";
                else
                cout << "(" << pow(imp [i], 2) << ")^1/2 ";//No imprime un escalar = 1 dado que esta implícito
            } cout << "(";
        }
        else if (i > 1)
            {
                det = floor(imp[i]);//elimina decimales para posteriormente determinar si es entero o no
                if((det - imp[i]) != 0)//En caso de ser decimal llama a la función fraccion.
                    fraccion (imp[i]);//la función busca una fracción equivalente al decimal
                else //De lo contrario imprime el numero entero
                    cout << imp[i];
                if (i < size_u - 1) //lo restante es por estética
                    cout << ", ";
                else
                    cout << ")";
            }
    }
}
void fraccion (double n) //Imprime una fracción equivalente al decimal que recibe
{
    bool det = true;
    double f;
    for (int i = 1; i < 10; i++) //Valores que toma el numerador
    {
        for (int j = -9; j < 10; j++)//Valores que toma el denominador
        {
            if ((j != -1) && (j != 0) && (j != 1))//Valores del denominador que se evitan
            {
             if (i != j) //Para no obtener un entero 1 se descarta i = j
            {
                f = i/(j+0.0);//Se obliga a f a ser un decimal con 0.0, y de esta forma no ser tomado por el programa como entero
                if ((n > (f - 0.001))&&(n < (f + 0.001))) //Intervalo de tolerancia al encontrar la fracción equivalente
                {
                    if (j < 0)//Por estética: en caso que el denominador sea negativo imprime su valor absoluto y el signo - como caracter
                        cout << "-" << i << '/' << abs(j);
                    else
                        cout << i << '/' << j;
                    det = false; //Condición para no imprimir el numero como decimal
                    i = j = 10; //en caso de haber encontrado la fracción equivalente antes del término del ciclo for, se rompe el ciclo igualando i y j a 10
                }
            }
            }
        }
    }
    if (det != false) //En caso de no encontrar una fracción equivalente se imprime el decimal
        cout << n;
}
void imprimir (double imp[]) //Imprime arreglos de vectores de tres elementos (los originales)
{
    double det;
    cout << "(";
    for (int i = 0; i < size; i++)
    {
            det = floor(imp[i]); //elimina decimales para comprobar si es entero o no
            if((det - imp[i]) != 0)//En caso de ser necesario busca una fraccion equivalente
                fraccion (imp[i]);
            else
                cout << imp[i]; //imprime el entero en caso de no ser decimal
            if (i < size - 1)
                cout << ", ";
    }
    cout << ")";
}
void vector2_ortogonal (double V2[], double U1[], double V2_O[]) //Se obtiene el vector ortogonal a U1
{
    double pp = 0, pp_u[size] = {};
    if (U1[0] == -1) //En caso de que el vector unitario U1 ya este multiplicado por su escalar
    {
        for (int i = 0; i < size; i++) //Se hace el producto punto y se almacena el escalar en pp
            pp += V2[i] * U1[i+2];
        for (int i = 0; i < size; i++)//Se multiplica el escalar (pp) por los elementos del vector unitario y se almacenan en pp_u
            pp_u[i] = pp*U1[i+2];
    }
    else//en caso de no estar multiplicado por el escalar entra a este ciclo, el cual incluye la multiplicación del escalar
    {
        for (int i = 0; i < size; i++)//Se hace el producto punto y se almacena el escalar en pp
            pp += V2[i] * U1[i+2] * (1/(U1[0]*U1[1]));
        for (int i = 0; i < size; i++)//Se multiplica el escalar (pp) por los elementos del vector unitario y se almacenan en pp_u
            pp_u[i] = pp*U1[i+2]*(1/(U1[0]*U1[1]));
    }
    for (int i = 0; i < size; i++) //Almacena el nuevo vector en V2_O
    {
        V2_O[i] = V2[i] - pp_u[i];
        if((V2_O[i] > -0.00001) && (V2_O[i]< 0.00001)) //En caso de ser un valor muy pequeño se redondea a 0 para evitar errores y dar mejor lectura al usuario
            V2_O[i] = 0;
    }

}
void vector3_ortogonal (double V3[], double U1[], double U2[], double V3_O[])//Se obtiene el vector ortogonal a U1 y a U2
{
    double pp = 0, pp_u[size] = {}, pp_2 = 0, pp_u2[size] = {};
    if (U1[0] == -1)//En caso de que el vector unitario U1 ya este multiplicado por su escalar
    {
        for (int i = 0; i < size; i++)//Se hace el producto punto y se almacena el escalar en pp
            pp += V3[i] * U1[i+2];
        for (int i = 0; i < size; i++)//Se multiplica el escalar (pp) por los elementos del vector unitario
            pp_u[i] = pp*U1[i+2];
    }
    else//en caso de no estar multiplicado por el escalar entra a este ciclo, el cual incluye la multiplicación del escalar
    {
        for (int i = 0; i < size; i++)
            pp += V3[i] * U1[i+2] * (1/(U1[0]*U1[1]));
        for (int i = 0; i < size; i++)
            pp_u[i] = pp*U1[i+2]*(1/(U1[0]*U1[1]));
    }
    if (U2[0] == -1)//lo siguiente es lo mismo pero con el vector unitario U2...
    {
        for (int i = 0; i < size; i++)
            pp_2 += V3[i] * U2[i+2];
        for (int i = 0; i < size; i++)
            pp_u2[i] = pp_2*U2[i+2];
    }
    else
    {
        for (int i = 0; i < size; i++)
            pp_2 += V3[i] * U2[i+2] * (1/(U2[0]*U2[1]));
        for (int i = 0; i < size; i++)
            pp_u2[i] = pp_2*U2[i+2]*(1/(U2[0]*U2[1]));
    }
    for (int i = 0; i < size; i++)//Almacena el nuevo vector en V3_O
    {
        V3_O[i] = V3[i] - pp_u[i] - pp_u2[i];
        if((V3_O[i] > -0.00001) && (V3_O[i]< 0.00001))//En caso de ser un valor muy pequeño se redondea a 0 para evitar errores y dar una mejor lecutra de los valores al usuario
            V3_O[i] = 0;
    }
}
