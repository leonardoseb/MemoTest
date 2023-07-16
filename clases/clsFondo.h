//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 1.0.0 estable         //
//              @@@@@  @    @@@@@  @    @       @    23/05/2014              //
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
// ARCHIVO             : clsBackGround.h
// AUTOR               : Arzua Juan Cruz.
// VERSION             : 0.0.1 estable.
// FECHA DE CREACION   : 11/06/2014.
// ULTIMA ACTUALIZACION: 11/06/2014.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05 / 12.11 / 13.12 / SVN
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//             Este archivo contiene la definicion de la clase clsFondo,
//             derivada de la clase clsBasicSprite.
//
//-----------------------------------------------------------------------------
//  ___________________________________________
//  |             clsBasicSprite              |
//  |-----------------------------------------|
//  | # error: clsError                       |
//  | # spritePointer: clsImage*              |
//  | # items: int                            |
//  | # name: char[30]                        |
//  | # i: int                                |
//  | # x: int                                |
//  | # y: int                                |
//  | # opacity: int                          |
//  | # transparent: rgbColor                 |
//  | # state: tSpriteState                   |
//  |-----------------------------------------|
//  | # inherit(): virtual void               |
//  | + clsBasicSprite()                      |
//  | + ~clsBasicSprite()                     |
//  | + unload(): void                        |
//  | + setItems(int): void                   |
//  | + setName(const char*): void            |
//  | + load(const char*): int                |
//  | + setI(int): int                        |
//  | + paste(int,int,SDL_Surface* sup): void |
//  | + setX(int): void                       |
//  | + setY(int): void                       |
//  | + setTransparent(rgbColor): void        |
//  | + setOpacity(int): void                 |
//  | + setState(tSpriteState): void          |
//  | + getName(): char*                      |
//  | + getX(): int                           |
//  | + getY(): int                           |
//  | + getWidth(): int                       |
//  | + getHeight(): int                      |
//  | + getTransparent(): rgbColor            |
//  | + getOpacity(): int                     |
//  | + getI(): int                           |
//  | + getPtr(): clsImage*                   |
//  | + getPtr(int): clsImage*                |
//  | + getItems(): int                       |
//  | + getState(): tSpriteState              |
//  |_________________________________________|
//               ^
//               |
//  _____________|____________________________
//  |              clsBackGround             |
//  |----------------------------------------|
//  |----------------------------------------|
//  | # inherit(): void                      |
//  | + init(): int                          |
//  |________________________________________|
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSFONDO_H
#define CLSFONDO_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsFondo: virtual public clsBasicSprite
{
  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    void inherit(){}; // Habilita a la clase para ser instanciada.

  public:
    int init(); // Inicializa al objeto instanciado.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa al objeto.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error (0 = OK).
//-----------------------------------------------------------------------------
int clsFondo::init()
{
  setItems(1); // Establece la cantidad de elementos del vector de imagenes

  setI(0);    // Ubica al indice del vector en la posicion 0.

  error.set(load("imagenes/fondo.jpg"));  // Carga la imagen en la posicion
                                        // indicada por el indice del vector.

  if(error.get())
  {
    return error.get(); // Si se produce un error en la carga, retorna el
                       // codigo de error.
  }

  // Mensaje para el archivo "stdout.txt".
  cout << "INICIALIZACION EXITOSA DEL SPRITE clsFondo" << endl;

  return error.get();// Retorna el codigo de error 0.
}

#endif // CLSFONDO_H

//### FIN DE ARCHIVO ##########################################################

