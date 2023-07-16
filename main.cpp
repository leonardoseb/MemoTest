//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                      @                                    //
//               @@@@@@@   @       @           @@@@@                         //
//              @      @   @       @   @@     @     @                        //
//                     @   @       @    @     @                              //
//               @@@@@@@    @     @     @      @@@@@                         //
//             @@      @     @   @      @           @      v 1.0.0 estable   //
//             @     @@@      @ @       @     @     @      25/10/2012        //
//              @@@@@  @       @      @@@@@    @@@@@                         //
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
// ARCHIVO             : main.h
// AUTOR               : Arzua Juan Cruz
// VERSION             :
// FECHA DE CREACION   :   /  /
// ULTIMA ACTUALIZACION:   /  /
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION:
//
///////////////////////////////////////////////////////////////////////////////

//=============================================================================
//                        COMPILACION MULTIPLATAFORMA
//=============================================================================
// COMPILACION EN WINDOWS
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Windows, descomente las tres lineas
// siguientes y comente las que se encuentran por debajo de "COMPILACION
// LINUX"
//-----------------------------------------------------------------------------

#ifndef _WIN32
  # define _WIN32
#endif

//=============================================================================
// COMPILACION EN LINUX
//-----------------------------------------------------------------------------
// Si este programa se va a compilar en Linux, descomente las tres lineas
// siguientes y comente las que se encuentran por debajo de "COMPILACION
// WINDOWS".
//-----------------------------------------------------------------------------
//#ifndef _LINUX
//  # define _LINUX
//#endif


//=============================================================================
// INCLUSION DEL SISTEMA adn++
//-----------------------------------------------------------------------------
#include "adn++_4.1.4/adn++.h"          // Libreria con del sistema adn++.

//=============================================================================
// INCLUSION DE LIBRERIAS DEL PROGRAMADOR
//-----------------------------------------------------------------------------
#include "clases/clsMotorPrograma.h"

//#############################################################################
//                           PROGRAMA PRINCIPAL
//=============================================================================
int main ( int argc, char** argv )
{
  //---------------------------------------------------------------------------
  // OBJETOS NECESARIOS PARA LINUX
  //---------------------------------------------------------------------------
  #ifdef _LINUX
    clsLog logFile; // Administrador de informes logs para Linux. (recomendado).
    logFile.open(); // Habilita la salida "stdout.txt"
  #endif

  //---------------------------------------------------------------------------
  // IDENTIFICACION DE LA VERSION adn++ EN EL ARCHIVO "stdout.txt".
  //---------------------------------------------------------------------------
  std::cout << "##########################################################" << std::endl;
  std::cout << "               " << ADNPP_VERSION                           << std::endl;
  std::cout << "**********************************************************" << std::endl;
  std::cout <<  std::endl;

  //---------------------------------------------------------------------------
  // OBJETOS NECESARIOS PARA EL PROGRAMA
  //---------------------------------------------------------------------------
  clsMotorPrograma motor;
  clsError error;          // Administrador de errores.            (requerido).
                           // Motor del proyecto                 (recomendado).

  //---------------------------------------------------------------------------
  // INICIALIZACION DEL MOTOR DEL PROYECTO.
  //---------------------------------------------------------------------------
     motor.setError(motor.init()); // Intenta inicializar el motor del proyecto.
                                  // En esta accion, intenta inicializar el
                                  // sistema de video grafico, el sistema de
                                  // pantalla fisica y el objeto avion. Si todo
                                  // sale bien, devuelve un 0 (cero), en caso
                                  // contrario, devuelve el codigo de error del
                                  // primer subsistema que no pudo inicializar.

    if(motor.getError())  // SI HUBO ERROR
    {
       motor.showError();// muestra el codigo de error por la salida estandar.
       return motor.getError();// termina la ejecucion del programa devolviendo
                                // el codigo del error producido.
    }

  //---------------------------------------------------------------------------
  // CICLO DE EJECUCION DEL PROGRAMA.
  //---------------------------------------------------------------------------
  motor.run();

  //---------------------------------------------------------------------------
  // FIN DEL PROGRAMA.
  //---------------------------------------------------------------------------
  // Fin sin errores
  //-----------------
  std::cout << std::endl;
  std::cout << "**********************************************************" << std::endl;
  std::cout << "       EL PROYECTO adn++ HA FINALIZADO CORRECTAMENTE      " << std::endl;
  std::cout << "##########################################################" << std::endl;
  return error.get(); // Fin normal del programa principal.
}

//### FIN DE ARCHIVO ##########################################################
