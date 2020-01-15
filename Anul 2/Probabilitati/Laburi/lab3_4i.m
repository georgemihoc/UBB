function poz = lab3_4i(p,k,m)
    poz = zeros(m, k+1);
    c = zeros(1, m);
    for i = 1:m
        stg = 0;
        for j = 2:k+1
            pas = 2*lab3_1(p,1,1)-1;
            poz(i,j) = poz(i, j-1) + pas;
            if pas == 1 && stg == 0
                c(i) = c(i) + 1;
            else
                stg = 1;
            end
        end
    end
end