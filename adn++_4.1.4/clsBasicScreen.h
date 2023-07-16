//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.3 estable         //
//              @@@@@  @    @@@@@  @    @       @    17/10/2012              //
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
////#############################################################################
// ARCHIVO             : clsBasicScreen.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.3 estable.
// FECHA DE CREACION   : 15/02/2011.
// ULTIMA ACTUALIZACION: 17/10/2012.
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
//             Este archivo contiene la definicion de la clase abstracta
//             clsBasicScreen perteneciente al sistema adn++ (Sistema de
//             Clases para Modo Grafico para C++).
//
//             La clase clsBasicScreen contiene los elementos basicos
//             necesarios para la administracion de las pantallas en el modo
//             grafico.
//
//-----------------------------------------------------------------------------
//   ___________________________________
//   |         clsBasicScreen          |
//   |---------------------------------|
//   | # error: clsError               |
//   | # screenPointer  : SDL_Surface* |
//   | # width : int                   |
//   | # height : int                  |
//   | # color: rgbColor               |
//   |------------------------_--------|
//   | # inherit(): virtual void       |
//   | + load(const char* archivo): int|
//   | + paste(SDL_Surface*): void     |
//   | + clean(rgbColor): void         |
//   | + setColor(rgbColor): void      |
//   | + getWidth(): int               |
//   | + getHeight(): int              |
//   | + getPtr(): SDL_Surface*        |
//   | + getColor(): rgbColor          |
//   |_________________________________|
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _CLSBASICSCREEN_H
#define _CLSBASICSCREEN_H

//#############################################################################
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsBasicScreen
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;             // Administrador de errores.
    SDL_Surface* screenPointer; // Puntero a la imagen asignada.
    int width;                  // Ancho de la pantalla en pixeles.
    int height;                 // Alto de la pantalla en pixeles.
    rgbColor color;             // Color de fondo.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    virtual void inherit()=0;     // Convierte a la clase en abstracta.

  public:
    int load(const char* archivo); // Carga una imagen de archivo.
    void paste(SDL_Surface*);       // Copia la imagen en otra pantalla.
    void clean(rgbColor);           // Borra la pantalla con color por parametro
    void setColor(rgbColor);        // Establece el color de la pantalla.
    SDL_Surface* getPtr();           // Devuelve el puntero a la imagen.
    int getWidth();                 // Devuelve el ancho de la pantalla.
    int getHeight();                // Devuelve el ancho de la pantalla.
    rgbColor getColor();            // Devuelve el color de la pantalla.
};

//*****************************************************************************
//			           DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int load(const char* archivo)
// ACCION    : Carga un archivio de imagen de tipo bmp en memoria correspon-
//             diente (RAM o Video).
// PARAMETROS: char* archivo -> cadena con el path y nombre de archivo.
// DEVUELVE  : int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsBasicScreen::load(const char* archivo)
{
  screenPointer = IMG_Load(archivo);
  if(screenPointer == NULL)
  {
      error.set(802);
      return error.get();
  }
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void paste(SDL_Surface* surface)
// ACCION    : Copia la imagen de la pantalla en otra dada designada en el
//             parametro surface.
// PARAMETROS: SDL_Surface* surface -> puntero a la pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicScreen::paste(SDL_Surface* surface)
{
  SDL_Rect area = {0,0,width,height};
  SDL_BlitSurface(screenPointer, NULL, surface, &area);
}

//=============================================================================
// METODO    : void clean(rgbColor bc).
// ACCION    : Borra la pantalla con color pasado por parametro.
// PARAMETROS: rgbColor bc -> color para borrar.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicScreen::clean(rgbColor bc=BLACK)
{
  uint32_t background = SDL_MapRGB(screenPointer->format,bc.r,bc.g,bc.b);
  SDL_FillRect(screenPointer, NULL, background);
}

//=============================================================================
// METODO    : void setColor(rgbColor bc).
// ACCION    : Cambia el color de la pantalla.
// PARAMETROS: rgbColor bc ->  nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicScreen::setColor(rgbColor bc)
{
  SDL_MapRGB(screenPointer->format,bc.r,bc.g,bc.b);
}

//=============================================================================
// METODO    : SDL_Surface* getPtr().
// ACCION    : Devuelve un puntero a la superficie de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Surface* -> puntero a la superficie.
//-----------------------------------------------------------------------------
SDL_Surface* clsBasicScreen::getPtr() { return screenPointer;}

//=============================================================================
// METODO    : int getWidth().
// ACCION    : Devuelve el ancho en pixeles de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : int -> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsBasicScreen::getWidth(){return width;}

//=============================================================================
// METODO    : int getHeight().
// ACCION    : Devuelve el alto en pixeles de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : int -> alto en pixeles.
//-----------------------------------------------------------------------------
int clsBasicScreen::getHeight(){return height;}

//=============================================================================
// METODO    : rgbColor getColor().
// ACCION    : Devuelve el color de la pantalla.
// PARAMETROS: NADA.
// DEVUELVE  : rgbColor -> color de pantalla.
//-----------------------------------------------------------------------------
rgbColor clsBasicScreen::getColor(){return color;}

#endif // _CLSBASICSCREEN_H
//### FIN DE ARCHIVO ##########################################################
