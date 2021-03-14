
# Compilador scss (con flex)

# In progress! ...

Ejemplo didáctico de la teoría de compiladores

### Caracteristicas
- Analizador léxico: implementado con flex
- Analizador sintáctico: (por verse)


## Ejemplos
Al final el compilador deberá de ser capaz de convertir el código scss a código css:

Entrada:
```
$bg: green;
.className{
  h1{
    background: red;
    padding: 10px;
  }
  &:hover{
    background: blue;
    border: 1px solid $bg;
  }
}
```

Salida:
```
.className h1{
  background: red;
  padding: 10px; 
}
.className::hover{
  background: blue;
  border: 1px solid green;
}

```








 









