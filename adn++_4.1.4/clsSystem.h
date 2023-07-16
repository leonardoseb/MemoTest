//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.2 estable         //
//              @@@@@  @    @@@@@  @    @       @    29/09/2012              //
//                                                                           //
//#############################################################################
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// Avis Software es marca registrada.
//
// Este programa es software libre; puede redistribuirlo o modificarlo bajo los
// terminos de la Licencia Publica General de GNU tal como se publica por la
// Free Software Foundation; ya sea la version 3 de la Licencia, o (a su
// eleccion) cualquier version posterior.
//
// Este programa se distribuye con la esperanza de que le sea util, pero SIN
// NINGUNA GARANTIA; sin incluso la garantia implicita de MERCANTILIDAD o
// IDONEIDAD PARA UN PROPOSITO PARTICULAR.
//
// Vea la Licencia Publica General GNU para mas detalles.
//
// Deberia haber recibido una copia de la Licencia Publica General de GNU
// junto con este programa, si no es asi, escriba a la Free Software Foundation,
// Inc, 59 Temple Place - Suite 330, Boston, MA 02111-1307, EE.UU.
//
//#############################################################################
// ARCHIVO             : clsSystem.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.2 estable.
// FECHA DE CREACION   : 08/11/2011.
// ULTIMA ACTUALIZACION: 29/09/2012.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DEDICATORIA: A mi Padre Amadeo Calabuig (28/12/1924 - 10/03/1995).
//=============================================================================
// DESCRIPCION:
//             Este archivo incluye la definicion de la clase clsSystem
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             Los metodos clsSystem permiten compatibilidad entre Linux y
//             Windows en algunas funciones basicas del modo consola como:
//             clearScreen() y pause(), generando una interfaz que permita
//             realizar codigos verdaderamente portables.
//
//=============================================================================
//      ______________________________
//      |          clsSystem         |
//      |----------------------------|
//      |----------------------------|
//      | + clearScreen(): void      |
//      | + pause(): void            |
//      | + pause(const char*): void |
//      |____________________________|
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef CLSSYSTEM_H
#define CLSSYSTEM_H

//=============================================================================
// DETERMINAR EL SISTEMA OPERATIVO
//-----------------------------------------------------------------------------
#ifdef _WIN32                  // Inclusiones para Windows.
  class clsSystem
  {
    public:
    //=============================================================================
    // METODO    : void clearScreen()
    // ACCION    : Borra la pantalla en modo consola.
    // PARAMETROS: NADA.
    // DEVUELVE  : NADA
    //-----------------------------------------------------------------------------
    void clearScreen() {system("cls");}

    //=============================================================================
    // METODO    : void pause()
    // ACCION    : Realiza una pausa hasta que se presione ENTER
    // PARAMETROS: NADA.
    // DEVUELVE  : NADA.
    // NOTA      : Este metodo esta sobre cargado, en este caso realiza una pausa
    //             sin mensaje
    //-----------------------------------------------------------------------------
    void pause() {std::cin.get();}

    //=============================================================================
    // METODO    : void pause(const char* msj)
    // ACCION    : Realiza una pausa hasta que se presione ENTER
    // PARAMETROS: const char* msj --> mensaje a ser mostrado.
    // DEVUELVE  : NADA
    // NOTA      : Este metodo esta sobre cargado, en este caso realiza una pausa
    //             con mensaje aclaratorio.
    //-----------------------------------------------------------------------------
    void pause(const char* msj){std::cout << msj;std::cin.get();}
  };

#else                          // Inclusiones para Linux
  class clsSystem
  {
    public:
    //=============================================================================
    // METODO    : void clearScreen()
    // ACCION    : Borra la pantalla en modo consola.
    // PARAMETROS: NADA.
    // DEVUELVE  : NADA
    //-----------------------------------------------------------------------------
    void clearScreen() {system("clear");}

    //=============================================================================
    // METODO    : void pause()
    // ACCION    : Realiza una pausa hasta que se presione ENTER
    // PARAMETROS: NADA.
    // DEVUELVE  : NADA.
    // NOTA      : Este metodo esta sobre cargado, en este caso realiza una pausa
    //             sin mensaje
    //-----------------------------------------------------------------------------
    void pause() {std::cin.get();}

    //=============================================================================
    // METODO    : void pause(const char* msj)
    // ACCION    : Realiza una pausa hasta que se presione ENTER
    // PARAMETROS: const char* msj --> mensaje a ser mostrado.
    // DEVUELVE  : NADA
    // NOTA      : Este metodo esta sobre cargado, en este caso realiza una pausa
    //             con mensaje aclaratorio.
    //-----------------------------------------------------------------------------
    void pause(const char* msj) {std::cout << msj;std::cin.get();}
  };
#endif

#endif // CLSSYSTEM_H
//### FIN DE ARCHIVO ##########################################################
