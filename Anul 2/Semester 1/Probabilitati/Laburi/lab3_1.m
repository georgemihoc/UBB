%p trebuie dat intre 0 si 1
function a=lab3_1(p,l,k)
a = randsample([0 1], l*k, true, [1-p p]);
a = reshape(a, l, k);
end