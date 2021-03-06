/*
    Group Number            -        26
    Abhinav Tuli            -   2017A7PS0048P
    Kushagra Raina          -   2017A7PS0161P
    Tanmay Moghe            -   2017A7PS0184P
    Amratanshu Shrivastava  -   2017A7PS0224P
    Rohit Bohra             -   2017A7PS0225P
*/

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "parserDef.h"
#include "lexerDef.h"
#include "symbolTableDef.h"

variableTable* initializeVarTable();

void printVarTable(variableTable* ptr);

int hash1(char * str);

void insertInVarTable(variableTable *ptr, char* var, bool isArray, int tag, int nestingLevel);

void updateArrayVarStatic(variableTable *ptr, char* var, int lB, int uB);

void updateArrayVarDynamic(variableTable *ptr, char* var, char* lB, char* uB);

bool searchInVarTable(variableTable *ptr, char* var);

variableTableEntry* retrieveVarTable(variableTable *ptr, char* var);

void deleteVarTable(variableTable *ptr);

functionTable* initializeFunTable();

void printFunTable(functionTable* ptr);

void insertInFunTable(functionTable *ptr, char* func, parameter* inputL, parameter* outputL);

bool searchInFunTable(functionTable *ptr, char* func);

void deleteFromFuncTable(functionTable *ptr, char* func);

functionTableEntry* retrieveFunTable(functionTable *ptr, char* func);

void deleteFunTable(functionTable *ptr);

parameter* initializeParameter(char* varID, bool isArray, int tag);

void updateParameterArrayStatic(parameter* p, int low, int high);

void updateParameterArrayDynamic(parameter* p, char* low, char* high);

void updateOffset(variableTable* ptr, char* varname, int offset);

void addParametertoList(parameter* head, parameter* node);

void printParameterList(parameter* head);

void printAllTables(functionTable *ptr, variableTable* driver);

bool searchNested(variableTable* ptr, char* varname);

variableTableEntry* searchNestedRetrieve(variableTable* ptr, char* varname);

void updateDefineBool(functionTable* ptr, char* funcName, bool isDefined);

void updateIsInput(variableTable* ptr, char* varname, bool isInput);

int retrieveWidth(variableTable* ptr, char* varname);

void printWidth(functionTable* ptr);

void printArray(functionTable* ptr);

#endif