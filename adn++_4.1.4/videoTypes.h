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
// ARCHIVO             : videoTypes.h
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
//             cion de los tipos para el modo grafico y las pantallas.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef VIDEOTYPES_H
#define VIDEOTYPES_H

//*****************************************************************************
//              ENUMERACIONES DEFINIDAS PARA VIDEO
//-----------------------------------------------------------------------------
// ENUMERACION DE TIPOS DE INICIALIZACION DE VIDEO
// Esta enumeracion se utiliza como parametros para la inicializacion del modo
// grafico.
//-----------------------------------------------------------------------------
enum graphicVideoMode{
                       DEFAULT,     // Resolucion de video de 800x600x16.
                       AUTODETECT   // Autodeteccion de la resolucion de video.
                     };

//*****************************************************************************
//              ENUMERACIONES DEFINIDAS PARA LAS PANTALLAS
//-----------------------------------------------------------------------------
// ENUMERACION DE TIPOS DE ENTORNOS POSIBLES
// Esta enumeracion es una adaptacion y traduccion de los tipos de
// entorno declarados en las librerias SDL.
//-----------------------------------------------------------------------------
enum environment {
                   //----------------------------------------------------------
                   // SIN TIPO
                   //----------------------------------------------------------
                   NOTHING         = 0,

                   //----------------------------------------------------------
                   // SOLO PARA PANTALLAS FISICAS
                   //----------------------------------------------------------
                   HARDWARE        = SDL_HWSURFACE,
                   ASINCRONIC      = SDL_ASYNCBLIT,
                   EMULATED        = SDL_ANYFORMAT,
                   DOUBLEBUFFER    = SDL_DOUBLEBUF,
                   FULLSCREEN      = SDL_FULLSCREEN,
                   RESIZABLE       = SDL_RESIZABLE,
                   NOTITLE         = SDL_NOFRAME,

                   //----------------------------------------------------------
                   // SOLO PARA PANTALLAS VIRTUALES
                   //----------------------------------------------------------
                   VIRTUAL         = SDL_SWSURFACE
                  };

//=============================================================================
// ENUMERACION DE TIPOS DE ESTADOS PARA BARRAS DE TITULO.
// Esta enumeracion contiene los tipos de estados posibles para la barra de
// titulo de la ventana en el monitor.
//-----------------------------------------------------------------------------
enum titlebar{ DISABLED = false, ENABLED = true};

#endif // VIDEOTYPES_H
//### FIN DE ARCHIVO ##########################################################
