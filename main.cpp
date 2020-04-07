#include <iostream>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <stdexcept>
#include <bitset>

using namespace std;

//.h & .cpp
#include "definiciones.h"
#include "funciones.cpp"

int main()
{
    //------

    int op = -1;
    bool exit = false;
    string param_string1 = "";
    string param_string2 = "";
    int param_int;
    int param_int2;
    int param_int3;
    float param_float1;
    float param_float2;
    DtFecha param_dtfecha;
    vaf av;

    //------

    while (exit == false)
    {
        string param_string1 = "";
        string param_string2 = "";
        int param_int=0;
        int param_int2=0;
        int param_int3=0;
        float param_float1=0;
        float param_float2=0;

        cout << "Bienvanido. ELija la opcion." << endl;
        cout << "     "
             << "1) Registrar usuario" << endl;
        cout << "     "
             << "2) Agregar vehiculo" << endl;
        cout << "     "
             << "3) Ingresar Vaije" << endl;
        cout << "     "
             << "4) Viajes Antes de Fecha" << endl;
        cout << "     "
             << "5) Eliminar Viajes" << endl;
        cout << "     "
             << "6) Cambiar Bateria Vehiculo" << endl;
        cout << "     "
             << "7) Obtener Vehiculos" << endl;
        cout << "     "
             << "0) Salir" << endl;
        cout << "Opcion:" << endl;
        cin >> op;

        switch (op){
            case 0:
                LimpiarPantalla();
                cout << "Gracias!" << endl;
                exit = true;
                break;
            case 1:
                LimpiarPantalla();
                //------

                cout << "Registrar Usuario" << endl;
                param_string1 = SolicitarString("Nombre");
                param_string2 = SolicitarString("Cedula");
                RegistrarUsuario(param_string1, param_string2);

                //------
                Espera(2);
                LimpiarPantalla();
                break;

            case 2:
                LimpiarPantalla();
                //------

                cout << "Registrar Vehiculo" << endl;
                param_int = SolicitarInt("nro Serie");
                //do
                //{
                    param_float1 = SolicitarFloat("Porcentaje Bateria");
                //if ((param_float1 > 100) && (param_float1 < 0))
                //{
                //    cout << "          El porcentaje de bateria no es aceptable, ingreselo nuevamente" << endl;
                //}
                //}
                //while ((param_float1 > 100) && (param_float1 < 0));
                //do
                //{
                    param_float2 = SolicitarFloat("Precio Base");
                //if (param_float2 <= 0)
                //{
                //cout << "          El Precio Base debe ser positivo, ingreselo nuevamente" << endl;
                //}
                //}
                //while (param_float2 <= 0);

                AgregarVehiculo(param_int, param_float1, param_float2);

                //------
                Espera(3);
                LimpiarPantalla();
                break;
            case 3:
                LimpiarPantalla();
                //------

            cout << "Ingresar Viaje" << endl;
            if (cant_usuarios == 0)
            {
                cout << "     No existen Usuarios" << endl;
            }
            else
            {
                if (cant_vehiculos == 0)
                {
                    cout << "     No existen Vehiculos" << endl;
                }
                else
                {
                    int i;
                    int ubc;
                    bool ci=false;
                    bool nserie=false;
                    try
                    {
                        param_string1 = SolicitarString("Cedula");
                        ubc=BuscarUsuario(param_string1);
                        if(ubc!=-1)
                        {
                            ci=true;
                        }
                        if(ci==false)
                        {
                            throw invalid_argument("La cedula ingresada no existe");
                        }
                        param_int = SolicitarInt("nro Serie");
                        ubc=BuscarVehiculo(param_int);
                        if(ubc!=-1)
                        {
                                nserie=true;
                        }

                        if(nserie==false)
                        {
                            throw invalid_argument("No existe un vehiculo con ese Nro de serie.");
                        }

                        param_int2 = SolicitarInt("Duracion Viaje");
                        if (param_int2 <= 0)
                        {
                            throw invalid_argument("          La Duracion Viaje debe ser positiva.");
                        }

                        param_int3 = SolicitarInt("Distancia Viaje");
                        if (param_int3 <= 0)
                        {
                            throw invalid_argument("          La Distancia Viaje debe ser positiva.");
                        }

                        param_dtfecha = SolicitarFecha("Fecha del Viaje");
                        IngresarViaje(param_string1, param_int, param_int2, param_int3, param_dtfecha);
                    }
                    catch (const std::invalid_argument& ia)
                    {
                        std::cerr << "Invalid argument: " << ia.what() << '\n';
                    }
                }
            }

                //------

                Espera(8);
                LimpiarPantalla();
                break;
            case 4:
                LimpiarPantalla();
                //------

                cout <<"Viajes Antes de Fecha"<<endl;
                if (cant_usuarios == 0)
                {
                    cout << "     No existen Usuarios" << endl;
                }
                else{
                    param_string1=SolicitarString("Cedula");
                    param_dtfecha=SolicitarFecha("Fecha antes de viaje");
                    av=verviajesantesdefecha(param_dtfecha,param_string1);
                    cout << "la cantidad de viajes encontrados fueron: " << av.cont << endl;
                }
                //------
                Espera(3);
                LimpiarPantalla();
                break;
            case 5:
                LimpiarPantalla();
                //------

                //------
                Espera(3);
                LimpiarPantalla();
                break;
            case 6:
                LimpiarPantalla();
                //------

                cout << "Cambio de Porcentaje de Bateria" << endl;
                param_int = SolicitarInt("nro Serie");
                do
                {
                    param_float1 = SolicitarFloat("Porcentaje Bateria");
                    if ((param_float1 > 100) && (param_float1 < 0))
                    {
                        cout << "          El porcentaje de bateria no es aceptable, ingreselo nuevamente" << endl;
                    }
                }
                while ((param_float1 > 100) && (param_float1 < 0));
                cambiarBateriaVehiculo(param_int, param_float1);

                //------
                Espera(3);
                LimpiarPantalla();
                break;
            case 7:
                LimpiarPantalla();
                //------
                if(a_Vehiculos[0]==NULL){
                    cout << "     No existen Vehiculos" << endl;
                }
                else{
                    printVehiculos();
                }

                //------
                Espera(3);
                LimpiarPantalla();
                break;
            default:
                LimpiarPantalla();
                //------

                throw std::invalid_argument("El numero que ingreso no es valido. Intente de nuevo.");

                //------
                Espera(3);
                LimpiarPantalla();
            }

    }

    //------

    return 0;
}
