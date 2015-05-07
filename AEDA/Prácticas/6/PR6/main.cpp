#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "binarysearchtree.h"
#include "dni.h"

void modo_demo(void);
void modo_esta(void);

void demo_insertar(dra::binarySearchTree<dra::dni>&, bool demo = false);
void demo_eliminar(dra::binarySearchTree<dra::dni>&, bool demo = false);

unsigned digits(unsigned i);

void dibujar_menu_estadisticas(unsigned c_nodos, unsigned c_pruebas);

void insertar_sin_repetir(std::vector<dra::dni>& banco);
void dibujar_tabla_estadisticas(std::vector<std::vector<unsigned>> datos);


int main(void)
{
    unsigned modo = 1; //0 = demostracion, 1 = estadistica

    do{
        system("clear");
        std::cout << "┌────────────┬───────────────────────────┐" << "\n";
        std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │" << "\n";
        std::cout << "├────────────┴───────────────────────────┤" << "\n";
        std::cout << "│ [1] Modo demostración                  │" << "\n";
        std::cout << "│ [2] Modo estadistica                   │" << "\n";
        std::cout << "│ [3] Salir                              │" << "\n";
        std::cout << "└────────────────────────────────────────┘" << "\n";
        if(modo != 1 && modo != 2 && modo != 3)
            std::cout << "✖  >";
        else
            std::cout << "   >";

        std::cout.flush();

        std::cin >> modo;

        switch(modo){
            case 1: modo_demo(); break;
            case 2: modo_esta(); break;
            case 3: std::cout << "Adios!" << std::endl;
        }


    }while(modo != 3);

    return 0;
}

void modo_demo(void)
{
    unsigned opcion = 1; //0 = demostracion, 1 = estadistica

    dra::binarySearchTree<dra::dni> arbol;

    do{
        system("clear");
        std::cout << "┌────────────┬───────────────────────────┬───────────────────┐" << "\n";
        std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │ Modo demostración │" << "\n";
        std::cout << "├────────────┴───────────────────────────┴───────────────────┤" << "\n";
        std::cout << "│ [1] Insertar Clave                                         │" << "\n";
        std::cout << "│ [2] Eliminar Clave                                         │" << "\n";
        std::cout << "│ [3] Mostrar árbol                                          │" << "\n";
        std::cout << "│ [4] Atrás                                                  │" << "\n";
        std::cout << "└────────────────────────────────────────────────────────────┘" << "\n";



        if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
            std::cout << "✖  >";
        else
            std::cout << "   >";

        std::cout.flush();

        std::cin >> opcion;

        switch(opcion){
            case 1: demo_insertar(arbol, true); break;
            case 2: demo_eliminar(arbol, true); break;
            case 3: arbol.toStream(std::cout); std::cin.ignore().get(); break;
        }


    }while(opcion != 4);
}

void demo_insertar(dra::binarySearchTree<dra::dni>& arbol, bool demo)
{
    dra::dni dummy;

    if(demo){
        unsigned clave;
        std::cout << "Introduce una clave (int): "; std::cout.flush();
        std::cin >> clave;
        dummy.value() = clave;
    }

    arbol.dra::binaryTree<dra::dni>::insert(dummy);
}

void demo_eliminar(dra::binarySearchTree<dra::dni>& arbol, bool demo)
{
    dra::dni dummy;

    if(demo){
        unsigned clave;
        std::cout << "Introduce una clave (int): "; std::cout.flush();
        std::cin >> clave;
        dummy.value() = clave;
    }

    arbol.dra::binaryTree<dra::dni>::erase(dummy);
}

void modo_esta(void)
{
    unsigned opcion = 1; //0 = demostracion, 1 = estadistica
    unsigned cantidad_pruebas = 10;
    unsigned cantidad_nodos = 10;

    do{
        dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);

        if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4){
            std::cout << "✖  >";
        }
        else if(cantidad_nodos < cantidad_pruebas){
            while(cantidad_nodos < cantidad_pruebas)
                cantidad_pruebas--;
            dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);
            std::cout << "✖  >";
        }
        else
            std::cout << "   >";

        std::cout.flush();

        std::cin >> opcion;

        switch(opcion){
            case 1:{
                std::cout << "Introduce la cantidad de nodos: "; std::cout.flush();
                std::cin >> cantidad_nodos;
            } break;
            case 2:{
                std::cout << "Introduce la cantidad de pruebas: "; std::cout.flush();
                std::cin >> cantidad_pruebas;
            } break;
            case 3:{
                std::vector<std::vector<unsigned>> datos(2); //[0] = inserciones [1] = busquedas

                for(unsigned i = 0; i < datos.size(); i++)
                    for(unsigned j = 0; j < 6 /* Numero columnas*/; j++)
                        datos[i].push_back(0);



                //Creada la tabla donde se guardarán los datos

                std::vector<dra::dni> banco_datos;

                for(unsigned i = 0; i < cantidad_nodos+cantidad_pruebas; i++)
                    insertar_sin_repetir(banco_datos);

                dra::binarySearchTree<dra::dni> arbol;

                unsigned nodos_insertados = 0;
                unsigned pruebas_hechas = 0;

                datos[0][2] = -1;

                for(unsigned i = 0; i < cantidad_nodos; i++){ //insertar
                    datos[0][0]++;
                    datos[1][0]++;
                    datos[0][1]++;

                    unsigned insertar_ahora = arbol.dra::binaryTree<dra::dni>::insert(banco_datos[i]);
                    datos[0][2] = std::min(datos[0][2], insertar_ahora);
                    datos[0][4] = std::max(datos[0][4], insertar_ahora);
                    datos[0][5] += insertar_ahora;
                    datos[0][3] = datos[0][5]/cantidad_nodos;
                    dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);
                    dibujar_tabla_estadisticas(datos);
                }

                datos[1][2] = -1;
                for(unsigned i = 0; i < cantidad_pruebas; i++){ //buscar los que ya están
                    datos[1][1]++;
                    unsigned buscar_ahora = arbol.dra::binaryTree<dra::dni>::insert(banco_datos[i%cantidad_nodos]);
                    datos[1][2] = std::min(datos[1][2], buscar_ahora);
                    datos[1][4] = std::max(datos[1][4], buscar_ahora);
                    datos[1][5] += buscar_ahora;
                    datos[1][3] = datos[1][5]/(cantidad_pruebas*2);
                    dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);
                    dibujar_tabla_estadisticas(datos);
                }

                for(unsigned i = banco_datos.size()-1; i >= cantidad_nodos; i--){ //buscar los que ya están
                    datos[1][1]++;
                    unsigned buscar_ahora = arbol.dra::binaryTree<dra::dni>::insert(banco_datos[i]);
                    datos[1][2] = std::min(datos[1][2], buscar_ahora);
                    datos[1][4] = std::max(datos[1][4], buscar_ahora);
                    datos[1][5] += buscar_ahora;
                    datos[1][3] = datos[1][5]/(cantidad_pruebas*2);
                    dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);
                    dibujar_tabla_estadisticas(datos);
                }

                //Lo enseñamos y paramos al final
                dibujar_menu_estadisticas(cantidad_nodos, cantidad_pruebas);
                dibujar_tabla_estadisticas(datos);
                std::cin.ignore().get();

            } break;
        }

    }while(opcion != 4);
}

unsigned digits(unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

void dibujar_menu_estadisticas(unsigned c_nodos, unsigned c_pruebas)
{
    system("clear");
    std::cout << "┌────────────┬───────────────────────────┬──────────────────┐" << "\n";
    std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │ Modo estadística │" << "\n";
    std::cout << "├────────────┴───────────────────────────┴──────────────────┤" << "\n";
    std::cout << "│ Cantidad de nodos actuales: " << c_nodos << std::setw(33 - digits(c_nodos)) << "│" <<"\n";
    std::cout << "│ Numero de pruebas actual: "   << c_pruebas << std::setw(35 - digits(c_pruebas)) << "│" <<"\n";
    std::cout << "│ [1] Cambiar numero de nodos en el árbol                   │" << "\n";
    std::cout << "│ [2] Cambiar número de pruebas                             │" << "\n";
    std::cout << "│ [3] Ejecutar                                              │" << "\n";
    std::cout << "│ [4] Atrás                                                 │" << "\n";
    std::cout << "└───────────────────────────────────────────────────────────┘" << "\n";
}

void insertar_sin_repetir(std::vector<dra::dni>& banco)
{
    dra::dni dummy;
    for(int i = 0; i < banco.size(); i++){
        if(dummy == banco[i]){
            dra::dni aux;
            dummy = aux;
            i = 0;
        }
    }
    banco.push_back(dummy);
}

void dibujar_tabla_estadisticas(std::vector<std::vector<unsigned>> datos)
{
    std::cout << "┌───────────┬───────┬─────────┬────────┬───────┬────────┐" << "\n";
    std::cout << "│ Operación │ Nodos │ Pruebas │ Minimo │ Medio │ Máximo │" << "\n";
    std::cout << "│ Inserción │" << datos[0][0] << std::setw(10 - digits(datos[0][0])) << "│" << datos[0][1] << std::setw(12 - digits(datos[0][1])) << "│" << datos[0][2] << std::setw(11 - digits(datos[0][2])) << "│" << datos[0][3] << std::setw(10 - digits(datos[0][3])) << "│" << datos[0][4] << std::setw(11 - digits(datos[0][4])) << "│" << "\n";
    std::cout << "│ Búsqueda  │" << datos[1][0] << std::setw(10 - digits(datos[1][0])) << "│" << datos[1][1] << std::setw(12 - digits(datos[1][1])) << "│" << datos[1][2] << std::setw(11 - digits(datos[1][2])) << "│" << datos[1][3] << std::setw(10 - digits(datos[1][3])) << "│" << datos[1][4] << std::setw(11 - digits(datos[1][4])) << "│" << "\n";
    std::cout << "└───────────┴───────┴─────────┴────────┴───────┴────────┘" << "\n";
}
