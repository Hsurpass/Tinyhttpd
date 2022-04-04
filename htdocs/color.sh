#!/usr/bin/bash
color="orange"
# echo ${color}

if [ ${REQUEST_METHOD} = "get" -o ${REQUEST_METHOD} = "GET" ]
then 
    color_string=${QUERY_STRING}
elif [ ${REQUEST_METHOD} = "POST" -o ${REQUEST_METHOD} = "post" ]
then
    read -n ${CONTENT_LENGTH} color_string
fi

if [ ${color_string} ]
then
color = ${color_string:6}
fi

echo "Content-Type: text/html; charset=ISO-8859-1"
echo ""
echo "<body bgcolor=\"${color}\">"
echo "<h1>This is ${color}</h1>"
echo "</body>"
