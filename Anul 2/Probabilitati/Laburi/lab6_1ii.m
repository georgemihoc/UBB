function lab6_1ii(n)
x = normrnd(1,1,1,n);
y = 3*x + 1;

fprintf('V(x) estimat: %3.2f.\n', var(x, 1));
fprintf('V(x) teoretic: 1.\n');
fprintf('V(y) estimat: %3.2f.\n', var(y, 1));
fprintf('V(y) teoretic: 9.\n');
fprintf('E(x*y) estimat: %3.2f.\n', mean(x.*y));
fprintf('E(x*y) teoretic: 7.\n');

R = corrcoef(x, y);
rho = R(1,2);
fprintf('rho estimat: %3.2f.\n', abs(rho));
fprintf('rho teoretic: 1.\n');

fprintf('p(x<2, y>1) estimat: %3.2f\n',mean(x<2 & y > 1));
fprintf('p(x<2, y>1) teoretic: %3.2f.\n', normcdf(2, 1, 1)-normcdf(0,1,1));
end 