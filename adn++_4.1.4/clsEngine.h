//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.0 estable         //
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
// ARCHIVO             : clsEngine.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.0 estable.
// FECHA DE CREACION   : 19/10/2011.
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
//             Este archivo incluye la definicion de la clase abstracta
//             clsEngine, que sirve como base para derivar motores de programas
//             para el sistema adn++ (Sistema de Clases para Modo Grafico para
//             C++).
//
//             La clase clsEngine, es en realidad una "agregacion" compuesta
//             por las clases clsError, clsGraphicMode, clsScreen, clsEvent y
//             clsTimer (un administrador de errores, un administrador de modo
//             de video grafico, un adminstrador de pantalla fisica, un admi-
//             nistrador de eventos y un timer, respectivamente).
//
//-----------------------------------------------------------------------------
//            __________________________________
//            |            clsEngine           |
//            |--------------------------------|
//            | # error: clsError              |
//            | # video: clsGraphicMode        |
//            | # screen: clsScreen            |
//            | # event: clsEvent              |
//            | # timer: clsTimer              |
//            |--------------------------------|
//            | + init(graphicVideoMode): int  |
//            | + init(int,int,int): int       |
//            | + present()=0: virtual int     |
//            | + run()=0: virtual int         |
//            | + getScreenWidth(): int        |
//            | + getScreenHeight(): int       |
//            | + getScreenDepth(): int        |
//            |________________________________|
//                        __________
//                        |        |
//                        | Engine |
//                        |________|
//                            < >
//                             |
//       ______________________|___________________
//       |         |           |        |         |
//   ___1|____ ___1|____ _____1|___ ___1|____ ___1|____
//   |       | |       | |        | |       | |       |
//   | Error | | Video | | Screen | | Event | | Timer |
//   |_______| |_______| |________| |_______| |_______|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSENGINE_H
#define CLSENGINE_H

//#############################################################################
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsEngine
{
  //===========================================================================
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;              // Administrador de errores.
    clsGraphicMode video;        // Administrador del modo Grafico.
    clsScreen screen;            // Administrador de pantalla fisica.
    clsEvent event;              // Administrador de eventos.
    clsTimer timer;              // Administrador de tiempos.

  //===========================================================================
  // METODOS
  //---------------------------------------------------------------------------
  public:
    int init(graphicVideoMode);  // Inicia el motor en forma automatica.
    int init(int,int,int);       // Inicia el motor en forma manual.
    virtual int present()=0;     // Presenta el motor (por ser virtual debe ser
                                 // redefinida).
    virtual int run()=0;         // Ejecuta el motor (por ser virtual debe ser
                                 // redefinida).
    int getScreenWidth();         // Devuelve al ancho de pantalla en pixeles.
    int getScreenHeight();         // Devuelve al alto de pantalla en pixeles.
    int getScreenDepth();         // Devuelve la profundidad de color en bits.
};

//*****************************************************************************
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init(graphicVideoMode gvm)
// ACCION    : Inicia el motor en forma automatica.
// PARAMETROS: graphicVideoMode gvm --> resolucion de video.
//             RESOLUCIONES POSIBLES: DEFAULT    (800x600x16).
//                                    AUTODETECT (detectada por el sistema).
// DEVUELVE  : int --> codigo de error producido (0 = todo bien).
//-----------------------------------------------------------------------------
int clsEngine::init(graphicVideoMode gvm=DEFAULT)
{
  //===========================================================================
  // INICIO DEL MODO GRAFICO.
  //---------------------------------------------------------------------------
  error.set(video.init(gvm));
  if(error.get())
  {
    return error.get();
  }

  video.crashPrevent();

  //===========================================================================
  // CONFIGURACION E INICIO DE LA PANTALLA FISICA.
  //---------------------------------------------------------------------------
  error.set(screen.init(video.getScreenWidth(),
                        video.getScreenHeight(),
                        video.getScreenDepth(),
                        DISABLED,
                        FULLSCREEN
                       )
           );
  if(error.get())
  {
    return error.get();
  }
  return error.get();
}

//=============================================================================
// METODO    : int init(int w, int h, int d)
// ACCION    : Inicia el motor en forma manual.
// PARAMETROS: int w --> ancho de pantalla en pixeles.
//             int h --> alto de pantalla en pixeles.
//             int d --> profundidad de colores en bits.
// DEVUELVE  : int --> codigo de error producido (0 = todo bien).
//-----------------------------------------------------------------------------
int clsEngine::init(int w, int h, int d)
{
  //===========================================================================
  // INICIO DEL MODO GRAFICO.
  //---------------------------------------------------------------------------
  error.set(video.init(w,h,d));
  if(error.get())
  {
    return error.get();
  }

  //===========================================================================
  // PREVENCION DE CUELGUES
  //---------------------------------------------------------------------------
  video.crashPrevent();

  //===========================================================================
  // CONFIGURACION E INICIO DE LA PANTALLA FISICA.
  //---------------------------------------------------------------------------
  error.set(screen.init(w,h,d,DISABLED,FULLSCREEN));
  if(error.get())
  {
    return error.get();
  }

  error.set(0);
  return error.get();
}

//=============================================================================
// EL SIGUIENTE ES UN MODELO DEL METODO int run().
//
// Para el uso de este modelo, hay que agregar como atributos a la clase
// derivada las dos pantallas virtuales siguientes:
//
// protected:
//   clsVirtualScreen background;  // Pantalla virtual para almacenar el fondo
//                                 // del programa.
//
//   clsVirtualScreen frame;       // Pantalla virtual para armar los fotogramas
//                                 // que daran vida al programa.
//
// Para redefinirlo, solo hay que copiarlo en la clase derivada y modificarlo.
//=============================================================================
// METODO    : int run()
// ACCION    : pone en funcionamiento al motor
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
/*
int clsEngine::run()
{
  bool end=false; // Flag de control del ciclo de ejecucion.

  //===========================================================================
  //             CICLO PRINCIPAL DE EJECUCION DEL MOTOR
  //---------------------------------------------------------------------------
  while(!end)
  {
    // Rearmar fotograma.
    // Mostrar fotograma.

    // Testear eventos.
       // Si hubo evento
       // {
       //   Actuar segun evento.
            // Si el evento debe cortar el ciclo
            // {
            //   end=true;
            // }
       // }
  }
  // Actuar segun caso
  rerutn 0;
}
*/

//=============================================================================
// METODO    : int getScreenWidth()
// ACCION    : Devuelve el ancho de la pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int -->  ancho en pixeles.
//-----------------------------------------------------------------------------
int clsEngine::getScreenWidth() {return video.getScreenWidth();}

//=============================================================================
// METODO    : int getScreenHeight()
// ACCION    : Devuelve el alto de la pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int -->  alto en pixeles.
//-----------------------------------------------------------------------------
int clsEngine::getScreenHeight() {return video.getScreenHeight();}

//=============================================================================
// METODO    : int getScreenDepth()
// ACCION    : Devuelve la profundidad de colores en bits.
// PARAMETROS: NADA.
// DEVUELVE  : int -->  profundidad de color en bits.
//-----------------------------------------------------------------------------
int clsEngine::getScreenDepth() {return video.getScreenDepth();}

#endif // CLSENGINE_H
//### FIN DE ARCHIVO ##########################################################
