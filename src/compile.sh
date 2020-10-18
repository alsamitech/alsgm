echo "(c) Alsami Technologies Foundation, 2020"
echo " "
echo "Complining ALSGM (codename: yin, Project ID: ALS_GM_ENGN)"
echo " "
echo "Please Enter Game Source Path: "
read sourcepath
echo "Please Enter Game Target Path: "
read targetpath
g++ -o $targetpath $sourcepath -lpthread -lX11 -Wwrite-strings
