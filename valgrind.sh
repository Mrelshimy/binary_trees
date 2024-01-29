if [ "$1" ]; then
	make leakcheck N="$1"
else
	echo "Enter the task number to check"
fi
