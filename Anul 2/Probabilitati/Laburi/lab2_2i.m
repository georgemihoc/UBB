function counter=lab2_2i(N)
    hold on; 
    axis square;
    axis off;
    rectangle('Position',[0 0 1 1],'FaceColor','w');
    rectangle('Position',[0 0 1 1],'Curvature',[1 1]);
    counter = 0;
    for i=1:N
        x=rand;
        y=rand;
        P=[x,y];
        O=[0.5 0.5];
        if(pdist([O;P]) < 0.5)
            plot(x,y,'or','MarkerSize',3,'MarkerFaceColor','r');
            counter++;
        end
    end
    counter=counter/N;
end