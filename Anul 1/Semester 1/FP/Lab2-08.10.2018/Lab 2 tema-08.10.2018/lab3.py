#Tema pt lab3 George Mihoc :

v = 0
while int(v) != 5 :
    v = input("1.Citire lista | 2.Proprietatea 1 | 3.Proprietatea 11 | 4.Proprietatea 2 | 5.Iesire din aplicatie")
    #if int(v) == 4 :
       # return
    if int(v) == 1:
        a = []
        n= input("Nr valorilor:")
        for i in range(int(n)):
            x=input()
            a.append(x)

    if int(v) == 2:
        maxi = 0
        poz = 0
        for i in range(int (n)-1):
            nr = 1
            for j in range(int(i),int (n)-1):
                if a[j]<a[j+1]:
                    nr += 1
                else:
                    break
            if nr>maxi :
                maxi = nr
                poz = i
        #print (a)
        #print(maxi)
        print("Proprietatea 1: ",a[poz:poz+maxi])


    elif int(v) == 3 :
        nr = 0
        poz = 0
        maxi = 0
        smax = -99999
        s = 0
        for i in range(int(n)):
            s = int(a[i])
            if s>smax :
                smax = s
                poz = i
                maxi = 1

            nr = 1
            for j in range (int (i)+1, int (n)):
                s += int(a[j])
                nr += 1
                if int(s) > int(smax) :
                    smax = s
                    poz = i
                    maxi = nr
                elif int(s) == int (smax) and int (nr) > int(maxi) :
                    poz = i
                    maxi = nr
        print ("Proprietatea 11: ", a[poz:poz+maxi])
    elif int (v) > 5:
        print("Cerinta inexistenta")
    elif int (v) == 4:
        maxim = 0
        pozitie = 0
        for i in range (int(n)-2):
            b = []
            poz = i
            nr = 1
            b.append(a[i])
            numere = 1
            ok = 1
            j = i+1
            while ok== 1 and  numere <= 3 and j< int(n):
                if a[j] in b:
                    b.append(a[j])
                    nr += 1
                    j += 1
                elif numere <3:
                    b.append(a[j])
                    j += 1
                    nr += 1
                    numere += 1
                else: ok = 0
                    
            if nr > maxim :
                maxim = nr
                pozitie = poz
        print ("Proprietatea 2:", a[pozitie:pozitie+maxim])
