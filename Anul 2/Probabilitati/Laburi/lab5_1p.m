function lab5_1p(n)
    clf; hold on;
    x = lab5_1([-1 2 3],[4/6 1/6 1/6],n);
    count = histc(x,[-1 2 3]);
    bar([-1 2 3],count/n,0.9,'FaceColor','b');
    bar([-1 2 3],[4/6 1/6 1/6],'FaceColor','y');
    media_sim = mean(x)
    media_t=(3+2-4)/6
end