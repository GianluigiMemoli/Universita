echo "*******************MAKECOMPILINGDIRS*********************"
echo "*********************************************************"
echo "*********************************************************"
printf "\n\n"
echo "TYPE PROJECTNAME"
read prjname
echo $prjname
mkdir -p -v "$prjname/bin"
printf '' > "$prjname/Makefile"
