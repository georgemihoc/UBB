function lab5_4(n)

x1 = exprnd(15,1,n);
x2 = exprnd(15,10,n);
y1 = unifrnd(5,15,1,n);
y2 = unifrnd(5,15,10,n);
i1 = (15 <= x1) & (x1 <= 10 + y1);
i2 = (15 <= x2) & (x2 <= 10 + y2);

prob_sim = mean(i1)
med_sim = mean(sum(i2,1))
prob_t = (3*exp(-5/3)-exp(-1))/2
med_t = 5*(3*exp(-5/3)-exp(-1))

%x = exprnd(15,10,n);
%y = unifrnd(5,15,10,n);
%i = (15 <= x) & (x <= 10 +y);