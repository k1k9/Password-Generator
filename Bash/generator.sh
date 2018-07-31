#!/bin/bash

characters=('1' '2' '3' '4' '5' '6' '7' '8' '9' '0' 'q' 'w' 'e' 'r' 't' 'y' 'u' 'i' 'o' 'p' 'a' 's' 'd' 'f' 'g' 'h' 'j' 'k' 'l' 'z' 'x' 'c' 'v' 'b' 'n' 'm' '!' '@' '#' '$' '%' '^' '&' '*' '(' ')' '-' '_' '=' '+' '`' '~' '[' ']' ';')

password=''

clear

printf "\n\tSelect Power of u password\n
\t1. Low (64 characters)
\t2. Medium (128 characters)
\t3. Hihg (512 characters)
\t4. Strong (1024 characters)
\t5. Ultra (2048 characters)\n"

power='0'
while [ "$power" = '0' ]; do
	read option

	case "$option" in
		"1") power='64' ;;
		"2") power='128' ;;
		"3") power='512' ;;
		"4") power='1024' ;;
		"5") power='2048' ;;
		*) echo 'Insert number from menu (1-5)'
	esac
done

for i in `seq 1 "$power"`
do
	chars="${#characters[@]}"
	nchar=$(( ( RANDOM % "$chars" )  + 0 ))
	char="${characters[$nchar]}"
	password+="$char"
done

printf "Your new password:\n %s" "$password"

printf '\n\nCan u save this pass to file?   (y/n): '; read -r ans
if [ "$ans" = "y" ] ; then
	printf "Can you change deafult path for save u new password?   (y/n): "; read -r path
	if [ "$path" = "n" ] ; then
		path="$PWD"
	elif [ "$path" = "y" ] ; then
		printf "Entry new path (example: /home/user/Desktop): "; read -r newpath
		path="$newpath"
	fi
	printf "If you want u can add note for ur password or leave it blan (example: pass to my mail): "; read -r note

	path+="/password.txt"
	fpass="$note"': '"$password"
	if [ -e "$path" ] ; then
	       fpass=$'\n\n\n'"$fpass"
      	fi	
	echo "$fpass" >> "$path"

	printf "\n\n\nThat's it! Your password will be save in %s \n" "$path"
fi
