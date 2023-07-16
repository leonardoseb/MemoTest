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
// ARCHIVO             : clsTablero.h
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
#ifndef CLSTABLERO_H
#define CLSTABLERO_H
//=============================================================================
// INCLUSIONES NECESARIAS
//-----------------------------------------------------------------------------
#include "clsFondo.h"
#include "clsFicha.h"
//*****************************************************************************
//				                DEFINICION DE LA CLASE
//=============================================================================

class clsTablero: virtual public clsMovilSprite
{
    //---------------------------------------------------------------------------
    // ATRIBUTOS
    //---------------------------------------------------------------------------
protected:
    void inherit() {};
    int x;
    int y;
    int fil;
    int col;
    clsFicha mat[4][4];
    clsTimer timer;
    clsRandom random;
    int dadasVuelta;


    //---------------------------------------------------------------------------
    // METODOS
    //---------------------------------------------------------------------------
public:
    int cargarTablero(SDL_Surface* , int ,int );
    bool estaEncima(int,int,SDL_Surface*);
    void mostrarTablero(SDL_Surface*);
    bool validarFicha(int);
    void mouseCommand(unsigned short , clsScreen *,clsEvent *);
    void sonIguales();

};
//=============================================================================
// METODO    : void mouseCommand(unsigned short btn, bool* endrun)
// ACCION    : Administra los comandos por mouse.
// PARAMETROS: unsigned short btn --> boton del mouse presionado.
//             bool* endrun  --> variable control del ciclo.
// DEVUELVE  : Nada.
//-----------------------------------------------------------------------------
void clsTablero::mouseCommand(unsigned short btn, clsScreen *monitor,clsEvent *event)
{
    switch(btn)
    {
    case MOUSE_LEFT_BUTTON:
        estaEncima(event->getCursorX(),
                   event->getCursorY(),monitor->getPtr()
                  );
        if(dadasVuelta==2)
        {
            if(sonIguales())
            {
            pausa
            quitarFichas();
            refresco monitor.refresh()
            }
             else
            {
            Pausa
            ponerFichasDeDorso()
            refresco
            }
        }

        break;
    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
int clsTablero::cargarTablero(SDL_Surface* screen, int x,int y)
{
    bool sigue=true;
    char path[]="imagenes/Frente01.png";
    this->x=x;
    this->y=y;
    int f,c,num,a;
    dadasVuelta=0;
    random.init();

    for(f=0; f<4; f++)
    {
        for(c=0; c<4; c++)
        {
            while(sigue)
            {
                num=random.getNumber(8);
                sigue=validarFicha(num);
            }
            path[16]=num+48;
            mat[f][c].init(path);
            mat[f][c].setId(num);
            mat[f][c].setX(x+(c*120));
            mat[f][c].setY(y+(f*120));
            sigue=true;

        }
    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
void clsTablero::mostrarTablero(SDL_Surface* screen)
{

    int f,c;
    for(f=0; f<4; f++)
    {
        for(c=0; c<4; c++)
        {
            mat[f][c].paste(mat[f][c].getX(),mat[f][c].getY(),screen);

        }
    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
bool clsTablero::estaEncima(int X, int Y,SDL_Surface* screen)
{
    for(int f=0; f<4; f++)
    {
        for(int c=0; c<4; c++)
        {
            if(X>=mat[f][c].getX() && X <=mat[f][c].getX()+mat[f][c].getWidth()
                    &&
                    Y>=mat[f][c].getY() && Y <=mat[f][c].getY()+mat[f][c].getHeight())
            {
                if(!mat[f][c].estaDeFrente())
                {
                    //sumo el contador

                    mat[f][c].voltearFicha();

                }

            }

        }

    }
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------
bool clsTablero::validarFicha(int numero)
{
    int i=0;

    for(int f=0; f<4; f++)
    {
        for (int c=0; c<4; c++)
        {
            if(mat[f][c].getId()==numero)
            {
                i++;
                if(i==2)
                {
                    return true;
                }
            }
        }

    }

    return false;
}

//=============================================================================
// METODO    :
// ACCION    :
// PARAMETROS:
// DEVUELVE  :
//-----------------------------------------------------------------------------

//void clsTablero::sonIguales()
//{
//    for(int f=0; f<4; f++)
//    {
//        for(int c=0; c<4; c++)
//        {
//            if(mat[f][c].estaDeFrente())
//            {
//                for(int fila=f; fila<4; fila++)
//                {
//                    for(int col=c; col<4; col++)
//                    {
//                        if(mat[fila][col].estaDeFrente())
//                        {
//                            if(mat[f][c].getId()==mat[fila][col].getId())
//                            {
//                                mat[f][c].taparFicha();
//                                mat[fila][col].taparFicha();
//                            }
//                            else
//                            {
//                                mat[fila][col].setI(0);
//                                mat[f][c].setI(0);
//
//                            }
//
//                        }
//                    }
//                }
//            }
//
//        }
//    }
//
//    dadasVuelta=0;
//}


void clsTablero::sonIguales()
{
    int i=0;
    int aux,aux2;
    int f1,c1,f2,c2;

    for(int f=0; f<4; f++)
    {
        for(int c=0; c<4; c++)
        {
            if(mat[f][c].estaDeFrente())
            {
                if(i==0)
                {
                    aux=mat[f][c].getId();
                    f1=f;
                    c1=c;
                    i++;
                }
                else
                {
                    aux2=mat[f][c].getId();
                    f2=f;
                    c2=c;
                }

            }
        }
    }

   if(aux==aux2)
   {
       mat[f1][c1].taparFicha();
       mat[f2][c2].taparFicha();
   }
   else
   {
       mat[f1][c1].setI(0);
       mat[f2][c2].setI(0);
   }



}

#endif // CLSTABLERO_H
