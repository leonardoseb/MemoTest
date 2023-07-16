//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.4 estable         //
//              @@@@@  @    @@@@@  @    @       @     29/05/2013             //
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
// ARCHIVO             : clsScreen.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.2 estable.
// FECHA DE CREACION   : 15/02/2011.
// ULTIMA ACTUALIZACION: 29/05/2013.
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
//             Este archivo contiene la definicion de la clase clsScreen
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsScreen, derivada de la clase abstracta clsBasicScreen,
//             contiene los elementos necesarios para la administracion de la
//             memoria de video, es decir, la pantalla del monitor en modo
//             grafico.
//
//-----------------------------------------------------------------------------
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
//   __________|_____________________
//   |          clsScreen           |
//   |------------------------------|
//   | # title: bool                |
//   |------------------------------|
//   | # void inherit(){}           |
//   | + init(unsigned int,         |
//   |        unsigned int,         |
//   |        unsigned int,         |
//   |        titlebar,             |
//   |        uint32_t flags): int  |
//   | + setTitle(const char*): void|
//   | + refresh(): void            |
//   | + ~clsScreen()               |
//   | + getTitle(): titlebar       |
//   |______________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSSCREEN_H
#define _CLSSCREEN_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsScreen: virtual public clsBasicScreen
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    titlebar title;      // Habilitacion de la barra de titulo.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  protected:
     void inherit(){};         // Convierte a la clase en instanciable.

  public:
     int init( int,    // Inicializa la pantalla fisica (monitor).
               int,
               int,
               titlebar,
               uint32_t flags);

      void setTitle(const char*); // Pone titulo a la ventana.

      void refresh();       // Refresca la pantalla del monitor para que se
                            // vean los cambios.

      ~clsScreen();         // Destructor.

      titlebar getTitle(); // Informa si la barra de titulo esta habilitada.
};

//=============================================================================
//			             DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init(unsigned int anch,unsigned int alt,
//                      unsigned int bpp,bool barra,Uint32_t flags)
// ACCION    : Inicializa la pantalla fisica (monitor).
// PARAMETROS: unsigned int w -> Ancho de la pantalla en pixeles.
//             unsigned int h -> Alto de la pantalla en pixeles.
//             unsigned int d -> Profundidad de color en bits.
//                               VALORES POSIBLES: 8, 16, 32 y 64.
//             titlebar bar   -> indicador de habilitacion de la barra de
//                               titulo.
//                               VALORES POSIBLES: ENABLED
//                                                 DISABLED
//             Uint32_t flags    -> tipos de entorno para la pantalla.
//             ----------------------------------------------------------------
//             |                VALORES POSIBLES PARA FLAGS
//             |---------------------------------------------------------------
//             | ASINCRONIC     | Habilita  el volcado asincronico  para
//             |                | la pantalla. Esto ralentiza el volcado
//             |                | en  maquinas  con  una  sola  CPU pero
//             |                | aprovecha   las  caracteristicas  del
//             |                | doble corazon.
//             |----------------|----------------------------------------------
//             | EMULATED       | En caso de no poder inicializar el entorno
//             |                | con la profundidad de color estipulada, per-
//             |                | mite hacerlo en algun modo compatible.
//             |----------------|----------------------------------------------
//             | FULLSCREEN     | Hailita la pantalla completa. Esto no
//             |                | siempre es posible.
//             |----------------|----------------------------------------------
//             | RESIZABLE      | Genera un entorno de ventana redimensionable.
//-----------------------------------------------------------------------------
// DEVUELVE: int --> codigo de error (0 = todo bien.).
//-----------------------------------------------------------------------------
int clsScreen::init(int w, int h, int d,
                    titlebar bar, uint32_t flags)
{
  if(flags)
  {
    screenPointer = SDL_SetVideoMode(w,h,d,HARDWARE|DOUBLEBUFFER|flags);
  }
  else
  {
    screenPointer = SDL_SetVideoMode(w,h,d,HARDWARE|DOUBLEBUFFER);
  }
  if (screenPointer==NULL)
  {
    error.set(800);
    return error.get();
  }

  title = bar;
  width  = w;
  height  = h;
  color = BLACK;

  std::cout << "INICIALIZACION EXITOSA DE LA PANTALLA FISICA." << std::endl;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void setTitle(const char* t).
// ACCION    : Si la barra de titutlo esta habilitada, le pone el titulo
//             pasado como parametro.
//             cambios.
// PARAMETROS: const char* t -> titulo nuevo.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::setTitle(const char* t)
{
  if(title==ENABLED) SDL_WM_SetCaption(t, NULL);
}

//=============================================================================
// METODO    : void refresh().
// ACCION    : Refresca la pantalla del monitor para que se vean los
//             cambios.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsScreen::refresh(){SDL_Flip(screenPointer);}

//=============================================================================
// METODO    : titlebar getTitle().
// ACCION    : Devuelve el estado de la barra de titutlo.
// PARAMETROS: NADA.
// DEVUELVE  : titlebar -> ENABLE = true / DESABLE = false
//-----------------------------------------------------------------------------
titlebar clsScreen::getTitle(){return title;}


//=============================================================================
// METODO    : ~clsScreen()
// ACCION    : Destructor.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsScreen::~clsScreen()
{
  if(screenPointer != NULL) SDL_FreeSurface(screenPointer);
  cout << "DESTRUYO EL OBJETO clsScreen." << endl;
}

#endif // _CLSSCREEN_H
//### FIN DE ARCHIVO ##########################################################
