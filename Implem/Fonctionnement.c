/********
* ec2c version 0.67
* c file generated for node : Fonctionnement 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Fonctionnement_EC2C_SRC_FILE
#include "Fonctionnement.h"
/*--------
 * the following ``constants'' must be defined:
extern _real minDistance;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _distance;
   _real _Cd_n;
   //OUTPUTS
   _boolean _Mode;
   //REGISTERS
   _boolean M25;
   _boolean M25_nil;
   _boolean M22;
   _boolean M22_nil;
   _boolean M13;
   _boolean M13_nil;
   _boolean M10;
} Fonctionnement_ctx;

// Single Static Context
static Fonctionnement_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Fonctionnement_I_distance(_real V){
   ctx._distance = V;
}
void Fonctionnement_I_Cd_n(_real V){
   ctx._Cd_n = V;
}
extern void Fonctionnement_O_Mode(_boolean);
#ifdef CKCHECK
extern void Fonctionnement_BOT_Mode();
#endif
/*--------
Internal reset input procedure
--------*/
static void Fonctionnement_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Fonctionnement_reset(){
   ctx.M25_nil = _true;
   ctx.M22_nil = _true;
   ctx.M13_nil = _true;
   ctx.M10 = _true;
   Fonctionnement_reset_input();
}
/*--------
Step procedure
--------*/
void Fonctionnement_step(){
//LOCAL VARIABLES
   _boolean L4;
   _boolean L9;
   _boolean L8;
   _boolean L19;
   _boolean L18;
   _boolean L21;
   _boolean L17;
   _boolean L16;
   _boolean L23;
   _boolean L15;
   _boolean L24;
   _boolean L14;
   _boolean L7;
   _boolean L6;
   _boolean L3;
   _boolean L2;
   _boolean T25;
   _boolean T22;
   _boolean T13;
//CODE
   L4 = (ctx._distance < minDistance);
   if (ctx.M10) {
      L9 = _false;
   } else {
      L9 = ctx.M13;
   }
   L8 = (! L9);
   L19 = (ctx._Cd_n > 50.000000);
   L18 = (L4 && L19);
   if (ctx.M10) {
      L21 = _false;
   } else {
      L21 = ctx.M22;
   }
   L17 = (L18 || L21);
   L16 = (L8 && L17);
   L23 = (ctx._Cd_n < 50.000000);
   L15 = (L16 && L23);
   if (ctx.M10) {
      L24 = _false;
   } else {
      L24 = ctx.M25;
   }
   L14 = (L15 || L24);
   L7 = (L8 && L14);
   L6 = (L7 && L19);
   L3 = (L4 || L6);
   L2 = (! L3);
   Fonctionnement_O_Mode(L2);
   T25 = L7;
   T22 = L16;
   T13 = L6;
   ctx.M25 = T25;
   ctx.M25_nil = _false;
   ctx.M22 = T22;
   ctx.M22_nil = _false;
   ctx.M13 = T13;
   ctx.M13_nil = _false;
   ctx.M10 = ctx.M10 && !(_true);
}
