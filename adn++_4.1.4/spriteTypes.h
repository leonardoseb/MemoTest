//#############################################################################
//                             AVIS SOFTWARE                                 //
//                     (Productos de Software Libre)                         //
//                                                                           //
//               @@@@@@@           @    @  @@@@@      @    @                 //
//              @      @           @    @@@    @@    @@@  @@@                //
//               @@@@@@@    @@@@@@@@    @       @     @    @                 //
//             @@      @   @@      @    @       @                            //
//             @     @@@   @     @@@    @       @    v 4.1.3 estable         //
//              @@@@@  @    @@@@@  @    @       @    07/10/2012              //
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
// ARCHIVO             : spriteTypes.h
// AUTOR               : Ruben Alberto Calabuig.
// VERSION             : 4.1.3 estable.
// FECHA DE CREACION   : 29/09/2011.
// ULTIMA ACTUALIZACION: 07/10/2012.
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
//             Este archivo reemplaza a la libreria adnHeaders.h, en la defini-
//             cion de los tipos para sprites.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef SPRITETYPES_H
#define SPRITETYPES_H

//*****************************************************************************
//              TIPOS DEFINIDOS PARA MOVILES
//-----------------------------------------------------------------------------
// ENUMERACION DE TIPOS DE RUMBOS POSIBLES
//-----------------------------------------------------------------------------
enum tCourse {NORTH=0, EAST=1, SOUTH=2,WEST=3};

//-----------------------------------------------------------------------------
// ENUMERACION DE TIPOS DE ESTADOS POSIBLES
//-----------------------------------------------------------------------------
enum tSpriteState {INACTIVE,ACTIVE};

//-----------------------------------------------------------------------------
// ESTRUCTURA DE TIPO tCoord PARA DETECTAR CONTACTOS
//-----------------------------------------------------------------------------
    struct tCoord
    {
      int x1,  // coord x inicial del sprite local.
          y1,  // coord y inicial del sprite local.
          x2,  // coord x final del sprite local.
          y2,  // coord y final del sprite local.
          x3,  // coord x inicial del sprite externo.
          y3,  // coord y inicial del sprite externo.
          x4,  // coord x final del sprite externo.
          y4,  // coord y final del sprite externo.
          w1,  // ancho del sprite local.
          w2,  // ancho del sprite externo.
          h1,  // alto del sprite local.
          h2,  // alto del sprite externo.
          xi1, // coord x inicial del area superpuesta en el sprite local.
          yi1, // coord y inicial del area superpuesta en el sprite local.
          xi2, // coord x inicial del area superpuesta en el sprite externo.
          yi2, // coord y inicial del area superpuesta en el sprite externo.
          aw,  // ancho del area superpuesta.
          ah,  // alto  del area superpuesta.
          ovl; // caso de superposicion (overlap).
        //------------------------------------------------
    };

#endif // SPRITETYPES_H
//### FIN DE ARCHIVO ##########################################################
