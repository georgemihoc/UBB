function lab4_2B(n)
    N = zeros(1,n);
    for i = 1:n
        %lab4_2 e bernoulli
        B1 = lab4_2(0.8);
        if B1 == 1
            B2 = lab4_2(0.9);
        else
            B2 = lab4_2(0.6);
        end
        
        if B2 == 1 && B1 == 1
            B3 = lab4_2(0.6);
        elseif B2 == 1 && B1 == 0
            B3 = lab4_2(0.2);
        elseif B2 == 0 && B1 == 1
            B3 = lab4_2(0.9);
        else
            B3 = lab4_2(0.4);
        end
        
        if B3 == 1
            B4 = lab4_2(0.3);
            B5 = lab4_2(0.5);
        else
            B4 = lab4_2(0.5);
            B5 = lab4_2(0.8);
        end
        
       if B5 == 1 && B4 == 1
            B6 = lab4_2(0.5);
        elseif B5 == 1 && B4 == 0
            B6 = lab4_2(0.3);
        elseif B5 == 0 && B4 == 1
            B6 = lab4_2(0.8);
        else
            B6 = lab4_2(0.5);
        end 
        
        N(i) = bin2dec(num2str([B6,B5,B4,B3,B2,B1]));
    end
    
    bar(0:64,histc(N, 0:64)/n);
    grid on;
    set(gca,'XLim',[0 64],'XTick',0:2:64);
end