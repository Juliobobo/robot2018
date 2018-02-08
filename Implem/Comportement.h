/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Comportement 
* to be used with : Comportement.c 
********/
#ifndef _Comportement_EC2C_H_FILE
#define _Comportement_EC2C_H_FILE
/* This program needs external declarations */
#include "Comportement_ext.h"
/*-------- Predefined types ---------*/
#ifndef _EC2C_PREDEF_TYPES
#define _EC2C_PREDEF_TYPES
typedef int _boolean;
typedef int _integer;
typedef char* _string;
typedef double _real;
typedef double _double;
typedef float _float;
#define _false 0
#define _true 1
#endif
/*--------- Pragmas ----------------*/
//MODULE: Comportement 3 2
//IN: _real Cg
//IN: _real Cd
//IN: _boolean Mode
//OUT: _real v_d
//OUT: _real v_g
#ifndef _Comportement_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Comportement_I_Cg(_real);
extern void Comportement_I_Cd(_real);
extern void Comportement_I_Mode(_boolean);
/*-------- Reset procedure -----------*/
extern void Comportement_reset();
/*--------Context init = context reset --------*/
#define Comportement_init Comportement_reset
/*-------- Step procedure -----------*/
extern void Comportement_step();
#endif
#endif
