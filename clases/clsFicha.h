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
// ARCHIVO             : clsFicha.h
// AUTOR               : Arzua Juan Cruz.
// VERSION             : 0.0.1
// FECHA DE CREACION   : 11/06/2014.
// ULTIMA ACTUALIZACION:
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE                 : Code::Blocks - 8.02 / 10.05
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSFICHA_H
#define CLSFICHA_H
//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================
class clsFicha: virtual public clsMovilSprite
{
    //---------------------------------------------------------------------------
    // ATRIBUTOS
    //---------------------------------------------------------------------------
protected:
    void inherit() {};
    int id;

    //---------------------------------------------------------------------------
    // METODOS
    //---------------------------------------------------------------------------
public:
    int init(char *);
    void voltearFicha();
    void taparFicha();
    bool estaDeFrente();
    bool estaTapada();
    int getId()
    {
        return id;
    }
    void setId(int);


};

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
int clsFicha::init(char *path)
{
    //char path[]="imagenes/Frente00.png"; // Cadena plantilla para armar el path de
    // cada archivo que se cargara en el vector
    // de imagenes del sprite.
    setItems(3); // Establece la cantidad de elementos del vector de imagenes
    setI(0);
    error.set(load("imagenes/Dorso.png"));
    if(error.get())
    {
        return error.get(); // Si se produce un error en la carga, retorna el
        // codigo de error.
    }
    setI(1);
    error.set(load(path));
    if(error.get())
    {
        return error.get(); // Si se produce un error en la carga, retorna el
        // codigo de error.
    }
    setI(2);
    error.set(load("imagenes/Transparente.png"));
    if(error.get())
    {
        return error.get(); // Si se produce un error en la carga, retorna el
        // codigo de error.
    }
    setI(0);
    // Mensaje para el archivo "stdout.txt".
    cout << "INICIALIZACION EXITOSA DEL SPRITE clsFicha" << endl;

    return error.get();  // Retorna el codigo de error 0.
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
bool clsFicha::estaDeFrente()
{
    if(getI()==1)
    {
        return true;
    }
    else
        return false;
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
bool clsFicha::estaTapada()
{
    if(getI()==2)
    {
        return true;
    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
void clsFicha::voltearFicha()
{
    if(getI()==0)
    {
        setI(1);

    }
    else
    {
        if(getI()==1)
        {
            setI(0);
        }
    }

}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
void clsFicha::taparFicha()
{
    if(getI()==1)
    {
        setI(2);
    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
void clsFicha::setId(int item)
{
    id=item;
}

#endif // CLSFICHA_H
