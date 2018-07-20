#ifndef HASH_H
#define HASH_H

/** **********************************************************************
 * \file hash.h
** Hash_Table:  Hash_Table
** Description:
**
**
** Largely based on code written by ejp@ausmelb.oz
**
** Constants:
**  HASH_TABLE_NULL - the null Hash_Table
**
************************************************************************/

/*
 * This work was supported by the United States Government, and is
 * not subject to copyright.
 *
 * $Log: hash.h,v $
 * Revision 1.6  1997/10/22 16:36:49  sauderd
 * Changed the use and definitions of the compiler macros MUL and DIV. They
 * seem to be defined and used only within hash.h and hash.c
 *
 * Revision 1.5  1997/01/21 19:17:11  dar
 * made C++ compatible
 *
 * Revision 1.4  1993/10/15  18:49:23  libes
 * CADDETC certified
 *
 * Revision 1.3  1992/08/18  17:15:40  libes
 * rm'd extraneous error messages
 *
 * Revision 1.2  1992/05/31  08:36:48  libes
 * multiple files
 *
 * Revision 1.1  1992/05/28  03:56:02  libes
 * Initial revision
 *
 * Revision 1.4  1992/05/14  10:14:33  libes
 * don't remember
 *
 * Revision 1.3  1992/02/12  07:06:15  libes
 * do sub/supertype
 *
 * Revision 1.2  1992/02/09  00:47:45  libes
 * does ref/use correctly
 *
 * Revision 1.1  1992/02/05  08:40:30  libes
 * Initial revision
 *
 * Revision 1.1  1992/01/22  02:17:49  libes
 * Initial revision
 *
 * Revision 1.7  1992/01/15  19:56:15  shepherd
 * Commented out text after #else and #endif.
 *
 * Revision 1.5  91/10/30  08:36:54  silver
 * Express N14 Changes
 *
 * Revision 1.6  1991/08/30  16:36:07  libes
 * fixed HASHlist to use state from parameter instead of static
 *
 * Revision 1.5  1991/08/06  18:55:21  libes
 * Declared HASHcopy for DICT_copy support
 *
 * Revision 1.4  1991/07/19  03:53:36  libes
 * added action HASH_DELETE
 * made action HASH_INSERT return failure upon duplicate entry
 *
 * Revision 1.3  1991/02/26  21:05:59  libes
 * Defined routines to visit every element in hash table.
 *
 * Revision 1.2  1990/09/06  10:51:11  clark
 * BPR 2.1 alpha
 *
 * Revision 1.1  90/06/11  17:05:54  clark
 * Initial revision
 *
 */

#include "sc_export.h"
#include "sc_fwd.h"

#include "basic.h"
#include "alloc.h"

/************/
/* typedefs */
/************/

typedef enum { HASH_FIND, HASH_INSERT, HASH_DELETE } Action;

/****************/
/* abstractions */
/****************/

struct Hash_Table_;
typedef struct Hash_Table_ *Hash_Table;

typedef struct Hash_Entry_ {
    unsigned char    *key;
    void *data;
    Symbol  *symbol;
    char type;
    struct Hash_Entry_ *next;
} Hash_Entry;

typedef struct Hash_Iterator_ {
    Hash_Table table;
    unsigned int hash;
    Hash_Entry *p;
    char type;
} Hash_Iterator;

/********************/
/* global variables */
/********************/

extern SC_EXPRESS_EXPORT struct freelist_head HASH_Table_fl;
extern SC_EXPRESS_EXPORT struct freelist_head HASH_Entry_fl;

/******************************/
/* macro function definitions */
/******************************/

/* maybe this could be migrated to the implementation */
#ifndef HASH_TESTING
#  define HASH_Table_new()      ((Hash_Table )ALLOC_new(&HASH_Table_fl))
#  define HASH_Table_destroy(x) ALLOC_destroy(&HASH_Table_fl,(Freelist *)(Generic)x)
#  define HASH_Entry_new()      ((Hash_Entry * )ALLOC_new(&HASH_Entry_fl))
#  define HASH_Entry_destroy(x) ALLOC_destroy(&HASH_Entry_fl,(Freelist *)(char *)x)
#else
#  define HASH_Table_new()      calloc(1, sizeof(struct Hash_Table_))
#  define HASH_Table_destroy(x) free(x)
#  define HASH_Entry_new()      calloc(1, sizeof(Hash_Entry))
#  define HASH_Entry_destroy(x) free(x)
#endif

/***********************/
/* function prototypes */
/***********************/

extern SC_EXPRESS_EXPORT void        HASHinitialize PROTO( ( void ) );
extern SC_EXPRESS_EXPORT Hash_Table  HASHcreate PROTO( ( void ) );
extern SC_EXPRESS_EXPORT Hash_Table  HASHcopy PROTO( ( Hash_Table ) );
extern SC_EXPRESS_EXPORT void        HASHdestroy PROTO( ( Hash_Table ) );
extern SC_EXPRESS_EXPORT Hash_Entry* HASHsearch PROTO( ( Hash_Table, Hash_Entry, Action ) );
extern SC_EXPRESS_EXPORT void        HASHdelete PROTO( ( Hash_Table, Hash_Entry * ) );
extern SC_EXPRESS_EXPORT void        HASHdo_init PROTO( ( Hash_Table, Hash_Iterator *, char ) );
extern SC_EXPRESS_EXPORT Hash_Entry* HASHdo PROTO( ( Hash_Iterator * ) );

#endif /*HASH_H*/
