cat /etc/passwd | egrep -v '(^#.*|^$)' | awk 'NR %2-1' | rev | egrep -o '[^:]*$' | sort -r | awk "NR >= "$FT_LINE1" && NR <= "$FT_LINE2 | awk 'ORS=", "' | sed 's/, $/./' | tr -d '\n'
