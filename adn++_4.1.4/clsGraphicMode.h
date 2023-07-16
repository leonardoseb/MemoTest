//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.0 estable         //
//              @@@@@  @    @@@@@  @    @       @    02/10/2012              //
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
// ARCHIVO             : clsGraphicMode.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.0 estable.
// FECHA DE CREACION   : 19/10/2011.
// ULTIMA ACTUALIZACION: 02/10/2012.
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
//             Este archivo incluye la definicion de la clase clsGraphicMode
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             clsGraphicMode contiene los elementos necesarios para la
//             administracion del modo de video grafico.
//
//=============================================================================
// _________________________________
// |       clsGraphicMode          |
// |-------------------------------|
// | # sdlError: int               |
// | # error: clsError             |
// | # screenWidth: int            |
// | # screenHeight: int           |
// | # screenDepth: int            |
// |-------------------------------|
// | + init(videoGraphicMode): int |
// | + init(int,int,int): int      |
// | + close(): void               |
// | + crashPrevent(): void        |
// | + getScreenWidth(): int       |
// | + getScreenHeight(): int      |
// | + getScreenDepth(): int       |
// |_______________________________|
//
//=============================================================================
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSVIDEOGRAFICO_H
#define CLSVIDEOGRAFICO_H

//#############################################################################
//				                DEFINICION DE LA CLASE
//=============================================================================

class clsGraphicMode
{
  protected:
    //=========================================================================
    // ATRIBUTOS
    //-------------------------------------------------------------------------
    int sdlError;      // Codigos de error devueltos por las SDL.
    clsError error;    // Administrador de errores.
    int screenWidth;   // Ancho de pantalla en pixeles.
    int screenHeight;  // Alto de pantalla en pixeles.
    int screenDepth;   // Profundidad de colores en bits.


  public:
    //=========================================================================
    // METODOS
    //-------------------------------------------------------------------------
    int init(graphicVideoMode); // Inicializa el subsistema de video en forma
                                // automatica.
    int init(int,int,int);      // Inicializa el subsistema de video en forma
                                // manual.
    void close();               // Cierra el subsistema de video.
    void crashPrevent();        // Cierra todo el sistema si se produce un
                                // cuelgue.
    int getScreenWidth();       // Devuelve el ancho de pantalla en pixeles.
    int getScreenHeight();      // Devuelve el alto de pantalla en pixeles.
    int getScreenDepth();       // Devuelve la profundidad e colores en bits.
};

//*****************************************************************************
//				           DEFINICION DE LOS METODOS
//=============================================================================
// <100> METODOS DEL SUBSISTEMA DE VIDEO
//=============================================================================
// METODO    : int init(graphicVideoMode gvm)
// ACCION    : Inicializa el subsistema de video en forma automatica.
// PARAMETROS: graphicVideoMode gvm --> resolucion de video.
//             MODOS POSIBLES: DEFAULT (800x600x16).
//                             DETECT  (autodetectado).
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsGraphicMode::init(graphicVideoMode gvm=DEFAULT)
{
  const SDL_VideoInfo* videoinfo;

  sdlError=SDL_InitSubSystem(SDL_INIT_VIDEO);
  if(sdlError<0)
  {
    error.set(100); // <100> ERRORES DE SUBSISTEMA DE VIDEO
    return error.get();
  }

  if(gvm==AUTODETECT)
  {
     videoinfo=SDL_GetVideoInfo();
     screenWidth=videoinfo->current_w;
     screenHeight=videoinfo->current_h;
     screenDepth=videoinfo->vfmt->BitsPerPixel;
  }
  else
  {
    screenWidth=800;
    screenHeight=600;
    screenDepth=16;
  }

  std::cout << "INICIALIZACION EXITOSA DEL MODO VIDEO GRAFICO." << std::endl;
  error.set(0);
  return error.get();
}


//=============================================================================
// METODO    : int init(int w, int h, int d)
// ACCION    : Inicializa el subsistema de video en forma manual.
// PARAMETROS: int w --> ancho de pantalla en pixeles.
//             int h --> alto de pantalla en pixeles.
//             int d --> profundidad de colores en bits.
// DEVUELVE  : int --> codigo de error. (0 = todo bien)
//-----------------------------------------------------------------------------
int clsGraphicMode::init(int w, int h, int d)
{
  sdlError=SDL_InitSubSystem(SDL_INIT_VIDEO);
  if(sdlError<0)
  {
    error.set(100); // <100> ERRORES DE SUBSISTEMA DE VIDEO
    return error.get();
  }

  screenWidth=w;
  screenHeight=h;
  screenDepth=d;

  std::cout << "INICIALIZACION EXITOSA DEL MODO VIDEO GRAFICO." << std::endl;
  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void close()
// ACCION    : Cierra el subsistema de video.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsGraphicMode::close()
{
  SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

//=============================================================================
// METODO    : void crashPrevent()
// ACCION    : Cierra todo el sistema si se produce un cuelgue.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsGraphicMode::crashPrevent()
{
  atexit(SDL_Quit);
}

//=============================================================================
// METODO    : int getScreenWidth()
// ACCION    : Devuelve el ancho de pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int --> ancho en pixeles.
//-----------------------------------------------------------------------------
int clsGraphicMode::getScreenWidth(){return screenWidth;}

//=============================================================================
// METODO    : int getScreenHeight()
// ACCION    : Devuelve el alto de pantalla en pixeles.
// PARAMETROS: NADA.
// DEVUELVE  : int --> alto en pixeles.
//-----------------------------------------------------------------------------
int clsGraphicMode::getScreenHeight(){return screenHeight;}

//=============================================================================
// METODO    : int getScreenDepth()
// ACCION    : Devuelve la profundidade de colores en bits
// PARAMETROS: NADA.
// DEVUELVE  : int --> profundidad en bits.
//-----------------------------------------------------------------------------
int clsGraphicMode::getScreenDepth(){return screenDepth;}


//### FIN DE ARCHIVO ##########################################################
#endif // CLSVIDEOGRAFICO_H
