function a=lab2_1i
    a = 0;
    u = ['r','r','r','r','r','a','a','a','v','v'];
    for step=1:2000
        b = randsample(u,3,'false');
        if(b(1) == 'r' || b(2) == 'r' || b(3) == 'r')
            a++;
        end
    end
    a = a/2000;
end