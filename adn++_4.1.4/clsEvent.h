//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.1 estable         //
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
// ARCHIVO             : clsEvent.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.1 estable.
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
//             Este archivo contiene la definicion de la clase clsEvent
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             clsEvent contiene los elementos necesarios para la administra-
//             cion de los eventos (TECLADO, MOUSE) en el modo grafico.
//
//-----------------------------------------------------------------------------
// DEFINICION DE EVENTO: Los eventos, comunmente llamados INTERRUPCIONES, son
//                       la base de la interactividad.
//
//                       Son necesarios para conocer conocer el estado de los
//                       perifericos de entrada (teclado, raton, joystick) en
//                       cualquier momento.
//
//                       En las SDL, un evento está asociado a una accion del
//                       usuario sobre la aplicacion que se esta ejecutando.
//-----------------------------------------------------------------------------
// GESTIÓN DE EVENTOS:   El subsistema de eventos de SDL se inicializa junto al
//                       subsistema de video, por lo que no hay que iniciarlo
//                       expresamente.
//
//                       En el sistema adn++, bastara con dedeclarar un objeto
//                       de tipo clsMode e iniciar el subsitema de video.
//
//=============================================================================
//        _____________________________
//        |          clsEvent         |
//        |---------------------------|
//        | # event:  SDL_Event       |
//        |---------------------------|
//        | + wasEvent(): bool        |
//        | + getEventType(): Uint8   |
//        | + getKey(): Uint16        |
//        | + getKeyMode(): SDLMod    |
//        | + getMouseButton(): Uint8 |
//        | + getCursorX(): Uint16    |
//        | + getCursorY(): Uint16    |
//        |___________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSEVENT_H
#define _CLSEVENT_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsEvent
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    SDL_Event event;   // Registro del evento.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------

  public:
    bool wasEvent();        // Informa si se produjo o no un evento.
    Uint8 getEventType();   // Devuelve el tipo de evento producido.
    Uint16 getKey();        // Devuelve la tecla presionada.
    SDLMod getKeyMode();    // Devuelve el estado de las teclas especiales
                            // (CAPSLOCK, NUMLOCK, CTRL, SHIFT y ALT).
    Uint8 getMouseButton(); // Devuelve el boton del mouse presionado.
    Uint16 getCursorX();    // Devuelve la coordenada x del puntero del mouse.
    Uint16 getCursorY();    // Devuelve la coordenada y del puntero del mouse.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : bool wasEvent()
// ACCION    : Informa si se produjo o no un evento.
// PARAMETROS: NADA.
// DEVUELVE  : bool -> "true" si hubo evento o "false" si no lo hubo.
//-----------------------------------------------------------------------------
bool clsEvent::wasEvent()
{
  if (SDL_PollEvent(&event))
  {
    return true;
  }
  return false;
}

//=============================================================================
// METODO    : Uint8 getEvenType()
// ACCION    : Informa el tipo de evento producido.
// PARAMETROS: NADA.
// DEVUELVE  : Uint8 -> tipo de evento SDL producido.
//-----------------------------------------------------------------------------
Uint8 clsEvent::getEventType() {return event.type;}

//=============================================================================
// METODO    : Uint16 getKey()
// ACCION    : Informa la tecla presionada.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 --> Codigo ASCII de la tecla presionada.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getKey()
{
    return (Uint16)event.key.keysym.sym;
}

//=============================================================================
// METODO    : SDLMod getKeyMode()
// ACCION    : Informa el estado de las teclas especiales (CAPSLOCK, NUMLOCK,
//             CTRL, SHIFT y ALT).
// PARAMETROS: NADA.
// DEVUELVE  : SDLMod -> Estado SDL de la tecla especial.
//-----------------------------------------------------------------------------
SDLMod clsEvent::getKeyMode() {return event.key.keysym.mod;}

//=============================================================================
// METODO    : Uint8 getMouseButtom()
// ACCION    : Informa el boton del mouse presionado.
// PARAMETROS: NADA.
// DEVUELVE  : Uint8 -> boton presionado.
//-----------------------------------------------------------------------------
Uint8 clsEvent::getMouseButton() {return event.button.button;}

//=============================================================================
// METODO    : Uint16 getCursorX()
// ACCION    : Informa la coordenada x del puntero del mouse.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 -> coordenada x.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getCursorX() {return event.button.x;}

//=============================================================================
// METODO    : Uint16 getCursorY()
// ACCION    : Informa la coordenada y del puntero del mouse.
// PARAMETROS: NADA.
// DEVUELVE  : Uint16 -> coordenada x.
//-----------------------------------------------------------------------------
Uint16 clsEvent::getCursorY() {return event.button.y;}

#endif // _CLSEVENT_H
//### FIN DE ARCHIVO ##########################################################
