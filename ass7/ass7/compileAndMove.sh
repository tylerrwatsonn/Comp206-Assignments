
gcc -o answer answer.c
gcc -o addgold addgold.c
cp answer ../public_html/cgi-bin
cp addgold ../public_html/cgi-bin
cd ../public_html
chmod 755 cgi-bin
cd cgi-bin
chmod 755 answer
mv answer answer.cgi
chmod 755 addgold
mv addgold addgold.cgi
