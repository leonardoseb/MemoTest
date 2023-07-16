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
//#############################################################################
// ARCHIVO             : clsBasicSprite.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.3 estable.
// FECHA DE CREACION   : 29/09/2011.
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
//             clsBasicSpriteperteneciente al sistema adn++ (Sistema de Clases
//             para Modo Grafico para C++).
//
//             La clase clsBasicSprite contiene los elementos necesarios para
//             la creacion de clases que necesiten las funcionalidadaes basicas
//             de un sprite.
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
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSBASICSPRITE_H
#define _CLSBASICSPRITE_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsBasicSprite
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;           // Administrador de errores.
    clsImage* spritePointer;  // Puntero al vector de imagenes.
    int items;                // Cantidad total de items del vector de imagenes.
    char name[30];            // Nombre del sprite.
    int i;                    // Elemento actual dentro del vector de imagenes.
    int x;                    // coordenada x del sprite.
    int y;                    // coordenada y del sprite.
    int opacity;              // Grado de opacidad de las imagenes.
    rgbColor transparent ;    // Color asignado como transparente.
    tSpriteState state;       // Estado del sprite.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    virtual void inherit()=0;      // Convierte a la clase en abstracta.

  public:
    clsBasicSprite();               // Constructor por defecto.
    ~clsBasicSprite();              // Destructor implicito.
    int load(const char*);       // Carga una imagen en el elemento actual
                                   // del sprite
    void unload();                 // Destructor explicito.
    void paste(int,                // Copia el sprite en las coordenadas x, y de
               int,                // la superficie destino.
               SDL_Surface* sup);

    void setName(const char*);    // Pone un nuevo nombre al sprite.
    void setItems(int);            // Asigna un vector de imagenes a un objeto
                                    // que aun no lo tiene.
    int setI(int);                 // Cambia el indice del vector de imagenes.
    void setX(int);                // Cambia la coordenada x del sprite.
    void setY(int);                // Cambia la coordenada y del sprite.
    void setTransparent(rgbColor); // Cambia el color transparente del sprite.
    void setOpacity(int);          // Cambia el nivel de opacidad del sprite.
    void setState(tSpriteState);   // Establece el estado del sprite.
    char* getName();               // Devuelve el nombre del sprite.
    int getX();                    // Devuelve la coordenada x del sprite.
    int getY();                    // Devuelve la coordenada y del sprite.
    int getWidth();                // Devuelve el ancho de la imagen actual.
    int getHeight();               // Devuelve el ancho de la imagen actual.
    rgbColor getTransparent();     // Devuelve el color transparente del sprite.
    int getOpacity();              // Devuelve el nivel de opacidad del sprite.
    int getI();                    // Devuelve el indice actual del vector de
                                   // imagenes.
    clsImage* getPtr();            // Devuelve un puntero al vector de imagenes.
    clsImage* getPtr(int);         // Devuelve un puntero a la imagen i del vector.
    int getItems();                // Devuelve el total de imagenes.
    tSpriteState getState();       // Devuelve el estado del sprite.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : clsBasicSprite()
// ACCION    : Constructor por defecto.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsBasicSprite::clsBasicSprite()
{
  setItems(1);
  i=0;
  x=0;
  y=0;
  transparent=PINK;
  opacity=255;
  setName("Sprite sin Nombre");
}

//=============================================================================
// METODO    : ~clsBasicSprite()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsBasicSprite::~clsBasicSprite()
{
  if(spritePointer) delete [] spritePointer;

  cout << "DESTRUYO LAS IMAGENES DEL SPRITE " << getName() <<  endl;
}

//=============================================================================
// METODO    : void unload()
// ACCION    : Destructor explicito.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::unload()
{
  delete [] spritePointer;
  cout << "DESTRUYO EL SPRITE " <<  getName() << endl;
}

//=============================================================================
// METODO    : void setItems(int cant)
// ACCION    : Genera un vector de imagenes en memoria dinamica con la
//             cantidad de elementos pasada como parametro.
// PARAMETROS: int c -> cantidad de elementos asignados.
// DEVUELVE  : NADA.
//.............................................................................
// NOTA: Este metodo se utiliza para asignar el vector despues que se
//       construyo un objeto por defecto.
//-----------------------------------------------------------------------------
void clsBasicSprite::setItems(int c)
{
  spritePointer = new clsImage[c];
  items=c;
}
//=============================================================================
// METODO    : void setName(const char* n)
// ACCION    : Asigna un nuevo Nombre al sprite.
// PARAMETROS: char* n -> nuevo nombre.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setName(const char* n){strcpy(name,n);}

//=============================================================================
// METODO    : int load(const char* file)
// ACCION    : Carga un archivo de imagen en el elemento actual del
//             vector de imagenes..
// PARAMETROS: char* archivo -> cadena con el path y nombre de archivo.
// DEVUELVE  : int --> codigo de error (0 = todo bien)
//-----------------------------------------------------------------------------
int clsBasicSprite::load(const char* file)
{
  if(spritePointer[i].load(file))
  {
      error.set(700);
      return error.get();
  }

  SDL_SetColorKey(spritePointer[i].getPtr(),
                  SDL_SRCCOLORKEY|SDL_RLEACCEL,
                  SDL_MapRGB(spritePointer[i].getPtr()->format,
                             transparent.r,
                             transparent.g,
                             transparent.b
                            )
                 );
  SDL_SetAlpha(spritePointer[i].getPtr(),SDL_SRCALPHA|SDL_RLEACCEL,255);

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : int setI(int item)
// ACCION    : Cambia el indice del vector de elementos:
// PARAMETROS: int item -> nuevo indice.
// DEVUELVE  : int -> el codigo de error relacionado con los
//             mensajes de error declarados en ClsDirectMediaError.h.
//-----------------------------------------------------------------------------
int clsBasicSprite::setI(int item)
{

  if(item < 0 || item >= items)
  {
     error.set(701);
     return error.get();
  }

  i = item;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void paste(unsigned int X,unsigned int Y,SDL_Surface* sup)
// ACCION    : Copia al sprite en las coordenadas (X,Y) de la superficie
//             designada en el parametro sup.
// PARAMETROS: unsigned int X    -> coordenada Y de la pantalla.
//             unsigned int Y    -> coordenada X de la pantalla.
//             SDL_Surface* sup  -> puntero a la superficie destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::paste(int X,int Y,SDL_Surface* sup)
{
  int Width=spritePointer[i].getPtr()->w;
  int Height=spritePointer[i].getPtr()->h;

  SDL_Rect area = {X,Y,Width,Height};
  x=X;
  y=Y;
  SDL_BlitSurface(spritePointer[i].getPtr(), NULL, sup, &area);
}

//=============================================================================
// METODO    : void setX(int X)
// ACCION    : Cambia la coordenada x del sprite.
// PARAMETROS: int X -> nueva coordenada x del sprite.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setX(int X){x=X;}


//=============================================================================
// METODO    : void setY(int Y)
// ACCION    : Cambia la coordenada y del sprite.
// PARAMETROS: int Y -> nueva coordenada y del sprite.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setY(int Y){y=Y;}

//=============================================================================
// METODO    : void setTransparent(rgbColor color)
// ACCION    : Cambia el color transparente del sprite.
// PARAMETROS: rgbColor color -> nuevo color transparente.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setTransparent(rgbColor color)
{
  transparent=color;
}

//=============================================================================
// METODO    : void setOpacity(int level)
// ACCION    : Cambia el nivel de opacidad del sprite.
// PARAMETROS: int level -> nuevo nivel de opacidad.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setOpacity(int level)
{
  SDL_SetAlpha(spritePointer[i].getPtr(),
               SDL_SRCALPHA|SDL_RLEACCEL,level);

  opacity=level;
}

//=============================================================================
// METODO    : int getX()
// ACCION    : Devuelve la coordenada x del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de x.
//-----------------------------------------------------------------------------
int clsBasicSprite::getX() {return x;}

//=============================================================================
// METODO    : int getY()
// ACCION    : Devuelve la coordenada y del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  valor de y.
//-----------------------------------------------------------------------------
int clsBasicSprite::getY() {return y;}

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho en pixeles de la imagen actual del
//             sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  cantidad de pixeles.
//-----------------------------------------------------------------------------
int clsBasicSprite::getWidth()
{
  return spritePointer[i].getPtr()->w;
}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto en pixeles de la imagen actual del
//             sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  cantidad de pixeles.
//-----------------------------------------------------------------------------
int clsBasicSprite::getHeight()
{
  return spritePointer[i].getPtr()->h;
}

//=============================================================================
// METODO    : rgbColor getTransparent()
// ACCION    : Devuelve el color transparente del sprite.
// PARAMETROS: NADA
// DEVUELVE  : rgbColor ->  Color transparente.
//-----------------------------------------------------------------------------
rgbColor clsBasicSprite::getTransparent(){ return transparent;}

//=============================================================================
// METODO    : int getOpacity()
// ACCION    : Devuelve el nivel de opacidad del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int ->  Nivel de opacidad.
//-----------------------------------------------------------------------------
int clsBasicSprite::getOpacity(){ return opacity;}

//=============================================================================
// METODO    : int getI()
// ACCION    : Devuelve el indice actual del vector de imagenes.
// PARAMETROS: NADA
// DEVUELVE  : int ->  indice actual.
//-----------------------------------------------------------------------------
int clsBasicSprite::getI(){ return i;}


//=============================================================================
// METODO    : char* getName()
// ACCION    : Devuelve el nombre del sprite.
// PARAMETROS: NADA
// DEVUELVE  : char* ->  puntero a la cadena del nombre.
//-----------------------------------------------------------------------------
char* clsBasicSprite::getName(){return name;};

//=============================================================================
// METODO    : clsImage* getPtr()
// ACCION    : Devuelve un puntero a la primera imagen del vector de imagenes.
// PARAMETROS: NADA
// DEVUELVE  : clsImage* ->  puntero al vector de imagenes.
//-----------------------------------------------------------------------------
clsImage* clsBasicSprite::getPtr(){return spritePointer;}


//=============================================================================
// METODO    : clsImage* getPtr(int i)
// ACCION    : Devuelve un puntero a la imagen i del vector de imagenes.
// PARAMETROS: int i --> posicion de la imagen dentro del vector.
// DEVUELVE  : clsImage* ->  puntero a la imagen de la posicion i.
//-----------------------------------------------------------------------------
clsImage* clsBasicSprite::getPtr(int i)
{
    if(i >= 0 && i < items) return spritePointer+i;
    return NULL;
}


//=============================================================================
// METODO    : int getItems()
// ACCION    : Devuelve la cantidad de imagenes del sprite.
// PARAMETROS: NADA
// DEVUELVE  : int --> cantidad de imagenes
//-----------------------------------------------------------------------------
int clsBasicSprite::getItems() {return items;}


//=============================================================================
// METODO    : void setState(tSpriteState st)
// ACCION    : Establece el estado del sprite.
// PARAMETROS: tSpriteState st -> Nuevo estado.
//                                Valores posibles: INACTIVE / ACTIVE.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsBasicSprite::setState(tSpriteState st)
{
   state=st;
}

//=============================================================================
// METODO    : tSpriteState getState()
// ACCION    : Devuelve el estado del sprite.
// PARAMETROS:
// DEVUELVE  : tSpriteState -> estado del sprite.
//                             Valores posibles: INACTIVE / ACTIVE.
//-----------------------------------------------------------------------------
tSpriteState clsBasicSprite::getState()
{
   return state;
}


#endif // _CLSBASICSPRITE_H
//### FIN DE ARCHIVO ##########################################################
