//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v. 4.1.4 estable.       //
//              @@@@@  @    @@@@@  @    @       @    18/10/2012              //
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
// ARCHIVO             : clsContactSprite.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.4 estable.
// FECHA DE CREACION   : 15/02/2011.
// ULTIMA ACTUALIZACION: 18/10/2012.
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
//             clsContactSprite perteneciente al sistema adn++ (Sistema de
//             Clases para Modo Grafico para C++).
//
//             La clase clsContactSprite, deriva de la clase abstracta
//             clMovilSprite, y contiene los elementos necesarios para la
//             creacion de clases que necesiten las funcionalidades basicas de
//             un sprite que pueda detectar contacto con otro sprite.
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
//               ^
//               |
//  _____________|__________________________________
//  |           clsContactSprite                   |
//  |----------------------------------------------|
//  | # coord: tCoord                              |
//  |----------------------------------------------|
//  | + clsContactSprite()                         |
//  | + ~clsContactSprite()                        |
//  | + getContact(clsBasicSprite*): bool          |
//  | # findLocalValues(): void                    |
//  | # findExternValues(clsBasicSprite*): void    |
//  | # findContactValues(clsBasicSprite*): void   |
//  | # getSuperposition(clsBasicSprite*): bool    |
//  | # getMatch(clsBasicSprite*): bool            |
//  |______________________________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSCONTACT_H
#define _CLSCONTACT_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsContactSprite: virtual public clsMovilSprite
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    tCoord coord;      // Estructura con datos de contacto.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
     clsContactSprite();                    // Constructor.
     ~clsContactSprite();                   // Destructor.
     bool getContact(clsBasicSprite*);     // Detecta contacto del sprite
                                           // LOCAL con otro sprite externo.

  protected:
    void findLocalValues();                // Busca coordenadas iniciales,
                                           // ancho y alto del sprite local.

    void findExternValues(clsBasicSprite*); // Busca coordenadas iniciales,
                                           // ancho y alto del sprite externo.

    int findContactValues(clsBasicSprite*);// Busca valores del area de
                                           // contacto.

    bool getSuperposition(clsBasicSprite*);// Detecta si hay superposicion de
                                          // areas entre el sprite local y
                                          // un sprite externo.

    bool getMatch(clsBasicSprite*);        // Detecta puntos de coincidencia
                                          // dentro del area de contacto.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : clsContactSprite()
// ACCION    : Constructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsContactSprite::clsContactSprite()
{
  setName("CONTACTSPRITE SIN NOMBRE.");

  setItems(1);
  setI(0);
  setX(0);
  setY(0);
  setSpeed(0);
  setCourse(EAST);
  setTransparent(PINK);

  coord.x1=0;
  coord.y1=0;
  coord.x2=0;
  coord.y2=0;
  coord.x3=0;
  coord.y3=0;
  coord.x4=0;
  coord.y4=0;
  coord.w1=0;
  coord.w2=0;
  coord.h1=0;
  coord.h2=0;
  coord.xi1=0;
  coord.yi1=0;
  coord.xi2=0;
  coord.yi2=0;
  coord.aw=0;
  coord.ah=0;
  coord.ovl=0;

}

//=============================================================================
// METODO    : ~clsContactSprite()
// ACCION    : Destructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsContactSprite::~clsContactSprite() {}

//=============================================================================
// METODO    : bool getContact(clsBasicSprite* spr)
// ACCION    : Desata una serie de procedimientos con el fin de detectar un
//             contacto entre el sprite local con un sprite externo.
// PARAMETROS: clsContactSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool ->  "true" si hay contacto y "false" si no lo hay.
//-----------------------------------------------------------------------------
bool clsContactSprite::getContact(clsBasicSprite* spr)
{
  coord.ovl=0;

  findLocalValues(); // Establecer los valores del sprite local.

  findExternValues(spr);// Establecer los valores del sprite externo.

  if(getSuperposition(spr)) // Verificar superposicion de areas.
  {
    findContactValues(spr); // Encontrar puntos opacos de contacto.

    if(getMatch(spr)) // // Verificar si existe coincidencia.
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

//=============================================================================
// METODO    : void findLocalValues()
// ACCION    : Busca coordenadas iniciales, ancho y alto  del sprite local.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsContactSprite::findLocalValues()
{
  coord.x1=this->getX();
  coord.y1=this->getY();
  coord.w1=this->getWidth();
  coord.h1=this->getHeight();
  coord.x2=coord.x1+coord.w1;
  coord.y2=coord.y1+coord.h1;
}

//=============================================================================
// METODO    : void findExternValues(clsBasicSprite* spr)
// ACCION    : Busca coordenadas iniciales, ancho y alto del sprite externo.
// PARAMETROS: clsContactSprite* spr -| puntero al sprite externo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsContactSprite::findExternValues(clsBasicSprite* spr)
{
  coord.x3=spr->getX();
  coord.y3=spr->getY();
  coord.w2=spr->getWidth();
  coord.h2=spr->getHeight();
  coord.x4=coord.x3+coord.w2;
  coord.y4=coord.y3+coord.h2;
}

//=============================================================================
// METODO    : bool getSuperposition(clsBasicSprite* spr)
// ACCION    : Determina si existe superposicion entre las areas del
//             sprite local y el sprite externo.
// PARAMETROS: clsContactSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool -> "true" si hay superposicion de areas y "false" si
//                     no la hay.
//-----------------------------------------------------------------------------
bool clsContactSprite::getSuperposition(clsBasicSprite* spr)
{
  if( coord.x1+coord.w1 > coord.x3 && coord.y1+coord.h1 > coord.y3 &&
      coord.x3+coord.w2 > coord.x1 && coord.y3+coord.h2 > coord.y1    )
  {
    return true;
  }
  return false;
}

//=============================================================================
// METODO    : int findContactValues(clsBasicSprite* spr)
// ACCION    : Busca los valores del area de contacto.
// PARAMETROS: clsContactSprite* spr -> puntero al sprite externo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
int clsContactSprite::findContactValues(clsBasicSprite* spr)
{

  coord.ovl=0;

  //---------------------------------------------------------------------------
  // CASO 01
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {

    coord.aw=coord.x2-coord.x3; coord.ah=coord.y2-coord.y1; coord.ovl=1;

    coord.xi1=coord.w1-coord.aw; coord.yi1=0;
    coord.xi2=0                ; coord.yi2=coord.y1-coord.y3;

    coord.ovl=1;
  }

  //---------------------------------------------------------------------------
  // CASO 02
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x1 ; coord.ah=coord.y2-coord.y1; coord.ovl=2;
    coord.xi1=0;               ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3; coord.yi2=coord.y1-coord.y3;

    coord.ovl=2;
  }

  //---------------------------------------------------------------------------
  // CASO 03
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x2-coord.x1 ; coord.ah=coord.y2-coord.y3; coord.ovl=3;
    coord.xi1=0                ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=coord.x1-coord.x3; coord.yi2=0;
    coord.ovl=3;
  }

  //---------------------------------------------------------------------------
  // CASO 04
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x1  ; coord.ah=coord.y4-coord.y1; coord.ovl=4;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=4;
  }

  //---------------------------------------------------------------------------
  // CASO 05
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x3  ; coord.ah=coord.y4-coord.y3; coord.ovl=5;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=5;
  }

  //---------------------------------------------------------------------------
  // CASO 06
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y4-coord.y3; coord.ovl=6;
    coord.xi1=0                 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=coord.w2-coord.aw; coord.yi2=0;
    coord.ovl=6;
  }

  //---------------------------------------------------------------------------
  // CASO 07
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y2-coord.y3; coord.ovl=7;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=7;
  }

  //---------------------------------------------------------------------------
  // CASO 08
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y4-coord.y1; coord.ovl=8;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=0;
    coord.xi2=0                 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=8;
  }

  //---------------------------------------------------------------------------
  // CASO 09 (muy raro)
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.y2-coord.y1  ; coord.ah=coord.y2-coord.y1; coord.ovl=9;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.x1-coord.x3 ; coord.yi2=coord.y1-coord.y3;
    coord.ovl=9;
  }

  //---------------------------------------------------------------------------
  // CASO 10 (muy raro)
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x3  ; coord.ah=coord.y4-coord.y3; coord.ovl=10;
    coord.xi1=coord.x3-coord.x1 ; coord.yi1=coord.y3-coord.y1;
    coord.xi2=0                 ; coord.yi2=0;
    coord.ovl=10;
  }

  //---------------------------------------------------------------------------
  // CASO 11
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x2-coord.x3   ; coord.ah=coord.y2-coord.y3; coord.ovl=11;
    coord.xi1=coord.w1-coord.aw ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=0                  ; coord.yi2=0;
    coord.ovl=11;
  }

  //---------------------------------------------------------------------------
  // CASO 12
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1<coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2<coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y2-coord.y3; coord.ovl=12;
    coord.xi1=0                 ; coord.yi1=coord.h1-coord.ah;
    coord.xi2=coord.w2-coord.aw; coord.yi2=0;
    coord.ovl=12;
  }

  //---------------------------------------------------------------------------
  // CASO 13
  //---------------------------------------------------------------------------
  if(coord.x1<coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2<coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x2-coord.x3; coord.ah=coord.y4-coord.y1; coord.ovl=13;
    coord.xi1=coord.w1-coord.aw  ; coord.yi1=0;
    coord.xi2=0                   ; coord.yi2=coord.h2-coord.ah;
    coord.ovl=13;
  }

  //---------------------------------------------------------------------------
  // CASO 14
  //---------------------------------------------------------------------------
  if(coord.x1>coord.x3 && coord.x1<coord.x4 && coord.x2>coord.x3 &&
     coord.x2>coord.x4 && coord.y1>coord.y3 && coord.y1<coord.y4 &&
     coord.y2>coord.y3 && coord.y2>coord.y4)
  {
    coord.aw=coord.x4-coord.x1  ; coord.ah=coord.y4-coord.y1; coord.ovl=14;
    coord.xi1=0                 ; coord.yi1=0;
    coord.xi2=coord.w2-coord.aw; coord.yi2=coord.h2-coord.ah;
    coord.ovl=14;
  }

  return coord.ovl;
}

//=============================================================================
// METODO    : bool getMatch(clsBasicSprite* spr)
// ACCION    : Determina si existe coincidencia de puntos opacos entre las dos
//             areas de superposicion.
// PARAMETROS: clsContactSprite* spr -> puntero al sprite externo.
// DEVUELVE  : bool -> "true" si hay coincidencia y "false" si no la hay
//-----------------------------------------------------------------------------
bool clsContactSprite::getMatch(clsBasicSprite* spr)
{
  int xl,yl,xe,ye,xaa,yaa;
  SDL_Color color;
  rgbColor pc;
  clsDot pixel;

   // Buscar punto opaco dentro del area de coincidencia del sprite local.
  for(yl = coord.yi1; yl < coord.yi1 + coord.ah; yl++)
  {

    for (xl = coord.xi1; xl < coord.xi1 + coord.aw ; xl++)
    {
      color=pixel.get(xl,yl,this->spritePointer[this->getI()].getPtr());
      pc.r=color.r; pc.g=color.g; pc.b=color.b;
      if(pc.r!=this->getTransparent().r ||
         pc.g!=this->getTransparent().g ||
         pc.b!=this->getTransparent().b
        )
      {
        // Se encontro un punto opaco dentro del area de contacto del sprite
        // local.
        xaa=xl-coord.xi1;
        yaa=yl-coord.yi1;
        xe=coord.xi2+xaa;
        ye=coord.yi2+yaa;

        // Verificar opacidad el punto coincidente del sprite externo
        i = spr->getI();
        color=pixel.get(xe,ye,spr->getPtr()->getPtr());
        pc.r=color.r; pc.g=color.g; pc.b=color.b;

        if(pc.r!=spr->getTransparent().r ||
           pc.g!=spr->getTransparent().g ||
           pc.b!=spr->getTransparent().b
          )
        {
          // Hay coincidencia de puntos opacos entre las dos areas.
          return true;
        }
      }
    }
  }
  return false;
}

#endif // _CLSCONTACT_H
//### FIN DE ARCHIVO ##########################################################
