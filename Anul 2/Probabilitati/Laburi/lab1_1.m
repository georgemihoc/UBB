function a=lab1_1(v,k)
c=nchoosek(v,k);
a = [];
for step=1:nchoosek(length(v),k)
    a=[a;perms(c(step,:))];
end
end