/********
* ec2c version 0.67
* c file generated for node : Comportement 
* context   method = STATIC
* ext call  method = PROCEDURES
********/
/* This program needs external declarations */
#define _Comportement_EC2C_SRC_FILE
#include "Comportement.h"
/*--------
 * the following ``constants'' must be defined:
extern _real kp_teta;
extern _real ki_teta;
extern _real pi;
--------*/
/*--------
Internal structure for the call
--------*/
typedef struct  {
   
   //INPUTS
   _real _Cg;
   _real _Cd;
   _boolean _Mode;
   //OUTPUTS
   _real _v_d;
   _real _v_g;
   //REGISTERS
   _real M22;
   _boolean M22_nil;
   _boolean M19;
} Comportement_ctx;

// Single Static Context
static Comportement_ctx ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void Comportement_I_Cg(_real V){
   ctx._Cg = V;
}
void Comportement_I_Cd(_real V){
   ctx._Cd = V;
}
void Comportement_I_Mode(_boolean V){
   ctx._Mode = V;
}
extern void Comportement_O_v_d(_real);
extern void Comportement_O_v_g(_real);
#ifdef CKCHECK
extern void Comportement_BOT_v_d();
extern void Comportement_BOT_v_g();
#endif
/*--------
Internal reset input procedure
--------*/
static void Comportement_reset_input(){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void Comportement_reset(){
   ctx.M22_nil = _true;
   ctx.M19 = _true;
   Comportement_reset_input();
}
/*--------
Step procedure
--------*/
void Comportement_step(){
//LOCAL VARIABLES
   _real L14;
   _real L17;
   _real L13;
   _real L11;
   _real L18;
   _real L10;
   _real L8;
   _real L23;
   _real L7;
   _real L31;
   _boolean L30;
   _real L32;
   _real L29;
   _real L28;
   _real L35;
   _real L33;
   _real L27;
   _real L25;
   _real L6;
   _real L4;
   _real L3;
   _real L41;
   _real L40;
   _real L39;
   _real L43;
   _real L42;
   _real L38;
   _real T22;
//CODE
   L14 = (pi / 200.000000);
   L17 = (ctx._Cd - ctx._Cg);
   L13 = (L14 * L17);
   L11 = (0.002000 * L13);
   if (ctx.M19) {
      L18 = 0.000000;
   } else {
      L18 = ctx.M22;
   }
   L10 = (L11 + L18);
   L8 = (ki_teta * L10);
   L23 = (kp_teta * L13);
   L7 = (L8 + L23);
   L31 = (2.000000 * L7);
   L30 = (L31 < 0.000000);
   L32 = (- L31);
   if (L30) {
      L29 = L32;
   } else {
      L29 = L31;
   }
   L28 = (- L29);
   L35 = (ctx._Cd + ctx._Cg);
   L33 = (0.005000 * L35);
   L27 = (L28 + L33);
   L25 = (2.000000 * L27);
   L6 = (L7 + L25);
   L4 = (0.500000 * L6);
   if (ctx._Mode) {
      L3 = L4;
   } else {
      L3 = 0.400000;
   }
   Comportement_O_v_d(L3);
   L41 = (- L7);
   L40 = (L41 + L25);
   L39 = (0.500000 * L40);
   L43 = (- 1.000000);
   L42 = (L43 * 0.400000);
   if (ctx._Mode) {
      L38 = L39;
   } else {
      L38 = L42;
   }
   Comportement_O_v_g(L38);
   T22 = L10;
   ctx.M22 = T22;
   ctx.M22_nil = _false;
   ctx.M19 = ctx.M19 && !(_true);
}
