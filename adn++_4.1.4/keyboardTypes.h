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
// ARCHIVO             : keyboardTypes.h
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
//             cion de los tipos de teclas.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef KEYBOARDTYPES_H
#define KEYBOARDTYPES_H

//*****************************************************************************
// CONSTANTES CON LOS CODIGOS DE TECLADO
//-----------------------------------------------------------------------------

  //...........................................................................
  // ESTADOS DE TECLA
  //...........................................................................
  const Uint8  KEY_FREE    = SDL_KEYUP;   // Tecla liberada
  const Uint8  KEY_PRESSED = SDL_KEYDOWN; // Tecla presionada.

  //...........................................................................
  // DIGITOS
  //...........................................................................
  const Uint16 KEY_0                    = 48;
  const Uint16 KEY_1                    = 49;
  const Uint16 KEY_2                    = 50;
  const Uint16 KEY_3                    = 51;
  const Uint16 KEY_4                    = 52;
  const Uint16 KEY_5                    = 53;
  const Uint16 KEY_6                    = 54;
  const Uint16 KEY_7                    = 55;
  const Uint16 KEY_8                    = 56;
  const Uint16 KEY_9                    = 57;

  //...........................................................................
  // SIGNOS
  //...........................................................................
  const Uint16 KEY_RIGHT_SLASH       = 47;
  const Uint16 KEY_LEFT_SLASH        = 92;
  const Uint16 KEY_EXCLAMATION_MARK  = 33;
  const Uint16 KEY_QUESTION_MARK     = 63;
  const Uint16 KEY_QUOTE             = 39;
  const Uint16 KEY_DOUBLE_QUOTE      = 34;
  const Uint16 KEY_COLON             = 58;
  const Uint16 KEY_PERIOD            = 46;
  const Uint16 KEY_COMMA             = 44;
  const Uint16 KEY_SEMICOLON         = 59;
  const Uint16 KEY_LEFT_PARENTHESES  = 40;
  const Uint16 KEY_RIGHT_PARENTHESES = 41;
  const Uint16 KEY_LEFT_BRACKET      = 91;
  const Uint16 KEY_RIGHT_BRACKET     = 93;
  const Uint16 KEY_LESS              = 60;
  const Uint16 KEY_GREATER           = 62;
  const Uint16 KEY_EQUALS            = 61;
  const Uint16 KEY_ASTERISK          = 42;
  const Uint16 KEY_PLUS              = 43;
  const Uint16 KEY_MINUS             = 45;
  const Uint16 KEY_UNDERSCORE        = 95;
  const Uint16 KEY_AT                = 64;
  const Uint16 KEY_SHARP             = 35;
  const Uint16 KEY_DOLLAR            = 36;
  const Uint16 KEY_AMPERSAND         = 38;
  const Uint16 KEY_BACKQUOTE         = 96;
  const Uint16 KEY_SPACE             = 32;

  //...........................................................................
  // LETRAS MAYUSCULAS
  //...........................................................................
  const Uint16 KEY_A                    = 65;
  const Uint16 KEY_B                    = 66;
  const Uint16 KEY_C                    = 67;
  const Uint16 KEY_D                    = 68;
  const Uint16 KEY_E                    = 69;
  const Uint16 KEY_F                    = 70;
  const Uint16 KEY_G                    = 71;
  const Uint16 KEY_H                    = 72;
  const Uint16 KEY_I                    = 73;
  const Uint16 KEY_J                    = 74;
  const Uint16 KEY_K                    = 75;
  const Uint16 KEY_L                    = 76;
  const Uint16 KEY_M                    = 77;
  const Uint16 KEY_N                    = 78;
  const Uint16 KEY_O                    = 79;
  const Uint16 KEY_P                    = 80;
  const Uint16 KEY_Q                    = 81;
  const Uint16 KEY_R                    = 82;
  const Uint16 KEY_S                    = 83;
  const Uint16 KEY_T                    = 84;
  const Uint16 KEY_U                    = 85;
  const Uint16 KEY_V                    = 86;
  const Uint16 KEY_W                    = 87;
  const Uint16 KEY_X                    = 88;
  const Uint16 KEY_Y                    = 89;
  const Uint16 KEY_Z                    = 90;

  //...........................................................................
  // LETRAS MINUSCULAS
  //...........................................................................
  const Uint16 KEY_a                    = 97;
  const Uint16 KEY_b                    = 98;
  const Uint16 KEY_c                    = 99;
  const Uint16 KEY_d                    = 100;
  const Uint16 KEY_e                    = 101;
  const Uint16 KEY_f                    = 102;
  const Uint16 KEY_g                    = 103;
  const Uint16 KEY_h                    = 104;
  const Uint16 KEY_i                    = 105;
  const Uint16 KEY_j                    = 106;
  const Uint16 KEY_k                    = 107;
  const Uint16 KEY_l                    = 108;
  const Uint16 KEY_m                    = 109;
  const Uint16 KEY_n                    = 110;
  const Uint16 KEY_o                    = 111;
  const Uint16 KEY_p                    = 112;
  const Uint16 KEY_q                    = 113;
  const Uint16 KEY_r                    = 114;
  const Uint16 KEY_s                    = 115;
  const Uint16 KEY_t                    = 116;
  const Uint16 KEY_u                    = 117;
  const Uint16 KEY_v                    = 118;
  const Uint16 KEY_w                    = 119;
  const Uint16 KEY_x                    = 120;
  const Uint16 KEY_y                    = 121;
  const Uint16 KEY_z                    = 122;

  //...........................................................................
  // CONTROLES
  //...........................................................................
  const Uint16 KEY_ENTER                = 13;
  const Uint16 KEY_ESCAPE               = 27;
  const Uint16 KEY_TAB                  = 9;
  const Uint16 KEY_BACKSPACE            = 8;
  const Uint16 KEY_DELETE               = 127;
  const Uint16 KEY_INSERT               = 277;
  const Uint16 KEY_PAUSE                = 19;
  const Uint16 KEY_NUMLOCK              = 300;
  const Uint16 KEY_CAPSLOCK             = 301;
  const Uint16 KEY_PRINT                = 316;
  const Uint16 KEY_RIGHT_SHIFT          = 303;
  const Uint16 KEY_LEFT_SHIFT           = 304;
  const Uint16 KEY_RIGHT_CTRL           = 305;
  const Uint16 KEY_LEFT_CTRL            = 306;
  const Uint16 KEY_RIGHT_ALT            = 307;
  const Uint16 KEY_LEFT_ALT             = 308;

  //...........................................................................
  // MOVIMIENTO DEL CURSOR
  //...........................................................................
  const Uint16 KEY_DOWN                 = 274;
  const Uint16 KEY_UP                   = 273;
  const Uint16 KEY_RIGHT                = 275;
  const Uint16 KEY_LEFT                 = 276;
  const Uint16 KEY_PAGEDOWN             = 281;
  const Uint16 KEY_PAGEUP               = 280;
  const Uint16 KEY_HOME                 = 278;
  const Uint16 KEY_END                  = 279;

  //...........................................................................
  // TECLAS FUNCION
  //...........................................................................
  const Uint16 KEY_F1                   = 282;
  const Uint16 KEY_F2                   = 283;
  const Uint16 KEY_F3                   = 284;
  const Uint16 KEY_F4                   = 285;
  const Uint16 KEY_F5                   = 286;
  const Uint16 KEY_F6                   = 287;
  const Uint16 KEY_F7                   = 288;
  const Uint16 KEY_F8                   = 289;
  const Uint16 KEY_F9                   = 290;
  const Uint16 KEY_F10                  = 291;
  const Uint16 KEY_F11                  = 292;
  const Uint16 KEY_F12                  = 293;

  //...........................................................................
  // NUMPAD
  //...........................................................................
  const Uint16 KEY_NUMPAD_0             = 256;
  const Uint16 KEY_NUMPAD_1             = 257;
  const Uint16 KEY_NUMPAD_2             = 258;
  const Uint16 KEY_NUMPAD_3             = 259;
  const Uint16 KEY_NUMPAD_4             = 260;
  const Uint16 KEY_NUMPAD_5             = 261;
  const Uint16 KEY_NUMPAD_6             = 262;
  const Uint16 KEY_NUMPAD_7             = 263;
  const Uint16 KEY_NUMPAD_8             = 264;
  const Uint16 KEY_NUMPAD_9             = 265;
  const Uint16 KEY_NUMPAD_EQUALS        = 272;
  const Uint16 KEY_NUMPAD_ENTER         = 271;
  const Uint16 KEY_NUMPAD_PLUS          = 270;
  const Uint16 KEY_NUMPAD_MINUS         = 269;
  const Uint16 KEY_NUMPAD_MULTIPLY      = 268;
  const Uint16 KEY_NUMPAD_DIVIDE        = 267;
  const Uint16 KEY_NUMPAD_PERIOD        = 266;


/*
  ------------- RESERVADA ----------------------------------------------------
  const Uint16 KEY_F13                  = 294;
  const Uint16 KEY_F14                  = 295;
  const Uint16 KEY_F15                  = 296;
  const Uint16 KEY_SCROLLOCK            = 302;

    SDLK_HELP		= 315,
	SDLK_RMETA		= 309,
	SDLK_LMETA		= 310,
	SDLK_LSUPER		= 311,		 Left Windows key
	SDLK_RSUPER		= 312,		 Right Windows key
	SDLK_MODE		= 313,		 Alt Gr key
	SDLK_COMPOSE	= 314,		 Multi-key compose key
	SDLK_SYSREQ		= 317,
	SDLK_BREAK		= 318,
	SDLK_MENU		= 319,
	SDLK_POWER		= 320,		Power Macintosh power key
	SDLK_EURO		= 321,		Some european keyboards
	SDLK_UNDO		= 322,		Atari keyboard has Undo

  -----------------------------------------------------------------------------
*/

//=============================================================================
// CONSTANTES DE TIPOS DE ESTADOS DE TECLAS ESPECIALES
// Estados de teclas especiales (CTRL, ALT, SHIFT, NUMLOCK, CAPSLOCK).
//-----------------------------------------------------------------------------
// TECLAS ESPECIALES PULSADAS
  const SDLMod KEY_MDF_NONE        = KMOD_NONE;  // Ninguna.
  const SDLMod KEY_MDF_NUMLOCK     = KMOD_NUM;   // Numlock.
  const SDLMod KEY_MDF_CAPSLOCK    = KMOD_CAPS;  // Capslock.
  const SDLMod KEY_MDF_LEFT_CTRL   = KMOD_LCTRL; // Control izquierdo.
  const SDLMod KEY_MDF_RIGHT_CTRL  = KMOD_RCTRL; // Control derecho.
  const SDLMod KEY_MDF_RIGHT_SHIFT = KMOD_RSHIFT;// Shift derecho.
  const SDLMod KEY_MDF_LEFT_SHIFT  = KMOD_LSHIFT;// Shift izquierdo.
  const SDLMod KEY_MDF_RIGHT_ALT   = KMOD_RALT;  // Alt derecho.
  const SDLMod KEY_MDF_LEFT_ALT    = KMOD_LALT;  // Alt iquierdo.

#endif // KEYBOARDTYPES_H
//### FIN DE ARCHIVO ##########################################################
