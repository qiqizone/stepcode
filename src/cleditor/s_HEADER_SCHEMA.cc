#ifndef  S_HEADER_SCHEMA_CC
#define  S_HEADER_SCHEMA_CC

/*
* NIST STEP Editor Class Library
* cleditor/s_HEADER_SCHEMA.cc
* April 1997
* David Sauder
* K. C. Morris

* Development of this software was funded by the United States Government,
* and is not subject to copyright.
*/

// This file was generated by fedex_plus.  You probably don't want to edit
// it since your modifications will be lost if fedex_plus is used to
// regenerate it.

/* $Id: s_HEADER_SCHEMA.cc,v 3.0.1.4 1997/11/05 22:11:42 sauderd DP3.1 $ */

#include <s_HEADER_SCHEMA.h>
#include <ExpDict.h>
#include <STEPattribute.h>

/*  **************  TYPES   */
TypeDescriptor * HEADER_SCHEMAt_SCHEMA_NAME;

/*  **************  ENTITIES    */
EntityDescriptor * HEADER_SCHEMAe_FILE_IDENTIFICATION = 0;
AttrDescriptor * a_0FILE_NAME = 0;
AttrDescriptor * a_1DATE = 0;
AttrDescriptor * a_2AUTHOR = 0;
AttrDescriptor * a_3ORGANIZATION = 0;
AttrDescriptor * a_4PREPROCESSOR_VERSION = 0;
AttrDescriptor * a_5ORIGINATING_SYSTEM = 0;

s_N279_file_identification::s_N279_file_identification( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_FILE_IDENTIFICATION;

    a = new STEPattribute( *a_0FILE_NAME, &_file_name );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_1DATE, &_date );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_2AUTHOR, &_author );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_3ORGANIZATION, &_organization );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_4PREPROCESSOR_VERSION, &_preprocessor_version );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_5ORIGINATING_SYSTEM, &_originating_system );
    a -> set_null();
    attributes.push( a );
}
s_N279_file_identification::~s_N279_file_identification() {  }

#ifdef __O3DB__
void
s_N279_file_identification::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_FILE_IDENTIFICATION;
}
#endif

const SCLP23( String ) &
s_N279_file_identification::file_name() const {
    return _file_name;
}

void
s_N279_file_identification::file_name( const char * x ) {
    _file_name = x;
}

const SCLP23( String ) &
s_N279_file_identification::date() const {
    return _date;
}

void
s_N279_file_identification::date( const char * x ) {
    _date = x;
}

StringAggregate &
s_N279_file_identification::author() {
    return ( StringAggregate & ) _author;
}

void
s_N279_file_identification::author( StringAggregate & x ) {
    _author = x;
}

StringAggregate &
s_N279_file_identification::organization() {
    return ( StringAggregate & ) _organization;
}

void
s_N279_file_identification::organization( StringAggregate & x ) {
    _organization = x;
}

const SCLP23( String ) &
s_N279_file_identification::preprocessor_version() const {
    return _preprocessor_version;
}

void
s_N279_file_identification::preprocessor_version( const char * x ) {
    _preprocessor_version = x;
}

const SCLP23( String ) &
s_N279_file_identification::originating_system() const {
    return _originating_system;
}

void
s_N279_file_identification::originating_system( const char * x ) {
    _originating_system = x;
}
EntityDescriptor * HEADER_SCHEMAe_IMP_LEVEL = 0;
AttrDescriptor * a_6IMPLEMENTATION_LEVEL = 0;

s_N279_imp_level::s_N279_imp_level( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_IMP_LEVEL;

    a = new STEPattribute( *a_6IMPLEMENTATION_LEVEL, &_implementation_level );
    a -> set_null();
    attributes.push( a );
}
s_N279_imp_level::~s_N279_imp_level() {  }

#ifdef __O3DB__
void
s_N279_imp_level::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_IMP_LEVEL;
}
#endif

const SCLP23( String ) &
s_N279_imp_level::implementation_level() const {
    return _implementation_level;
}

void
s_N279_imp_level::implementation_level( const char * x ) {
    _implementation_level = x;
}
EntityDescriptor * HEADER_SCHEMAe_FILE_NAME = 0;
AttrDescriptor * a_7NAME = 0;
AttrDescriptor * a_8TIME_STAMP = 0;
AttrDescriptor * a_9AUTHOR = 0;
AttrDescriptor * a_10ORGANIZATION = 0;
AttrDescriptor * a_11STEP_VERSION = 0;
AttrDescriptor * a_12PREPROCESSOR_VERSION = 0;
AttrDescriptor * a_13ORIGINATING_SYSTEM = 0;
AttrDescriptor * a_14AUTHORISATION = 0;

p21DIS_File_name::p21DIS_File_name( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_FILE_NAME;

    a = new STEPattribute( *a_7NAME, &_name );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_8TIME_STAMP, &_time_stamp );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_9AUTHOR, &_author );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_10ORGANIZATION, &_organization );
    a -> set_null();
    attributes.push( a );

    /*
        a = new STEPattribute (*a_11STEP_VERSION, &_step_version);
        a -> set_null ();
         attributes.push (a);
    */

    a = new STEPattribute( *a_12PREPROCESSOR_VERSION, &_preprocessor_version );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_13ORIGINATING_SYSTEM, &_originating_system );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_14AUTHORISATION, &_authorisation );
    a -> set_null();
    attributes.push( a );
}
p21DIS_File_name::~p21DIS_File_name() {  }

#ifdef __O3DB__
void
p21DIS_File_name::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_FILE_NAME;
}
#endif
const SCLP23( String ) &
p21DIS_File_name::name() const {
    return _name;
}

void
p21DIS_File_name::name( const char * x ) {
    _name = x;
}

const SCLP23( String ) &
p21DIS_File_name::time_stamp() const {
    return _time_stamp;
}

void
p21DIS_File_name::time_stamp( const char * x ) {
    _time_stamp = x;
}

StringAggregate &
p21DIS_File_name::author() {
    return ( StringAggregate & ) _author;
}

void
p21DIS_File_name::author( StringAggregate & x ) {
    _author = x;
}

StringAggregate &
p21DIS_File_name::organization() {
    return ( StringAggregate & ) _organization;
}

void
p21DIS_File_name::organization( StringAggregate & x ) {
    _organization = x;
}

/*
const SCLP23(String) &
p21DIS_File_name::step_version() const
    { return _step_version; }

void
p21DIS_File_name::step_version (const char * x)
    { _step_version = x; }
*/

const SCLP23( String ) &
p21DIS_File_name::preprocessor_version() const {
    return _preprocessor_version;
}

void
p21DIS_File_name::preprocessor_version( const char * x ) {
    _preprocessor_version = x;
}

const SCLP23( String ) &
p21DIS_File_name::originating_system() const {
    return _originating_system;
}

void
p21DIS_File_name::originating_system( const char * x ) {
    _originating_system = x;
}

const SCLP23( String ) &
p21DIS_File_name::authorisation() const {
    return _authorisation;
}

void
p21DIS_File_name::authorisation( const char * x ) {
    _authorisation = x;
}
EntityDescriptor * HEADER_SCHEMAe_FILE_DESCRIPTION = 0;
AttrDescriptor * a_15DESCRIPTION = 0;
AttrDescriptor * a_16IMPLEMENTATION_LEVEL = 0;

p21DIS_File_description::p21DIS_File_description( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_FILE_DESCRIPTION;

    a = new STEPattribute( *a_15DESCRIPTION, &_description );
    a -> set_null();
    attributes.push( a );

    a = new STEPattribute( *a_16IMPLEMENTATION_LEVEL, &_implementation_level );
    a -> set_null();
    attributes.push( a );
}
p21DIS_File_description::~p21DIS_File_description() {  }

#ifdef __O3DB__
void
p21DIS_File_description::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_FILE_DESCRIPTION;
}
#endif

StringAggregate &
p21DIS_File_description::description() {
    return ( StringAggregate & ) _description;
}

void
p21DIS_File_description::description( StringAggregate & x ) {
    _description = x;
}

const SCLP23( String ) &
p21DIS_File_description::implementation_level() const {
    return _implementation_level;
}

void
p21DIS_File_description::implementation_level( const char * x ) {
    _implementation_level = x;
}
EntityDescriptor * HEADER_SCHEMAe_S_CLASSIFICATION = 0;
AttrDescriptor * a_17SECURITY_CLASSIFICATION = 0;

s_N279_classification::s_N279_classification( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_S_CLASSIFICATION;

    a = new STEPattribute( *a_17SECURITY_CLASSIFICATION, &_security_classification );
    a -> set_null();
    attributes.push( a );
}
s_N279_classification::~s_N279_classification() {  }

#ifdef __O3DB__
void
s_N279_classification::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_S_CLASSIFICATION;
}
#endif

const SCLP23( String ) &
s_N279_classification::security_classification() const {
    return _security_classification;
}

void
s_N279_classification::security_classification( const char * x ) {
    _security_classification = x;
}
EntityDescriptor * HEADER_SCHEMAe_S_FILE_DESCRIPTION = 0;
AttrDescriptor * a_18DESCRIPTION = 0;

s_N279_file_description::s_N279_file_description( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_S_FILE_DESCRIPTION;

    a = new STEPattribute( *a_18DESCRIPTION, &_description );
    a -> set_null();
    attributes.push( a );
}
s_N279_file_description::~s_N279_file_description() {  }

#ifdef __O3DB__
void
s_N279_file_description::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_S_FILE_DESCRIPTION;
}
#endif

const SCLP23( String ) &
s_N279_file_description::description() const {
    return _description;
}

void
s_N279_file_description::description( const char * x ) {
    _description = x;
}
EntityDescriptor * HEADER_SCHEMAe_MAXSIG = 0;
AttrDescriptor * a_19MAXIMUM_SIGNIFICANT_DIGIT = 0;

p21DIS_Maxsig::p21DIS_Maxsig( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_MAXSIG;

    a = new STEPattribute( *a_19MAXIMUM_SIGNIFICANT_DIGIT, &_maximum_significant_digit );
    a -> set_null();
    attributes.push( a );
}
p21DIS_Maxsig::~p21DIS_Maxsig() {  }

#ifdef __O3DB__
void
p21DIS_Maxsig::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_MAXSIG;
}
#endif

SCLP23( Integer )
p21DIS_Maxsig::maximum_significant_digit() {
    return ( SCLP23( Integer ) ) _maximum_significant_digit;
}

void
p21DIS_Maxsig::maximum_significant_digit( SCLP23( Integer )  x ) {
    _maximum_significant_digit = x;
}
EntityDescriptor * HEADER_SCHEMAe_CLASSIFICATION = 0;
AttrDescriptor * a_20SECURITY_CLASSIFICATION = 0;

p21DIS_Classification::p21DIS_Classification( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_CLASSIFICATION;

    a = new STEPattribute( *a_20SECURITY_CLASSIFICATION, &_security_classification );
    a -> set_null();
    attributes.push( a );
}
p21DIS_Classification::~p21DIS_Classification() {  }

#ifdef __O3DB__
void
p21DIS_Classification::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_CLASSIFICATION;
}
#endif

const SCLP23( String ) &
p21DIS_Classification::security_classification() const {
    return _security_classification;
}

void
p21DIS_Classification::security_classification( const char * x ) {
    _security_classification = x;
}
EntityDescriptor * HEADER_SCHEMAe_FILE_SCHEMA = 0;
AttrDescriptor * a_21SCHEMA_IDENTIFIERS = 0;

p21DIS_File_schema::p21DIS_File_schema( ) {
    STEPattribute * a;

    eDesc = HEADER_SCHEMAe_FILE_SCHEMA;

    a = new STEPattribute( *a_21SCHEMA_IDENTIFIERS, &_schema_identifiers );
    a -> set_null();
    attributes.push( a );
}
p21DIS_File_schema::~p21DIS_File_schema() {  }

#ifdef __O3DB__
void
p21DIS_File_schema::oodb_reInit() {
    eDesc = HEADER_SCHEMAe_FILE_SCHEMA;
}
#endif

StringAggregate &
p21DIS_File_schema::schema_identifiers() {
    return ( StringAggregate & ) _schema_identifiers;
}

void
p21DIS_File_schema::schema_identifiers( StringAggregate & x ) {
    _schema_identifiers = x;
}
#endif
