import DiccionarioMorse as dm

class Frase:
    def __init__(self, string: str):
        self.string = string

    def hacer_lista(self):
        return list(self.string)

    def Str_a_Mor(self):
        return dm.traducir(self.string)




frase1 = Frase("Hola")
print(frase1.Str_a_Mor())
