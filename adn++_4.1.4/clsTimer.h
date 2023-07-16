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
// ARCHIVO             : clsTimer.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.2 estable.
// FECHA DE CREACION   : 15/02/2011.
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
//             Este archivo incluye la definicion de la clase clsTimer
//             perteneciente adn++ (Sistema de Clases para Modo Grafico
//             para C++).
//
//             clsTimer contiene los elementos necesarios para la administracion
//             del tiempo en el modo grafico.
//
//=============================================================================
//
//        ______________________________
//        |          clsTimer          |
//        |----------------------------|
//        | # event: clsEvent          |
//        | # initialtime: int         |
//        | # now: int                 |
//        |----------------------------|
//        | + wait(int): void          |
//        | + waitForKey(Uint16): void |
//        | + start(): void            |
//        | + update(): void           |
//        | + getTicks(): int          |
//        | + getState(): int          |
//        |____________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSTIMER_H
#define _CLSTIMER_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsTimer
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsEvent event;  // administrador de eventos
    int initialtime; // contiene el valor de arranque.
    int now;         // contiene el tiempo transcurrido desde el arranque.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
    void wait(int);          // Espera la cantidad de milisegundos pasados por
                             // parametro.
    void waitForKey(Uint16); // Espera que se presione una tecla pasada como
                             // parametro.
    void start();            // Pone en marcha el timer.
    void update();           // Actualiza el tiempo del timer.

    int getTicks();    // Devuelve la cantidad de milisegundos pasados desde el
                       // momento que se incializo el modo grafico.
    int getState();    // Devuelve el tiempo transcurrido desde el arranque.
};

//=============================================================================
//			             DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int getTicks()
// ACCION    : Devuelve la cantidad de milisegundos transcurridos desde el
//             momento en que se inicializo el modo grafico.
// PARAMETROS: NADA.
// DEVUELVE  : int -> cantidad de milisegundos.
//-----------------------------------------------------------------------------
int clsTimer::getTicks()
{
  return (int) SDL_GetTicks();
}

//=============================================================================
// METODO    : void wait(int mls)
// ACCION    : Hace una pausa de la cantidad de milisegundos establecidos como
//             parametro.
// PARAMETROS: int mls -> cantidad de millisegundos de duracion de la pausa.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::wait(int mls)
{
  SDL_Delay(mls);
}

//=============================================================================
// METODO    : void start()
// ACCION    : Pone en marcha el timer.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::start()
{
  initialtime=getTicks();
}

//=============================================================================
// METODO    : void update()
// ACCION    : Actualiza el tiempo transcurrido desde la puesta en marcha.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::update()
{
  now = getTicks() - initialtime;
}

//=============================================================================
// METODO    : int getState()
// ACCION    : Devuelve el estado actual del timer.
// PARAMETROS: NADA.
// DEVUELVE  : int -> diferencia entre tiempoActual y tiempoInicial.
//-----------------------------------------------------------------------------
int clsTimer::getState()
{
  update();
  return now;
}

//=============================================================================
// METODO    : void waitFor(Uint16 t)
// ACCION    : Hace una pausa hasta que se presiona una tecla pasada como para-
//             metro.
// PARAMETROS: Uint16 -> Tecla que debe ser presionada para terminar la pausa.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTimer::waitForKey(Uint16 t)
{
    bool end=false;
    Uint16 key;
    do
    {
       if(event.wasEvent())
       {
            if(event.getEventType()==KEY_PRESSED)
            {
                key=event.getKey();
                if(key==t)
                {
                    end=true;
                }
            }
       }
    } while(!end);
}

#endif // _CLSTIMER_H
//### FIN DE ARCHIVO ##########################################################
