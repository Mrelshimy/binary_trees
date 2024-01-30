if [ "$1" ]; then
	make leakcheck N="$1"
	make clean
else
	echo "Enter the task number to check"
fi
