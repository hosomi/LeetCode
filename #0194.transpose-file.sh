# Read from the file file.txt and print its transposed content to stdout.
cols=$(wc file.txt | awk '{print $2 / $1}')

for i in `seq 1 $cols`
do
    awk -v col="$i" '{print $col}' file.txt |xargs
done
