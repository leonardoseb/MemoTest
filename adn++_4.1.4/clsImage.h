//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.2 estable         //
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
// ARCHIVO             : clsImage.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.2 estable.
// FECHA DE CREACION   : 15/02/2011.
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
//             Este archivo contiene la definicion de la clase clsImage
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsImage contiene los elementos necesarios para la
//             administracion de imagenes de tipo "bmp" en el modo grafico.
//
//=============================================================================
//      ________________________________
//      |           clsImage           |
//      |------------------------------|
//      | # error: clsError            |
//      | # imagePointer: SDL_Surface* |
//      |------------------------------|
//      | + load(const char*): int     |
//      | + unload(): void             |
//      | + ~clsImage()                |
//      | + getPtr(): SDL_Surface*     |
//      |______________________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSIMAGE_H
#define _CLSIMAGE_H

//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsImage
{
  //---------------------------------------------------------------------------
  // ATRIBUTOS
  //---------------------------------------------------------------------------
  protected:
    clsError error;            // Administrador de errores.
    SDL_Surface* imagePointer; // Puntero a la imagen.

  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
    int load(const char*);// Carga un archivo de imagen en memoria RAM.
    void unload();         // Destructor explicito.
    ~clsImage();           // Destructor implicito.
    SDL_Surface* getPtr(); // Devuelve el puntero a la imagen.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : SDL_Surface getPtr()
// ACCION    : Devuelve un puntero a la imagen.
// PARAMETROS: NADA.
// DEVUELVE  : SDL_Surface* -> puntero a la imagen.
//-----------------------------------------------------------------------------
SDL_Surface* clsImage::getPtr(){return imagePointer;}

//=============================================================================
// METODO    : int load(const char* archivo)
// ACCION    : Carga un archivio de imagen en memoria RAM.
// PARAMETROS: char* archivo -> cadena con el path y nombre de archivo.
// DEVUELVE  : int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsImage::load(const char* archivo)
{
  imagePointer = IMG_Load(archivo);
  if(imagePointer == NULL)
  {
    error.set(600);
    return error.get();
  }

  SDL_SetColorKey(imagePointer,
                  SDL_SRCCOLORKEY|SDL_RLEACCEL,
                  SDL_MapRGB(imagePointer->format,PINK.r,PINK.g,PINK.b));

  SDL_SetAlpha(imagePointer,SDL_SRCALPHA|SDL_RLEACCEL,255);

  error.set(0);
  return error.get();
}

//=============================================================================
// METODO    : void unload()
// ACCION    : Destructor explicito.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsImage::unload()
{
  if(imagePointer) SDL_FreeSurface(imagePointer);
}

//=============================================================================
// METODO    : ~clsImage()
// ACCION    : Destructor implicito.
// PARAMETROS: NADA
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
clsImage::~clsImage()
{
  if(imagePointer) delete imagePointer;
  /*
  if(imagePointer != NULL) SDL_FreeSurface(imagePointer);
  */
}

#endif // _CLSIMAGE_H
//### FIN DE ARCHIVO ##########################################################
