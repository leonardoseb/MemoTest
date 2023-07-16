//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.4 estable         //
//              @@@@@  @    @@@@@  @    @       @    29/05/2013              //
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
//=============================================================================
// Que es Avis adn++
//
//     Avis adn++ es un sistema de librerias clases desarrolladas en c++, y
//     basadas en las SDL de Sam Lantinga.
//
//     El objetivo de adn++, es introducir a los alumnos en la OOP (programa-
//     cion orientada a objeto.
//
//     Avis adn++ es un producto registrado de Avis SOFTWARE.
//
//-----------------------------------------------------------------------------
// ARCHIVOS QUE COMPONEN EL SISTEMA Avis adn++
//
// El paqueta Avis adn++ se compone de los siguientes archivos.
//
// =============================================================================
// |                            ARCHIVOS DEL SISTEMA                           |
// |___________________________________________________________________________|
// |         ARCHIVO       |     VERSION     |    FECHA       |   PRINCIPALES  |
// |-----------------------+-----------------+----------------|----------------|
// | main.cpp              |  v1.0.0 estable |   29/05/2013   | Principal      |
// | adn++.h               |  v4.1.4 estable |   29/05/2013   | Este archivo   |
// |.......................|.................|................|................|
// |         ARCHIVO       |     VERSION     |    FECHA       | TIPOS DE DATOS |
// |-----------------------+-----------------+----------------|----------------|
// | videoTypes.h          |  v4.1.3 estable |   07/10/2012   | Video/Pantalla |
// | mouseTypes.h          |  v4.1.3 estable |   07/10/2012   | Mouse          |
// | keyboardTypes.h       |  v4.1.3 estable |   07/10/2012   | Teclado        |
// | colorTypes.h          |  v4.1.3 estable |   07/10/2012   | Colores        |
// | spriteTypes.h         |  v4.1.3 estable |   07/10/2012   | Sprites        |
// | textTypes.h           |  v4.1.3 estable |   07/10/2012   | Textos         |
// |.......................|.................|................|................|
// |         ARCHIVO       |     VERSION     |    FECHA       |      CLASES    |
// |-----------------------+-----------------+----------------|----------------|
// | clsBasicScreen.h      |  v4.1.3 estable |   17/10/2012   | Abstracta      |
// | clsBasicSprite.h      |  v4.1.3 estable |   17/10/2012   | Abstracta      |
// | clsContactSprite.h    |  v4.1.4 estable |   18/10/2012   | Abstracta      |
// | clsDot.h              |  v4.1.0 estable |   29/09/2012   | Instanciable   |
// | clsEngine             |  v4.1.0 estable |   29/09/2012   | Abstracta      |
// | clsError.h            |  v4.1.4 estable |   18/10/2012   | Instanciable   |
// | clsEvent.h            |  v4.1.1 estable |   29/09/2012   | Instanciable   |
// | clsGraphicMode.h      |  v4.1.0 estable |   02/10/2012   | Instanciable   |
// | clsImage.h            |  v4.1.2 estable |   02/10/2012   | Instanciable   |
// | clsLog                |  v4.1.0 estable |   29/09/2012   | Instanciable   |
// | clsMovilSprite.h      |  v4.1.3 estable |   17/10/2012   | Abstracta      |
// | clsRandom.h           |  v4.1.3 estable |   17/10/2012   | Instanciable   |
// | clsRectangle          |  v4.1.0 estable |   29/09/2012   | Instanciable   |
// | clsScreen.h           |  v4.1.4 estable |   29/05/2013   | Instanciable   |
// | clsSystem.h           |  v4.1.2 estable |   29/09/2012   | Instanciable   |
// | clsText.h             |  v4.1.0 estable |   29/09/2012   | Instanciable   |
// | clsTextBox.h          |  v4.1.4 estable |   24/10/2012   | Instanciable   |
// | clsTimer.h            |  v4.1.2 estable |   29/09/2012   | Instanciable   |
// | clsVirtualScreen.h    |  v4.1.0 estable |   29/09/2012   | Instanciable   |
// |_______________________|_________________|________________|________________|

//#############################################################################
// ARCHIVO             : adn++.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.4 estable.
// FECHA DE CREACION   : 15/02/2011.
// ULTIMA ACTUALIZACION: 25/10/2012
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DEDICATORIA: A mi Padre Amadeo Calabuig (28/12/1924 - 10/03/1995).
//=============================================================================
//
// DESCRIPCION:
//             Este archivo incluye la definicion del sistema adn++ (Sistema
//             de Clases para Modo Grafico para C++).
//
//             Las bibliotecas integrantes del sistema adn++ permiten:
//
//             A) Iniciar y administrar los distintos subsistemas multimedia:
//                <100>   VIDEO.
//
//             B) Reactivar las salidas por consola.
//             C) Administrar los errores.
//             D) Administrar imagenes en memoria RAM.
//             E) Administrar pantallas tanto virtuales como fisicas.
//             F) Administrar Sprites.
//             G) Administrar eventos tales como:
//                G.1) Teclado.
//                G.2) Mouse.
//                G.3) Joystick.
//             ----------------------------------------------------------------
//
//             NOTAS:
//                   1) adn++ utiliza las librerias SDL (Simple DirectMedia
//                      Layer) de Sam Lantinga.
//
//                      Las SDL se distribuyen con licencia LGPL y tienen la
//                      ventaja de ser multiplataforma.
//
//                   2) Los subsistemas AUDIO, CD-ROM, TIMERS y JOYSTICK no han
//                      sido implementados en esta version.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _ADN_PP_H_
#define _ADN_PP_H_

const char ADNPP_VERSION[]="SISTEMA adn++ - version 4.1.4";

//=============================================================================
// INCLUSIONES
//-----------------------------------------------------------------------------
#include <cstdlib>  // Libreria estandar de C++.
#include <cstdio>   // Libreria estandar de E/S.
#include <cstring>  // Libreria estandar para el manejo de cadenas.
#include <iostream> // Libreria estandar para el manejo de flujos de E/S.
#include <ctime>    // Libreria que incluye funciones relacionadas con el
                    // tiempo.
using namespace std;// Espacio de nombres estandar.

//#############################################################################
// ¡¡¡MUY IMPORTANTE!!!
//
// OPCIONES DE LINKEO.
//
// Para que las librerias SDL_Image, SDL_mixer y SDL_ttf sean reconocidas deben
// ser declaradas en el IDE.
//
// Para este fin, es necesario ir a:

//         "Settings/compiler and debugger.../Linquer settings"
//
// y en la solapa
//
//         "Other linker options"
//
// agregar las siguientes lineas:
//
//    -lSDL_image
//    -lSDL_mixer
//    -lSDL_ttf
//
//#############################################################################

//=============================================================================
// INCLUSIONES DE LIBRERIAS SDL (Simple DirectMedia Layer)
// AUTOR   : Sam Lantinga.
// LICENCIA: licencia LGPL.
//-----------------------------------------------------------------------------
//
#ifdef _WIN32                  // Inclusiones para Windows.
    #include <SDL/SDL.h>
    #include <SDL/SDL_image.h>
    #include <SDL/SDL_ttf.h>
    #include <SDL/SDL_mixer.h>
#endif

#ifdef _LINUX                  // Inclusiones para Linux
    #include <SDL.h>
    #include "SDL_image.h"
    #include "SDL_ttf.h"
    #include "SDL_mixer.h"
#endif

//=============================================================================
// INCLUSIONES DE LIBRERIAS DEL SISTEMA adn++.
// AUTOR   : Ruben Alberto Calabuig.
// LICENCIA: licencia LGPL.
//-----------------------------------------------------------------------------
#include "videoTypes.h"       // Tipos para modo video grafico y pantallas.
#include "mouseTypes.h"       // Tipos para mouse.
#include "keyboardTypes.h"    // Tipos para teclado.
#include "colorTypes.h"       // Tipos para colores.
#include "spriteTypes.h"      // Tipos para sprites.
#include "textTypes.h"        // Tipos para texto.

#include "clsLog.h"           // Administrador de archivos log.
#include "clsError.h"         // Clase abstracta para el manejo de errores.
#include "clsGraphicMode.h"   // Clase para administrar el modo grafico.
#include "clsEvent.h"         // Clase para administrar interrupciones.
#include "clsSystem.h"        // Clase para administrar comandos del sistema
                              // que permitan compatibilidad multiplataforma.
#include "clsBasicScreen.h"    // Clase abstracta para derivar clsScreen y
                              // clsVirtualScreen.
#include "clsScreen.h"        // Clase para administrar la pantalla de video.
#include "clsVirtualScreen.h" // Clase para administrar pantallas virtuales.
#include "clsDot.h"           // Clase para dibujar y leer puntos en superfi-
                              // cies.
#include "clsRectangle.h"     // Clase para dibujar rectangulos.
#include "clsImage.h"         // Clase para administrar imagenes en memoria RAM
#include "clsBasicSprite.h"    // Clase abstracta para generar clases de sprites
                              // basicos.
#include "clsMovilSprite.h"   // Clase abstracta para generar clases derivadas
                              // con funcionalidades basicas de movimiento.
#include "clsContactSprite.h" // Clase abstracta para generar clases derivadas
                              // con funcionalidades de contacto.
#include "clsText.h"          // Clase para administrar textos en modo grafico.
#include "clsTimer.h"         // Secuenciador para administrar tiempos.
#include "clsRandom.h"        // Clase para generar numeros aleatorios.
#include "clsTextBox.h"       // Clase para generar cajas de texto.
#include "clsEngine.h"        // Clase para derivar motores de programas.

#endif // _ADN_PP_H_
//### FIN DE ARCHIVO ##########################################################
