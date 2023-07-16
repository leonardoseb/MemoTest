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
// ARCHIVO             : clsRandom.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.3 estable.
// FECHA DE CREACION   : 15/02/2011.
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
//             Este archivo incluye la definicion de la clase clsRandom necesa-
//             ria para instanciar objetos que generen numeros aleatorios.
//
//=============================================================================
// NOTA:
//
//      La clase clsRandom al no ser abstracta, puede ser instanciada.
//
//
//-----------------------------------------------------------------------------
//        _________________________
//        |       clsRandom       |
//        |-----------------------|
//        |-----------------------|
//        | + init(): void        |
//        | + getNumber(int): int |
//        |_______________________|
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _CLSRANDOM_H
#define _CLSRANDOM_H
//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsRandom
{
  //---------------------------------------------------------------------------
  // METODOS
  //---------------------------------------------------------------------------
  public:
    void init();         // Inicializa la secuencia de numeros aleatorios.
    int  getNumber(int); // Genera y devuelve un numero al azar.
};

//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : void init().
// ACCION    : Inicializa la secuencia de numeros aleatorios.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsRandom::init()
{
  time_t t;
  srand((unsigned) time(&t));

  std::cout << "INCIALIZACION EXITOSA DEL GENERADOR DE NUMEROS ALEATORIOS"
            << std::endl;
}

//=============================================================================
// METODO    : int getNumber(int n).
// ACCION    : Genera y devuelve un numero aleatorio entero entre 0 y n-1.
// PARAMETROS: int n -> numero tope del rango aleatorio.
// DEVUELVE  : int n -> numero aleatorio generado.
//-----------------------------------------------------------------------------
int clsRandom::getNumber(int n)
{
  return rand() % n;
}

#endif // _CLSRANDOM_H
//### FIN DE ARCHIVO ##########################################################
