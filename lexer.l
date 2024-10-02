%{
#include "project1.h"  // Ensure INTEGER is defined in project1.h
#include <string.h>
%}

%option noyywrap

%%

[0-9]+    { return INTEGER; }
"+"       { return '+'; }
"-"       { return '-'; }
"*"       { return '*'; }
"/"       { return '/'; }
"("       { return '('; }
")"       { return ')'; }
[ \t\n]   { /* Ignore whitespace */ }
.         { /* Error handling for unexpected characters */ }

%%