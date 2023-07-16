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
// ARCHIVO             : clsDot.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.0 estable.
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
//             Este archivo incluye la definicion de la clase clsDot pertene-
//             ciente al sistema adn++ (Sistema de Clases para Modo Grafico
//             para C++).
//
//             clsDot, es una clase que solo contiene dos metodos (set() y
//             get()), que dibujan y leen pixeles respectivamente desde super-
//             ficies en el modo grafico.
//
//=============================================================================
//  ________________________________________________________
//  |                        clsDot                        |
//  |------------------------------------------------------|
//  |------------------------------------------------------|
//  | + set(int x, int y, rgbColor, SDL_Surface*): void    |
//  | + get(int x, int y, SDL_Surface*): SDL_Color         |
//  |______________________________________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSDOT_H
#define _CLSDOT_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsDot
{
  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
    void set(int x, int y, rgbColor, SDL_Surface*);  // Dibuja un punto de
                                                     // color en una supeficie
                                                     // dada.
    SDL_Color get(int x, int y, SDL_Surface*);       // Lee el color un punto
                                                     // desde una superficie
                                                     // dada.

};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : void set(int x,int y,rgbColor color,SDL_Surface* sup)
// ACCION    : Dibuja un punto de color en las coordenadas x e y de una
//             superficie dada.
// PARAMETROS: int x            -> coordenada x.
//             int y            -> coordenada y.
//             rgbColor color   -> color del punto.
//             SDL_Surface* sup -> superficie donde se dibujara el punto.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsDot::set(int x, int y, rgbColor color, SDL_Surface* sup)
{
  // Convierte color
  Uint32 col=SDL_MapRGB(sup->format, color.r, color.g, color.b);

  // Determina posición de inicio
  char *buffer=(char*) sup->pixels;

  // Calcula offset para y
  buffer+=sup->pitch*y;

  // Calcula offset para x
  buffer+=sup->format->BytesPerPixel*x;

  // Copia el pixel
  memcpy(buffer, &col, sup->format->BytesPerPixel);
}

//=============================================================================
// METODO    : SDL_Color get(int x,int y,SDL_Surface* sup)
// ACCION    : Retorna el color de un pixel que se encuentra en las coordenadas
//             x e y de una superficie dada.
// PARAMETROS: int x            -> coordenada x.
//             int y            -> coordenada y.
//             SDL_Surface* sup -> superficie donde se leera el punto.
// DEVUELVE  : SDL_Color -> componentes RGB del pixel.
//----------------------------------------------------------------------
SDL_Color clsDot::get(int x, int y,SDL_Surface* sup)
{
  SDL_Color color;
  Uint32 col;

  // Determina posición de inicio
  char *buffer=(char *) sup->pixels;

  // Calcula offset para y
  buffer+=sup->pitch*y;

  // Calcula offset para x
  buffer+=sup->format->BytesPerPixel*x;

  // Obtiene el pixel
  memcpy(&col, buffer, sup->format->BytesPerPixel);

  // Descompone el color
  SDL_GetRGB(col, sup->format, &color.r, &color.g, &color.b);

  // Devuelve el color
  return color;
}

#endif // _CLSDOT_H
//### FIN DE ARCHIVO ##########################################################
