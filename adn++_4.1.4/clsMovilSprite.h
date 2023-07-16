//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.3 estable         //
//              @@@@@  @    @@@@@  @    @       @    17/10/2012.             //
//                                                                           //
//#############################################################################
//
//  **************************************************************************
//  * El software libre no es una cuestion economica sino una cuestion etica *
//  **************************************************************************
//
// AVIS Software es marca registrada.
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
// ARCHIVO             : clsMovilSprite.h
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
//             clsMovilSprite perteneciente al sistema adn++ (Sistema de Clases
//             para Modo Grafico para C++).
//
//             La clase abstracta clsMovilSprite, deriva de la clase abstracta
//             clsBasicSprite, y contiene los elementos necesarios para la
//             creacion de clases que necesiten las funcionalidades basicas
//             de un sprite con movimiento (velocidad, rumbo, etc.).
//
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
//  _____________|________________
//  |      clsMovilSprite        |
//  |----------------------------|
//  | # speed: int               |
//  | # course: tCourse          |
//  |----------------------------|
//  | + clsMovilSprite()         |
//  | + setSpeed(int): void      |
//  | + setCourse(tCourse): void |
//  | + getSpeed(): int          |
//  | + getCourse(): tCourse     |
//  |____________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSMOVILSPRITE_H
#define _CLSMOVILSPRITE_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsMovilSprite: virtual public clsBasicSprite
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    int speed;      // Velocidad de desplazamiento.
    tCourse course; // Direccion de desplazamiento.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
   public:
    clsMovilSprite();        // Constructor.
    void setSpeed(int);      // Establece la velocidad de desplazamiento del
                             // sprite.
    void setCourse(tCourse); // Etablece la direccion de desplazamiento del
                             // sprite.
    int getSpeed();          // Devuelve la velocidad de desplazamiento del
                             // sprite.
    tCourse getCourse();     // Devuelve la direccion de desplazamiento del
                             // sprite.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : clsMovilSprite()
// ACCION    : Constructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsMovilSprite::clsMovilSprite() {setName("MOVIL SIN NOMBRE");}

//=============================================================================
// METODO    : void setSpeed(int v)
// ACCION    : Establece la velocidad de desplazamiento del movil.
// PARAMETROS: int v --> nueva velocidad.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMovilSprite::setSpeed(int v) {speed = v;}

//=============================================================================
// METODO    : void setCourse(tCourse r)
// ACCION    : Establece la direccion de desplazamiento del movil.
// PARAMETROS: tCourse r --> nueva rumbo.
//             Rumbos posibles: NORTH (hacia arriba),
//                              EAST  (hacia la derecha),
//                              SOUTH (hacia abajo),
//                              WEST  (hacia la izquierda).
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMovilSprite::setCourse(tCourse r) {course = r;}

//=============================================================================
// METODO    : int getSpeed()
// ACCION    : Devuelve la velocidad de desplazamiento del movil.
// PARAMETROS: NADA.
// DEVUELVE  : int v --> la velocidad expresada en pixeles
//-----------------------------------------------------------------------------
int clsMovilSprite::getSpeed(){ return speed;}

//=============================================================================
// METODO    : tCourse getCourse()
// ACCION    : Devuelve la direccion de desplazamiento del movil.
// PARAMETROS: NADA.
// DEVUELVE  : tCourse --> el rumbo.
//             Rumbos posibles: NORTH (hacia arriba),
//                              EAST  (hacia la derecha),
//                              SOUTH (hacia abajo),
//                              WEST (hacia la izquierda).
//-----------------------------------------------------------------------------
tCourse clsMovilSprite::getCourse(){ return course;}

#endif // _CLSMOVILSPRITE_H

//### FIN DE ARCHIVO ##########################################################
