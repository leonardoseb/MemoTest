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
////#############################################################################
// ARCHIVO             : clsLog.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.0 estable.
// FECHA DE CREACION   : 08/11/2011.
// ULTIMA ACTUALIZACION: 29/09/2012.
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
//             Este archivo contiene la definicion de la clase clsLog
//             perteneciente al sistema adn++ (Sistema de Clases para Modo
//             Grafico para C++).
//
//             La clase clsLog, contiene los elementos basicos necesarios para
//             la administracion de archivos de texto referentes a la salida de
//             errores y logs.
//
//             clsLog fue desarrollada especificamente para generar el archivo
//             de texto "stdout.txt", en la plataforma Linux.
//
//-----------------------------------------------------------------------------
//   __________________
//   |     clsLog     |
//   |----------------|
//   |----------------|
//   | + open: void   |
//   | + close: void  |
//   |________________|
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef CLSLOG_H
#define CLSLOG_H

//#############################################################################
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsLog
{
  //===========================================================================
  // METODOS
  //---------------------------------------------------------------------------
  public:
    void open();   // Habilita el sistema de logs.
    void close();  // Cierra el sistema de logs.
};

//*****************************************************************************
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : void open()
// ACCION    : Activa el sistema de logs.
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsLog::open()
{

  freopen("stdout.txt","w",stdout);
}

//=============================================================================
// METODO    : void close()
// ACCION    : Cierra el sistema de logs.
// PARAMETROS: NADA.
// DEVUELVE  : NADA
//-----------------------------------------------------------------------------
void clsLog::close()
{
  freopen("CON","w",stdout);
  freopen("CON","w",stderr);
}

#endif // CLSLOG_H
//### FIN DE ARCHIVO ##########################################################
