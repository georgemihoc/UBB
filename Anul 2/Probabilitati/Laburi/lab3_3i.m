function a = lab3_3i(p,m)
    a = zeros(1,m);
    for i=1:m
        while ~lab3_1(p,1,1)
            a(i) += 1;
        end
    end
end