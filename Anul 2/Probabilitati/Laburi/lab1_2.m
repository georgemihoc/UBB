function ceva=lab1_2(k,n)
pos1=nchoosek(1:n+k-1,k-1);
ceva=zeros(nchoosek(n+k-1,k-1),k);
for j=1:nchoosek(n+k-1,k-1)
    sir=zeros(1,n+k-1);
    sir(pos1(j,:))=1;
    i=1;
    ceva(j,i)=0;
    disp(sir);
    for ind=1:n+k-1
        if sir(ind)==0
            ceva(j,i)=ceva(j,i)+1;
        else
            i=i+1;
        end
    end
end
end