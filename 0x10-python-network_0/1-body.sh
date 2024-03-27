#!/bin/bash
# Sends a GET request to the URL, and displays the body 
curl -sLf "$1" -X GET
