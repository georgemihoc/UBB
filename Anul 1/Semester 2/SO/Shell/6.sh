dir = $1
nrfisiere=0
T=0
echo "director curent: $dir"
for F in `find $dir -type f -name "*.txt"`
do
        let nrfisiere=nrfisiere+1
        nrli=`grep "" $F | wc -l`
        let T=T+nrli
done

echo "Numarul de fisiere cu extensia .txt este: $nrfisiere"
echo "Nr de linii total este: $T"
let media=T/nrfisiere
echo "Media este $media"

