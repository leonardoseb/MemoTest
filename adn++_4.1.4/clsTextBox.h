//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.4 estable         //
//              @@@@@  @    @@@@@  @    @       @    24/10/2012              //
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
// ARCHIVO             : clsTextBox.h
// AUTOR               : Ruben Alberto Calabuig.
// COLABORACION        : Agustin Miranda.
// VERSION             : 4.1.4 estable.
// FECHA DE CREACION   : 26/10/2011.
// ULTIMA ACTUALIZACION: 24/10/2012.
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
//             Este archivo contiene la definicion de la clase clsTextBox
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsTextBox, que es en realidad una agregacion, contiene
//             los elementos necesarios para la administracion de cajas de tex-
//             to para el modo grafico.
//
//             Los objetos de clase clsTextBox pueden utilizarse para ingresar
//             o mostrar datos.
//
//=============================================================================
// _________________________________________
// |               clsTextBox              |
// |---------------------------------------|
// | # error: clsError                     |
// | # event: clsEvent                     |
// | # box: clsRectangle                   |
// | # text: clsText                       |
// | # string[256]: char                   |
// | # straux[256]: char                   |
// | # boxStyle: tBoxStyle                 |
// | # cursor: int                         |
// |---------------------------------------|
// | # strInv(char*): void                 |
// | # intToStr(int,char*): void           |
// | + init(SDL_Surface*): int             |
// | + input(): int                        |
// | + show(SDL_Surface*): void            |
// | + setBoxStyle(tBoxStyle): texTBoxStyle|
// | + setString(const char*): void        |
// | + setStrAux(const char*): void        |
// | + setFontFile(const char*): int       |
// | + setFontSize(int): int               |
// | + setFontColor(rgbColor): void        |
// | + setFillColor(rgbColor): void        |
// | + setLineColor(rgbColor): void        |
// | + setNumber(int): void                |
// | + setX(int): void                     |
// | + setY(int): void                     |
// | + setWidth(int): void                 |
// | + setHeight(int): void                |
// | + getBoxPtr(): clsRectangle*          |
// | + getTextPtr(): clsText*              |
// | + getBoxStyle(): tBoxStyle            |
// | + getString(): char*                  |
// | + getStrAux(): char*                  |
// | + getFontFile: char*                  |
// | + getNumber(): int                    |
// | + getX(int): int                      |
// | + getY(int): int                      |
// | + getWidth(): int                     |
// | + getHeight(): int                    |
// |_______________________________________|
//
//                        ___________
//                        |         |
//                        | Textbox |
//                        |_________|
//                            < >
//                             |
//       ______________________|_________
//       |         |           |        |
//   ___1|____ ___1|____ _____1|___ ___1|____
//   |       | |       | |        | |       |
//   | Error | |  Box  | |  Text  | | Event |
//   |_______| |_______| |________| |_______|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSTEXTBOX_H
#define CLSTEXTBOX_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsTextBox
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;               // Administrador de errores.
    clsEvent event;               // Administrador de eventos.
    clsRectangle box;             // Caja de la textbox.
    clsText text;                 // Administrador del texto.
    char string[256];             // Cadena interna de la textbox.
    char straux[256];             // Cadena auxiliar.
    tBoxStyle boxStyle;           // Estilo de la caja de la textbox.
    int cursor;                   // Posicion del cursor dentro de la caja.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
    void strInv(char*);            // Invierte una cadena pasada.
    void intToStr(int,char*);      // Convierte un numero entero en cadena.

  public:
    int init();                    // Inicializa la textbox.
    int input(SDL_Surface*);       // Permite el ingresar texto en una pantalla.
    void show(SDL_Surface*);       // Muestra la textbox en una pantalla.
    void setBoxStyle(tBoxStyle);   // Cambia el estilo de la caja.
    void setString(const char*);   // Cambia la cadena interna.
    void setStrAux(const char*);   // Cambia la cadena auxiliar.
    int setFontFile(const char*);  // Cambia path y nombre del archivo ttf.
    int setFontSize(int);          // Cambia el tamanio de la fuente.
    void setFontColor(rgbColor);   // Cambia el color del texto.
    void setFillColor(rgbColor);   // Cambia el color de relleno de la textbox.
    void setLineColor(rgbColor);   // Cambia el color de borde de la textbox-
    void setNumber(int);           // Cambia la cadena interna por una cadena
                                    // integrada solo por digitos.
    void setX(int);                // Cambia la coordenada x de la textbox.
    void setY(int);                // Cambia la coordenada y de la textbox.
    void setWidth(int);            // Cambia el ancho de la textbox.
    void setHeight(int);           // Cambia el alto de la textbox.
    clsRectangle* getBoxPtr();     // Devuelve un puntero al rectangulo de la
                                   // textbox.
    clsText* getTextPtr();         // Devuelve un puntero al texto de la textbox.
    tBoxStyle getBoxStyle();       // Devuelve el estilo de la caja.
    char* getString();             // Devuelve la cadena interna.
    char* getStrAux();             // Devuelve la cadena auxiliar.
    char* getFontFile();           // Devuelve el nombre del archivo ttf.
    int   getNumber();             // Devuelve el valor numerico de la cadena
                                   // interna de la textbox.
    int getX();                    // Devuelve la coordenada x de la textbox.
    int getY();                    // Devuelve la coordenada y de la textbox.
    int getWidth();                 // Devuelve el ancho de la textbox.
    int getHeight();                 // Devuelve el alto de la textbox.
};

//=============================================================================
//			             DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa la textbox.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsTextBox::init()
{
  error.set(text.init());
  if(error.get())
  {
    return error.get();
  }

  text.setFontColor(BLACK);
  text.setBackColor(GRAY);
  setFontSize(12);
  box.config(10,10,20,34,BLACK,WHITE);
  boxStyle=FILL;
  cursor=20;
  string[0]=' ';
  string[1]='\0';

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : int input(SDL_Surface* scr)
// ACCION    : Permite el ingreso de texto a la textbox en una pantalla.
//             Si se presiona ESCAPE cancela el ingreso.
// PARAMETROS: SDL_Surface* scr --> puntero a la pantalla.
// DEVUELVE  : int --> codigo de salida.
//                     Codigos posibles: 1 = ENTER
//                                       2 = ESCAPE
//                                       0 = cualquier otra tecla.
//.............................................................................
//                          ¡¡¡IMPORTANTE!!!
//
//   Debido a que el metodo input() lee de una tecla por vez, este debe ser
// incluido en un ciclo externo a la clase.
//
//   Esta circunstancia hace que no haya control de la cadena cuando se desea
// cancelar el ingreso, por lo que recomiendo el siguiente esquema de uso:
//
//
//  int end;                       // Declarar una variable entera para
//                                 // controlar el ciclo.
//
//  textbox.show(pnt.getPtr());    // Mostrar la caja fuera del ciclo.
//  pnt.paste(screen.getPtr());
//  screen.refresh();
//
//  end=0;                         // Inicializar la variable de control.
//
//  textbox.setStrAux(textbox.getString()); // Hacer una copia backup de la
//                                          // cadena interna.
//
//  while (end==0)
//  {
//    //=========================================//
//    //        HACER LO QUE CORRESPONDA         //
//    //=========================================//
//
//    end=textbox.input(pnt.getPtr()); // Realizar el ingreso.
//    pnt.paste(screen.getPtr());
//    screen.refresh();
//  }
//
//  if(end==2)textbox.setString(textbox.getStrAux()); // Si se salio con ESC
//                                                    // recuperar la cadena
//                                                    // backup.
//
//-----------------------------------------------------------------------------
int clsTextBox::input(SDL_Surface* scr)
{
    Uint8 leter;
    Uint16 key;

    cursor=strlen(string);

    show(scr);

    if(event.wasEvent())
    {
      if(event.getEventType()==KEY_PRESSED)
      {
        key=event.getKey();
        switch(key)
        {
           case KEY_ENTER: string[cursor]='\0';
                           return 1;
                           break;

           case KEY_ESCAPE: return 2;
                            break;

           case KEY_BACKSPACE: if(cursor>0) cursor--;
                               if(cursor==0)
                               {
                                 string[0]=' ';
                                 string[1]='\0';
                               }
                               else
                               {
                                 string[cursor]='\0';
                               }
                               return 0;
                               break;

           default:  leter=(Uint8)key;

                     string[cursor]=leter;
                     string[cursor+1]='\0';
                     cursor++;
                     return 0;
        }
      }
      return 0;
    }
    return 0;
}

//=============================================================================
// METODO    : void show(SDL_Surface* scr)
// ACCION    : Muestra la textbox en una pantalla.
// PARAMETROS: SDL_Surface* scr --> puntero a la pantalla.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::show(SDL_Surface* scr)
{
  if(boxStyle==FILL)
  {
    box.fill(scr);
  }
  else
  {
    box.empty(scr);
  }

  text.write(string,
             box.getXi()+text.getHeight(),
             box.getYi()+((box.getHeight()-text.getHeight())/2),
             scr);
}
//=============================================================================
// METODO    : void setBoxStyle(tBoxStyle sty)
// ACCION    : Cambia el estilo de la caja de la textbox
// PARAMETROS: tBoxStyle sty --> nuevo estilo.
//                               Estilos posibles: EMPTY,FILL.
//
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setBoxStyle(tBoxStyle sty)
{
  boxStyle=sty;
}

//=============================================================================
// METODO    : void setString(const char* str)
// ACCION    : Cambia la cadena de la textbox.
// PARAMETROS: const char* str --> nueva cadena.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setString(const char* str)
{
  int i;
  int len = strlen(str);

  if(len>256)  len=256;

  for(i=0;i<len;i++) string[i]=str[i];
  string[i]='\0';
}

//=============================================================================
// METODO    : void setStrAux(const char* str)
// ACCION    : Cambia la cadena auxiliar.
// PARAMETROS: const char* str --> nueva cadena.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setStrAux(const char* str)
{
  strcpy(straux,str);
}


//=============================================================================
// METODO    : int setFontFile(const char* str)
// ACCION    : Cambia path y nombre de archivo ttf.
// PARAMETROS: const char* str --> nueva path y nombre.
// DEVUELVE  : int --> codigo de error ( 0  = todo bien).
//-----------------------------------------------------------------------------
int clsTextBox::setFontFile(const char* str)
{
  error.set(text.setFontFile(str));
  if(error.get())
  {
    return error.get();
  }
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : int setFontSize(int sz)
// ACCION    : Cambia el tamanio de la fuente.
// PARAMETROS: int sz --> nuevo tamanio.
// DEVUELVE  : int --> codigo de error ( 0  = todo bien).
//-----------------------------------------------------------------------------
int clsTextBox::setFontSize(int sz)
{
  error.set(text.loadFont(getFontFile(),sz));
  if(error.get())
  {
    return error.get();
  }

  box.setYf(box.getYi()+sz+4);

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void setFontColor(rgbColor color)
// ACCION    : Cambia el color de la fuente.
// PARAMETROS: rgbColor c --> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setFontColor(rgbColor color)
{
  text.setFontColor(color);
}

//=============================================================================
// METODO    : void setFillColor(rgbColor color)
// ACCION    : Cambia el color de relleno de la textbox.
// PARAMETROS: rgbColor c --> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setFillColor(rgbColor color)
{
  box.setBackColor(color);
}

//=============================================================================
// METODO    : void setLineColor(rgbColor color)
// ACCION    : Cambia el color de linea de la textbox.
// PARAMETROS: rgbColor c --> nuevo color.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::setLineColor(rgbColor color)
{
  box.setLineColor(color);
}

//=============================================================================
// METODO    : void setNumber(int n)
// ACCION    : Cambia la cadena interna por una cadena formada solo por digitos.
// PARAMETROS: int n --> numero entero a ingresar.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsTextBox::setNumber(int n)
{
  intToStr(n,string);
  strInv(string);
}

//=============================================================================
// METODO    : void setX(int X)
// ACCION    : Cambia la coordenada x de la textbox.
// PARAMETROS: int X --> nueva coorednada.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsTextBox::setX(int X)
{
  box.setXi(X);
  box.setXf(X+box.getWidth());
}

//=============================================================================
// METODO    : void setY(int Y)
// ACCION    : Cambia la coordenada y de la textbox.
// PARAMETROS: int Y --> nueva coorednada.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsTextBox::setY(int Y)
{
  box.setYi(Y);
  box.setYf(Y+box.getHeight());
}

//=============================================================================
// METODO    : void setWidth(int w)
// ACCION    : Cambia la coordenada y de la textbox.
// PARAMETROS: int w --> nuevo ancho.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsTextBox::setWidth(int w)
{
  box.setXf(box.getXi()+w);
}

//=============================================================================
// METODO    : void setHeight(int h)
// ACCION    : Cambia la coordenada y de la textbox.
// PARAMETROS: int h --> nuevo alto.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsTextBox::setHeight(int h)
{
  box.setYf(box.getYi()+h);
}

//=============================================================================
// METODO    : clsRectangle* getBoxPtr()
// ACCION    : Devuelve el puntero al rectangulo de la textbox.
// PARAMETROS: NADA.
// DEVUELVE  : clsRectangle* --> puntero al rectangulo.
//-----------------------------------------------------------------------------
clsRectangle* clsTextBox::getBoxPtr(){return &box;};


//=============================================================================
// METODO    : clsText* getTextPtr()
// ACCION    : Devuelve el puntero al texto de la textbox.
// PARAMETROS: NADA.
// DEVUELVE  : clsText* --> puntero al texto.
//-----------------------------------------------------------------------------
clsText* clsTextBox::getTextPtr(){return &text;};

//=============================================================================
// METODO    : tBoxStyle getBoxStyle()
// ACCION    : Devuelve el estilo de la caja de la textbox.
// PARAMETROS: NADA.
// DEVUELVE  : tBoxstyle --> estilo.
//-----------------------------------------------------------------------------
tBoxStyle clsTextBox::getBoxStyle(){return boxStyle;};

//=============================================================================
// METODO    : char* getString()
// ACCION    : Devuelve la cadena interna de la textbox.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> la cadena.
//-----------------------------------------------------------------------------
char* clsTextBox::getString(){return string;}

//=============================================================================
// METODO    : char* getStrAux()
// ACCION    : Devuelve la cadena auxiliar.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> la cadena.
//-----------------------------------------------------------------------------
char* clsTextBox::getStrAux(){return straux;}

//=============================================================================
// METODO    : char* getFontFile()
// ACCION    : Devuelve el path y el nombre del archivo ttf.
// PARAMETROS: NADA.
// DEVUELVE  : char* --> path y nombre de archivo.
//-----------------------------------------------------------------------------
char* clsTextBox::getFontFile(){return text.getFontFile();}

//=============================================================================
// METODO    : int getNumber()
// ACCION    : Devuelve una cadena interna de la textbox almacenada en forma de
//             numero entero.
// PARAMETROS: NADA
// DEVUELVE  : int --> el numero entero.
//-----------------------------------------------------------------------------
int clsTextBox::getNumber()
{
    int num=0;
    int fact=1;
    int i=strlen(string)-1;
    if(string[0]=='-')
    {
        while(i>0)
        {
           num+=(string[i]-48)*fact;
           fact*=10;
           i--;
        }
        num=num*(-1);
    }
    else
    {
        while(i>=0)
        {
           num+=(string[i]-48)*fact;
           fact*=10;
           i--;
        }
    }
    return num;
}

//=============================================================================
// METODO    : int getX()
// ACCION    : Devuelve la coordenada x de la textbox.
// PARAMETROS: NADA
// DEVUELVE  : int --> coordenada x actual.
//-----------------------------------------------------------------------------
int clsTextBox::getX() {return box.getXi();}

//=============================================================================
// METODO    : int getY()
// ACCION    : Devuelve la coordenada y de la textbox.
// PARAMETROS: NADA
// DEVUELVE  : int --> coordenada y actual.
//-----------------------------------------------------------------------------
int clsTextBox::getY() {return box.getYi();}

//=============================================================================
// METODO    : int getWidth()
// ACCION    : Devuelve el ancho de la textbox.
// PARAMETROS: NADA
// DEVUELVE  : int --> ancho actual.
//-----------------------------------------------------------------------------
int clsTextBox::getWidth() {return box.getXf()-box.getXi();}

//=============================================================================
// METODO    : int getHeight()
// ACCION    : Devuelve el alto de la textbox.
// PARAMETROS: NADA
// DEVUELVE  : int --> alto actual.
//-----------------------------------------------------------------------------
int clsTextBox::getHeight() {return box.getYf()-box.getYi();}

//=============================================================================
//                             METODOS PROTEGIDOS
//=============================================================================
// METODO    : void strInv(char* str)
// ACCION    : Invierte la cadena pasada como parametro.
// PARAMETROS: char* str --> cadena a invertir.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::strInv(char* str)
{
    char aux;
    int i=0;
    int j=strlen(str)-1;

    while(i<j)
    {
        aux=str[i];
        str[i]=str[j];
        str[j]=aux;
        i++;
        j--;
    }
}

//=============================================================================
// METODO    : void intToStr(int num, char* string)
// ACCION    : Convierte un entero a cadena.
// PARAMETROS: int num --> numero a convertir.
//             char* string --> cadena con el numero convertido.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsTextBox::intToStr(int num, char* str)
{
    int i=0;
    int division;
    int rest;
    int divisor=10;
    int restDivisor=1;
    bool neg=false;
    if(num<0)//PARCHE PARA NEGATIVOS
    {
        neg=true;
        num=num*(-1);
    }
    do
    {
        division=num/divisor;
        rest=num%divisor;
        str[i]=rest/restDivisor+48;
        i++;
        divisor*=10;
        restDivisor*=10;
    }while(division>0);

    if(neg==true)
    {
        str[i]='-';
        i++;
    }
    str[i]='\0';
}

#endif // CLSTEXTBOX_H
//### FIN DE ARCHIVO ##########################################################
