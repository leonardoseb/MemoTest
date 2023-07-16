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
// ARCHIVO             : clsText.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.10 estable.
// FECHA DE CREACION   : 15/02/2011.
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
//             Este archivo contiene la definicion de la clase clsText pertene-
//             ciente al sistema adn++ (Sistema de Clases para Modo Grafico
//             para C++).
//
//             La clase clsTextncontiene los elementos necesarios para la
//             administracion de los textos en el modo grafico.
//
//=============================================================================
// __________________________________________________________
// |                         clsText                        |
// |--------------------------------------------------------|
// | # error: clsError                                      |
// | # fontName: char[]                                     |
// | # fontFile: char[]                                     |
// | # frame: SDL_Surface*                                  |
// | # font: TTF_Font*                                      |
// | # fontColor: rgbColor                                  |
// | # backColor: rgbColor                                  |
// | # style: tFontStyle                                    |
// | # texture: tFontTexture                                |
// | # Height: int                                          |
// | # Width: int                                           |
// |--------------------------------------------------------|
// | + init(): int                                          |
// | + loadFont(const char*,int): int                       |
// | + setFontColor(rgbColor): void                         |
// | + setBackColor(rgbColor): void                         |
// | + setStyle(tFontStyle): void                           |
// | + setTexture(tFontTexture): void                       |
// | + setFontFile(const char*): int                        |
// | + write(const char*,int,int,SDL_Surface*): void        |
// | + writeBlended(const char*,int,int,SDL_Surface*): void |
// | + centredWrite(const char*,int,SDL_Surface*): void     |
// | + getFontColor(): rgbColor                             |
// | + getBackColor(): rgbColor                             |
// | + getStyle(): tFontStyle                               |
// | + getTexture(): tFontTexture                           |
// | + getHeight(): int                                     |
// | + getWidth(): int                                      |
// | + getFontName(): char*                                 |
// | + getFontFile(): char*                                 |
// |________________________________________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSTEXT_H
#define _CLSTEXT_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsText
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;              // Administrador de errores
    char fontName[256];          // Nombre de la fuente atual.
    char fontFile[256];          // Nombre del archivo actual.
    SDL_Surface* frame;          // Marco del texto;
    TTF_Font* font;              // Puntero al archivo de fuente.
    rgbColor fontColor;          // Color de la fuente
    rgbColor backColor;          // Color fondo. Por defecto PINK.
    tFontStyle style;            // Estilo de la fuente.
    tFontTexture texture;        // Textura de la fuente.
    int Height;                    // Altura total del texto;
    int Width;                    // Ancho total del texto;

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
    int init();                          // Inicializa el modo texto para el
                                         // modo grafico.
    ~clsText();                          // Destructor.
    int  loadFont(const char*, int);     // Carga un archivo fuente tipo ttf.
    void setFontColor(rgbColor);         // Cambia el color de la fuente.
    void setBackColor(rgbColor);         // Cambia el color del fondo.
    void setStyle(tFontStyle);           // Cambia el estilo de la fuente.
    void setTexture(tFontTexture);       // Cambia la textura de la fuente.
    int setFontFile(const char*);        // Cambia path y nombre de archivo ttf.
    void write(const char*,int,          // Escribe un texto en una pantalla.
               int,SDL_Surface*);
    void writeBlended(const char*, int,  // Escribe el texto blendeado en una
                      int, SDL_Surface*);// pantalla.
    void centredWrite(const char*,int,   // Escribe un texto centrado en una
                      SDL_Surface*);     // pantalla.
    rgbColor getFontColor();             // Devuelve el color de la fuente.
    rgbColor getBackColor();             // Devuelve el color del fondo.
    tFontStyle getStyle();               // Devuelve el estilo.
    tFontTexture getTexture();           // Devuelve la textura.
    int getHeight();                       // Devuelve la altura.
    int getWidth();                       // Devuelve el ancho.
    char* getFontName();                 // Devuelve el nombre de la fuente.
    char* getFontFile();                 // Devuelve el nombre del archivo.
};

//=============================================================================
//			             DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa el uso de texto en modo grafico.
//             VALORES POR DEFECTO: estilo     -> NORMAL.
//                                  textura    -> SOLID.
//                                  ancho      -> 20.
//                                  alto       -> 20.
//                                  fontColor  -> BLACK.
//                                  backColor  -> GRAY.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error ( 0 = todo bien)
//-----------------------------------------------------------------------------
int clsText::init()
{
  if(TTF_Init() < 0)
  {
    error.set(900);
    return error.get();
  }

  style=NORMAL;
  texture=SOLID;
  Height=20;
  Width=20;
  fontColor=BLACK;
  backColor=GRAY;

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    :  ~clsText()
// ACCION    : Destructor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsText::~clsText()
{
  cout << "DESTRUYO EL OBJETO TEXTO " << getFontFile() << endl;
}

//=============================================================================
// METODO    : int loadFont(char* file, int size)
// ACCION    : Carga un archivo de fuente tipo ttf..
// PARAMETROS: char* file -> Ruta y nombre del archivo ttf.
//             int size   -> Tamanio de la fuente.
// DEVUELVE  : int --> codigo de error ( 0 = todo bien).
//-----------------------------------------------------------------------------
int clsText::loadFont(const char* file, int size)
{
  char aux[256];
  int i,j;

  font=TTF_OpenFont(file,size);
  if(font==NULL)
  {
    error.set(901);
    return error.get();
  }

  i=strlen(file)-1;
  while(file[i]!='/' && file[i]!='\\')
  {
    i--;
  }

  i++;
  j=0;
  while(file[i]!='\0')
  {
    aux[j]=file[i];
    i++;
    j++;
  }
  aux[j-4]='\0';

  strcpy(fontName,aux);
  strcpy(fontFile,file);

  Width=size;
  Height=size;

  error.set(0);
  return error.get();

}

//=============================================================================
// METODO    : void setFontColor(rgbColor color)
// ACCION    : Cambia el color del texto.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setFontColor(rgbColor color)
{
  fontColor=color;
}

//=============================================================================
// METODO    : void setBackColor(rgbColor color)
// ACCION    : Cambia el color del fondo del texto.
// PARAMETROS: rgbColor color -> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setBackColor(rgbColor color)
{
  backColor=color;
}

//=============================================================================
// METODO    : void setStyle(tFontStyle sty)
// ACCION    : Cambia el estilo de la fuente.
// PARAMETROS: tFontStyle sty -> estilos
//                               Estilos posibles: NORMAL,BOLD,ITALIC.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setStyle(tFontStyle sty)
{
  style=sty;
}

//=============================================================================
// METODO    : void setTexture(tFontTexture tex)
// ACCION    : Cambia la textura de la fuente.
// PARAMETROS: tFontTexture tex -> texturas.
//                                 Texturas posibles: SOLID,SHADED.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::setTexture(tFontTexture tex)
{
  texture=tex;
}

//=============================================================================
// METODO    : int setFontFile(const char* str)
// ACCION    : Cambia path y nombre de archivo ttf.
// PARAMETROS: const char* str --> path y archivo ttf-
// DEVUELVE  : int --> codigo de error ( 0 = todo bien).
//-----------------------------------------------------------------------------
int clsText::setFontFile(const char* str)
{
  error.set(loadFont(str,Width));
  if(error.get())
  {
    return error.get();
  }

  error.set(0);
  return error.get();
}
//=============================================================================
// METODO    : void centredWrite(char* texto,int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto centrado en las coordenadas Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::centredWrite(const char* text,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  SDL_Color bcolor;

  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  bcolor.r=backColor.r;
  bcolor.g=backColor.g;
  bcolor.b=backColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  switch(texture)
  {
    case SOLID   : frame = TTF_RenderText_Solid(font,text,fcolor);
                   break;
    case SHADED  : frame = TTF_RenderText_Shaded(font,text,fcolor,bcolor);
                   break;
  }

  int x=(scr->w - this->getWidth())/2;

  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;

  SDL_BlitSurface(frame,NULL,scr,&area);
}

//=============================================================================
// METODO    : void write(char* text, intx, int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto en las coordenadas X e Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int x              -> Coordenada X de la superficie destino
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::write(const char* text,int x,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  SDL_Color bcolor;

  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  bcolor.r=backColor.r;
  bcolor.g=backColor.g;
  bcolor.b=backColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  switch(texture)
  {
    case SOLID     : frame = TTF_RenderText_Solid(font,text,fcolor);
                    break;
    case SHADED:    frame = TTF_RenderText_Shaded(font,text,fcolor,bcolor);
                    break;
  }
  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;
  SDL_BlitSurface(frame,NULL,scr,&area);
}

//=============================================================================
// METODO    : void writeBlended(char* text, intx, int y,SDL_Surfacr* scr)
// ACCION    : Escribe un texto en las coordenadas X e Y de una pantalla.
// PARAMETROS: char* text         -> Texto a escribir.
//             int x              -> Coordenada X de la superficie destino
//             int y              -> Coordenada Y de la superficie destino.
//             SDL_Surface* scr   -> Pantalla destino.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsText::writeBlended(const char* text,int x,int y,SDL_Surface* scr)
{
  SDL_Color fcolor;
  fcolor.r=fontColor.r;
  fcolor.g=fontColor.g;
  fcolor.b=fontColor.b;

  SDL_Rect area;

  TTF_SizeText(font,text,&Width,&Height);

  switch(style)
  {
    case NORMAL   : TTF_SetFontStyle(font,TTF_STYLE_NORMAL);
                    break;
    case BOLD     : TTF_SetFontStyle(font,TTF_STYLE_BOLD);
                    break;
    case ITALIC   : TTF_SetFontStyle(font,TTF_STYLE_ITALIC);
                    break;
  }

  frame = TTF_RenderText_Blended(font,text,fcolor);

  area.x=x;
  area.y=y;
  area.w=frame->w;
  area.h=frame->h;
  SDL_BlitSurface(frame,NULL,scr,&area);
}

//=============================================================================
// METODO    : rgb getFontColor()
// ACCION    : Devuelve el color de la fuente.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Color -> color de fuente.
//-----------------------------------------------------------------------------
rgbColor clsText::getFontColor(){return fontColor;};

//=============================================================================
// METODO    : rgbColor getBackColor()
// ACCION    : Devuelve el color de fondo.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Color -> color de fondo.
//-----------------------------------------------------------------------------
rgbColor clsText::getBackColor(){return backColor;};

//=============================================================================
// METODO    : tFontStyle getStyle()
// ACCION    : Devuelve el estilo de la fuente .
// PARAMETROS: NADA.
// DEVUELVE  : tFontStyle -> Estilo.
//-----------------------------------------------------------------------------
tFontStyle clsText::getStyle(){return style;};

//=============================================================================
// METODO    : tFontTexture getTexture()
// ACCION    : Devuelve la textura de la fuente .
// PARAMETROS: NADA.
// DEVUELVE  : tFontTexture -> Textura.
//-----------------------------------------------------------------------------
tFontTexture clsText::getTexture(){return texture;};

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho total del texto.
// PARAMETROS: NADA.
// DEVUELVE  : int -> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsText::getWidth(){return Width;}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto total del texto.
// PARAMETROS: NADA.
// DEVUELVE  : int -> alto en pixeles.
//-----------------------------------------------------------------------------
int clsText::getHeight(){return Height;}

//=============================================================================
// METODO    : char* getFontName().
// ACCION    : Devuelve el nombre de la fuente.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> nombre de la fuente.
//-----------------------------------------------------------------------------
char* clsText::getFontName(){return fontName;}

//=============================================================================
// METODO    : char* getFontFile().
// ACCION    : Devuelve el nombre del archivo ttf.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> nombre del archivo.
//-----------------------------------------------------------------------------
char* clsText::getFontFile(){return fontFile;}

#endif // _CLSTEXT_H
//### FIN DE ARCHIVO ##########################################################
