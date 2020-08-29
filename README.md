


# Sass to css compiler 

# In progress! ...

Compilador de Sass escrito en javascript

## Ejemplos

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



Se compila a:

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








 









