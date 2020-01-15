dir=$1
nrfisiere=0
T=0
echo "director curent: $dir"
for F in `find $dir -type f -name "*.rtf"`
do
       	echo $F
	cat $cat $F | wc -l
	if [ $nr -gt 5 ] then
	echo $F
	fi
done

