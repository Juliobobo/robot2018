/********
* ec2c version 0.67
* context   method = STATIC
* ext call  method = PROCEDURES
* c header file generated for node : Fonctionnement 
* to be used with : Fonctionnement.c 
********/
#ifndef _Fonctionnement_EC2C_H_FILE
#define _Fonctionnement_EC2C_H_FILE
/* This program needs external declarations */
#include "Fonctionnement_ext.h"
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
//MODULE: Fonctionnement 2 1
//IN: _real distance
//IN: _real Cd_n
//OUT: _boolean Mode
#ifndef _Fonctionnement_EC2C_SRC_FILE
/*-------- Input procedures -------------*/
extern void Fonctionnement_I_distance(_real);
extern void Fonctionnement_I_Cd_n(_real);
/*-------- Reset procedure -----------*/
extern void Fonctionnement_reset();
/*--------Context init = context reset --------*/
#define Fonctionnement_init Fonctionnement_reset
/*-------- Step procedure -----------*/
extern void Fonctionnement_step();
#endif
#endif
