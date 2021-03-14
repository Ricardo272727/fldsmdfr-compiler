%{
 #include <math.h>
%}
DIGITO [0-9]
WORD   [A-Za-z-][A-Za-z0-9-]*
HEX_COLOR #[[0-9A-F]{3-6}]
HS [h[1-6]]
HTML_TEXT p|span|label
HTML_LINK a|base
HTML_IMG img|area|map|param|object
HTML_LIST ul|ol|li|dl|dt|dd
HTML_TABLE tr|td|th|tbody|thead|tfoot|caption
HTML_FORMS form|input|textarea|select|option|button|legend
HTML_MEDIA audio|video
HTML body|html|canvas|center|div|iframe|footer|header|main|section|nav
CSS_PROPS background|border
CSS_VALUES none|flex|center|left|right


%%
"."{WORD}+ {
  printf( "Clase: (%s)\n", yytext );
}

"#"{WORD}+ {
  printf( "Id: (%s)\n", yytext );
}

"{" {
  printf( "Llave que abre (%s)\n", yytext );
}

"}" {
  printf( "Llave que cierra (%s)\n", yytext );
}

":" {
  printf( "Asignacion (%s)\n", yytext );
}

"," {
  printf( "Separador coma , \n");
}

";" {
  printf( "Punto y coma ; \n");
}

{HS}|{HTML_MEDIA}|{HTML_FORMS}|{HTML_TABLE}|{HTML_LIST}|{HTML_IMG}|{HTML_LINK}|{HTML_TEXT}|{HTML} {
  printf("Html tag: %s\n", yytext);
}

{CSS_PROPS} {
  printf("Propiedad: %s\n", yytext);
}

{CSS_VALUES} {
  printf("Valor: %s\n", yytext);
}

{WORD} {
  printf("Palabra no identificada: %s\n", yytext);
}

[ \t\n]+          /* se come los espacios en blanco */

.           printf( "Caracter no reconocido: %s\n", yytext );
%%
int main( int argc, char ** argv ){
   ++argv; --argc;  /* se salta el nombre del programa */
   if ( argc > 0 )
           yyin = fopen( argv[0], "r" );
   else
           yyin = stdin;
   yylex();
}
