def functie(a):
    a[0] = 42
    print (id(a))
    return 7
x= [1,2]
print(id(x))
functie(x)
print(x)