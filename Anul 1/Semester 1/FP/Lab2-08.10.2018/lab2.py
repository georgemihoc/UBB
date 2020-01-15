n = input("Dati nr n:")
p1 = 1
p2 = int (n)-1
ok = 0
if int(n)<3:
    print("imposibil")
else:
        while ok == 0 :
            #print (p1,p2)
            p1 += 1
            p2 -= 1
            
            ok1 = 1
            ok2 = 1
            
            for i in range(2,p1-1):
                if p1%i == 0:
                    ok1 = 0
                    
            for i in range(2,p2-1):
                if p2%i == 0:
                    ok2 = 0
            
            if ok1 == 1 and ok2 == 1:
                ok= 1

            if p1>int(n) or p2<0:
                break
        if p1>0 and  p2>0 :
            print ("p1= ",p1," p2= ",p2)
        else:
            print ("imposibil")
