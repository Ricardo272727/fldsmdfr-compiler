## En desarrollo

## Compilador basico autocontenido 

Compila desde un lenguaje llamado *fldsmdfr* a lenguaje ensamblador NASM (x86_64), basado en el compilador creado en: 
http://blog.pucp.edu.pe/blog/tito/2019/01/09/crea-tu-propio-compilador-parte-3-inventando-un-lenguaje/ 


#### Caracteristicas

- Compila a .asm NASM linux

- Imperativo, Nada de caracteristicas funcionales complejas

- Tipado

- Con solo dos tipos de datos(para que sea autocontenido)

- Reducida cantidad de instrucciones

- Soporte a manejo de archivos

#### Palabras reservadas

“var”, “number”, “string”, “if”, “then”, “end”, “while”, “do”, “proc”, “func” y “exit”.

#### Comentarios

// esto es un comentario

#### Identificadores

- El primer caracter debe ser: letra(mayuscula o minuscula) o guion bajo
- los caracteres siguientes pueden ser numeros, letras o guion bajo _
- Solo letras del alfabeto en ingles
- longitud menor a 255 caracteres

#### Ejemplo 

<declaraciones de funciones>
<declaraciones de variables>
<programa principal>

#### Hello world

print "Hola mundo"

#### No puntos y comas

#### Otro ejemplo

var x: number
var cad: string
cad = "hola"
print cad


#### Operadores

"=" asignacion de variables y comparacion de numeros

"<>" comparacion de numeros

"+" suma de numeros y concatenacion de cadenas

"-" resta de numeros

">" comparacion de numeros

"<" comparacion de numeros


#### Expresiones

Las expresiones son simples. De dos operandos.

##### Expresiones validas

x = 1

x = x + y

x > 0

##### Expresiones invalidas

x = x + y + 1

x > y + 1 


#### Tipos de datos

Tipo numerico -> numeros con signo (hasta 32 bits de longitud). Ejemplos: 1000, -50. Solo valores enteros

Tipo cadena -> Cadenas de cualquier longitud terminadas en caracter NULL
Ejemplo: "fldsmdfr" longitud maxima de 255 caracteres

Las cadenas dentro del codigo solo pueden ocupar una linea.

Los numeros tambien pueden ser usados como booleanos asumiendo todo valor != 0 como TRUE

#### Variables

Se declaran con la palabra reservada "var"

var x: number

var y: string

Solo se permite una declaracion por cada palabra "var"

Se pueden hacer declaraciones en cualquier lugar del codigo

No se manejara constantes

#### Arreglos

var x[10]: integer
var cad[5]: string

cad[1] = 65; // primer caracter: 'A'

#### Estructuras

- sentencia condicional

if <expresion> then <cuerpo> end

- bucle 

while <expresion> do <cuerpo> end


#### Funciones

Funciones definidas por el usuario

func <nombre>
<cuerpo>
end

Todos los parametros se pasan por valor (copia)

Las funciones pueden devolver valores con "exit"

func doble(x: integer)
    exit x + x
end

#### Funciones predefinidas

print <expresion>

println <expresion>

Sale de una funcion devolviendo un valor
exit <expresion>

Devuelve la longitud de una cadena como numero
length(<expresion>) 

Convierte de string a numero
StrToInt(<expresion>)

Convierte un numero en string
IntToStr(<expresion>)



### Partes de un compilador

#### Analizador lexico (lexer)

Identifica y extrae los "tokens", que son los elementos minimos de caracteres con significado coherente para un lenguaje de programacion

#### Analizador sintactico (parser)

Procesa los tokens de acuerdo a las reglas de la gramatica del lenguaje de programacion. Por lo general su resultado termina en lo que se llama un __arbol de sintaxis__


#### Analizador semantico

Realiza una comprobacion de mayor nivel al codigo fuente, como por ejemplo, si un tipo de datos es valido en la posicion donde se encuentra.

#### Arbol de sintaxis

Puede haber uno o varios. Es una estrutura que representa al codigo fuente en cuanto a estructura. Los nodos del arbol pueden representar a funciones o declaraciones. Se usa para realizar el analisis semantico y para la generacion de codigo

#### Generador de codigo intermedio

Realiza la primer etapa en la generacion de codigo. Se suele usar un codigo intermedio, para simplificar la generacion de codigo y para facilitar la creacion de nuevos generadores de codigo.

#### Generador de codigo

Crea el codigo destino, lo ideal es binario o ejecutable, pero aqui crearemos codigo ensamblador

#### Optimizador de codigo

La idea es obtener un codigo simplificado, optimo y/o rapido.







