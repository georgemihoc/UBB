function lab4_1()
    fileID = fopen('keyword_spam.txt','r');
    spam = textscan(fileID,'%s');
    fclose(fileID);
    
    fileID = fopen('keyword_ham.txt','r');
    ham = textscan(fileID,'%s');
    fclose(fileID);

    fileID = fopen('email2.txt','r');
    email = textscan(fileID,'%s');
    fclose(fileID);
    
    words = unique([spam{1};ham{1}]);
    p_spam = numel( spam{1}) / (numel(spam{1}) + numel(ham{1})); 
    p_ham = numel( ham{1}) / (numel(spam{1}) + numel(ham{1})); 
    
    for i = 1:numel(words)
        sumspam = sum(strcmp(words{i}, spam{1})) / numel(spam{1});
        sumham = sum(strcmp(words{i}, ham{1})) / numel(ham{1});
        
        if ismember(words{i},email{1})
            p_spam = p_spam*sumspam;
            p_ham = p_ham*sumham;
        else
            p_spam = p_spam*(1-sumspam);
            p_ham = p_ham*(1-sumham);
        end
    end
    
    if p_spam > p_ham
        disp('email spam');
    else
        disp('email ham');

end