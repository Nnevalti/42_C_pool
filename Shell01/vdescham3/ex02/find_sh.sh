find . -type f -name "*.sh" | egrep -o '[^/]*$' | cut -d . -f 1
