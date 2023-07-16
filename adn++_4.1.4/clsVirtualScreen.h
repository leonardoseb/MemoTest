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
// ARCHIVO             : clsVirtualScreen.h
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
//             Este archivo contiene la definicion de la clase clsVirtualScreen
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsVirtualScreen deriva de la clase clsBasicScreen, y
//             contiene los elementos necesarios para la administracion de
//             pantallas virtuales en modo grafico.
//
//             Las pantallas virtuales son copias de la memoria de video en la
//             memoria RAM.
//=============================================================================
//   ____________________________________
//   |          clsBasicScreen          |
//   |----------------------------------|
//   | # error: clsError                |
//   | # screenPointer  : SDL_Surface*  |
//   | # Width : int                    |
//   | # Height : int                   |
//   | # color: rgbColor                |
//   |----------------------------------|
//   | # inherit(): virtual void        |
//   | + load(const char* archivo): int |
//   | + paste(SDL_Surface*): void      |
//   | + clean(rgbColor): void          |
//   | + getWidth(): int                |
//   | + getHeight(): int               |
//   | + getPtr(): SDL_Surface*         |
//   |__________________________________|
//             ^
//             |
//             |
//   __________|_____________________________________________
//   |                  clsVirtualScreen                    |
//   |------------------------------------------------------|
//   |------------------------------------------------------|
//   | # inherit(){}: void                                  |
//   | + init(unsigned int,unsigned int,unsigned int): int  |
//   | + ~clsVirtualScreen()                                |
//   |______________________________________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSVIRTUALSCREEN_H
#define _CLSVIRTUALSCREEN_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsVirtualScreen: virtual public clsBasicScreen
{
  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    void inherit(){}; // Habilitacion de la clase para ser instanciada.

  public:
    int init(unsigned int, // Inicializa la pantalla virtual.
             unsigned int,
             unsigned int);

    ~clsVirtualScreen(); // Destructor.
};

//=============================================================================
//		                 DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init(unsigned int anch, unsigned int alt, unsigned int bpp)
// ACCION    : Inicializa la pantalla en memoria RAM (pantalla virtual).
// PARAMETROS: unsigned int w -> Ancho de la pantalla en pixeles.
//             unsigned int h -> Alto de la pantalla en pixeles.
//             unsigned int d -> Profundidad de color en bits.
//                               VALORES POSIBLES: 8, 16, 32 y 64.
//-----------------------------------------------------------------------------
// DEVUELVE: int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsVirtualScreen::init(unsigned int w,
                           unsigned int h,
                           unsigned int d)
{
  screenPointer = SDL_SetVideoMode(w,h,d,VIRTUAL);
  if (screenPointer==NULL)
  {
      error.set(801);
      return error.get();
  }

  width  = w;
  height  = h;
  color = BLACK;

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : ~clsVirtualScreen()
// ACCION    : Destructor.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsVirtualScreen::~clsVirtualScreen()
{
  if(screenPointer != NULL) SDL_FreeSurface(screenPointer);
  cout << "Destruyo el objeto clsVirtualScreen." << endl;
}

#endif // _CLSVIRTUALSCREEN_H
//### FIN DE ARCHIVO ##########################################################
