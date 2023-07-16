//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.1 estable         //
//              @@@@@  @    @@@@@  @    @       @    15/07/2012              //
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
// ARCHIVO             : clsMotorPrograma.h
// AUTOR               : Arzua Juan Cruz.
// VERSION             : 0.0.1
// FECHA DE CREACION   : 08/06/2014.
// ULTIMA ACTUALIZACION: 08/06/2014.
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//             Este archivo contiene la definicion de la clase clsMotorPrograma
//             que es una agregacion que concentra,relaciona y organiza a todos
//             los componentes del proyecto.
//
//             En otras palabras, es el motor del proyecto.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef MOTORPROGRAMA_H
#define MOTORPROGRAMA_H

//=============================================================================
// INCLUSIONES NECESARIAS
//-----------------------------------------------------------------------------
#include "clsFondo.h"
#include "clsTablero.h"
//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsMotorPrograma
{
    //---------------------------------------------------------------------------
    // ATRIBUTOS
    //---------------------------------------------------------------------------
protected:
    clsError error;       // Objeto para administrar los errores.
    clsGraphicMode video; // Objeto para administrar el modo video grafico.
    clsScreen monitor;    // Objeto para administrar la pantalla fisica.
    clsEvent event;       // Objeto para administrar los eventos de teclado.
    clsTimer timer;       // Administrador de tiempos y pausas.
    clsFondo fondo;
    clsTablero tablero;

    //---------------------------------------------------------------------------
    // METODOS
    //---------------------------------------------------------------------------
public:
    int init();          // Inicializa el motor.
    void run();          // Pone en marcha el motor.
    void mouseCommand(unsigned short);    // Administrador de comandos de mouse
    int keyCommand(unsigned int,bool*);         //Administrador de comandos por teclado

    int  getError();     // Devuelve el codigo de error producido durante
    // la inicializacion del motor.

    void setError(int); // Establece el codigo de error producido.
    void showError();    // Muestra por la salida estandar el error produ-
    // cido.

};
//=============================================================================
//				                DEFINICION DE LOS METODOS
//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa el motor.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error (0 = todo bien).
//-----------------------------------------------------------------------------
int clsMotorPrograma::init()
{
    error.set(video.init(1024,768,32)); // Intenta incializar el modo video auto-
    // detectando la resolucion de video.
    if(error.get())          // Si se produjo algun error.
    {
        error.show();        // Muestra el error por la salida estandar.
        cout << endl;
        return error.get(); // Devuelve le codigo de error.
    }

    video.crashPrevent(); // Si se priduce un cuelgue, cierra automaticamente
    // las SDL, devolviendo toda la memoria dinamica
    // reservada

    error.set(monitor.init(video.getScreenWidth(), // Intenta iniciar la panta-
                           video.getScreenHeight(),// lla fisica.
                           video.getScreenDepth(),
                           ENABLED,
                           RESIZABLE
                          )
             );

    //INICIALIZAR FONDO DE PANTALLA
    error.set(fondo.init());
    if(error.get())
    {
        return error.get();  // Si se produce un error, retorna el
        // codigo de error.
    }

    fondo.setX(0);                   // Establece la coordenada X del fondo.
    fondo.setY(0);                   // Establece la coordenada Y del fondo.
    fondo.setName("FONDO PANTALLA"); // Nombre interno del sprite.



    if(error.get()) // Si se produjoo algun error.
    {
        error.show(); // Muestra el error por la salida estandar.
        cout << endl;
        return error.get(); // Devuelve el codigo de error.
    }

    return error.get(); // Si llego hasta aqui es porque no hubo errores.
}

//=============================================================================
// METODO    : void run()
// ACCION    : Pone en marcha al motor.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMotorPrograma::run()
{

    int dadasVuelta=0;
    bool endrun=false;  // Variable que controla el ciclo de ejecucion.
    Uint16 key;  // Variable para almacenar el codigo de la tecla presionada.
    monitor.clean();
        fondo.paste(fondo.getX(), // Pega el fondo en la pantalla.
                    fondo.getY(),
                    monitor.getPtr()
                   );
    tablero.cargarTablero(monitor.getPtr(),100,100);


    while(!endrun)  // Ciclo de ejecucion
    {
        monitor.clean();
        fondo.paste(fondo.getX(), // Pega el fondo en la pantalla.
                    fondo.getY(),
                    monitor.getPtr()
                   );
        tablero.mostrarTablero(monitor.getPtr());
        monitor.refresh();
        if(dadasVuelta==2)
        {
            timer.wait(500);
            tablero.sonIguales();
            dadasVuelta=0;
        }

        if(event.wasEvent())   // Verifica si se produjo un evento
        {
            switch(event.getEventType()) // Si se presiono una tecla
            {

            case KEY_PRESSED:
                error.set(keyCommand(event.getKey(), // Determina la
                                     &endrun)        // la accion
                         );                         // segun la tecla
                break;

            case MOUSE_DOWN:
                tablero.mouseCommand(event.getMouseButton(),&monitor,&event);
                dadasVuelta++;
                break;
            }
        }
    }

}

//=============================================================================
// METODO    : int getError()
// ACCION    : Devuelve el  codigo de error producido al inicializarse el
//             motor.
// PARAMETROS: NADA.
// DEVUELVE  : int --> codigo de error producido ( 0 = todo bien).
//-----------------------------------------------------------------------------
int clsMotorPrograma::getError()
{
    return error.get();
}

//=============================================================================
// METODO    : void setError(int errorID)
// ACCION    : Establece el codigo de error producido.
// PARAMETROS: int errorID --> codigo de error producido.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMotorPrograma::setError(int errorID)
{
    error.set(errorID);
}

//=============================================================================
// METODO    : void showError()
// ACCION    : Muestra el error producido por la salida estandar.
// PARAMETROS: NADA.
// DEVUELVE  : NADA.
//-----------------------------------------------------------------------------
void clsMotorPrograma::showError()
{
    error.show();
}


int clsMotorPrograma::keyCommand(unsigned int key,bool* endrun)
{
    error.set(0);  // Inicializa el codigo de error.

    switch(key)
    {
    case KEY_ESCAPE:
        *endrun=true;  // Tecla ESCAPE - termina el ciclo.
        break;                       // decrementa la velocidad
    }


    return error.get(); // Retorna el codigo de error 0.
}
//### FIN DE ARCHIVO ##########################################################



#endif // CLSMOTORPROGRAMA_H
