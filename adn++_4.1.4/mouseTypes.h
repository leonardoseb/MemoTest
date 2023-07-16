//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.3 estable         //
//              @@@@@  @    @@@@@  @    @       @    07/10/2012              //
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
// ARCHIVO             : mouseTypes.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.3 estable.
// FECHA DE CREACION   : 29/09/2011.
// ULTIMA ACTUALIZACION: 07/10/2012.
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
//             Este archivo reemplaza a la libreria adnHeaders.h, en la defini-
//             cion de los tipos de mouse.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MOUSETYPES_H
#define MOUSETYPES_H

//*****************************************************************************
// CONSTANTES CON LOS CODIGOS PARA MOUSE
//-----------------------------------------------------------------------------
  const Uint8  MOUSE_MOTION = SDL_MOUSEMOTION;      // Mouse mivido.
  const Uint8  MOUSE_DOWN   = SDL_MOUSEBUTTONDOWN;  // Boton presionado.
  const Uint8  MOUSE_UP     = SDL_MOUSEBUTTONUP;    // Boton liberado.

  const Uint8  MOUSE_LEFT_BUTTON     = SDL_BUTTON_LEFT;   // Boton izquierdo.
  const Uint8  MOUSE_RIGHT_BUTTON    = SDL_BUTTON_RIGHT;  // Boton derecho.
  const Uint8  MOUSE_MIDDLE_BUTTON   = SDL_BUTTON_MIDDLE; // Boton medio.

#endif // MOUSETYPES_H
//### FIN DE ARCHIVO ##########################################################
