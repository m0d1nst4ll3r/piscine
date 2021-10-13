cat /etc/passwd | sed s/:.*// | rev | head -c -1 | sed -z s/'\n'/', '/g | sed s/$/./
