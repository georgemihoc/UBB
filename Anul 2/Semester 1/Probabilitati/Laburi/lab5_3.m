function lab5_3(n)
    x = zeros(n,2);
    for i = 1:n
        k = unidrnd(8);
        if k <= 2
            x(i,:) = [-1 -1];
        elseif k == 3
            x(i,:) = [-1 1];
        elseif k == 4
            x(i,:) = [-1 2];
        elseif k == 5
            x(i,:) = [1 -1];
        elseif k == 6 || k == 7
            x(i,:) = [1 1];
        else
            x(i,:) = [1 2];
        end
    end
    prob_sim = mean(x(:,1).*x(:,2) >= 1)
    prob_ter = 2/8 + 2/8 + 1/8
    med_sim = mean(x(:,1).*x(:,2))
    med_t = -2*1/8 - 1*2/8 + 1*4/8 + 2*1/8
end