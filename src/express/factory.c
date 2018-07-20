#include "express/schema.h"
#include "express/type.h"

#include "express/dict.h"

/** Create and return an empty scope inside a parent scope. */
Scope SCOPEcreate( char type ) {
    Scope d = SCOPE_new();
    d->symbol_table = DICTcreate( 50 );
    d->type = type;
    return d;
}

Scope SCOPEcreate_tiny( char type ) {
    Scope d = SCOPE_new();
    d->symbol_table = DICTcreate( 1 );
    d->type = type;
    return d;
}

void SCOPEdestroy( Scope scope ) {
    SCOPE_destroy( scope );
}

/**
 * create a scope without a symbol table
 * used for simple types
 */
Scope SCOPEcreate_nostab( char type ) {
    Scope d = SCOPE_new();
    d->type = type;
    return d;
}

/** Create and return a schema. */
Schema SCHEMAcreate( void ) {
    Scope s = SCOPEcreate( OBJ_SCHEMA );
    s->enum_table = DICTcreate(50);
    s->u.schema = SCHEMA_new();
    return s;
}

/**
 * create a type with no symbol table
 */
Type TYPEcreate_nostab( struct Symbol_ *symbol, Scope scope, char objtype ) {
    Type t = SCOPEcreate_nostab( OBJ_TYPE );
    TypeHead th = TYPEHEAD_new();

    t->u.type = th;
    t->symbol = *symbol;
    DICTdefine( scope->symbol_table, symbol->name, ( Generic )t, &t->symbol, objtype );

    return t;
}

/**
 * create a type but this is just a shell, either to be completed later
 * such as enumerations (which have a symbol table added later)
 * or to be used as a type reference
 */
Type TYPEcreate_name( Symbol * symbol ) {
    Scope s = SCOPEcreate_nostab( OBJ_TYPE );
    TypeHead t = TYPEHEAD_new();

    s->u.type = t;
    s->symbol = *symbol;
    return s;
}

Type TYPEcreate( enum type_enum type ) {
    TypeBody tb = TYPEBODYcreate( type );
    Type t = TYPEcreate_from_body_anonymously( tb );
    return( t );
}

Type TYPEcreate_from_body_anonymously( TypeBody tb ) {
    Type t = SCOPEcreate_nostab( OBJ_TYPE );
    TypeHead th = TYPEHEAD_new();

    t->u.type = th;
    t->u.type->body = tb;
    t->symbol.name = 0;
    SYMBOLset( t );
    return t;
}

TypeBody TYPEBODYcreate( enum type_enum type ) {
    TypeBody tb = TYPEBODY_new();
    tb->type = type;
    return tb;
}

Symbol * SYMBOLcreate( char * name, int ref_typ, int line, const char * filename ) {
    Symbol * sym = SYMBOL_new();
    sym->name = name;
    sym->ref_typ = ref_typ;
    sym->line = line;
    sym->filename = filename; /* NOTE this used the global 'current_filename',
                               * instead of 'filename'. This func is only
                               * called in two places, and both calls use
                               * 'current_filename'. Changed this to avoid
                               * potential future headaches. (MAP, Jan 12)
                               */
    return sym;
}
