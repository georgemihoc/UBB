function lab5_2(n)
    clf; hold on;
    x = normrnd(165,10,1,n);
    wbin = (max(x) - min(x)) / 10;
    bins = min(x):wbin:max(x);
    count = histc(x,bins);
    bar(bins,count/(n*wbin),'histc');
    f = @(x) normpdf(x,165,10);
    fplot(f,[min(x),max(x)],'r');
    med_sim = mean(x), med_t = 165
    prop_sim = mean(160 <= x & x <= 170)
    prop_t = normcdf(170,165,10) - normcdf(160, 165, 10)
end