'''
Un punto es una unidad ( . = 1u)
Un guion son tres unidades ( - = 3u)
El espacio entre partes de una misma letra es una unidad (1u)
El espacio entre letras son tres unidades (3u)
El espacio entre palabras son siete unidades (7u)
'''

Diccionario = {
    "A" : [ '.' , '-' , '%' ],
    "B" : [ '-' , '.' , '.' , '.' , '%'],
    "C" : [ '-' , '.' , '-' , '.' , '%' ],
    "D" : [ '-' , '.' , '.' , '%' ],
    "E" : [ '.' , '%' ],
    "F" : [ '.' , '.' , '-' , '.' , '%' ],
    "G" : [ '-' , '-' , '.' , '%' ],
    "H" : [ '.' , '.' , '.' , '.' , '%' ],
    "I" : [ '.' , '.' , '%' ],
    "J" : [ '.' , '-' , '-' , '-' , '%' ],
    "K" : [ '-' , '.' , '-' , '%' ],
    "L" : [ '.' , '-' , '.' , '.' , '%' ],
    "M" : [ '-' , '-' , '%' ],
    "N" : [ '-' , '.' , '%' ],
    "O" : [ '-' , '-' , '-' , '%' ],
    "P" : [ '.' , '-' , '-' , '.' , '%' ],
    "Q" : [ '-' , '-' , '.' , '-' , '%' ],
    "R" : [ '.' , '.' , '.' , '%' ],
    "T" : [ '-' , '%' ],
    "U" : [ '.' , '.' , '-' , '%' ],
    "V" : [ '.' , '.' , '.' , '-' , '%' ],
    "W" : [ '.' , '-' , '-' , '%' ],
    "X" : [ '-' , '.' , '.' , '-' , '%' ],
    "Y" : [ '-' , '.' , '-' , '-' , '%' ],
    "Z" : [ '-' , '-' , '.' , '.' , '%' ],
    " " : ['$'],
    "1" : [ '.' , '-' , '-' , '-' , '-' , '%' ],
    "2" : [ '.' , '.' , '-' , '-' , '-' , '%' ],
    "3" : [ '.' , '.' , '.' , '-' , '-' , '%' ],
    "4" : [ '.' , '.' , '.' , '.' , '-' , '%' ],
    "5" : [ '.' , '.' , '.' , '.' , '.' , '%' ],
    "6" : [ '-' , '.' , '.' , '.' , '.' , '%' ],
    "7" : [ '-' , '-', '.' , '.' , '.' , '%' ],
    "8" : [ '-' , '-' , '-' , '.' , '.' , '%' ],
    "9" : [ '-' , '-' , '-' , '-' , '.' , '%' ],
    "0" : [ '-' , '-' , '-' , '-' , '-' , '%' ]
}

def traducir(frase):
    lista = list(frase.upper())
    nueva_lista = []
    for i in range(0, len(lista)):
        nueva_lista += Diccionario[lista[i]]
    
    return nueva_lista

