#!/bin/bash
# A script that sends a DELETE request to the URL
[ -z "$1" ] && echo "Usage: $0 <URL>" && exit 1 || curl -s -X DELETE "$1"
