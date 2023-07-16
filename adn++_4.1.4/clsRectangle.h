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
// ARCHIVO             : clsRectangle.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.0 estable.
// FECHA DE CREACION   : 26/10/2011.
// ULTIMA ACTUALIZACION: 29/09/2012.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DEDICATORIA: A mi Padre Amadeo Calabuig (28/12/1024 - 10/03/1995).
//=============================================================================
// DESCRIPCION:
//             Este archivo contiene la definicion de la clase clsRectangle
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsRectangle contiene los elementos necesarios para la
//             administracion de rectangulos para el modo grafico.
//
//=============================================================================
// __________________________________________________________
// |                      clsRectangle                      |
// |--------------------------------------------------------|
// | # pixel: clsDot                                        |
// | # lColor: rgbColor                                     |
// | # fColor: rgbColor                                     |
// | # xi: int                                              |
// | # xf: int                                              |
// | # yi: int                                              |
// | # yf: int                                              |
// | # Width: int                                           |
// | # Height: int                                          |
// |--------------------------------------------------------|
// | # hLine(int,SDL_Surface*): void                        |
// | # vLine(int,SDL_Surface*): void                        |
// | + clsRectangle()                                       |
// | + config(int,int,int,int,rgbColor,rgbColor): void      |
// | + empty(SDL_Surface*): void                            |
// | + fill(SDL_Surface*): void                             |
// | + setLineColor(rgbColor): void                         |
// | + setBackColor(rgbColor): void                         |
// | + setXi(int): void                                     |
// | + setXf(int): void                                     |
// | + setYi(int): void                                     |
// | + setXf(int): void                                     |
// | + getLineColor(): rgbColor                             |
// | + getBackColor(): rgbColor                             |
// | + getHeight(): int                                     |
// | + getWidth(): int                                      |
// | + getXi(int): int                                      |
// | + getXf(): int                                         |
// | + getYi(): int                                         |
// | + getYf(): int                                         |
// |________________________________________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSRECTANGLE_H_INCLUDED
#define CLSRECTANGLE_H_INCLUDED

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsRectangle
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
   protected:
    clsDot pixel;        // Objeto para dibujar el rectangulo.
    rgbColor lColor;     // Color de borde de el rectangulo.
    rgbColor fColor;     // Color de fondo de el rectangulo.
    int xi;              // Coordenada x inicial de el rectangulo.
    int xf;              // Coordenada x final de el rectangulo.
    int yi;              // Coordenada y inicial de el rectangulo.
    int yf;              // Coordenada x final de el rectangulo.
    int Width;            // Ancho del rectangulo.
    int Height;            // Alto del rectangulo.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    void  hLine(int,SDL_Surface*);      // Dibuja una linea horizontal.
    void  vLine(int,SDL_Surface*);      // Dibuja una linea vertical.

  public:
    clsRectangle();                      // Constructor.
    void config(int,int,int,int,         // Configura el rectangulo.
                rgbColor,rgbColor);
    void  empty(SDL_Surface*);           // Dibuja un rectangulo vacio.
    void  fill(SDL_Surface*);            // Dibuja un rectangulo relleno.
    void paste(SDL_Surface*);            // Muestra el rectangulo en una pantalla.
    void setLineColor(rgbColor);         // Cambia el color del borde.
    void setBackColor(rgbColor);         // Cambia el color de fondo.
    void setXi(int);                     // Cambia la coordenada x inicial.
    void setXf(int);                     // Cambia la coordenada x final.
    void setYi(int);                     // Cambia la coordenada y inicial.
    void setYf(int);                     // Cambia la coordenada y final.
    rgbColor getLineColor();             // Devuelve el color de linea.
    rgbColor getBackColor();             // Devuelve el color de fondo.
    int getHeight();                       // Devuelve la altura total en pixeles.
    int getWidth();                       // Devuelve el ancho total en pixeles.
    int getXi();                         // Devuelve la coordenada x inicial.final.
    int getXf();                         // Devuelve la coordenada x inicial.final.
    int getYi();                         // Devuelve la coordenada y inicial.
    int getYf();                         // Devuelve la coordenada y final.
};

//=============================================================================
//			             DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : void clsRectangle()
// ACCION    : Constructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsRectangle::clsRectangle()
{
  xi=1;
  xf=100;
  yi=1;
  yf= 22;
  Width=xf-xi;
  Height=yf-yi;

  lColor=BLACK;
  fColor=WHITE;
}

//=============================================================================
// METODO    : void config(int x1, int y1, int x2,int y2
//                         rgbColor lc, rgbColor fc, rgbColor tc)
// ACCION    : Configura el rectangulo.
// PARAMETROS: int x1      --> Coordenada x inicial de el rectangulo.
//             int y1      --> Posicion y de el rectangulo.
//             int x2      --> Coordenada x final de el rectangulo.
//             rgbColor lc --> Color de borde de el rectangulo.
//             rgbColor fc --> Color de fondo de el rectangulo.
//             rgbColor tc --> Color de texto de el rectangulo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::config(int x1, int y1, int x2, int y2,rgbColor lc, rgbColor fc)
{
    xi=x1;
    xf=x2;
    yi=y1;
    yf=y2;
    lColor=lc;
    fColor=fc;
}

//=============================================================================
// METODO    : void setLineColor(rgbColor color)
// ACCION    : Cambia el color de la linea del rectangulo.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setLineColor(rgbColor color)
{
  lColor=color;
}

//=============================================================================
// METODO    : void setBackColor(rgbColor color)
// ACCION    : Cambia el color del fondo del rectangulo.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setBackColor(rgbColor color)
{
  fColor=color;
}

//=============================================================================
// METODO    : void setXi(int x)
// ACCION    : Cambia la coordenada x inicial.
//
//             NOTA: solo actua si el nuevo valor es menor que la coordenada
//                   x final.
// PARAMETROS: int x --> nueva coordenada.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setXi(int x) {xi=x;}

//=============================================================================
// METODO    : void setXf(int x)
// ACCION    : Cambia la coordenada x final.
//
//             NOTA: solo actua si el nuevo valor es mayor que la coordenada
//                   x inicial.
// PARAMETROS: int x --> nueva coordenada.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setXf(int x) {xf=x;}

//=============================================================================
// METODO    : void setYi(int y)
// ACCION    : Cambia la coordenada y inicial.
//
//             NOTA: solo actua si el nuevo valor es menor que la coordenada
//                   y final.
// PARAMETROS: int y --> nueva coordenada.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setYi(int y) {yi=y;}

//=============================================================================
// METODO    : void setYf(int y)
// ACCION    : Cambia la coordenada y final.
//
//             NOTA: solo actua si el nuevo valor es mayor que la coordenada
//                   y inicial.
// PARAMETROS: int y --> nueva coordenada.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::setYf(int y) {yf=y;}

//=============================================================================
// METODO    : rgbColor getLineColor()
// ACCION    : Devuelve el color la la linea del rectangulo.
// PARAMETROS: NADA.
// DEVUELVE  : rgbColor -> color de linea.
//-----------------------------------------------------------------------------
rgbColor clsRectangle::getLineColor(){return lColor;};

//=============================================================================
// METODO    : rgbColor getBackColor()
// ACCION    : Devuelve el color de fondo del rectangulo.
// PARAMETROS: NADA.
// DEVUELVE  : rgbColor -> color de fondo.
//-----------------------------------------------------------------------------
rgbColor clsRectangle::getBackColor(){return fColor;};

//=============================================================================
// METODO    : void hLine(int y, SDL_Surface* scr)
// ACCION    : Dibuja un borde horizontal del rectangulo en una pantalla.
// PARAMETROS: int y --> coordenada y de la linea.
//             SDL_Surface* pant --> puntero a la pantalla.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::hLine(int y, SDL_Surface* scr)
{
    int i;
    for (i=xi;i<=xf;i++)
    {
        pixel.set(i,y,lColor,scr);
    }
}

//=============================================================================
// METODO    : void vLine(int x, SDL_Surface* scr)
// ACCION    : Dibuja un borde vertical del rectangulo en una pantalla.
// PARAMETROS: int x --> coordenada y de la linea.
//             SDL_Surface* pant --> puntero a la pantalla.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::vLine(int x, SDL_Surface* scr)
{
    int i;
    for (i=yi;i<=yf;i++)
    {
        pixel.set(x,i,lColor,scr);
    }
}

//=============================================================================
// METODO    : void empty(SDL_Surface*scr)
// ACCION    : Dibuja el rectangulo vacio en una pantalla.
// PARAMETROS: SDL_Surface* pant --> puntero a la pantalla.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::empty(SDL_Surface* scr)
{
    hLine(yi,scr);
    hLine(yf,scr);
    vLine(xi,scr);
    vLine(xf,scr);
}

//=============================================================================
// METODO    : void fill(SDL_Surface* scr)
// ACCION    : Dibuja el rectangulo de fondo en una pantalla.
// PARAMETROS: SDL_Surface* pant --> puntero a la pantalla.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRectangle::fill(SDL_Surface* scr)
{
    int f,c;
    hLine(yi,scr);
    hLine(yf,scr);
    vLine(xi,scr);
    vLine(xf,scr);
    for(f=yi+1; f<yf; f++)
    {
       for (c=xi+1;c<xf;c++)
       {
            pixel.set(c,f,fColor,scr);
       }
    }
}

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho total.
// PARAMETROS: NADA.
// DEVUELVE  : int -> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsRectangle::getWidth(){return Width;}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto total.
// PARAMETROS: NADA.
// DEVUELVE  : int -> alto en pixeles.
//-----------------------------------------------------------------------------
int clsRectangle::getHeight(){return Height;}

//=============================================================================
// METODO    : int getXi()
// ACCION    : Devuelve la coordenada x inicial.
// PARAMETROS: NADA.
// DEVUELVE  : int -> coordenada xi.
//-----------------------------------------------------------------------------
int clsRectangle::getXi(){return xi;}

//=============================================================================
// METODO    : int getXf()
// ACCION    : Devuelve la coordenada x final.
// PARAMETROS: NADA.
// DEVUELVE  : int -> coordenada xf.
//-----------------------------------------------------------------------------
int clsRectangle::getXf(){return xf;}

//=============================================================================
// METODO    : int getYi()
// ACCION    : Devuelve la coordenada y inicial.
// PARAMETROS: NADA.
// DEVUELVE  : int -> coordenada yi.
//-----------------------------------------------------------------------------
int clsRectangle::getYi(){return yi;}

//=============================================================================
// METODO    : int getYf()
// ACCION    : Devuelve la coordenada y final.
// PARAMETROS: NADA.
// DEVUELVE  : int -> coordenada yf.
//-----------------------------------------------------------------------------
int clsRectangle::getYf(){return yf;}

#endif // CLSRECTANGLE_H_INCLUDED
//### FIN DE ARCHIVO ##########################################################
