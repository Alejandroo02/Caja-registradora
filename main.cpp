#include <iostream>
#include <string>
#include <locale>
#include <vector>

using namespace std;

bool esNegativo(double precio) //Funcion para comprobar si el numero introducido es negativo
{
    if(precio < 0)
    {
        return false;
    }
    return true;
}

void devuelta(double totalCompra, double pago) //Funcion para mostrar la devuelta en cada moneda
{
    int cantidadMoneda [10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Arreglo que almacena cada moneda devuelta
    string moneda[10] = {"$100", "$50", "$20", "$10", "$5", "$1", "25¢", "10¢" , "5¢", "1¢"}; //Arreglo de nombres de monedas

    double devolucion = pago - totalCompra;
    cout << "Su devuelta es: ";
    cout << devolucion << endl;

    while(true) //Ciclo while que calcula la devuelta de la compra
    {
        if(devolucion >= 100)
        {
            cantidadMoneda[0]++;
            devolucion = devolucion - 100;
        }
        else if(devolucion >= 50)
        {
            cantidadMoneda[1]++;
            devolucion = devolucion - 50;
        }
        else if(devolucion >= 20)
        {
            cantidadMoneda[2]++;
            devolucion = devolucion - 20;
        }
        else if(devolucion >= 10)
        {
            cantidadMoneda[3]++;
            devolucion = devolucion - 10;
        }
        else if(devolucion >= 5)
        {
            cantidadMoneda[4]++;
            devolucion = devolucion - 5;
        }
        else if(devolucion >= 1)
        {
            cantidadMoneda[5]++;
            devolucion = devolucion - 1;
        }
        else if(devolucion >= 0.25)
        {
            cantidadMoneda[6]++;
            devolucion = devolucion - 0.25;
        }
        else if(devolucion >= 0.1)
        {
            cantidadMoneda[7]++;
            devolucion = devolucion - 0.1;
        }
        else if(devolucion >= 0.05)
        {
            cantidadMoneda[8]++;
            devolucion = devolucion - 0.05;
        }
        else if(devolucion >= 0.01)
        {
            cantidadMoneda[9]++;
            devolucion = devolucion - 0.01;
        }
        else
        {
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        cout << moneda[i] + "\t";
    }

    cout << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << cantidadMoneda[i];
        cout << "\t";
    }

}

int main() //Funcion main donde se introducen los precios de los articulos y la cantidad a pagar
{
    locale loc;
    double totalCompra = 0;
    double precio = 0;
    double pago = 0;
    char afirmacion;

    while(true) //Ciclo while que permite comprar mas de un articulo
    {
        cout << "Introdusca el precio del producto: ";
        cin >> precio;

        if(!esNegativo(precio)) //Chequea si el precios es negativo
        {
           continue;
        }

        totalCompra = totalCompra + precio;

        cout << "Desea seguir comprando? (s/n): ";
        cin >> afirmacion;

        if(tolower(afirmacion, loc) == 'n') //Condicion para dejar de comprar articulos
        {
            break;
        }
    }

    cout << "Su total de compra hace: ";
    cout << totalCompra << endl;

    while(true)
    {
        cout << "Con cuanto pagara?: ";
        cin >> pago;

        if (pago < totalCompra){
            cout << "Lo que introdujo es menor al total de la compra, intente de nuevo." << endl;
            continue;
        }

        break;
    }

    devuelta(totalCompra, pago);

    return 0;
}
